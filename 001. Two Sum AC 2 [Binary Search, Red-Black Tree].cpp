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

        // NOTE(Wuxiang): multimap would use Red-Black Tree.
        multimap<int, int> numsTree;

        for (int i = 0; i < nums.size(); ++i)
        {
            numsTree.insert({ nums[i], i });
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            int difference = target - nums[i];
            auto iter = numsTree.find(difference);
            if (iter != numsTree.end())
            {
                // Not a duplication
                if (iter->second > i)
                {
                    return vector<int> { i, iter->second };
                }

                // Duplication
                else if (iter->second == i)
                {
                    // Since the Red-Black Tree is sorted, same duplication would
                    // be next element if they are equal. If the case, we can
                    // still count them as valid answer because they have different
                    // index.
                    ++iter;

                    if (iter->first == difference)
                    {
                        return vector<int> { i, iter->second };
                    }
                }
            }
        }
    }
};
