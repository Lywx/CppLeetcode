#include <string>

using namespace std;

class Solution
{
public:
    string reverseString(string s)
    {
        string reverse;

        // NOTE(Wuxiang): Reverse iteration with size_t
        for (size_t i = s.length() - 1; i < s.length(); --i)
        {
            reverse.push_back(s[i]);
        }

        return reverse;
    }
};