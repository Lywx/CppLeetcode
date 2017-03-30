#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(const char *s, int length)
    {
        if (length == 1)
        {
            return true;
        }

        auto lengthHalf = length / 2;

        for (auto index = 0; index < lengthHalf; ++index)
        {
            if (s[index] != s[length - 1 - index])
            {
                return false;
            }
        }

        return true;
    }

    void partition(const char *s, int length, vector<string>& partitionCurrent, std::vector<vector<string>>& partitionList)
    {
        // When the caller has used up all the substring length available.
        if (length == 0)
        {
            partitionList.push_back(partitionCurrent);
        }

        // Scan across the different substring length so we can find a valid palindrome.
        // If so, we continue partition until we has partitioned the rest of the substring.

        // NOTE(Wuxiang): You are always guaranteed to get at least one palindrome string,
        // because the one char string is always palindrome.
        for (int lengthCurrent = 1; lengthCurrent <= length; ++lengthCurrent)
        {
            if (isPalindrome(s, lengthCurrent))
            {
                partitionCurrent.push_back(string(s, lengthCurrent));

                partition(s + lengthCurrent, length - lengthCurrent, partitionCurrent, partitionList);

                partitionCurrent.pop_back();
            }
        }
    }

    std::vector<vector<string>> partition(string s)
    {
        std::vector<vector<string>> partitionList;
        vector<string> partitionCurrent;
        partition(s.data(), s.size(), partitionCurrent, partitionList);
        return partitionList;
    }
};