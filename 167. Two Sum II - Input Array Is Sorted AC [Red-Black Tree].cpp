#include <vector>

#include <unordered_map>
#include <map>

using namespace std;

// @complexity N ^ Log(N).
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // NOTE(Wuxiang): unordered_map and map work with list of int without duplication.
        //
        // unordered_map<int, int> numsHash;

        // NOTE(Wuxiang): multimap would use Red-Black Tree. So the name is not actually accurate to be "hash".
        multimap<int, int> numsHash;

        for (auto i = 0; i < int(nums.size()); ++i)
        {
            numsHash.insert({ nums[i], i });
        }

        for (auto i = 0; i < int(nums.size()); ++i)
        {
            int difference = target - nums[i];
            auto iter = numsHash.find(difference);
            if (iter != numsHash.end())
            {
                if (iter->second > i)
                {
                    return vector<int> { i + 1, iter->second + 1};
                }
                else if (iter->second == i)
                {
                    ++iter;

                    if (iter->first == difference)
                    {
                        return vector<int> { i + 1, iter->second + 1};
                    }
                }
            }
        }
    }
};
