#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        unordered_map<int, int> numContains;

        for (auto num : nums)
        {
            ++numContains[num];

            if (numContains[num] > nums.size() / 2)
            {
                return num;
            }
        }
    }
};
