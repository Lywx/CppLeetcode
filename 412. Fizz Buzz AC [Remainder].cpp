#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        for (int i = 1; i <= n; ++i)
        {
            bool m3 = i % 3 == 0;
            bool m5 = i % 5 == 0;
            bool m35 = i % 15 == 0;

            if (m35)
            {
                result.push_back("FizzBuzz");
                continue;
            }

            if (m3)
            {
                result.push_back("Fizz");
                continue;
            }

            if (m5)
            {
                result.push_back("Buzz");
                continue;
            }

            result.push_back(to_string(i));
        }
        return result;
    }
};