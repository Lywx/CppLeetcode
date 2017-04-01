#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> uniquePathTable;

    void buildUniquePathTable(int m, int n)
    {
        int rowNum = m;
        int columnNum = n;

        uniquePathTable.assign(rowNum + 1, vector<int>(columnNum + 1, -1));

        // From right to left in the figure
        for (int rowLeft = 0; rowLeft <= rowNum; ++rowLeft)
        {
            // From bottom to top in the figure
            for (int columnLeft = 0; columnLeft <= columnNum; ++columnLeft)
            {
                uniquePathTable[rowLeft][columnLeft] = computeOrGetUniquePaths(rowLeft, columnLeft);
            }
        }
    }

    int computeOrGetUniquePaths(int row, int column)
    {
        int& uniquePathSlot = uniquePathTable[row][column];
        if (uniquePathSlot != -1)
        {
            return uniquePathSlot;
        }

        if (row < 1 || column < 1)
        {
            return 0;
        }

        if (row == 1 && column == 1)
        {
            return 1;
        }

        return computeOrGetUniquePaths(row - 1, column) + computeOrGetUniquePaths(row, column - 1);
    }

    int uniquePaths(int m, int n)
    {
        buildUniquePathTable(m, n);

        return uniquePathTable[m][n];
    }
};
