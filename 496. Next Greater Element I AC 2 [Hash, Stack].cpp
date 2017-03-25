#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// @complexity time N, space N.
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        unordered_map<int, int> nextGreaterHash;
        stack<int> descentStack;
        for (int num : nums)
        {
            while (descentStack.size() > 0

                    // Only when the previous number is greater than the current
                    // number. If this condition is satisfied continually, the stack
                    //would only pushed in the descending sequence of numbers.
                    // That means the top of the number is biggest of all.
                    && descentStack.top() < num)
            {
                nextGreaterHash[descentStack.top()] = num;
                descentStack.pop();
            }

            descentStack.push(num);
        }

        vector<int> nextGreaterResult;

        for (int num : findNums)
        {
            nextGreaterResult.push_back(nextGreaterHash.count(num) ? nextGreaterHash[num] : -1);
        }

        return nextGreaterResult;
    }
};