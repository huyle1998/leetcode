#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return Bst(root, LONG_MAX, LONG_MIN);
    }
    bool Bst(TreeNode* root, long max_val, long  min_val) {
        if (root == NULL) {
            return true;
        }
        if (root->val >= max_val || root->val <= min_val) {

            return false;
        }
        return Bst(root->left, root->val, min_val) && Bst(root->right, max_val, root->val);
    }
};

TreeNode* createTree(vector<int>& nodeValues) {
    uint8_t treeLevel = log2(nodeValues.size() + 1);
    TreeNode*** nodes = new TreeNode** [treeLevel];
    for (uint8_t level = 0; level < treeLevel; level++) {
        uint32_t numNodeOnLevel = 1 << level;
        nodes[level] = new TreeNode* [numNodeOnLevel];
        for (uint32_t i = 0; i < numNodeOnLevel; i++) {
            uint32_t nodeValue = nodeValues[numNodeOnLevel - 1 + i];
            if (nodeValue > 0) {
                TreeNode* pNode = new TreeNode(nodeValue);
                nodes[level][i] = pNode;
            }
            else {
                nodes[level][i] = NULL;
            }
        }
    }
    for (uint8_t level = 0; level < treeLevel; level++) {
        uint32_t numNodeOnLevel = 1 << level;
        for (uint32_t i = 0; i < numNodeOnLevel; i++) {
            if (level < treeLevel - 1 && nodes[level][i] != NULL) {
                nodes[level][i]->left = nodes[level + 1][2*i];
                nodes[level][i]->right = nodes[level + 1][2*i + 1];
            } 
            else if (nodes[level][i] == NULL) {

            } 
            else {
                nodes[level][i]->left = NULL;
                nodes[level][i]->right = NULL;
            }
        }
    }
    return nodes[0][0];
}

void main() {
    Solution solution;
    TreeNode* root;
    vector<int> nodeValues = { 8,7,10,5,0,0,15,4,6,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,11,14,0,0 };
    root = createTree(nodeValues);
    if (solution.isValidBST(root) == true) {
        cout << "This tree is valid BST." << endl;
    }
    else {
        cout << "This tree is not valid BST." << endl;
    }
}