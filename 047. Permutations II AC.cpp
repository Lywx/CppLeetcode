#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(std::vector<int>& nums)
    {
        // NOTE(Wuxiang): Based on the observation the duplication only happens when the
        // lexicographical order has been wrapped around and if the wrapped
        // around permutation would possibly collides the permutation with least
        // lexicographical order. But this only becomes useful when we can
        // identify efficiently when two permutation would collide. Comparing two
        // permutation is just too expensive. In order to identify it cheaply,
        // we sort the permutation first to get the permutation with least
        // lexicographical order. Then we can be guaranteed the collision happen
        // only when the permutation wraps around.
        sort(nums.begin(), nums.end());

        vector<vector<int>> permutation;
        do
        {
            permutation.push_back(nums);
        }

        // We stop computing when the wrapping happens.
        while (next_permutation(nums.begin(), nums.end()));

        return permutation;
    }
};
