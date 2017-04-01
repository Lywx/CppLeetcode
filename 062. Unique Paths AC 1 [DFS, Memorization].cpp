#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> uniquePathTable;

    int computeOrGetUniquePaths(int rowLeft, int columnLeft)
    {
        int& uniquePathSlot = uniquePathTable[rowLeft][columnLeft];
        if (uniquePathSlot != -1)
        {
            return uniquePathSlot;
        }

        if (rowLeft < 1 || columnLeft < 1)
        {
            return 0;
        }

        if (rowLeft == 1 && columnLeft == 1)
        {
            return 1;
        }

        uniquePathSlot = computeOrGetUniquePaths(rowLeft - 1, columnLeft) + computeOrGetUniquePaths(rowLeft, columnLeft - 1);
        return uniquePathSlot;
    }

    int uniquePaths(int m, int n)
    {
        uniquePathTable.assign(m + 1, vector<int>(n + 1, -1));

        return computeOrGetUniquePaths(m, n);
    }
};
