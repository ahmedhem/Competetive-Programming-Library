#include <algorithm>
#include <iostream>
#include <string>

bool good(const std::string& s) {
  for (int i = 1; s[i]; ++i) {
    if (s[i] == s[i - 1]) return false;
  }
  return true;
}

int main() {
  std::string s = "000000111111111";
  int cnt = 0;
  do {
    if (good(s)) ++cnt;
  } while (std::next_permutation(s.begin(), s.end()));
  std::cout << cnt << std::endl;

  return 0;
}
