// NOTE(Wuxiang): Decision problem if you observed n = 1, 2, 3, ... quickly you
// will find:
// N = 1 2 3 4 5 6 7 8 9 10
// W   Y Y Y N Y Y Y N Y Y
// W - Win, Y - Yes, N - No
//
// NOTE(Wuxaing): The problem is recursive. canWinNim(n) = !canWinNim(n - k),
// where k is the stone taken this turn.
//
// NOTE(Wuxiang): Optimal strategy is easy to find. Any player should ensure that
// n mod 4 == 0 is satisfied at the end of his round. 
class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};
