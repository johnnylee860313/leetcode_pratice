// class Solution {
// public:
//     string frequencySort(string s) {
//         vector<string> fq(s.size()+1);
//         string fqsort;
//         unordered_map<char,int>count_map;
//         for(auto c : s)++count_map[c];

//         for(auto ele:count_map){
//             fq[ele.second].append(ele.second,ele.first);
//         }
//          for (int i = s.size(); i > 0; --i) {
//             if (!fq[i].empty()) fqsort.append(fq[i]);
//         }
//         return fqsort;
//     }
// };
class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> q;
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (auto a : m) q.push({a.second, a.first});
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            res.append(t.first, t.second);
        }
        return res;
    }
};