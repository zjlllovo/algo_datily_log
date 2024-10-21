#include <iostream>

using std::cout;
using std::endl;

int My_Strlen(const char *var) {
  const char *pstr = var;
  int cnt = 0;
  while (*pstr != '\0') {
    pstr++;
    cnt++;
  }
  return cnt;
}

int main() {
  char buf[] = "hello world";
  int cnt = My_Strlen(buf);
  cout << cnt << endl;
  return 0;
}
