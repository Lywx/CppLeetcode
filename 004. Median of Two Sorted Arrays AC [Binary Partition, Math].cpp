#include <algorithm>
#include <vector>

using namespace std;

// NOTE(Wuxiang): Learned from Soul Machine's book. This algorithm demonstrates
// how pointer can be used to efficiently search into array or vector container.
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int k = m + n;

        // When k is odd.
        if (k & 0x1)
        {
            // [A ...   X   ... Z]
            //          ^
            return findKth(nums1.data(), m, nums2.data(), n, k / 2 + 1);
        }

        // When k is even.
        else
        {
            // This is the position of the if-sorted element array before searching.
            //
            // [A ...   X X   ... Z]
            //          ^ ^
            return (findKth(nums1.data(), m, nums2.data(), n, k / 2)
                    + findKth(nums1.data(), m, nums2.data(), n, k / 2 + 1)) / 2.0;
        }
    }
private:
    // @summary Find the k-th smallest element in A, B array if they are merged together.
    static int findKth(int *A, int m, int *B, int n, int k)
    {
        // Assume that A has m elements.
        // Assume that B has n elements.
        //
        // Assume that m is equal or smaller than n.
        // Assume that m + n >= k.

        // Deal with case regards to m, n.
        {
            if (m > n)
            {
                return findKth(B, n, A, m, k);
            }

            if (m == 0)
            {
                return B[k - 1];
            }
        }

        // Deal with case regards to A, B, k.
        {
            if (k == 1)
            {
                return min(A[0], B[0]);
            }

            // The element number examined (or skipped) in A, guaranteed to be less than size
            // of the array, in the mean time, examine as many elements in the A
            // array as possible.
            //
            // Try to equally partition the k / 2 element we need to skip. The
            // reason k / 2 is that we can only assume m + n >= k. It doesn't make any
            // sense if we try use any thing larger than or equals to k, like:
            //
            // int countA = min(k, m)
            //
            // in this iteration. Because we want to find the k-th smallest number.
            // If we coded as above the result would be we skip k number in A --
            // we would skip 0 number in B. That would cause we cannot include
            // information in B. You would actually divide unequally, as long as
            // both array has some elements included. But the inequality would
            // cause log(x) N instead of log(2) N worst complexity, where x = "one
            // divided by the larger proportion of the division", like x = 1.5
            // when you do a 1 : 2 division. Remember that the smaller the base is,
            // the bigger the number. The computation result for x comes from the
            // fact we can only skip certain number of elements in one of two arrays.
            // The skipped array must be the array has smaller value at the computed index.
            // In the worst case, the array would be the one has smaller size -- You would
            // skip the only one third of total size out of 1 : 2 division.
            //
            // If we cannot do precisely that, that must be the case that A is too short.
            // We would enter m == 0 case in next iteration. Because after that,
            // m - countA == 0 is true.
            int countA = min(k / 2, m);

            // The index equals to number of element left for examination after
            // cutting off indexA element already. We should not examine (or skip) more
            // than k elements.
            int countB = k - countA;

            int indexA = countA - 1;
            int indexB = countB - 1;

            if (A[indexA] < B[indexB])
            {
                return findKth(A + countA, m - countA, B, n, k - countA);
            }
            else if (A[indexA] > B[indexB])
            {
                return findKth(A, m, B + countB, n - countB, k - countB);
            }
            else
            {
                return A[indexA];
            }
        }
    }
};