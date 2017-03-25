#include <map>

using namespace std;

class Solution 
{
public:
    vector<string> findWords(vector<string>& words) 
    {
        map<char, int> table = {
            {'Q', 0},
            {'W', 0},
            {'E', 0},
            {'R', 0},
            {'T', 0},
            {'Y', 0},
            {'U', 0},
            {'I', 0},
            {'O', 0},
            {'P', 0},

            {'q', 0},
            {'w', 0},
            {'e', 0},
            {'r', 0},
            {'t', 0},
            {'y', 0},
            {'u', 0},
            {'i', 0},
            {'o', 0},
            {'p', 0},

            {'a', 1},
            {'s', 1},
            {'d', 1},
            {'f', 1},
            {'g', 1},
            {'h', 1},
            {'j', 1},
            {'k', 1},
            {'l', 1},

            {'A', 1},
            {'S', 1},
            {'D', 1},
            {'F', 1},
            {'G', 1},
            {'H', 1},
            {'J', 1},
            {'K', 1},
            {'L', 1},

            {'z', 2},
            {'x', 2},
            {'c', 2},
            {'v', 2},
            {'b', 2},
            {'n', 2},
            {'m', 2},

            {'Z', 2},
            {'X', 2},
            {'C', 2},
            {'V', 2},
            {'B', 2},
            {'N', 2},
            {'M', 2}
        };

        vector<string> possibleWords;

        for (const auto& word : words)
        {
            int row = table[word[0]];
            bool rowSame = true;
            for (const auto& c : word)
            {
                if (table[c] != row)
                {
                    rowSame = false;
                    break;
                }
            }

            if (rowSame)
            {
                possibleWords.push_back(word);
            }
        }

        return possibleWords;
    }
};