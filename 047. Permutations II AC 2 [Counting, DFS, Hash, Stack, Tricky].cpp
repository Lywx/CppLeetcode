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
            int num = nums[i];

            // NOTE(Wuxiang): This way of avoiding duplicates requires sorting
            // of 'nums' vector at the beginning.
            //
            // This solution avoid duplicates in '047. Permutations II WA 2 [Counting, DFS, Duplicate, Hash, Stack]'.
            // The reason is that we avoid use different index at the same number,
            // so that case like before would not happen.
            //
            // nums:            [1 1 2]
            // i sequence:       0 0 1
            // recursion depth:  1 2 3
            if (i > 0 && nums[i - 1] == num)
            {
                continue;
            }

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
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            ++numMap[num];
        }

        choose(nums);

        return permutationList;
    }
};