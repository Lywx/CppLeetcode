#include <string>

using namespace std;

// complexity O(M * N).
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = int(haystack.size());
        int n = int(needle.size());

        int shiftMax = m - n;
        for(int shift = 0; shift <= shiftMax; ++shift)
        {
            bool match = true;

            for (int index = 0; index < needle.size(); ++index)
            {
                if (needle[index] != haystack[shift + index])
                {
                    match = false;
                }
            }

            if (match)
            {
                return shift;
            }
        }

        return -1;
    }
};