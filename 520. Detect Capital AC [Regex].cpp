#include <string>
#include <regex>

using namespace std;

class Solution
{
public:
    bool isLowercase(std::string& word)
    {
        regex pattern("[A-Z]");
        return !regex_search(word, pattern);
    }

    bool isUppercase(std::string& word)
    {
        regex pattern("[a-z]");
        return !regex_search(word, pattern);
    }

    bool isTitlecase(std::string& word)
    {
        regex pattern("[A-Z]");
        return !regex_search(word.begin() + 1, word.end(), pattern) && regex_search(word.begin(), word.begin() + 1, pattern);
    }

    bool detectCapitalUse(std::string word)
    {
        return isUppercase(word)
               || isLowercase(word)
               || isTitlecase(word);
    }
};
