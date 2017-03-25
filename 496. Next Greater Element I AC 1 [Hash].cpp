#include <unordered_map>
#include <vector>

using namespace std;

// @complexity time N ^ 2, space N.
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        unordered_map<int, int> indexHash;
        for (auto index = 0; index < nums.size(); ++index)
        {
            indexHash[nums[index]] = index;
        }

        vector<int> nextGreaterResult;
        for (auto numIndex1st = 0; numIndex1st < findNums.size(); ++numIndex1st)
        {
            auto num = findNums[numIndex1st];
            auto nextGreaterFound = false;

            for (auto numIndex2nd = indexHash[num]; numIndex2nd < nums.size(); ++numIndex2nd)
            {
                if (nums[numIndex2nd] > num)
                {
                    nextGreaterResult.push_back(nums[numIndex2nd]);
                    nextGreaterFound = true;
                    break;
                }
            }

            if (!nextGreaterFound)
            {
                nextGreaterResult.push_back(-1);
            }
        }

        return nextGreaterResult;
    }
};