// class Solution {
// public:
//     string reorganizeString(string s) {
//         string res = "";
//         unordered_map<char,int> mp;
//         priority_queue<pair<int,char>> pq;

//         for(char c:s)mp[c]++;
//         for(auto c:mp){
//             if(c.second > (s.size()+1)/2)return "";
//             pq.push({c.second,c.first});
//         }

//         while(pq.size() >= 2){
//             auto c1 = pq.top();pq.pop();
//             auto c2 = pq.top();pq.top();
            
//             res += c1.second;
//             res += c2.second;
            
//             if(--c1.first > 0)pq.push(c1);
//             if(--c2.first > 0)pq.push(c2);
//         }

//         if (pq.size() > 0) res.push_back(pq.top().second);
//         return res;
//     }
// };
class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (char c : S) ++m[c];
        for (auto a : m) {
            if (a.second > (S.size() + 1) / 2) return "";
            q.push({a.second, a.first});
        }
        while (q.size() >= 2) {
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        if (q.size() > 0) res.push_back(q.top().second);
        return res;
    }
};