class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // m, n represents the time you could still go down and right respectively.

        if (m < 1 || n < 1)
        {
            return 0;
        }

        if (m == 1 && n == 1)
        {
            return 1;
        }

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};