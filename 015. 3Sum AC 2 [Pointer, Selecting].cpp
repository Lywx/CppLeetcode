#include <algorithm>
#include <vector>

using namespace std;

// NOTE(Wuxiang): This solution is similar to AC 1. It is no less efficient, but more
// easily understood.
class Solution
{
public:

    // NOTE(Wuxiang): The key of this algorithm is i, j, k corresponds to iterators
    // to three unique numbers so there is no duplication happening.
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());

        for (int index = 0; index < nums.size(); ++index)
        {
            int twoSum = -nums[index];

            int indexFront = index + 1;
            int indexBack = nums.size() - 1;

            while (indexFront < indexBack)
            {
                int sum = nums[indexFront] + nums[indexBack];

                // Finding answer which start from number num[i]
                if (sum < twoSum)
                {
                    ++indexFront;
                }
                else if (sum > twoSum)
                {
                    --indexBack;
                }
                else
                {
                    vector<int> combination(3, 0);
                    combination[0] = nums[index];
                    combination[1] = nums[indexFront];
                    combination[2] = nums[indexBack];
                    result.push_back(combination);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (indexFront < indexBack && nums[indexFront] == combination[1])
                    {
                        ++indexFront;
                    }

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (indexFront < indexBack && nums[indexBack] == combination[2])
                    {
                        --indexBack;
                    }
                }

            }

            // Processing duplicates of Number 1
            while (index + 1 < nums.size() && nums[index + 1] == nums[index])
            {
                ++index;
            }
        }

        return result;
    }
};
