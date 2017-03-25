#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>>& board, int row, int col)
    {
        auto rowNum = board.size();
        auto colNum = board[0].size();

        board[row][col] = '.';

        static vector<pair<int, int>> d = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

        for (int i = 0; i < d.size(); ++i)
        {
            auto dx = d[i].first;
            auto dy = d[i].second;

            auto r = row + dy;
            auto c = col + dx;

            if (0 <= r && r < rowNum
                    && 0 <= c && c < colNum
                    && board[r][c] == 'X')
            {
                dfs(board, r, c);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board)
    {
        auto rowNum = board.size();
        auto colNum = board[0].size();
        auto shipNum = 0;

        for (int row = 0; row < rowNum; ++row)
        {
            for (int col = 0; col < colNum; ++col)
            {
                if (board[row][col] == 'X')
                {
                    ++shipNum;

                    dfs(board, row, col);
                }
            }
        }

        return shipNum;
    }
};
