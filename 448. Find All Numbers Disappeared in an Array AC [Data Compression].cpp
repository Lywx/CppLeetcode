#include <iostream>
#include <vector>

using namespace std;

// NOTE(Wuxiang): To understand this algorithm, you'd better list a few number to
// run the code by your pencil.
//
// https://discuss.leetcode.com/topic/65738/java-accepted-simple-solution
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> disappearedNumbers;

        for (auto i = 0; i < nums.size(); ++i)
        {
            auto value = nums[i];

            // NOTE(Wuxiang): This abs has two roles:
            // 1. Replace if use abs to improve CPU performance.
            // 2. Get the valid value from some position even
            // somewhere has been marked as negative.
            value = abs(value);

            // NOTE(Wuxiang): Mark the position as "seen" in the mean time, pertains
            // the original information.
            //
            // NOTE(Wuxiang): This abs is to prevent the marker flipped back to
            // original unmarked state.
            nums[value - 1] = -abs(nums[value - 1]);
        }

        for (auto i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                disappearedNumbers.push_back(i + 1);
            }
        }

        return disappearedNumbers;
    }
};
