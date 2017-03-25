
    public class Solution
    {
        public string ReverseString(string s)
        {
            var reverse = s.Reverse();
            var reverseBuilder = new StringBuilder();
            foreach (var c in reverse)
            {
                reverseBuilder.Append(c);
            }

            return reverseBuilder.ToString();
        }
    }
