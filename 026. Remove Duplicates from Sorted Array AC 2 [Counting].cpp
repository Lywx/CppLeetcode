#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int indexUnique = 0;
        for (size_t index = 1; index < nums.size(); ++index)
        {
            if (nums[indexUnique] != nums[index])
            {
                nums[++indexUnique] = nums[index];
            }
        }

        return indexUnique + 1;
    }
};