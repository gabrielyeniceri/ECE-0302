// Project 3 -- XML Parser

/** @file XMLParser.cpp */

#include <string>
#include "XMLParser.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>

//These 2 helper function ensure the error checking
//removes the whitespace charactrs from string
static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}


//tag must not be empty, first char cannot be - or . or a digit
//it must be one of the approved characters
//if it passes all the checks here it returns true
static bool isValidTagName(const std::string &name) {
    if (name.empty())
        return false;
    char first = name[0];
    if (first == '-' || first == '.' || std::isdigit(first))
        return false;
    for (char c : name) {
        if (std::isspace(c))
            return false;
        if (!(std::isalnum(c) || c == '_' || c == '-' || c == '.'))
            return false;
    }
    return true;
}

XMLParser::XMLParser() : isParsedSuccessfully(false)
{
	clear();
} // end default constructor

// Then finish this function to pass the 4th~6th unit tests
bool XMLParser::tokenizeInputString(const std::string &inputString)
{//it scans the input to break it into xml tokens
//it goes idenitifies characters such as <> then identifies the type
//like the declaration, start tag, empty tag, end tag and content
//for each token it validates to ensure no illegal white space or invalid tag, if it is it returns false
	// TODO, use '<' and '>' as anchors to scan string; Remember to clear each time before
	// tokenizing a new string, and refer to the following code structure:

	// for (char c : inputString)
	// {
	// 	if (c == '<') {?? continue;}
	// 	else if (c == '>') {?? continue;}
	// 	else {?? continue;}
	// }
    //most of the code is just error checking, to ensure the input is correct
        //clears the previous tokens and parsing state
        tokenizedInputVector.clear();
        elementNameBag.clear();
        while (!parseStack.isEmpty())
            parseStack.pop();
        size_t i = 0;
        bool foundMarkup = false;
        while (i < inputString.size())
        {//processes the input string
            if (inputString[i] == '<')
            {
                foundMarkup = true;
                size_t j = inputString.find('>', i);
                if (j == std::string::npos)
                    return false;
                std::string token = inputString.substr(i, j - i + 1);
                //rejected if it contains an extra <
                if (token.find('<', 1) != std::string::npos)
                    return false;
                if (token.substr(0, 2) == "<?")
                {//must not have whitespace immediately after <?
                    if (token.size() < 4 || std::isspace(token[2]) || token.substr(token.size() - 2) != "?>")
                    return false;
                    std::string inner = token.substr(2, token.size() - 4);
                    inner = trim(inner);
                    if (inner.empty())
                    return false;
                    tokenizedInputVector.push_back(TokenStruct{DECLARATION, inner});
                }
                else if (token.substr(0, 2) == "</")
                {
                    if (token.size() < 4 || std::isspace(token[2]))
                        return false;//ensures token length is sufficient as well as no white space follwing </
                    std::string inner = token.substr(2, token.size() - 3);
                    inner = trim(inner);
                    if (inner.empty() || !isValidTagName(inner))
                        return false;
                    tokenizedInputVector.push_back(TokenStruct{END_TAG, inner});
                }
                else if (token.size() >= 2 && token[token.size() - 2] == '/' && token[token.size() - 1] == '>')
                {//no white space and length
                    if (token.size() < 4 || std::isspace(token[1]))
                        return false;
                        //extracts tag name
                    std::string inner = token.substr(1, token.size() - 3);
                    inner = trim(inner);
                    if (inner.empty())
                        return false;
                    std::istringstream iss(inner);
                    std::string tagName;
                    iss >> tagName;
                    if (!isValidTagName(tagName))
                        return false;
                    tokenizedInputVector.push_back(TokenStruct{EMPTY_TAG, tagName});
                }
                else
                {//ensures token length and no white space
                    if (token.size() < 3 || std::isspace(token[1]))
                        return false;
                    std::string inner = token.substr(1, token.size() - 2);
                    inner = trim(inner);
                    if (inner.empty())
                        return false;
                        //extracts tag name
                    std::istringstream iss(inner);
                    std::string tagName;
                    iss >> tagName;
                    if (!isValidTagName(tagName))
                        return false;
                    tokenizedInputVector.push_back(TokenStruct{START_TAG, tagName});
                }
                i = j + 1;
            }
            else
            {//finds characters till < then trims and adds as a content token
                size_t j = inputString.find('<', i);
                if (j == std::string::npos)
                    j = inputString.size();
                std::string content = inputString.substr(i, j - i);
                content = trim(content);
                if (!content.empty())
                    tokenizedInputVector.push_back(TokenStruct{CONTENT, content});
                i = j;
            }
        }
        if (!foundMarkup)
            return false;//no markup is found in the input
        return true;
    }    

// Then finish this function to pass the 7th~9th unit test
bool XMLParser::parseTokenizedInput()
{
	// TODO, iterate through tokenizedInputVector to check validity
	// and update stack and bag accordingly, and refer to the following code structure:
    // returns true if it was succesfull otherwise false is returned
	// for (int i = 0; i < tokenizedInputVector.size(); i++)
	// {
	//   if (?? == START_TAG) {?? continue;}
	// 	 else if (?? == END_TAG) {?? continue;}
	// 	 else if (?? == EMPTY_TAG) {?? continue;}
	// 	 ...
	// }
if (tokenizedInputVector.empty())//error checks no input
return false;
if (!cutTest())
return false;

//first it clears
while (!parseStack.isEmpty())
	parseStack.pop();
elementNameBag.clear();
//then it goes through each token, in the order they were input
bool encounteredRoot = false;
//this for loop does not break until it is empty or there's an error
//it uses case to process each token based off their type
for (auto &token : tokenizedInputVector) {
	switch (token.tokenType) {
		case DECLARATION:
			if (encounteredRoot)
				return false;
			break;
		case START_TAG:
			if (parseStack.isEmpty()) {
			if (encounteredRoot)
				return false;
			encounteredRoot = true;
			}
			parseStack.push(token.tokenString);
			elementNameBag.add(token.tokenString);
			break;
		case END_TAG:
			if (parseStack.isEmpty())
				return false;
			{
			std::string top = parseStack.peek();
			if (top != token.tokenString)
				return false;
			parseStack.pop();
			}
			break;
		case EMPTY_TAG:
			if (parseStack.isEmpty()) {
			if (encounteredRoot)
				return false;
			encounteredRoot = true;
			}
			elementNameBag.add(token.tokenString);
			break;
		case CONTENT: {
			bool allWhitespace = true;
			for (char c : token.tokenString) {
			if (!std::isspace(c)) {
				allWhitespace = false;
				break;
				}
			}
			if (!allWhitespace && parseStack.isEmpty())
				return false;
			break;
		}
		default:
			return false;//ensures no unknown token type
	}
}
if (!parseStack.isEmpty())//when it is empty it returns false which means it processed it all
	return false;
isParsedSuccessfully = encounteredRoot;
return isParsedSuccessfully;
}

void XMLParser::clear()
{
    tokenizedInputVector.clear();
    elementNameBag.clear();
    while (!parseStack.isEmpty())
        parseStack.pop();
    isParsedSuccessfully = false;
}

std::vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

bool XMLParser::containsElementName(const std::string &element) const
{
	if (!isParsedSuccessfully)
	throw std::logic_error("XML has not been tokenized and parsed successfully.");
return elementNameBag.contains(element);
}

int XMLParser::frequencyElementName(const std::string &element) const
{
	// TODO
	// Throw std::logic_error if either tokenizeInputString() or parseTokenizedInput() returns false
	// If Bag is updated correctly, this should be as simple as one line.
    if (!isParsedSuccessfully)
        throw std::logic_error("XML has not been tokenized and parsed successfully.");
    return elementNameBag.getFrequencyOf(element);
}
bool XMLParser::cutTest() {
    if (tokenizedInputVector.empty()) //fail if no tokens
        return false;
    const TokenStruct &firstToken = tokenizedInputVector.front();//gets first and last token
    const TokenStruct &lastToken = tokenizedInputVector.back();
    //checkes first and last token
    //first token cannot be content or end_tag
    //last token cannot be content or end_tag either
    if (firstToken.tokenType == CONTENT || firstToken.tokenType == END_TAG)
        return false;
    if (lastToken.tokenType == CONTENT || lastToken.tokenType == START_TAG)
        return false;
    return true;
}