#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    template<class Iter, class T>
    int binary_find(Iter begin, Iter end, T value)
    {
        auto iter = lower_bound(begin, end, value);

        // NOTE(Wuxiang): This is almost equivalent. But this only use less
        // than operator, which is the only operator lower_bound use.
        // if (iter != end && !(value < *iter))
        if (iter != end && value == *iter)
        {
            return iter - begin;
        }
        else
        {
            return -1;
        }
    }

    int search(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0)
        {
            return -1;
        }

        int indexPivot;

        {
            auto index = 0;
            for (; nums[0] <= nums[index] && index < nums.size(); ++index)
            {
            }

            indexPivot = index;
        }

        int indexLeft = binary_find(nums.begin(), nums.begin() + indexPivot, target);
        int indexRight = -1;

        // When the array is not rotated, it count as pivot index equals to the size of the array.
        if (indexPivot < nums.size())
        {
            indexRight = binary_find(nums.begin() + indexPivot, nums.end(), target);
        }

        return indexLeft != -1
               ? indexLeft
               : (indexRight != -1
                  ? indexPivot + indexRight
                  : -1);
    }
};
