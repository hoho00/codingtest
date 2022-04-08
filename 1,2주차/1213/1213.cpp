#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string getAnswer(string s) {
  sort(s.begin(), s.end());
  map<char, int> m;
  string ans;
  
  for (int i = 0; i < s.size(); i++) {
    m[s[i]] ++;
  }
  int oddCount = 0;
  char oddChar = ' ';
  for (auto e : m) {
    if (e.second % 2 == 1) {
      oddCount ++;
      oddChar = e.first;
    }
  }
  if (oddCount > 1) {
    return "I'm Sorry Hansoo";
  }
  for (auto e : m) {
    string tmp = "";
    for (int i = 0; i < e.second / 2; i++) {
      ans += e.first;
    }
  }
  string rev = ans;
  reverse(rev.begin(), rev.end());
  if (oddCount == 1) ans += oddChar;
  return ans + rev;

  return ans;

}

int main()
{
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "rt", stdin);
  string s;
  cin >> s;
  cout << getAnswer(s);
  return 0;
}