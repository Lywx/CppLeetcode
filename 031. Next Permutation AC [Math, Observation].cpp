#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        int indexPivot = -1;

        // Find pivot position.
        for (int index = int(nums.size()) - 1; index >= 1; --index)
        {
            if (nums[index - 1] < nums[index])
            {
                indexPivot = index - 1;
                break;
            }
        }

        // When the pivot is outside the vector, this is the case has the maximal
        // lexicographical order.
        if (indexPivot == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            // Find largest index where element is larger than the pivot.
            int indexMax = indexPivot + 1;
            for (int index = indexPivot + 2; index < nums.size(); ++index)
            {
                if (nums[index] > nums[indexPivot])
                {
                    indexMax = index;
                }
            }

            // Swap the pivot and largest index just found.
            swap(nums[indexMax], nums[indexPivot]);

            // Reverse all the element right to the pivot. This actually avoid
            // the case when the reverse counter the effect of swapping,
            // because that could only happen when indexPivot == indexMax - 1.
            // In that case, the reverse function arguments passed would be all
            // directed to 1-sized region so you would not worry about reverse-countering.
            reverse(nums.begin() + indexPivot + 1, nums.end());
        }
    }
};
