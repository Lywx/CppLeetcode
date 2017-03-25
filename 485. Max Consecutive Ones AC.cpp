#include <vector>

class Solution
{
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums)
    {
        int count = 0;
        int countMax = 0;
        int index = 0;

        while (index < nums.size())
        {
            if (nums[index] == 1)
            {
                ++count;
            }
            else
            {
                if (count > countMax)
                {
                    countMax = count;
                }

                count = 0;
            }

            ++index;
        }

        if (count > countMax)
        {
            countMax = count;
        }

        return countMax;
    }
};
