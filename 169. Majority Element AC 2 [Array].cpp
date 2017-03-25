#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        auto major = nums[0];
        auto majorNetCount = 1;

        for (auto index = 1; index < nums.size(); ++index)
        {
            if (majorNetCount == 0)
            {
                // Change major.
                major = nums[index];
                majorNetCount = 1;
            }
            else if (major == nums[index])
            {
                ++majorNetCount;
            }
            else
            {
                // Make use of the fact the majority element would make of most
                // elements in the array. This only reflects the net difference
                // between number of major element and all the rest of elements.
                --majorNetCount;
            }
        }

        return major;
    }
};
