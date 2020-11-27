#include <iostream>
#include <vector>
#include <string>

  // defination https://leetcode-cn.com/problems/count-complete-tree-nodes/
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class SolutionOne {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        std::vector<TreeNode*>vec_tree;

        vec_tree.push_back(root);

        for (size_t i = 0; i < vec_tree.size(); ++i) {
            if (vec_tree[i]->left != nullptr)
                vec_tree.push_back(vec_tree[i]->left);
            if (vec_tree[i]->right != nullptr)
                vec_tree.push_back(vec_tree[i]->right);
        }

        int count = static_cast<int>(vec_tree.size());
        return count;

    }
};

class SolutionTwo{
public:

    void Tree(TreeNode* root, int* count){

        if(root != nullptr) (*count)++;

        if(root->left != nullptr) Tree(root->left, count);
        if(root->right != nullptr) Tree(root->right, count);

    }

    int countNodes(TreeNode* root){

        int* count = new int(0);
        Tree(root, count);

        return *count;


    }
};

class SolutionThree{
public:

    int countNodes(TreeNode* root){

    }
};

int main() {
    std::string s = "abc";
    std::string c = "abc";
    std::cout<<s.compare(c)<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
