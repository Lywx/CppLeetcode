public class Solution
{
    public int MaxProfit(int[] prices)
    {
        var sumProfit = 0;
        for (var i = 1; i < prices.Length; ++i)
        {
            var profit = prices[i] - prices[i - 1];
            if (profit > 0)
            {
                sumProfit += profit;
            }
        }

        return sumProfit;
    }
}