#include <numeric>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string permutation;
        for (int i = 1; i < n + 1; ++i)
        {
            permutation.push_back('0' + i);
        }
        --k;

        while(k > 0)
        {
            next_permutation(permutation.begin(), permutation.end());
            --k;
        }

        return permutation;
    }
};