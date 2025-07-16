class Solution {
public:
    bool valid = true;

    pair<long, long> validate(TreeNode* node) {
        if (!node)
            return {LONG_MAX, LONG_MIN}; // Should use LONG, not INT
        
        if (!valid)
            return {LONG_MIN, LONG_MAX};

        pair<long, long> leftPair = validate(node->left);
        pair<long, long> rightPair = validate(node->right);

        if (leftPair.second >= node->val || rightPair.first <= node->val) {
            valid = false;
            return {LONG_MIN, LONG_MAX};
        }

        long minVal = min(leftPair.first, (long)node->val);
        long maxVal = max(rightPair.second, (long)node->val);
        return {minVal, maxVal};
    }

    bool isValidBST(TreeNode* root) {
        validate(root);
        return valid;
    }
};
