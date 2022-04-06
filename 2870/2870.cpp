#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std; 

typedef long long ll;

int N;

vector<string> v;

bool isNum(char c) {
  if (c >= '0' && c <= '9') return true;
  return false;
}

bool isZero(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '0') return false;
  }
  return true;
}

void extractNumber(string s) {
  string ret = "";
  for (int i = 0; i < s.size(); i++) {
    if (isNum(s[i])) {
      ret += s[i];
    }
    else {
      if (ret != "") {
        if (isZero(ret)) {
          v.push_back("0");
        }
        else {
          while(ret[0] == '0') {
            ret = ret.substr(1);
          }
          v.push_back(ret);
        }
      }
      ret = "";
    }
  }
  if (ret != "") {
    if (isZero(ret)) v.push_back("0");
    else {
      while(ret[0] == '0') {
        ret = ret.substr(1);
      }
      v.push_back(ret);
    }
  }
}

bool compare(string& s1, string &s2) {
  if (s1.size() == s2.size()) {
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] == s2[i]) continue;
      return s1[i] < s2[i];
    }
  }
  return s1.size() < s2.size();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    extractNumber(tmp);
  }
  if (v.size() > 0) sort (v.begin(), v.end(), compare);

  for (auto e : v) cout << e << '\n';

  return 0;
}