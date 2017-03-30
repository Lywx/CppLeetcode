#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Solution
{
public:
    int factorial(int n)
    {
        auto result = 1;

        for (; n > 1; --n)
        {
            result *= n;
        }

        return result;
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        auto permutationNum = factorial(nums.size());
        vector<vector<int>> permutation;
        while(permutationNum > 0)
        {
            permutation.push_back(nums);
            --permutationNum;

            next_permutation(nums.begin(), nums.end());
        }

        return permutation;
    }
};