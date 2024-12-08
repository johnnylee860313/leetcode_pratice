/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeserialize(vals, i);
    }

private:
    void dfsSerialize(TreeNode* node, vector<string>& res) {
        if (!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(vector<string>& vals, int& i) {
        if (vals[i] == "N") {
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);
        return node;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream outStream;
        dfs_serialize(root, outStream);
        return outStream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream inStream(data);
        return dfs_deserialize(inStream);
    }
    
    void dfs_serialize(TreeNode* root, ostringstream& outStream){
        if (!root) {
            outStream<<"# ";
            return;
        } else {
            outStream<<root->val<<' ';
        }
            
        dfs_serialize(root->left, outStream);
        dfs_serialize(root->right, outStream);
    }
    
    TreeNode* dfs_deserialize(istringstream& inStream) {
        string val;
        inStream>>val;
        
        if (val == "#") return nullptr;
       
        TreeNode* node = new TreeNode(stoi(val));
        
        node->left = dfs_deserialize(inStream);
        node->right = dfs_deserialize(inStream);
        return node;
    }

};

