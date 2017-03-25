#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    std::vector<int> intersection(vector<int>& nums1, std::vector<int>& nums2)
    {
        auto result = vector<int>();

        auto& numsShorter = nums1.size() < nums2.size() ? nums1 : nums2;
        sort(numsShorter.begin(), numsShorter.end());

        auto& numsLonger = nums1.size() < nums2.size() ? nums2 : nums1;
        auto  numsLongerContains = unordered_map<int, int>();

        for (auto num : numsLonger)
        {
            ++numsLongerContains[num];
        }

        for (auto index = 0; index < numsShorter.size(); ++index)
        {
            // Avoid duplication.
            if (index > 0 && numsShorter[index - 1] == numsShorter[index])
            {
                continue;
            }

            auto num = numsShorter[index];

            if (numsLongerContains[num] > 0)
            {
                result.push_back(num);
            }
        }

        return result;
    }
};
