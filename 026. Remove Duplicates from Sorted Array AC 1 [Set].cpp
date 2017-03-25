#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        set<int> numsKnown;

        for (auto i = 0; i < nums.size(); ++i)
        {
            if (numsKnown.find(nums[i]) == numsKnown.end())
            {
                numsKnown.insert(nums[i]);
            }
        }

        {
            int i = 0;
            for (auto iter = numsKnown.begin(); iter != numsKnown.end(); ++iter)
            {
                nums[i] = *iter;
                ++i;
            }
        }

        return numsKnown.size();
    }
};
