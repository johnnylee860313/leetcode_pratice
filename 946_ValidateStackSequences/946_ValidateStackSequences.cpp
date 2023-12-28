//O(n)
//iterate and push the number in the pushed vector into stack,
//check the top of the stack is equal to popped vector in order or not
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int start = 0;
        int res = 0;

        for(int i = 0;i < pushed.size();++i){
            st.push(pushed[i]);

            while(!st.empty() && st.top() == popped[start]){
                st.pop();
                start++;
            }
            
        }

        return st.empty()?true:false;
    }
};