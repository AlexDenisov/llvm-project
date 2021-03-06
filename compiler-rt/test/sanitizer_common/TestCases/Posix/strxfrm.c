// RUN: %clang -O0 %s -o %t && %run %t
// UNSUPPORTED: darwin

#include <assert.h>
#include <locale.h>
#include <wchar.h>

int main(int argc, char **argv) {
  char q[10];
  size_t n = strxfrm(q, "abcdef", sizeof(q));
  assert(n < sizeof(q));

  char q2[10];
  locale_t loc = newlocale(LC_ALL_MASK, "", (locale_t)0);
  n = strxfrm_l(q2, L"qwerty", sizeof(q), loc);
  assert(n < sizeof(q2));

  freelocale(loc);
  return 0;
}
