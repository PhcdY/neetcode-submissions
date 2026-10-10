class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minprice=prices[0];

        for (int i:prices){
            if(profit<i-minprice){
                profit = i-minprice;
            }
            if(minprice>i){
                minprice = i;
            }
        }
    return profit;
    }
};
