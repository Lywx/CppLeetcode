#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        const unsigned bitLength = sizeof(int) * 8;

        // unsigned char supports 0-255 range in counting.
        unsigned char bitCount[bitLength];
        fill(begin(bitCount), end(bitCount), 0);

        for (auto numIndex = 0; numIndex < nums.size(); ++numIndex)
        {
            for (auto bitIndex = 0; bitIndex < bitLength; ++bitIndex)
            {
                // Based on the idea that extends the bit-wise operation. Because
                // the bit operation could not provide the more than 1 bit (0-1)
                // number of accuracy.
                bitCount[bitIndex] += ((nums[numIndex] >> bitIndex) & 1) ? 1 : 0;

                // Differentiate between 1 and 3.
                bitCount[bitIndex] %= 3;
            }
        }

        auto result = 0;
        for (auto bitIndex = 0; bitIndex < bitLength; ++bitIndex)
        {
            result += (bitCount[bitIndex] << bitIndex);
        }

        return result;
    }
};