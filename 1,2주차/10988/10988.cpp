#include <iostream>
#include <string>

using namespace std;

bool isPellin(string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 -i]) return false;
  }
  return true;
}

int main()
{
  freopen("input.txt", "rt", stdin);
  string s;
  cin >> s;

  cout << isPellin(s);

  return 0;
}