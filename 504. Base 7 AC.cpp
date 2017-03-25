#include <string>
#include <vector>

using namespace std;

char to_char(int i)
{
    static char charArray[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    return charArray[i];
}

class Solution
{
public:

    string convertToBase7(int num)
    {
        auto base = 7;
        auto negative = false;
        auto result = string();

        if (num < 0)
        {
            negative = true;
            num = -num;
        }

        auto quotient = num / base;
        auto remainder = num % base;

        result.push_back(to_char(remainder));

        while (quotient != 0)
        {
            remainder = quotient % base;
            quotient = quotient / base;

            result.push_back(to_char(remainder));
        }

        if (negative)
        {
            result.push_back('-');
        }

        reverse(result.begin(), result.end());

        return result;
    }
};