#include <queue>
#include <vector>

using std::queue;
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

vector<vector<int>> LevelorderTraversal(TreeNode *root) {
  queue<TreeNode *> que;
  vector<vector<int>> result;
  que.push(root);
  while (root) {
    vector<int> vec;
    int sz = que.size();
    while (sz--) {
      TreeNode *node = que.front();
      que.pop();
      vec.push_back(node->_val);
      if (node->_left) {
        que.push(node->_left);
      }

      if (node->_right) {
        que.push(node->_right);
      }
    }
    result.push_back(vec);
  }
  return result;
}

int main() {
  TreeNode node5(5, nullptr, nullptr);
  TreeNode node3(3, nullptr, nullptr);
  TreeNode node4(4, nullptr, nullptr);
  TreeNode node2(2, &node4, &node5);
  TreeNode root(1, &node2, &node3);

  LevelorderTraversal(&root);

  return 0;
}
