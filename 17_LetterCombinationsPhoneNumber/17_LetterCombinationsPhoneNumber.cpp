//O(4^N), "wxyz" = 4
//O(1)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combination;
        
        if (digits.empty())return {};
        
        
        dfsCombine(digits, dict, combination, 0, "");
        
        return combination;
    }
    void dfsCombine(string digits, vector<string> dict, vector<string>& combination, int pos, string cur){
        if (pos == digits.size())return combination.push_back(cur);
        
        string str = dict[digits[pos] - '0'];
        
        for(int i = 0; i < str.size();++i){
            dfsCombine(digits, dict, combination, pos + 1, cur + str[i]);
        }
        return;
    }
};