class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int maxP = 0;

        for(int i =1;i < prices.size();i++)
        {
            curMin = min(prices[i], curMin);
            maxP = max(maxP, prices[i] - curMin);
        }

        return maxP;
    }
};
