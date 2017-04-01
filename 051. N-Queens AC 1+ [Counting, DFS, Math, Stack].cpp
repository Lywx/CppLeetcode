#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// NOTE(Wuxiang): You would like to avoid store a board structure in this problem.
// Because the queen collision detection can be done in constant time even you don't
// have a structure for a board. You don't want to waste time in maintain the
// validity of the board structure.
class Solution
{
public:
    list<vector<pair<int, int>>> queenArrangementList;
    vector<pair<int, int>> queenArrangementCurrent;
    vector<vector<string>> queenResultList;
    vector<string>         queenResultTemplate;

    bool canQueenAttack(int rowIndexQueen, int columnIndexQueen, int rowIndexTarget, int columnIndexTarget)
    {
        int rowDiff = rowIndexQueen - rowIndexTarget;
        int columnDiff = columnIndexQueen - columnIndexTarget;

        return rowDiff == 0
               || columnDiff == 0
               || rowDiff == columnDiff
               || rowDiff == -columnDiff;
    }

    // NOTE(Wuxiang): The improvement of this routine over "051. N-Queens AC 1 [Counting, DFS, Stack]" is
    // that this routine use the notion of one queen per row. As a result, we avoid
    // looping though rows altogether.
    void chooseQueen(int rowOffset, int columnOffset, int rowNum, int columnNum)
    {
        // Termination condition
        if (queenArrangementCurrent.size() == rowNum)
        {
            queenArrangementList.push_back(queenArrangementCurrent);

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

    void prepareResult(int rowNum, int columnNum)
    {
        typedef list<vector<pair<int, int>>>::iterator Iter;

        queenResultTemplate.assign(rowNum, string(columnNum, '.'));

        for (Iter iter = queenArrangementList.begin(); iter != queenArrangementList.end(); ++iter)
        {
            vector<string> queenArrangementResult = queenResultTemplate;

            for (int queenIndex = 0; queenIndex < int(iter->size()); ++queenIndex)
            {
                pair<int, int> q = (*iter)[queenIndex];
                queenArrangementResult[q.first][q.second] = 'Q';
            }

            queenResultList.push_back(queenArrangementResult);
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        int rowNum = n;
        int columnNum = n;

        chooseQueen(0, 0, rowNum, columnNum);

        prepareResult(rowNum, columnNum);

        return queenResultList;
    }
};