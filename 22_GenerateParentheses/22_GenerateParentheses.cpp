//O(2^N)
//O(N)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        string parenth = "";
        
        dfsParenthensisCombine(parenthesis, n, n, parenth);
        return parenthesis;
    }
    
    void dfsParenthensisCombine(vector<string>& parenthesis, int left,
                                int right, string& parenth)
    {
        // cout<<parenth<<endl;
        if (left+right == 0)return parenthesis.push_back(parenth);
        if (right < left) return;
        
        if (left > 0){
            dfsParenthensisCombine(parenthesis, left-1, right, parenth += '(' );
            
            parenth.pop_back();
        }
        if (right > 0){
            dfsParenthensisCombine(parenthesis, left, right-1, parenth += ')' );
            // cout<<parenth<<endl;
            parenth.pop_back();
        }
        
        return;
    }
};