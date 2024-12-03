/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
  vector<TreeNode *> generateAllBSTs(int left, int right)
  {
    std::vector<TreeNode *> trees;

    if (left > right)
    {
      trees.push_back(nullptr);
    }
    else
    {
      for (int eachRootNode = left; eachRootNode <= right; ++eachRootNode)
      {
        std::vector<TreeNode *> leftSubtree =
            generateAllBSTs(left, eachRootNode - 1);
        std::vector<TreeNode *> rightSubtree =
            generateAllBSTs(eachRootNode + 1, right);

        for (TreeNode *eachLeftSubtree : leftSubtree)
        {
          for (TreeNode *eachRightSubtree : rightSubtree)
          {
            TreeNode *newNode = new TreeNode(eachRootNode, eachLeftSubtree, eachRightSubtree);
            trees.push_back(newNode);
          }
        }
      }
    }
    return trees;
  }

public:
  vector<TreeNode *> generateTrees(int n) { return generateAllBSTs(1, n); }
};