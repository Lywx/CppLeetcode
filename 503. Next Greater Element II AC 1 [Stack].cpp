#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(std::vector<int>& nums)
    {
        vector<int> nextGreaterResult(nums.size(), -1);

        // The content <int, int> pair = <number in the 'nums' array, index in the 'nums' array>.
        stack<pair<int, int>> descentStack;

        for (int repeat = 0; repeat < 2; ++repeat)
        {
            for (int index = 0; index < nums.size(); ++index)
            {
                int num = nums[index];

                while (descentStack.size() > 0

                        // Only when the previous number is greater than the current
                        // number. If this condition is satisfied continually, the stack
                        //would only pushed in the descending sequence of numbers.
                        // That means the top of the number is biggest of all.
                        && descentStack.top().first < num)
                {
                    nextGreaterResult[descentStack.top().second] = num;
                    descentStack.pop();
                }

                descentStack.push(make_pair(num, index));
            }
        }

        return nextGreaterResult;
    }
};
