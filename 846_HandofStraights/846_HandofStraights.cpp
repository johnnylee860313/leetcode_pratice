class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        
        if (hand.size()% groupSize != 0)return false;
        
        for(auto num:hand){//value:count
            mp[num]++;
        }
       
        while(!mp.empty()){
            int curr = mp.begin()->first;
            for(int i = 0;i < groupSize;++i){
                if (mp[curr+i] == 0)return false;
                mp[curr+i]--;
                if (mp[curr+i] == 0)mp.erase(curr+i);
            }
        }
        return true;
    }
};

/*
    Given int array, return true if can rearrange cards into groupSize consecutive
    Ex. hand = [1,2,3,6,2,3,4,7,8], groupSize = 3 -> true, [1,2,3],[2,3,4],[6,7,8]

    Loop thru ordered map, for a value, check groupSize consecutive & remove

    Time: O(n log n)
    Space: O(n)
*/

