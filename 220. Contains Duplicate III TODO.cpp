#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
    {
        unordered_map<int, int> numNearestIndex;

        for (auto index = 0; index < nums.size(); ++index)
        {
            auto num = nums[index];

            if (numNearestIndex.count(num) > 0
                    && abs(numNearestIndex[num] - index) <= k)
            {
                return true;
            }

            // We only care about number at the nearest index for right-sided numbers.
            numNearestIndex[num] = index;
        }

        return false;
    }
};
