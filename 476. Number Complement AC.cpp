class Solution 
{
public:
    int findComplement(int num) 
    {
        int complement = 0;

        // Last examined bit is n-th bit.
        int n = 0;        
        while (num > 0)
        {
            // When examined last bit as 1
            if (num & 1 == 1)            
            {
                complement += 0 << n;
            }

            // When examined last bit as 0
            else
            {
                complement += 1 << n;
            }

            ++n;

            // Moved the examining position.
            num >>= 1;
        }

        return complement;
    }
};