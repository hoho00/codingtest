#include <iostream>
#include <string>

using namespace std;

int a[30];

int main()
{
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    cout << a[i] << " ";
  }
  return 0;
}