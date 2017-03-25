#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <numeric>

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

    // int factorial(int n)
    // {
    //     if (n > 1)
    //     {
    //         return n * factorial(n - 1);
    //     }
    //
    //     return 1;
    // }

    int baseExpansionAt(int base, int index, int demical)
    {
        auto quotient = demical / base;
        auto remainder = demical % base;

        ++index;

        while (quotient != 0 && index > 0)
        {
            remainder = quotient % base;
            quotient = quotient / base;

            ++index;
        }

        return remainder;
    }

    vector<int> baseExpansion(int base, int demical)
    {
        auto result = vector<int>();

        auto quotient = demical / base;
        auto remainder = demical % base;

        result.push_back(remainder);

        while (quotient != 0)
        {
            remainder = quotient % base;
            quotient = quotient / base;

            result.push_back(remainder);
        }

        return result;
    }

    vector<vector<int>> combine(int n, int k)
    {
        int combinationNum = factorial(n) / factorial(n - k) / factorial(k);

        // Prepare for filling in number.
        vector<vector<int>> result;
        {
            for (int combinationIndex = 0; combinationIndex < combinationNum; ++combinationIndex)
            {
                result.push_back(vector<int>(k, 0));
            }
        }

        for (int combinationIndex = 0; combinationIndex < combinationNum; ++combinationIndex)
        {
            for (int positionIndex = 0; positionIndex < k; ++positionIndex)
            {
                auto base = 1 + positionIndex;
                auto binaryIndex = baseN(combinationIndex, 6);

                auto a = (binaryIndex >> k - 1 - positionIndex) & 1 ? 1 : 0;

                result[combinationIndex][positionIndex] = base + a;
            }
        }

        return result;
    }
};
