#include <algorithm>
#include <vector>

using namespace std;

// NOTE(Wuxiang): This solution is only useful for k-sum problem. Its methodology
// is not easily reused elsewhere.
class Solution
{
public:

    // NOTE(Wuxiang): The key of this algorithm is i, j, k corresponds to iterators
    // to three unique numbers so there is no duplication happening.
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;

        if (nums.size() < 3)
        {
            return result;
        }

        sort(nums.begin(), nums.end());

        const int target = 0;

        // i starts with the first element, ends with 3rd count from the end.
        for (auto i = nums.begin(); i < nums.end() - 2; ++i)
        {
            // Avoid duplicated iterator.
            auto j = i + 1;

            // Skip loop through duplication. This is necessary to avoid duplication in result.
            if (i - nums.begin() > 0 && *i == *(i - 1))
            {
                continue;
            }

            // k starts with last valid element.
            auto k = nums.end() - 1;

            // Avoid duplicated iterator.
            while (j < k)
            {
                if (*i + *j + *k < target)
                {
                    ++j;

                    // Skip loop through duplication.
                    while (*j == *(j - 1) && j < k)
                    {
                        ++j;
                    }
                }

                // NOTE(Wuxiang): Interesting part.
                else if (*i + *j + *k > target)
                {
                    --k;

                    // Skip loop through duplication. This is necessary to avoid duplication in result.
                    while (*k == *(k + 1) && j < k)
                    {
                        --k;
                    }
                }
                else
                {
                    result.push_back({ *i, *j, *k });

                    ++j;
                    --k;

                    // Skip loop through duplication. This is necessary to avoid duplication in result.
                    while (*j == *(j - 1) && *k == *(k + 1) && j < k)
                    {
                        ++j;
                    }
                }
            }
        }

        return result;
    }
};
