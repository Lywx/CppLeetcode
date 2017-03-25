#include <vector>

using namespace std;

class Solution
{
public:
    int countBattleships(vector<vector<char>>& board)
    {
        auto rowNum = board.size();
        auto colNum = board[0].size();
        auto shipNum = 0;

        for (int row = 0; row < rowNum; ++row)
        {
            for (int col = 0; col < colNum; ++col)
            {
                // NOTE(Wuxiang): Utilize the logic provided by the description.
                if (board[row][col] == '.')
                {
                    continue;
                }

                if (row > 0 && board[row - 1][col] == 'X')
                {
                    continue;
                }

                if (col > 0 && board[row][col - 1] == 'X')
                {
                    continue;
                }

                ++shipNum;
            }
        }

        return shipNum;
    }
};
