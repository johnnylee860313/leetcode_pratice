class Solution {
public:
    string simplifyPath(string path) {
        string res;
        vector<string> dirs;
        int i = 0, n = path.size();
        while (i < n) {
            while (path[i] == '/' && i < n) ++i;
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < n) ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!dirs.empty()) dirs.pop_back(); 
            } else if (s != ".") {
                dirs.push_back(s);
            }
        }
        for (string str : dirs) res += "/" + str;
        return res.empty() ? "/" : res;
    }
};