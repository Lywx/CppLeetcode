#include <string>
#include <stack>
#include <list>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
    stack<char, list<char>> parenthesisStack;
    unordered_map<char, char> parenthesisMatch;
    set<char> parenthesisClose;

    bool matchParenthesis(char c)
    {
        return parenthesisMatch[parenthesisStack.top()] == c;
    }

    bool isValid(std::string s)
    {
        parenthesisMatch['('] = ')';
        parenthesisMatch['['] = ']';
        parenthesisMatch['{'] = '}';
        parenthesisClose.insert(')');
        parenthesisClose.insert(']');
        parenthesisClose.insert('}');

        for (int index = 0; index < s.size(); ++index)
        {
            auto c = s[index];

            if (parenthesisMatch.count(c))
            {
                parenthesisStack.push(c);
            }
            else if (parenthesisClose.count(c))
            {
                if (matchParenthesis(c))
                {
                    parenthesisStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return parenthesisStack.empty();
    }
};
