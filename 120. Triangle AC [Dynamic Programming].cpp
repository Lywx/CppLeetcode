#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    void buildMinimalTotalTable(vector<vector<int>>& minimalTotalTable, vector<std::vector<int>>& triangle)
    {
        int levelNum = int(triangle.size());

        // Initialize table.
        minimalTotalTable = vector<vector<int>>(levelNum, vector<int>());
        for (int levelIndex = 0; levelIndex < levelNum; ++levelIndex)
        {
            int columnNum = levelIndex + 1;
            minimalTotalTable[levelIndex].assign(columnNum, INT_MAX);
        }

        // Determine path to first and last column at each level.
        for (int levelIndex = 0, pathSumLeft = 0, pathSumRight = 0; levelIndex < levelNum; ++levelIndex)
        {
            int columnNum = levelIndex + 1;

            pathSumLeft += triangle[levelIndex][0];
            pathSumRight += triangle[levelIndex][columnNum - 1];

            minimalTotalTable[levelIndex][0] = pathSumLeft;
            minimalTotalTable[levelIndex][columnNum - 1] = pathSumRight;
        }

        for (int levelIndex = 1; levelIndex < levelNum; ++levelIndex)
        {
            int columnNum = levelIndex + 1;

            // Skip first and last column.
            for (int columnIndex = 1; columnIndex < columnNum - 1; ++columnIndex)
            {
                minimalTotalTable[levelIndex][columnIndex] = min(
                            minimalTotalTable[levelIndex - 1][columnIndex - 1],
                            minimalTotalTable[levelIndex - 1][columnIndex]) + triangle[levelIndex][columnIndex];
            }
        }
    }

    int minimumTotal(vector<vector<int>>& minimalTotalTable, int levelNum)
    {
        int levelIndex = levelNum - 1;
        int columnNum = levelNum;

        int minTotal = INT_MAX;

        for (int columnIndex = 0; columnIndex < columnNum; ++columnIndex)
        {
            if (minTotal > minimalTotalTable[levelIndex][columnIndex])
            {
                minTotal = minimalTotalTable[levelIndex][columnIndex];
            }
        }

        return minTotal;
    }

    int minimumTotal(vector<std::vector<int>>& triangle)
    {
        vector<vector<int>> minimalTotalTable;
        buildMinimalTotalTable(minimalTotalTable, triangle);

        int levelNum = int(triangle.size());
        return minimumTotal(minimalTotalTable, levelNum);
    }
};
