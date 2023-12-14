// class Solution {
// public:
//     int maxLength(vector<string>& arr) {
//         return dfs(arr,0,"");
//     }

//     int dfs(vector<string>& arr,int start,string curr){
//         unordered_set<char> hs(curr.begin(),curr.end());

//         if(curr.size() != hs.size())return 0;

//         int res = curr.size();
//         for(int i = start;i < arr.size();++i){
//             res = max(res,dfs(arr,i+1,curr+arr[i]));
//         }
//         return res;
//     }
// };
class Solution{
public:
    int maxLength(vector<string>& arr){
        vector<bitset<26>> all{bitset<26>()};
        int res = 0;

        for(auto word:arr){
            bitset<26> cur;
            for(auto c:word){
                cur.set(c-'a');
            }

            int n = cur.count();
            if(n < word.size())continue;

            for (int i = (int)all.size() - 1; i >= 0; --i) {
                bitset<26> t = all[i];
                if ((t & cur).any()) continue;//if intersect
                all.push_back(t | cur);
                res = max(res, (int)t.count() + n);
            }
        }

        return res;
    }
};
