#include <iostream>
#include <limits>
using namespace std;

//  REF : https://leetcode.com/problems/validate-binary-search-tree/
//  NOTES :
//        Need to compare given node with updated UPPER BOUND and LOWER BOUND
//        Like "Count good nodes in BT" deque stack will have now two more elements
//        [node, low, high] to implement iterative DFS/BFS solution
//  O(T) : O(n)
//  O(S) : O(n)

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
        // INT_MIN and INT_MAX is not working for all testcases
        return valid(root, INT_MIN, INT_MAX);
    }

    bool valid(TreeNode* node, int low, int high) {
        if (node == nullptr)
            return true;

        if !(node->val > low && node->val < high)
            return false;

        // This can also work
        // if (node->val <= low || node->val >= high)
        //     return false;

        return valid(node->left, low, node->val) && valid(node->right, node->val, high);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, nullptr, nullptr);
    }

    bool valid(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (node == nullptr)
            return true;
        
        if ((low != nullptr && node->val <= low->val) ||
            (high != nullptr && node->val >= high->val))
            return false;

        return valid(node->left, low, node) && valid(node->right, node, high);
    }
};

class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        long long maxi = LONG_MAX;      // Only this is the difference.
        long long mini = LONG_MIN;
        return valid(root, mini, maxi);
    }

    bool valid(TreeNode* node, long long low, long long high) {
        if (node == nullptr)
            return true;

        if (!(node->val > low && node->val < high))
            return false;
        // if (node->val <= low || node->val >= high)
        //     return false;

        return valid(node->left, low, node->val) && valid(node->right, node->val, high);
    }
};