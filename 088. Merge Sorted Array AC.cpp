#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (n == 0)
        {
            return;
        }

        while (m < nums1.size())
        {
            nums1.pop_back();
        }

        while (n < nums2.size())
        {
            nums2.pop_back();
        }

        typedef vector<int>::iterator iter;
        iter nums1Itr = nums1.begin();
        iter nums2Itr = nums2.begin();
        while (nums1Itr < nums1.end()
                && nums2Itr < nums2.end())
        {
            if (*nums1Itr >= *nums2Itr)
            {
                nums1Itr = nums1.insert(nums1Itr, *nums2Itr);
                ++nums2Itr;
            }
            else
            {
                ++nums1Itr;
            }
        }

        if (nums1Itr < nums1.end())
        {
            return;
        }
        else // if (nums2Itr < nums2.end())
        {
            while(nums2Itr != nums2.end())
            {
                nums1.push_back(*nums2Itr);
                ++nums2Itr;
            }
        }
    }
};