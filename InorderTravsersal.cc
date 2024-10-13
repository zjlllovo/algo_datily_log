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
      : _val(0), _left(left), _right(right) {}
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> stk;
    vector<int> vec;
    TreeNode *cur = root;
    while (cur || !stk.empty()) {
      if (cur) {
        stk.push(cur);
        cur = cur->_left;

      } else {
        vec.push_back(stk.top()->_val);
        cur = stk.top()->_right;
        stk.pop();
      }
    }
    return vec;
  }
};
int main() { return 0; }
