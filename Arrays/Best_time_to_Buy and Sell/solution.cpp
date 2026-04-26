class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sellingDay=0;
        int buyingDay=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buyingDay){
                buyingDay=prices[i];
            }
            sellingDay=max(prices[i]-buyingDay,sellingDay);
        }
        return sellingDay;

        
    }
};
