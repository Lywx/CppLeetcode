#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        auto length = s.length();
        auto lengthHalf = s.length() / 2;

        for (auto i = 0; i < lengthHalf; ++i)
        {
            if (s[i] != s[length - i])
            {
                return false;
            }
        }

        return true;
    }

    std::vector<vector<string>> partition(string s)
    {
        std::vector<vector<string>> partitionList;

        for (int i = 0; i < 1; ++i)
        {

        }
    }
};
