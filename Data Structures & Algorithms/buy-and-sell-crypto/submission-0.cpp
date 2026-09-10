class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int profit = 0;
        int low = prices[0];
        for(int i=1;i < prices.size();++i)
        {
            low = min(prices[i], low);
            profit = prices[i] - low;
            maxP = max(maxP,profit);
        }
        return maxP;
    }
};
