class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minP = prices[0];
        for(int i = 1; i< prices.size();i++)
        {
            minP = min(prices[i], minP);
            maxProfit = max(prices[i]- minP, maxProfit);
        }
        return maxProfit;
    }
};
