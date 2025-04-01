#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "Stack.hpp"
#include "XMLParser.hpp"
#include <fstream>

/* Provided test cases*/
TEST_CASE("XMLParser: Test int Stack push and size", "[Stack]")
{
	Stack<int> intStack;
	int testSize = 3;
	int stackSize;
	bool correctPush, correctSize;
	for (int i = 0; i < testSize; i++)
	{
		correctPush = intStack.push(i);
		stackSize = intStack.size();
		correctSize = (stackSize == (i + 1));
		if (!correctPush || !correctSize)
		{
			break;
		}
	}
	REQUIRE(correctPush);
	REQUIRE(correctSize);
}

TEST_CASE("XMLParser: Test int Stack peek and pop", "[Stack]")
{
	Stack<char> charStack;
	int testSize = 10;
	int stackSize;
	bool correctSizeAfterPush;
	for (char c = 'a'; c < 'a' + testSize; c++)
	{
		charStack.push(c);
		stackSize = charStack.size();
		correctSizeAfterPush = (stackSize == (c - 'a' + 1));
		if (!correctSizeAfterPush)
		{
			break;
		}
	} // should be 'a' to 'j'
	REQUIRE(correctSizeAfterPush);
	bool notEmptyYetAfterPop, correctItem, notEmptyYetAfterPeek;
	for (char i = 'a' + testSize - 1; i >= 'a'; i--)
	{
		notEmptyYetAfterPop = !charStack.isEmpty();
		char elem = charStack.peek();
		correctItem = (elem == i);
		notEmptyYetAfterPeek = !charStack.isEmpty();
		charStack.pop();
		if (!notEmptyYetAfterPop || !correctItem || !notEmptyYetAfterPeek)
		{
			break;
		}
	}
	REQUIRE(notEmptyYetAfterPop);
	REQUIRE(correctItem);
	REQUIRE(notEmptyYetAfterPeek);
	REQUIRE(charStack.isEmpty() == true);
}

TEST_CASE("XMLParser: Test std::string Stack peek, pop and clear", "[Stack]")
{
	Stack<std::string> stringStack;
	std::vector<std::string> vec = {"Touching", "you", "touching", "me", "sweet", "Caroline"};
	int i = 1;
	bool correctSize;
	for (std::string s : vec)
	{
		stringStack.push(s);
		correctSize = (stringStack.size() == i);
		if (!correctSize)
		{
			break;
		}
		i++;
	}
	REQUIRE(correctSize);
	bool notEmptyYetAfterPop, correctItem, notEmptyYetAfterPeek;
	for (i = 0; i < 4; i++)
	{
		notEmptyYetAfterPop = !stringStack.isEmpty();
		std::string c = stringStack.peek();
		correctItem = (c == vec[vec.size() - 1 - i]);
		notEmptyYetAfterPeek = !stringStack.isEmpty();
		stringStack.pop();
		if (!notEmptyYetAfterPop || !correctItem || !notEmptyYetAfterPeek)
		{
			break;
		}
	}
	REQUIRE(notEmptyYetAfterPop);
	REQUIRE(correctItem);
	REQUIRE(notEmptyYetAfterPeek);
	REQUIRE(stringStack.size() == 2);
	stringStack.clear();
	REQUIRE(stringStack.isEmpty() == true);
}

TEST_CASE("XMLParser: Test tokenize <test>stuff</test>", "[XMLParser]")
{
	// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
	XMLParser myXMLParser;
	std::string testString = "<test>stuff</test>";
	REQUIRE(myXMLParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
																		 TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
																		 TokenStruct{StringTokenType::END_TAG, std::string("test")}};
	std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
	for (int i = 0; i < result.size(); i++)
	{
		REQUIRE(result[i].tokenType == output[i].tokenType);
		REQUIRE(result[i].tokenString == output[i].tokenString);
	}
}

TEST_CASE("XMLParser: Test tokenize with invalid chars", "[XMLParser]")
{
	XMLParser myXMLParser;
	std::string testString = "<test>stuff</3test>";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString)); // first char being number in tag

	testString = "<te$t>stuff</te$t>";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString)); // $ in tag

	testString = "<test>stuff< hi/></test>";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString)); // space in tag

	testString = "<start";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString)); // example in project description

	testString = "  >";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString));

	testString = " ";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString));

	testString = "< /end>";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString));

	testString = "<>";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString));

	testString = "<start <stuff>>";
	REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString));

	testString = "</test>stuff<test>";
	REQUIRE(myXMLParser.tokenizeInputString(testString)); // example in project description, true even not valid
}

TEST_CASE("XMLParser: Test tokenize string with more elements", "[XMLParser]")
{
	XMLParser myXMLParser;
	std::string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>";
	REQUIRE(myXMLParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::DECLARATION, std::string("xml version=\"1.0\" encoding=\"UTF-8\"")},
																		 TokenStruct{StringTokenType::START_TAG, std::string("Note")},
																		 TokenStruct{StringTokenType::START_TAG, std::string("From")},
																		 TokenStruct{StringTokenType::CONTENT, std::string("Tom")},
																		 TokenStruct{StringTokenType::END_TAG, std::string("From")},
																		 TokenStruct{StringTokenType::START_TAG, std::string("To")},
																		 TokenStruct{StringTokenType::CONTENT, std::string("Alice")},
																		 TokenStruct{StringTokenType::END_TAG, std::string("To")},
																		 TokenStruct{StringTokenType::END_TAG, std::string("Note")}};
	std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();

	REQUIRE(result.size() == output.size());
	bool correctType, correctString;
	for (int i = 0; i < result.size(); i++)
	{
		correctType = (result[i].tokenType == output[i].tokenType);
		correctString = (result[i].tokenString.compare(output[i].tokenString) == 0);
		if (!correctType || !correctString)
		{
			break;
		}
	}
	REQUIRE(correctType);
	REQUIRE(correctString);
}

TEST_CASE("XMLParser: Test parseTokenizedInput", "[XMLParser]")
{
	XMLParser myXMLParser;
	std::string testString = "<test myattr='abcdef'>stuff<this_is_empty_tag/></test>";
	REQUIRE(myXMLParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
																		 TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
																		 TokenStruct{StringTokenType::EMPTY_TAG, std::string("this_is_empty_tag")},
																		 TokenStruct{StringTokenType::END_TAG, std::string("test")}};
	std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
	REQUIRE(myXMLParser.parseTokenizedInput());
	output = myXMLParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
	bool correctType, correctString;
	for (int i = 0; i < result.size(); i++)
	{
		correctType = (result[i].tokenType == output[i].tokenType);
		correctString = (result[i].tokenString.compare(output[i].tokenString) == 0);
		if (!correctType || !correctString)
		{
			break;
		}
	}
	REQUIRE(correctType);
	REQUIRE(correctString);
}

// Refer to online parser https://jsonformatter.org/xml-parser#Sample
TEST_CASE("XMLParser: Test XMLParser tokenize then parse various strings", "[XMLParser]")
{
	XMLParser myXMLParser;

	REQUIRE_FALSE(myXMLParser.parseTokenizedInput()); // Hint: Can't parse empty

	REQUIRE(myXMLParser.tokenizeInputString(" <someTag>Content</someTag> ")); // Hint: Tokenize then parse \" <someTag>Content</someTag> \""
	REQUIRE(myXMLParser.parseTokenizedInput());

	REQUIRE(myXMLParser.tokenizeInputString("<?xml version =\"1.0\"?><html><head>Content here</head><body>Content here<empty src=\"f\"/></body></html>"));
	REQUIRE(myXMLParser.parseTokenizedInput());

	REQUIRE(myXMLParser.tokenizeInputString("<?xml version =\"1.0\"?><head>sometext</head>\n<body>sometext</body>"));
	REQUIRE_FALSE(myXMLParser.parseTokenizedInput());
}

TEST_CASE("XMLParser: Test XMLParser parse, contains and frequency", "[XMLParser]")
{
	XMLParser myXMLParser;
	std::ifstream myfile("../TestFile.txt");
	std::string inputString((std::istreambuf_iterator<char>(myfile)), (std::istreambuf_iterator<char>()));

	REQUIRE(myXMLParser.tokenizeInputString(inputString));
	REQUIRE(myXMLParser.parseTokenizedInput());
	REQUIRE(myXMLParser.containsElementName("catalog"));
	REQUIRE(myXMLParser.frequencyElementName("catalog") == 1);
	REQUIRE(myXMLParser.containsElementName("product"));
	REQUIRE(myXMLParser.frequencyElementName("product") == 1);
	REQUIRE(myXMLParser.containsElementName("catalog_item"));
	REQUIRE(myXMLParser.frequencyElementName("catalog_item") == 2);
	REQUIRE(myXMLParser.containsElementName("item_number"));
	REQUIRE(myXMLParser.frequencyElementName("item_number") == 2);
	REQUIRE(myXMLParser.containsElementName("size"));
	REQUIRE(myXMLParser.frequencyElementName("size") == 6);
	REQUIRE(myXMLParser.containsElementName("color_swatch"));
	REQUIRE(myXMLParser.frequencyElementName("color_swatch") == 15);
}

TEST_CASE("XMLParser: Test XMLParser with XML file workflow", "[XMLParser]")
{
	// Test a workflow with a valid XML file (e.g., one Canvas page)
	XMLParser myParser;
	std::string inputString;
	std::ifstream myfile("../xmlFile.txt");
	char c;

	// read in the test file
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile.get(c);
			inputString.push_back(c);
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open (find) the input file" << std::endl;
	}

	// try to tokenize the input string
	bool success = myParser.tokenizeInputString(inputString);
	REQUIRE(success == true);

	// look at the tokenized input string
	std::vector<TokenStruct> tokenizedInput = myParser.returnTokenizedInput();
	REQUIRE(tokenizedInput.size() == 91);

	// try to parse the tokenized input string to see if it is valid XML
	success = myParser.parseTokenizedInput();
	REQUIRE(success == true);

	// see if the element named "strong" was there
	success = myParser.containsElementName("strong");
	REQUIRE(success == true);

	// see how many times the element named "span" was there
	int number = myParser.frequencyElementName("span");
	REQUIRE(number == 16);
}

/* Write your own uint tests here*/
//Test should not match test and should return false
TEST_CASE("XMLParser: Test invalid XML with mismatched case", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "<Test>content</test>";
    REQUIRE(myXMLParser.tokenizeInputString(testString));
    REQUIRE_FALSE(myXMLParser.parseTokenizedInput());
}

//ensures the parser can handle more than one delcaration
TEST_CASE("XMLParser: Test multiple declarations", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                             "<?xml-stylesheet type=\"text/xsl\" href=\"style.xsl\"?>"
                             "<root><child>data</child></root>";
    REQUIRE(myXMLParser.tokenizeInputString(testString));
    REQUIRE(myXMLParser.parseTokenizedInput());
    REQUIRE(myXMLParser.containsElementName("root"));
    REQUIRE(myXMLParser.containsElementName("child"));
    REQUIRE(myXMLParser.frequencyElementName("child") == 1);
}

//irregular white spaces, for testing trimming
TEST_CASE("XMLParser: Test nested elements with irregular whitespace", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "<root>\n    <child>   Some    content with   spaces  </child>\n</root>";
    REQUIRE(myXMLParser.tokenizeInputString(testString));
    REQUIRE(myXMLParser.parseTokenizedInput());
    REQUIRE(myXMLParser.containsElementName("root"));
    REQUIRE(myXMLParser.containsElementName("child"));
}

//invalid declaration, white space so it tests the parser since formatting is wrong
TEST_CASE("XMLParser: Test invalid declaration with leading whitespace", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "<? xml version=\"1.0\"?><root></root>";
    REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString));
}

//only white space, should just return false since no markup should be found
TEST_CASE("XMLParser: Test input with only whitespace and no markup", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "     \n\t   ";
    REQUIRE_FALSE(myXMLParser.tokenizeInputString(testString));
}

//tests that the empty tags are processed correctly
TEST_CASE("XMLParser: Test multiple consecutive empty tags", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "<root><empty1/><empty2/><empty3/></root>";
    REQUIRE(myXMLParser.tokenizeInputString(testString));
    REQUIRE(myXMLParser.parseTokenizedInput());
    REQUIRE(myXMLParser.containsElementName("empty1"));
    REQUIRE(myXMLParser.containsElementName("empty2"));
    REQUIRE(myXMLParser.containsElementName("empty3"));
    REQUIRE(myXMLParser.frequencyElementName("empty1") == 1);
    REQUIRE(myXMLParser.frequencyElementName("empty2") == 1);
    REQUIRE(myXMLParser.frequencyElementName("empty3") == 1);
}

//tests a valid xml string, confirms tag names are extracted correctly and parsed xml is valid
TEST_CASE("XMLParser: Test valid XML with attributes", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "<book title=\"The You You Are: A Spiritual Biography of You\" author=\"Ricken Lazlo Hale\">"
                             "<summary>Are you ready to meet the person who truly makes you “You”: You?</summary></book>";
    REQUIRE(myXMLParser.tokenizeInputString(testString));
    REQUIRE(myXMLParser.parseTokenizedInput());
    REQUIRE(myXMLParser.containsElementName("book"));
    REQUIRE(myXMLParser.containsElementName("summary"));
    REQUIRE(myXMLParser.frequencyElementName("book") == 1);
}

//checks that parser is rejecting the xml because there is non whitespace outside the root element
TEST_CASE("XMLParser: Test XML with text outside root element", "[XMLParser]") {
    XMLParser myXMLParser;
    std::string testString = "Some text outside<root><child>data</child></root>";
    REQUIRE(myXMLParser.tokenizeInputString(testString));
    REQUIRE_FALSE(myXMLParser.parseTokenizedInput());
}

TEST_CASE("XMLParser: Checkoff test case", "[XMLParser]") {
    std::string allowedPunc = "!\"#$%&'()*+,/;=?@[\\]^`{|}~";//given input
    //valid case
    std::string validXML = "<root attr=\"" + allowedPunc + "\">" + allowedPunc + "</root>";
    XMLParser validParser;
    REQUIRE(validParser.tokenizeInputString(validXML));
    REQUIRE(validParser.parseTokenizedInput());
    REQUIRE(validParser.containsElementName("root"));

    //invalid case 1
    std::string invalidContentXML = "<root attr=\"" + allowedPunc + "\">" + allowedPunc + "<</root>";
    XMLParser invalidContentParser;
    REQUIRE_FALSE(invalidContentParser.tokenizeInputString(invalidContentXML));
	//invalid case 2
    std::string invalidAttrXML = "<<root attr=\"" + allowedPunc + ">\">>" + allowedPunc + "</root>";
    XMLParser invalidAttrParser;
    REQUIRE_FALSE(invalidAttrParser.tokenizeInputString(invalidAttrXML));
}

//Test cases for the new function cut test
TEST_CASE("XMLParser: first token is content, so it fails", "[XMLParser][cutTest]") {
    XMLParser parser;
    std::string xmlWithLeadingContent = "unexpectedContent<root>valid</root>";
    REQUIRE(parser.tokenizeInputString(xmlWithLeadingContent));
    REQUIRE_FALSE(parser.parseTokenizedInput());
}

TEST_CASE("XMLParser: valid XML cuttest pass", "[XMLParser][cutTest]") {
    XMLParser parser;
    std::string validXML = "<root><child>content</child></root>";
    REQUIRE(parser.tokenizeInputString(validXML));
    REQUIRE(parser.parseTokenizedInput());
}