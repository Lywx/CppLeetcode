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
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> combinations;
        vector<int> combination(k, 0);

        auto positionIndex = 0;
        while (positionIndex >= 0)
        {
            ++combination[positionIndex];

            if (combination[positionIndex] > n)
            {
                --positionIndex;
            }
            else if (positionIndex == k - 1)
            {
                combinations.push_back(combination);
            }
            else
            {
                ++positionIndex;
                combination[positionIndex] = combination[positionIndex - 1];
            }
        }

        return combinations;
    }
};
