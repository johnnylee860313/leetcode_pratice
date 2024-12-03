///O(Len(Coins)∗Amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)return 0;
        
        vector<int> dp_combination(amount+1,amount+1);
        dp_combination[0] = 0;
        
        for(int i = 1;i <= amount;++i){
            for(auto coin:coins){
                if (coin > i)continue;
                dp_combination[i] = min(dp_combination[i], 1+dp_combination[i-coin]);
            }
        }
        
        return (dp_combination[amount] == amount+1)?-1:dp_combination[amount];
    }
};
