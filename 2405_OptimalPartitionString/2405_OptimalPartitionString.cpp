//Greedy, hash set 
//O(n)
//O(1), because the largest extra space using in hashset will be 26 (a-z)
class Solution {
public:
    int partitionString(string s) {  
        unordered_set<char> hash;
        int count = 1;

        for(int i = 0;i < s.size();++i){
            if(hash.count(s[i])!= 0){
                ++count;
                hash.clear();
            }
            hash.insert(s[i]);
        }
        return count;
    }
};