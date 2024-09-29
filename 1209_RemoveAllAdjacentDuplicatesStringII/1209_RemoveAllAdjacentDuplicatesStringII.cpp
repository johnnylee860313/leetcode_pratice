class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;
        stack<pair<int,char>> st;
        st.push({0,'#'});
        for(char c : s) {
            if (st.top().second != c) {
                st.push({1,c});
            } else if (++(st.top().first) == k){
                st.pop();
            }
        }

        while(!st.empty()){
            if (st.top().second == '#')break;
            for(int i = 0;i < st.top().first;++i){
                res += st.top().second;
            }
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};