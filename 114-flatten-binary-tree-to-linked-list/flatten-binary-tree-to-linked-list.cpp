class Solution {
public:
    bool isLeafNode(TreeNode* node){
        return !node->left && !node->right;
    }

    TreeNode* flat(TreeNode* node){
        if(!node) return nullptr;
        if(isLeafNode(node)) return node;
        
        TreeNode* lastLeftNode = flat(node->left);
        TreeNode* lastRightNode = flat(node->right);

        if(lastLeftNode){
            lastLeftNode->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }

        return lastRightNode ? lastRightNode : lastLeftNode;
    }

    void flatten(TreeNode* root) {
        flat(root);
    }
};
