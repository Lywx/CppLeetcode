#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

template<typename T, typename Iter>
int binary_find(Iter begin, Iter end, T target)
{
    auto iter = lower_bound(begin, end, target);
    if (iter != end && !(target < *iter))
    {
        return iter - begin;
    }
    else
    {
        return -1;
    }
}

class Solution
{
public:
    // @summary Compress three ordered non-negative number into an unsigned int,
    // which is one to one mapping for (i, j, k).
    static unsigned int threeHash(unsigned char i, unsigned char j, unsigned char k)
    {
        // Assume i <= j <= k.

        static vector<unsigned char> combination;

        combination = { i, j, k };
        return (combination[0]) | (combination[1] << 10) | (combination[2] << 20);
    }

    // @remark This solution works when input numbers are small.
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // Pre-sort the input number to make sure the i, j, k input in the hash
        // function is ordered correctly, so that the duplication won't happen.
        sort(nums.begin(), nums.end());

        auto result = vector<vector<int>>();
        unordered_map<unsigned int, bool> resultAdded;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                auto difference = 0 - (nums[i] + nums[j]);

                auto k = binary_find(nums.begin() + j + 1, nums.end(), difference);
                if (k != -1)
                {
                    // Amend the skipped index.
                    k += j + 1;

                    // Because the hash function only works with unsigned number, have to offset them into positive number.
                    static const int hashOffset = 128;

                    // Compute hash key to prevent duplication.
                    auto hashKey = threeHash(hashOffset + nums[i], hashOffset + nums[j], hashOffset + nums[k]);

                    if (difference == nums[k] && !resultAdded[hashKey])
                    {
                        resultAdded[hashKey] = true;
                        result.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return result;
    }
};
