#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// NOTE(Wuxiang): Based on "051. N-Queens AC 1+ [Counting, DFS, Math, Stack]".
class Solution
{
public:
    vector<pair<int, int>> queenArrangementCurrent;
    int queenArrangementCount = 0;


    bool canQueenAttack(int rowIndexQueen, int columnIndexQueen, int rowIndexTarget, int columnIndexTarget)
    {
        int rowDiff = rowIndexQueen - rowIndexTarget;
        int columnDiff = columnIndexQueen - columnIndexTarget;

        return rowDiff == 0
               || columnDiff == 0
               || rowDiff == columnDiff
               || rowDiff == -columnDiff;
    }

    void chooseQueen(int rowOffset, int columnOffset, int rowNum, int columnNum)
    {
        // Termination condition
        if (queenArrangementCurrent.size() == rowNum)
        {
            ++queenArrangementCount;
            return;
        }

        for (int columnIndex = columnOffset; columnIndex < columnNum; ++columnIndex)
        {
            if (queenArrangementCurrent.empty())
            {
                queenArrangementCurrent.push_back(make_pair(rowOffset, columnIndex));

                chooseQueen(rowOffset + 1, 0, rowNum, columnNum);

                queenArrangementCurrent.pop_back();
            }
            else
            {
                bool queenCanAttackIsNone = true;

                for (int queenIndex = 0; queenIndex < int(queenArrangementCurrent.size()); ++queenIndex)
                {
                    pair<int, int> q = queenArrangementCurrent[queenIndex];

                    if (canQueenAttack(q.first, q.second, rowOffset, columnIndex))
                    {
                        queenCanAttackIsNone = false;
                        break;
                    }
                }

                if (queenCanAttackIsNone)
                {
                    queenArrangementCurrent.push_back(make_pair(rowOffset, columnIndex));

                    chooseQueen(rowOffset + 1, 0, rowNum, columnNum);

                    queenArrangementCurrent.pop_back();
                }
            }
        }
    }

    int totalNQueens(int n)
    {
        int rowNum = n;
        int columnNum = n;

        chooseQueen(0, 0, rowNum, columnNum);

        return queenArrangementCount;
    }
};