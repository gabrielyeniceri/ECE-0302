#include <string>
#include <vector>
#include <iostream>
#include <cctype>    
#include <locale>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string> candidateStringVector, vector<string> currentStringVector)
{   
    currentRecursionLevel++;
    if (currentRecursionLevel > maxRecursionLevel) {
        maxRecursionLevel = currentRecursionLevel;
    }
    if (!cutTest2(candidateStringVector, currentStringVector)) {
        currentRecursionLevel--;//keeps track of recursion
        return;
    }
    //no more words to add
    if (currentStringVector.empty()) {
        string concatenated;
        for (int i = 0; i < candidateStringVector.size(); i++) {
            concatenated += candidateStringVector[i];
        }
        if (isPalindrome(concatenated)) {
            palindromes.push_back(candidateStringVector);
        }
        currentRecursionLevel--;
        return;
    }
    //if its not empty it continues to try each remaining word
    for (int i = 0; i < currentStringVector.size(); i++) {
        vector<string> newCandidate = candidateStringVector;
        newCandidate.push_back(currentStringVector[i]);
        vector<string> remaining = currentStringVector;
        remaining.erase(remaining.begin() + i);
        recursiveFindPalindromes(newCandidate, remaining);
    }
    currentRecursionLevel--;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

//initializes private member
FindPalindrome::FindPalindrome()
{
    wordList.clear();
    palindromes.clear();
    currentRecursionLevel = 0;
    maxRecursionLevel = 0;
}

//clears memory
FindPalindrome::~FindPalindrome()
{
    wordList.clear();
    palindromes.clear();
}

//returns the number of palindrome sentences found
int FindPalindrome::number() const
{
    return palindromes.size();
}

//clears list and results
void FindPalindrome::clear()
{
    wordList.clear();
    palindromes.clear();
    currentRecursionLevel = 0;
    maxRecursionLevel = 0;
}
//all words in the vector are concatenated into a single string then converted to lowercase
//then counts the frequency of the letters from a to z
//if character has odd freq it returns false
//returns true when total chars in the vector have at most one odd freq
bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
    string all;
    for (int i = 0; i < stringVector.size(); i++) {
        all += stringVector[i];
    }
    string lowerAll = all;
    convertToLowerCase(lowerAll);
    int freq[26] = {0};
    for (int i = 0; i < lowerAll.size(); i++) {
        if (isalpha(lowerAll[i])) {
        freq[lowerAll[i] - 'a']++;
        }
    }
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
        oddCount++;
        }
        if (oddCount > 1)
        return false;
    }
    return true;
}
//cuttest 2 prunes the search space, splits into two, remaining words and palindrome candidates
//it is put into lowercase then computes the frequency of each letter in both concatenated strings

//identifies which group has fewers characters or if its equal, all letters in smaller string must be found in the larger string at the same
//freq to be possible palindrome, if the freq in the smaller string exceeds the larger it returns false, avoids etra computing
//does not determine the final form of palindrome
//for the vector with fewers characters after concatenation each letterf must appear in the other vector with at least as high a count
bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
    string s1, s2;
    for (int i = 0; i < stringVector1.size(); i++) {
        s1 += stringVector1[i];
    }
    for (int i = 0; i < stringVector2.size(); i++) {
        s2 += stringVector2[i];
    }
    string ls1 = s1, ls2 = s2;
    convertToLowerCase(ls1);
    convertToLowerCase(ls2);
    
    int freq1[26] = {0}, freq2[26] = {0};
    //finds which string is shorter and compares
    if (ls1.size() <= ls2.size()) {
        for (int i = 0; i < ls1.size(); i++) {
            if (isalpha(ls1[i]))
            freq1[ls1[i]-'a']++;
        }
        for (int i = 0; i < ls2.size(); i++) {
            if (isalpha(ls2[i]))
            freq2[ls2[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] > freq2[i])
            return false;
        }
    }
    else {
        for (int i = 0; i < ls1.size(); i++) {
            if (isalpha(ls1[i]))
            freq1[ls1[i]-'a']++;
        }
        for (int i = 0; i < ls2.size(); i++) {
            if (isalpha(ls2[i]))
            freq2[ls2[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq2[i] > freq1[i])
            return false;
        }
    }
    return true;
}

//adds a single word to the instance and returns false if the word is empty, already exists or containers non letters
bool FindPalindrome::add(const string & value)
{
    if (value.empty())
        return false;
    for (int i = 0; i < value.size(); i++) {
        if (!isalpha(value[i]))
            return false;
    }
    string lowerVal = value;
    convertToLowerCase(lowerVal);
    for (int i = 0; i < wordList.size(); i++) {
        string lw = wordList[i];
        convertToLowerCase(lw);
        if (lw == lowerVal)
        return false;
    }
    wordList.push_back(value);
    //find palindromes again
    palindromes.clear();
    currentRecursionLevel = 0;//resets
    maxRecursionLevel = 0;
    if (cutTest1(wordList)) {
        vector<string> candidate;
        recursiveFindPalindromes(candidate, wordList);
    }
    return true;
}
//adds a vector of words and returns false if any word is invalid or a dupe 
bool FindPalindrome::add(const vector<string> & stringVector)
{
    //checks each word for uniqueness and validity
    vector<string> lowerNew;
    for (int i = 0; i < stringVector.size(); i++) {
        if (stringVector[i].empty())
            return false;
        for (int j = 0; j < stringVector[i].size(); j++) {
            if (!isalpha(stringVector[i][j]))
                return false;
        }
        string lowerWord = stringVector[i];
        convertToLowerCase(lowerWord);
        //dupe checker for new words
        for (int k = 0; k < lowerNew.size(); k++) {
            if (lowerNew[k] == lowerWord)
                return false;
        }
        lowerNew.push_back(lowerWord);
    }
    //dupe checker for already added words
    for (int i = 0; i < stringVector.size(); i++) {
        string lowerWord = stringVector[i];
        convertToLowerCase(lowerWord);
        for (int j = 0; j < wordList.size(); j++) {
            string lw = wordList[j];
            convertToLowerCase(lw);
            if (lw == lowerWord)
                return false;
        }
    }
    for (int i = 0; i < stringVector.size(); i++) {
        wordList.push_back(stringVector[i]);
    }
    
    //find palindromes again
    palindromes.clear();
    currentRecursionLevel = 0;
    maxRecursionLevel = 0;
    if (cutTest1(wordList)) {
        vector<string> candidate;
        recursiveFindPalindromes(candidate, wordList);
    }
    return true;
}
//returns the vector of the palindrome sentence
vector< vector<string> > FindPalindrome::toVector() const
{
    return palindromes;
}

int FindPalindrome::countRecursion() const {
    return maxRecursionLevel;
}
