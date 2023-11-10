class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n<=1){return 0;}
        int buy=prices[0],sell=0;
        
        for(int i=1;i<n;i++){
            buy = min(buy,prices[i]);
            sell = max(sell,prices[i]-buy);
        }
        return sell;
    }
};