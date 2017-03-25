#include <cmath>

using namespace std;

class Solution
{
public:
    int countDigits(int num)
    {
        int i = 1;
        while (true)
        {
            if (num / int(pow(10, i)) == 0)
            {
                break;
            }

            ++i;
        }

        return i;
    }

    // NOTE(Wuxiang): num % 10 ^ i / 10 ^ (i - 1), where i = 1, 2, 3, 4, 5
    // Ex: 54321 % 10 ^ 3 = 321, 321 / 10 ^ 2 = 3.
    //
    int extractDigit(int num, int i)
    {
        return num % int(pow(10, i)) / int(pow(10, i - 1));
    }

    int addDigits(int num)
    {
        int digits;
        int result = num;
        while ((digits = countDigits(result)) != 1)
        {
            int sum = 0;

            for (auto i = 1; i < digits + 1; ++i)
            {
                sum += extractDigit(result, i);
            }

            result = sum;
        }

        return result;
    }
};