class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(),products.end());
        auto it  = products.begin();
        string query;

        for(auto c : searchWord){
            vector<string> out;
            query += c;
            it  = lower_bound(it,products.end(),query);
            for(int i = 0;i < 3 && it+i != products.end();++i){//suggest 3 at most
                string word = *(it+i);
                if(word.substr(0,query.size()) != query)break;
                out.push_back(word);
            }
            res.push_back(out);
        }
        
        return res;
    }
};