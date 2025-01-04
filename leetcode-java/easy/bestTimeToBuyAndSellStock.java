public class bestTimeToBuyAndSellStock {
    public static int maxProfit(int[] prices) {

        int profit = 0, maxPrice = 0, i = 0, j = 1;

        while (j < prices.length) {
            if (prices[j] > prices[i]) {
                profit = prices[j] - prices[i];
                maxPrice = Math.max(maxPrice, profit);
            } else {
                i = j;
            }
            j++;
        }

        return maxPrice;
    }

    public static void main(String[] args) {
        /*
         * You are given an array prices where prices[i] is the price of a given stock
         * on the ith day.
         * 
         * You want to maximize your profit by choosing a single day to buy one stock
         * and choosing a different day in the future to sell that stock.
         * 
         * Return the maximum profit you can achieve from this transaction. If you
         * cannot achieve any profit, return 0.
         */
        int[] prices = { 7, 1, 5, 3, 6, 4 };

        System.out.println(maxProfit(prices));
    }
}