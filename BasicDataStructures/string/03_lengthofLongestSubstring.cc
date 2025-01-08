// base std::string

#include <algorithm>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

int lengthOfLongestSubstring(string s) {
  unordered_set<char> charset;
  int left = 0;
  int maxLen = 0;
  for (int right = 0; right < s.size(); right++) {
    while (charset.find(s[right]) != charset.end()) {
      charset.erase(s[left]);
      left++;
    }
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
