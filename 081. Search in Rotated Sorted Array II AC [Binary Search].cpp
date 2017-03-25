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
        if (iter != end && value == *iter)
        {
            return iter - begin;
        }
        else
        {
            return -1;
        }
    }

    bool search(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0)
        {
            return false;
        }

        int indexPivot;

        {
            auto index = 0;
            auto numIncreasing = nums[0];
            for (; numIncreasing <= nums[index] && index < nums.size(); ++index)
            {
                numIncreasing = nums[index];
            }

            indexPivot = index;
        }

        int indexLeft = binary_find(nums.begin(), nums.begin() + indexPivot, target);
        int indexRight = -1;
        if (indexPivot < nums.size())
        {
            indexRight = binary_find(nums.begin() + indexPivot, nums.end(), target);
        }

        return indexLeft != -1
               ? true
               : (indexRight != -1
                  ? true
                  : false);
    }
};
