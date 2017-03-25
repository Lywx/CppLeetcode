#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
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
            auto num = numsShorter[index];

            if (numsLongerContains[num] > 0)
            {
                result.push_back(num);
                --numsLongerContains[num];
            }
        }

        return result;

    }
};