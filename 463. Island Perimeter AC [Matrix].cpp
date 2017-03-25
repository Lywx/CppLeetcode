#include <vector>
#include <list>
#include <array>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<int>>& grid, int i, int j)
    {
        auto row = grid.size();
        auto column = grid[0].size();

        return 0 <= i && i < row
               && 0 <= j && j < column;
    }

    bool hasBorderUp(vector<vector<int>>& grid, int row, int col)
    {
        bool valid = isValid(grid, row - 1, col);
        return grid[row][col] == 1 && (valid ? (grid[row - 1][col] == 0) : true);
    }

    bool hasBorderDown(vector<vector<int>>& grid, int row, int col)
    {
        bool valid = isValid(grid, row + 1, col);
        return grid[row][col] == 1 && (valid ? (grid[row + 1][col] == 0) : true);
    }

    bool hasBorderRight(vector<vector<int>>& grid, int row, int col)
    {
        bool valid = isValid(grid, row, col + 1);
        return grid[row][col] == 1 && (valid ? (grid[row][col + 1] == 0) : true);
    }

    bool hasBorderLeft(vector<vector<int>>& grid, int row, int col)
    {
        bool valid = isValid(grid, row, col - 1);
        return grid[row][col] == 1 && (valid ? (grid[row][col - 1] == 0) : true);
    }

    int blockPerimeter(vector<vector<int>>& grid, int row, int col)
    {
        return (hasBorderUp(grid, row, col) ? 1 : 0)
               + (hasBorderDown(grid, row, col) ? 1 : 0)
               + (hasBorderLeft(grid, row, col) ? 1 : 0)
               + (hasBorderRight(grid, row, col) ? 1 : 0);
    }

    int islandPerimeter(vector<vector<int>>& grid)
    {
        auto row = grid.size();
        auto column = grid[0].size();
        auto perimeter = 0;

        for (int rowIndex = 0; rowIndex < row; ++rowIndex)
        {
            for (int columnIndex = 0; columnIndex < column; ++columnIndex)
            {
                perimeter += blockPerimeter(grid, rowIndex, columnIndex);
            }
        }

        return perimeter;
    }
};