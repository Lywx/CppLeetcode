#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(std::vector<int>& nums)
    {
        auto numSize = nums.size();
        vector<int> nextGreaterResult(numSize, -1);

        // Store the index of descending numbers.
        stack<int> descentIndexStack;

        for (int indexRange2x = 0; indexRange2x < numSize * 2; ++indexRange2x)
        {
            int index = indexRange2x % numSize;
            int num = nums[index];

            while (descentIndexStack.size() > 0

                    // Only when the previous number is greater than the current
                    // number. If this condition is satisfied continually, the stack
                    //would only pushed in the descending sequence of numbers.
                    // That means the top of the number is biggest of all.
                    && nums[descentIndexStack.top()] < num)
            {
                nextGreaterResult[descentIndexStack.top()] = num;
                descentIndexStack.pop();
            }

            if (indexRange2x < numSize)
            {
                descentIndexStack.push(indexRange2x);
            }
        }

        return nextGreaterResult;
    }
};
