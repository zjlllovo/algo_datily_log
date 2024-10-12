#include <queue>
#include <vector>

using std::queue;
using std::vector;

class TreeNode {
public:
  TreeNode() : val(0), _LeftNode(nullptr), _RighNode(nullptr) {}
  TreeNode(int x) : val(x), _LeftNode(nullptr), _RighNode(nullptr) {}
  TreeNode(int x, TreeNode *LeftNode, TreeNode *RighNode)
      : val(x), _LeftNode(LeftNode), _RighNode(RighNode) {}
  int val;
  TreeNode *_LeftNode;
  TreeNode *_RighNode;
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> que;
    if (root) {
      que.push(root);
    }
    vector<vector<int>> result;
    while (!que.empty()) {
      int size = que.size();
      vector<int> vec;
      while (size--) {
        TreeNode *front = que.front();
        que.pop();
        vec.push_back(front->val);
        if (front->_LeftNode) {
          que.push(front->_LeftNode);
        }
        if (front->_RighNode) {
          que.push(front->_RighNode);
        }
      }
      result.push_back(vec);
    }
    return result;
  }
};

int main() { return 0; }
