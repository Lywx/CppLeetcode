#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    void buildMaxSubArrayTable(vector<vector<int>>& maxSubArrayTable, vector<int>& nums)
    {
        maxSubArrayTable = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
    }

    int maxSubArray(vector<int>& nums)
    {
        vector<vector<int>> maxSubArrayTable;
        buildMaxSubArrayTable(maxSubArrayTable, nums);

        return;
    }
};