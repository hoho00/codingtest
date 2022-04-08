#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPattern(string str, vector<string>& pattern) {
  int minSize = 0;
  for (auto e : pattern) minSize += e.size();
  if (str.size() < minSize) return false;
  
  // for (int i = 0; i < pattern[0].size(); i++) {
  //   if (str[i] != pattern[0][i]) {
  //     //cout << i << " : " << str[i] << " " << pattern[0][i] << endl;
  //     return false;
  //   }
  // }

  string pre = str.substr(0, pattern[0].size());
  string suf = str.substr(str.size() - pattern[1].size());
  if (pre == pattern[0] && suf == pattern[1]) return true;
  return false;

  // for (int i = 0; i < pattern[1].size(); i++) {
  //   if (str[str.size() - 1 - i] != pattern[1][pattern[1].size() - 1 - i]) {
  //     //cout << i << " : " << str[str.size() - 1 - i] << " " <<pattern[1][pattern[1].size() - 1 - i] << endl;
  //     return false;
  //   }
  // }
  // return true;

}

vector<string> getPatternVector(string pattern) {
  vector<string> ret;
  int pos = pattern.find('*');
  string pre = pattern.substr(0, pos);
  string suf = pattern.substr(pos + 1);
  ret.push_back(pre);
  ret.push_back(suf);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "rt", stdin);

  int N;
  string pattern;
  cin >> N;
  cin >> pattern;
  vector<string> patterns = getPatternVector(pattern);

  //for (auto e : patterns) cout << e << endl;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (isPattern(s, patterns)) cout << "DA" << '\n';
    else cout << "NE" << '\n';
  }

  return 0;
}