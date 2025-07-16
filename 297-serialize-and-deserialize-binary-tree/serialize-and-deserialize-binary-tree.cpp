/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Serialize the tree into a string
    string serialize(TreeNode* root) {
        if (!root) return "[null]";
        string ans = "[";
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();
            if (node) {
                ans += to_string(node->val) + ",";
                nodes.push(node->left);
                nodes.push(node->right);
            } else {
                ans += "null,";
            }
        }
        // Remove trailing "null,"s
        while (ans.size() >= 5 && ans.substr(ans.size() - 5) == "null,") {
            ans.erase(ans.size() - 5);
        }
        if (!ans.empty() && ans.back() == ',') ans.pop_back();
        ans += "]";
        return ans;
    }

    // Deserialize the string back into a tree
    TreeNode* deserialize(string data) {
        if (data == "[null]") return nullptr;
        data.erase(0, 1); // remove '['
        data.pop_back();   // remove ']'
        vector<string> vals;
        string current;
        for (char c : data) {
            if (c == ',') {
                vals.push_back(current);
                current.clear();
            } else {
                current += c;
            }
        }
        if (!current.empty()) vals.push_back(current);

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> nodes;
        nodes.push(root);
        int i = 1;
        while (!nodes.empty() && i < vals.size()) {
            TreeNode* node = nodes.front();
            nodes.pop();
            if (vals[i] != "null") {
                node->left = new TreeNode(stoi(vals[i]));
                nodes.push(node->left);
            }
            i++;
            if (i < vals.size() && vals[i] != "null") {
                node->right = new TreeNode(stoi(vals[i]));
                nodes.push(node->right);
            }
            i++;
        }
        return root;
    }
};
