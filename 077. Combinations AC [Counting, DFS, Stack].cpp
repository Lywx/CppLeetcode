#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <numeric>

using namespace std;

// complexity O(N! / (N - K)!)
class Solution
{
public:
    vector<int>         combinationCurrent;
    vector<vector<int>> combinationList;

    void choose(int i, int n, int k)
    {
        if (combinationCurrent.size() == k)
        {
            combinationList.push_back(combinationCurrent);
            return;
        }

        for (; i <= n; ++i)
        {
            combinationCurrent.push_back(i);
            choose(i + 1, n, k);
            combinationCurrent.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        choose(1, n, k);

        return combinationList;
    }
};
