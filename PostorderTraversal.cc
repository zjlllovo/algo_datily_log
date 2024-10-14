#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class TreeNode {
public:
  int _val;
  TreeNode *_left;
  TreeNode *_right;
  TreeNode() : _val(0), _left(nullptr), _right(nullptr) {}
  TreeNode(int x) : _val(x), _left(nullptr), _right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : _val(x), _left(left), _right(right) {}
};

vector<int> PostorderTraversal(TreeNode *root) {
  stack<TreeNode *> stk;
  vector<int> result;
  stk.push(root);
  while (!stk.empty()) {
    TreeNode *node = stk.top();
    stk.pop();
    result.push_back(node->_val);

    if (node->_left) {
      stk.push(node->_left);
    }
    if (node->_right) {
      stk.push(node->_right);
    }
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  TreeNode *node4 = new TreeNode(4);
  TreeNode *node5 = new TreeNode(5);
  TreeNode *node2 = new TreeNode(2, node4, node5);
  TreeNode *node3 = new TreeNode(3);
  TreeNode *root = new TreeNode(1, node2, node3);
  vector<int> vec = PostorderTraversal(root);
  for (auto &it : vec) {
    std::cout << it << std::endl;
  }

  return 0;
}
