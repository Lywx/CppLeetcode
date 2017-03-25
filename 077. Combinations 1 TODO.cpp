#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> Key;
struct Hasher
{
    std::size_t operator()(const Key& key) const
    {
        using std::size_t;
        using std::hash;
        using std::string;

        for (auto i = 0; i < key.size(); ++i)
        {
            int k = key[i];
            auto a = hash<int>(k);
            (key.at(i));
        }

        ((hash<int>()(key.first)
          ^ (hash<int>()(key.second) << 1)) >> 1)
        ^ (hash<int>()(key.third) << 1)

        return ;
    }
};

class Solution
{
public:
    int m_n;
    int m_k;
    vector<vector<int>> *m_ans;
    unordered_map<Key, vector<int>> m_hash;

    vector<vector<int>> combine(int n, int k)
    {
        m_n = 4;
        m_k = 2;

        m_ans = new vector<vector<int>>();

        auto vec = vector<int>();
        vec.reserve(m_k);

        for (auto dim = 0; dim < m_k; ++dim)
        {
            for (auto i = 1; i < m_n; ++i)
            {
                assign(vec, dim, i);

                if (!exists(vec))
                {
                    add(vec);
                }
            }
        }

        return *m_ans;
    }

    inline bool exists(vector<int> vec)
    {
        auto itr = m_hash.find(vec);
        return itr != m_hash.end() ? true : false;
    }

    inline void add(vector<int> vec)
    {
        m_hash[vec] = vec;
        m_ans->push_back(vec);
    }

    inline void assign(vector<int>& vec, int dim, int val)
    {
        vec.at(dim) = val;
    }
};