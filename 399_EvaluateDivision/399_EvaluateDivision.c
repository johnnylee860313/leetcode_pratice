class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        for(int i=0; i<equations.size(); i++) {
           auto first = equations[i][0];
           auto second = equations[i][1];
           m[first][second] = values[i];
           m[second][first] = 1.0 / values[i];
        }
        
        vector<double> result;
        for(auto q : queries) {
            string start = q[0];
            string end = q[1];
            
            unordered_map<string, bool> visited;
            visited[start] = true;
            double res = 1.0;
            
            if(dfs(m, visited, start, end, res)) {
                result.push_back(res);
            } else {
                result.push_back(-1.0);
            }
        }
        
        return result;
    }
private:
    bool dfs( unordered_map<string, unordered_map<string, double>>& m, 
              unordered_map<string, bool>& visited, 
              string& start, string& end, double& res  ) {
                 
        if ( m.find(start) == m.end() || m.find(end) == m.end() ) return false;
        if ( start == end ) return true;
        
        for (auto it = m[start].begin(); it != m[start].end(); ++it) {
            auto key = it->first;
            auto value = it->second;
            // already visited, skip it.
            if (visited.find(key) != visited.end() ) {
                continue;
            }
            
            visited[key] = true;
            double old = res;
            res *= value;
            
            if (dfs(m, visited, key, end, res)) {
                return true;
            }
            //didn't find the result, reset the current result, and go to next one
            res = old;
            visited.erase(key);
        }
        
        return false;
    }
};

