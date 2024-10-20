#include <cstdio>
#include <string.h>

void *MyMemcpy(void *dest, const void *src, int count) {
  char *pdest = (char *)dest;
  const char *psrc = (const char *)src;
  for (int i = 0; i < count; i++) {
    pdest[i] = psrc[i];
  }
  return dest;
}

int main() {
  const char *src = "hello world";
  char dest[128] = {0};
  void *rest = MyMemcpy(dest, src, strlen(src));
  printf("rest : %s\n", dest);
  return 0;
}
