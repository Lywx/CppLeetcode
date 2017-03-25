class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        int difference = hammingDifference(x, y);
        return countBit(difference);
    }

    int hammingDifference(int x, int y)
    {
        return (x & ~y) | (~x & y);
    }

    // http://stackoverflow.com/a/109915/1940602
    int countBit(int x)
    {
        int count = 0;
        while (x > 0)
        {
            if (x & 1 == 1)
            {
                ++count;
            }

            x >>= 1;
        }

        return count;
    }
};