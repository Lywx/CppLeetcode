#include <vector>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> numTreeList(n + 1, 0);

        numTreeList[0] = 1;
        numTreeList[1] = 1;
        numTreeList[3] = 2;

        for (int i = 3; i <= n; ++i)
        {
            for (int j = 0; j <= i - 1; ++j)
            {
                numTreeList[i] += numTreeList[j] * numTreeList[i - 1 - j];
            }
        }

        return numTreeList[n];
    }
};