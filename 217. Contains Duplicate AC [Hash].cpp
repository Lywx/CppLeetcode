#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        unordered_map<int, int> numContains;

        for (auto num : nums)
        {
            ++numContains[num];
        }

        for (auto numPair : numContains)
        {
            if (numPair.second > 1)
            {
                return true;
            }
        }

        return false;
    }
};
