class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> fruitCnt;
        int start = 0;
        int res = 0;

        for(int i = 0;i < fruits.size();++i){
            ++fruitCnt[fruits[i]];

            while(fruitCnt.size() > 2){
                if(--fruitCnt[fruits[start]] == 0){
                    fruitCnt.erase(fruits[start]);
                }
                ++start;
            }
            res = max(res,i-start+1);
        }
        return res;
    }
};
