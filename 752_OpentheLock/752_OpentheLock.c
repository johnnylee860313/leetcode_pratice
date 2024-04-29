class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlock(deadends.begin(), deadends.end());
        unordered_set<string> visited{{"0000"}};
        queue<string> q{{"0000"}};
        vector<int> list{-1,1}; // each number bit plus one or minus one
        int res = 0;

        if(target == "0000")return 0;
        if(deadlock.count("0000"))return -1;

        while(!q.empty()){
            ++res;
            for(int i = q.size();i > 0;--i){//q size
                auto t = q.front();q.pop();
                for(int j = 0; j < t.size();++j){//iterate number size
                    for(int k = 0;k < list.size();++k){
                        string str = t;
                        str[j] = ((t[j] - '0') + 10 + list[k]) % 10 + '0';//9+1=0;0-1=9
                        if(str == target)return res;
                        if(!visited.count(str) && !deadlock.count(str))q.push(str);
                        visited.insert(str);
                    }
                }
            }
        }

        return -1;
    }
};
 