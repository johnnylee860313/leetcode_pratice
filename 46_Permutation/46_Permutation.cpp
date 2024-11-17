//O(N!)


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> permutation;
        vector<bool> visited(nums.size(),0);
        
        DFS_buildPermutations(nums, permutations, permutation, 0, visited);    
        
        return permutations;
    }
    
    void DFS_buildPermutations(vector<int>& nums, vector<vector<int>>& permutations, 
                               vector<int>& permutation, int level, vector<bool>& visited)
    {
        // for(int i = 0;i < permutation.size();++i){
        //     cout<<permutation[i];
        // }
        // cout<<endl;

        if (level == nums.size()) return permutations.push_back(permutation);
        
        for(int i = 0;i < nums.size();++i){
            if (visited[i] == true)continue;
            visited[i] = true;
            permutation.push_back(nums[i]);
            DFS_buildPermutations(nums, permutations, permutation, level+1, visited);
            visited[i] = false;
            permutation.pop_back();
        }
        return;
    }
};