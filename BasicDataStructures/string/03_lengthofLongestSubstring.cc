// base std::string

#include <algorithm>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

int lengthOfLongestSubstring(string s) {
  unordered_set<char> charset; // charset作为窗口
  int left = 0;
  int maxLen = 0;
  for (int right = 0; right < s.size(); right++) { // 遍历s
    //---@ right:当前需要对比的字符的索引
    //---@ charset:窗口
    // 把当前字符s[right]和窗口内的字符逐一对比
    while (charset.find(s[right]) != charset.end()) {
      // 若窗口内已有s[right],滑动左窗口
      charset.erase(s[left]);
      left++;
    }
    // 若没有，滑动右窗口
    charset.insert(s[right]);
    maxLen = std::max(maxLen, right - left + 1);
  }
  return maxLen;
}

int main() {
  string s = "abcabcbb";
  cout << lengthOfLongestSubstring(s) << endl;
  return 0;
}
