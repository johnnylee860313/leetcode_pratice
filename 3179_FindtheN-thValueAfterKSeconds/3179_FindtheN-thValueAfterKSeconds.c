//O(NK)
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> state(n,1);
        vector<int> last = state;

        for(int i = 1;i <= k;++i){
            for(int j = 1;j < n;++j){
                state[j] = (state[j-1]+last[j])%1000000007;
            }
            last = state;
        }
        return state[n-1];
    }
};