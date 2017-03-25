#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string urlSubfix("/");
        auto urlSubfixIndex = find_end(longUrl.begin(), longUrl.end(), urlSubfix.begin(), urlSubfix.end());
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string urlSubfix("/");
        auto urlSubfixIndex = find_end(shortUrl.begin(), shortUrl.end(), urlSubfix.begin(), urlSubfix.end());
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));