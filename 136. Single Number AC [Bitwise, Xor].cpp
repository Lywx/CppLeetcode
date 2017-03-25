#include <vector>

using namespace std;

class Solution
{
public:
    // https://discuss.leetcode.com/topic/1916/my-o-n-solution-using-xor/6
    //
    // This XOR operation works because it's like XORing all the numbers by itself.
    // So if the array is {2,1,4,5,2,4,1} then it will be like we are performing
    // this operation:
    //
    // ((2 ^ 2) ^ (1 ^ 1) ^ (4 ^ 4) ^ (5)) = > (0 ^ 0 ^ 0 ^ 5) = > 5.
    //
    // Hence picking the odd one out(5 in this case). The commutative property of
    // XOR contributes to the conclusion.
    int singleNumber(vector<int>& nums)
    {
        int mask = 0;

        for (auto index = 0; index < nums.size(); ++index)
        {
            mask ^= nums[index];
        }

        return mask;
    }
};