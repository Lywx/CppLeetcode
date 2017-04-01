#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // unordered_set is implemented in open hashing. That improves the searching
    // speed in order to avoid number duplication.
    unordered_set<int> permutationCurrentSet;
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

            unordered_set<int>::iterator iter = permutationCurrentSet.find(num);
            if (iter == permutationCurrentSet.end())
            {
                permutationCurrent.push_back(num);
                permutationCurrentSet.insert(num);

                choose(nums);

                permutationCurrent.pop_back();
                permutationCurrentSet.erase(num);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        choose(nums);

        return permutationList;
    }
};