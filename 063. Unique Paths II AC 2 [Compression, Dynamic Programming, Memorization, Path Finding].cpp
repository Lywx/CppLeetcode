#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> uniquePathTable;

    void buildUniquePathTable(int rowNum, int columnNum, vector<vector<int>>& obstacleGrid)
    {
        uniquePathTable.assign(columnNum + 1, 0);

        // From right to left in the figure
        for (int rowLeft = 0; rowLeft <= rowNum; ++rowLeft)
        {
            // From bottom to top in the figure
            for (int columnLeft = 0; columnLeft <= columnNum; ++columnLeft)
            {
                uniquePathTable[columnLeft] = computeUniquePaths(rowLeft, columnLeft, obstacleGrid);
            }
        }
    }

    int computeUniquePaths(int rowLeft, int columnLeft, vector<vector<int>>& obstacleGrid)
    {
        int rowNum = obstacleGrid.size();
        int columnNum = obstacleGrid[0].size();

        int rowIndex = rowNum - rowLeft;
        int columnIndex = columnNum - columnLeft;

        // Because we would have both rowLeft and columnLeft equal to zero, in
        // which case, their corresponding row and column index is outside the
        // bounds (rowNum + 1) and (columnNum + 1) respectively.
        //
        // We have to make sure they don't cause access violation here.
        //
        // It is possible for all the paths are blocked, so we have to test against
        // the grid first.
        if (rowIndex < rowNum
                && columnIndex < columnNum
                && obstacleGrid[rowIndex][columnIndex])
        {
            return 0;
        }

        if (rowLeft < 1 || columnLeft < 1)
        {
            return 0;
        }

        if (rowLeft == 1 && columnLeft == 1)
        {
            return 1;
        }

        return
            // Before write to uniquePathTable[columnLeft], uniquePathTable[columnLeft] is effectively uniquePathTable[rowLeft - 1][columnLeft].
            uniquePathTable[columnLeft] +

            // Since we scan column value from 0 to n, uniquePathTable[columnLeft] is effectively uniquePathTable[rowLeft][columnLeft - 1].
            uniquePathTable[columnLeft - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int rowNum = obstacleGrid.size();
        int columnNum = obstacleGrid[0].size();

        if (obstacleGrid[0][0] || obstacleGrid[rowNum - 1][columnNum - 1])
        {
            return 0;
        }

        buildUniquePathTable(rowNum, columnNum, obstacleGrid);

        return uniquePathTable[columnNum];
    }
};
