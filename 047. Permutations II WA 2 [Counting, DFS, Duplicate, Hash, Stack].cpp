#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // unordered_map is implemented in open hashing. That improves the searching
    // speed in order to avoid number duplication. <int, int> represents <number, number show time>.
    unordered_map<int, int> numMap;

    // unordered_map is implemented in open hashing. That improves the searching
    // speed in order to avoid number duplication. <int, int> represents <number, number use time>.
    unordered_map<int, int> permutationCurrentMap;
    vector<int> permutationCurrent;
    vector<vector<int>> permutationList;

    void choose(vector<int>& nums)
    {
        if (permutationCurrent.size() == nums.size())
        {
            permutationList.push_back(permutationCurrent);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            // NOTE(Wuxiang): The problem with this algorithm is that 'nums' may
            // contain duplicates. If you pick the same number (duplicates) at
            // different invocation of 'choose' method at the same index, you would
            // get duplicates.
            //
            // For example, [1 1 2] could generated from:
            // nums:            [1 1 2]
            // i sequence 1:     0 1 2
            // recursion depth:  1 2 3
            //
            // i sequence 2:     1 0 2
            // recursion depth:  1 2 3
            int num = nums[i];

            if (permutationCurrentMap[num] < numMap[num])
            {
                permutationCurrent.push_back(num);
                ++permutationCurrentMap[num];

                choose(nums);

                permutationCurrent.pop_back();
                --permutationCurrentMap[num];
            }
        }
    }

    vector<vector<int>> permuteUnique(std::vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            ++numMap[num];
        }

        choose(nums);

        return permutationList;
    }
};