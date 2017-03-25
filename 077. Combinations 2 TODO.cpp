#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <numeric>

using namespace std;

struct Digit
{
    unsigned int m_max;
    unsigned int m_min;
    unsigned int m_current;

    Digit(int current, int min, int n)
    {
        m_max = n;
        m_min = min;
        m_current = current;
    }

    bool increment()
    {
        ++m_current;

        if (m_current > m_max)
        {
            m_current = m_min;
            return true;
        }

        return false;
    }

    operator int() const
    {
        return m_current;
    }
};

struct Counter
{
    vector<Digit>& m_digits;
    int            m_count;

    Counter(vector<Digit>& counters) :
        m_digits (counters),
        m_count(0)
    {
    }

    void increment()
    {
        if (m_digits.front().increment())
        {
            carry_higher(1);
        }

        ++m_count;
    }

private:
    void carry_higher(int dim) const
    {
        if (m_digits[dim].increment())
        {
            carry_higher(dim + 1);
        }
    }
};

typedef vector<Digit> DigitVec;

namespace std {
template <>
struct hash<set<int>>
{
    size_t operator () (const set<int> &set) const
    {
        vector<int> vec(set.begin(), set.end());
        size_t value = 0;
        for (auto i = 0; i < vec.size(); ++i)
        {
            value += vec[i] * pow(10, i);
        }

        return value;
    }
};
}

struct DigitVecHash
{
    size_t operator()(const DigitVec& key) const
    {
        using std::sort;
        set<int> keySet(key.begin(), key.end());
        sort(keySet.begin(), keySet.end());
        hash<set<int>> hashFunc {};
        return hashFunc(keySet);
    }
};

class Solution
{
public:
    int                 m_n;
    int                 m_k;
    vector<vector<int>> m_ans;

    unordered_map<DigitVec, vector<Digit>, DigitVecHash> m_existTable;
    unordered_map<DigitVec, bool, DigitVecHash>          m_allowTable;

    vector<vector<int>> combine(int n, int k)
    {
        m_k = k;
        m_n = n;
        m_ans = vector<vector<int>>();

        auto digits = vector<Digit>();
        digits.reserve(m_k);
        digits.assign(m_k, Digit(1, 1, n));

        auto counter = Counter(digits);
        auto countMax = pow(m_n, m_k);
        while (counter.m_count < countMax)
        {
            counter.increment();

            if (allow(digits) && !exists(digits))
            {
                add(digits);
            }
        }

        return m_ans;
    }

    inline bool allow(DigitVec& key)
    {
        auto itr = m_allowTable.find(key);
        if (itr == m_allowTable.end())
        {
            unordered_set<int> set(key.begin(), key.end());
            auto value = set.size() == key.size();
            m_allowTable[key] = value;
            return value;
        }

        return (*itr).second;
    }

    inline bool exists(DigitVec& key)
    {
        auto itr = m_existTable.find(key);
        auto found = itr != m_existTable.end();
        return found ? true : false;
    }

    inline void add(DigitVec key)
    {
        m_existTable[key] = key;

        auto combination = vector<int>();
        for (size_t i = 0; i < key.size(); ++i)
        {
            combination.push_back(key[i].m_current);
        }

        m_ans.push_back(std::move(combination));
    }
};

void main()
{
    auto sol = Solution();
    sol.combine(4, 2);
}

