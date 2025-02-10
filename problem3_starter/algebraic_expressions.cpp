#include <string>
#include <iostream>
#include <cctype> // for isalpha
#include <functional>
#include "algebraic_expressions.hpp"

bool isoperator(char ch)
{
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(std::string s, int last)
{
  int first = 0;

  if ((first > last))
  {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch))
  {
    return last;
  }
  else
  {
    if (isoperator(ch))
    {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1)
      {
        return endPost(s, lastEnd - 1);
      }
      else
      {
        return -1;
      }
    }
    else
    {
      return -1;
    }
  }
}

bool isPost(std::string s)
{
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(const std::string &postfix, std::string &prefix)
{//ensures there is no empty input
  if (postfix.empty())
      throw std::invalid_argument("Empty postfix expression");
  for (char c : postfix)//this ensures there are only letters or valid ops
  {
      if (!std::isalpha(c) && !isoperator(c))
          throw std::invalid_argument("Invalid character in postfix expression");
  }
//this basically uses the current index to capture and return the prefix equivalen
  int pos = postfix.size() - 1;
  std::function<std::string()> rec = [&]() -> std::string {
      if (pos < 0)
          throw std::invalid_argument("Invalid postfix expression");

      char ch = postfix[pos];
      pos--;
      //if operator then return same if not then it finds the finds its two operands recursively
      if (std::isalpha(ch))
      {
          return std::string(1, ch);
      }
      else if (isoperator(ch))
      {
          std::string operand2 = rec();
          std::string operand1 = rec();
          return std::string(1, ch) + operand1 + operand2;
      }
      else
      {
          throw std::invalid_argument("Invalid character in postfix expression");
      }
  };
  //by this point if pos is not -1 that means there are extra chars that were not consumsed by the recursive fn
  prefix = rec();
  if (pos != -1)
      throw std::invalid_argument("Extra characters in postfix expression");
}