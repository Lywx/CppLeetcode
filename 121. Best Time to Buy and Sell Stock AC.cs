using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int MaxProfit(int[] prices)
    {
        var maxProfit = 0;
        var minBuy = 0;

        for (var i = 0; i < prices.Length; ++i)
        {
            if (i != 0)
            {
                maxProfit = Math.Max(prices[i] - minBuy, maxProfit);
            }

            if (i != 0)
            {
                minBuy = Math.Min(prices[i], minBuy);
            }
            else
            {
                minBuy = prices[i];
            }
        }

        return maxProfit;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        var prices = new List<int>();

        var lineRead = Console.ReadLine().Trim();
        var lineElems = lineRead.Split(' ');
        for (var i = 0; i < lineElems.Length; ++i)
        {
            var p = int.Parse(lineElems[i]);
            prices.Add(p);
        }

        var solution = new Solution();

        Console.WriteLine(solution.MaxProfit(prices.ToArray()));
        Console.ReadLine();
    }
}
