#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // @summary n * (n - 1) * ... * begin.
    // @remark This is possible for result to be corrupted by overflowing if n is too large.
    int64_t factorial(int n, int begin = 1)
    {
        // NOTE(Wuxiang): This program can only get accepted using 64 bit int.
        int64_t result = 1;

        for (int i = begin; i <= n; ++i)
        {
            result *= i;
        }

        return result;
    }

    // C^{k}_{n}
    int combination(int n, int k)
    {
        // Math level optimization
        {
            if (k == 0)
            {
                return 1;
            }

            if (k == 1)
            {
                return n;
            }
        }

        int64_t result = factorial(n, n - k + 1);
        result /= factorial(k);
        return int(result);
    }

    int uniquePaths(int m, int n)
    {
        return combination(m + n - 2, min(m - 1, n - 1));
    }
};