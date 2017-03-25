#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        set<int> numsKnown;
        map<int, int> numsDuplicate;

        for (auto i = 0; i < nums.size(); ++i)
        {
            if (numsKnown.find(nums[i]) == numsKnown.end())
            {
                numsKnown.insert(nums[i]);
                numsDuplicate[nums[i]] = 0;
            }
            else
            {
                ++numsDuplicate[nums[i]];
            }
        }

        int i = 0;

        for (auto iter = numsKnown.begin(); iter != numsKnown.end(); ++iter)
        {
            auto num = *iter;

            auto repeat = (numsDuplicate[num] <= 1 ? numsDuplicate[num] : 1);
            while (repeat >= 0)
            {
                nums[i] = num;
                ++i;

                --repeat;
            }
        }

        return i;
    }
};