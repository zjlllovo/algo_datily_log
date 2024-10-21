#include <assert.h>
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

int _My_Strlen_1(const char *var) {
  assert(var);
  if (!*var)
    return 0;
  else {
    return 1 + _My_Strlen_1(++var);
  }
}
int main() {
  char buf[] = "hello world";
  int cnt = _My_Strlen_1(buf);
  cout << cnt << endl;
  return 0;
}
