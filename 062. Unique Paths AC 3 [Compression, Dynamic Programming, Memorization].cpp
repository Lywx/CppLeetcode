#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> uniquePathTable;

    void buildUniquePathTable(int rowNum, int columnNum)
    {
        uniquePathTable.assign(columnNum + 1, -1);

        // From right to left in the figure
        for (int rowLeft = 0; rowLeft <= rowNum; ++rowLeft)
        {
            // From bottom to top in the figure
            for (int columnLeft = 0; columnLeft <= columnNum; ++columnLeft)
            {
                uniquePathTable[columnLeft] = computeOrGetUniquePaths(rowLeft, columnLeft);
            }
        }
    }

    int computeOrGetUniquePaths(int rowLeft, int columnLeft)
    {
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

    int uniquePaths(int m, int n)
    {
        buildUniquePathTable(m, n);

        return uniquePathTable[n];
    }
};
