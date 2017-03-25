#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        const int duplicationAllowed = 2;

        if (nums.size() <= duplicationAllowed)
        {
            return nums.size();
        }

        int indexFilled = duplicationAllowed;

        for (int index = duplicationAllowed; index < nums.size(); ++index)
        {
            if (nums[index] != nums[indexFilled - duplicationAllowed])
            {
                nums[indexFilled] = nums[index];

                ++indexFilled;
            }
        }

        return indexFilled;
    }
};