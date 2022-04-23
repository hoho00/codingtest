#include <iostream> 
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std; 

int T;

deque<int> makeVector(string str) {
  deque<int> ret;
  int a = 0;
  for (auto e : str) {
    if (e == '[' || e == ']') continue;
    if (e >= '0' &&  e <= '9') a = a* 10 + (e - '0');
    else {
      if (a > 0) ret.push_back(a);
      a = 0;
    }
  }
  ret.push_back(a);
  return ret;
}

void makeAnswer(deque<int> v, bool isRight) {
  cout << '[';
  if (isRight) {
    while(!v.empty()) {
      cout << v.front();
      if (v.size() != 1) cout << ',';
      v.pop_front();
    }
  }
  else {
    reverse(v.begin(), v.end());
     while(!v.empty()) {
      cout << v.front();
      if (v.size() != 1) cout << ',';
      v.pop_front();
    }
  }
  cout << "]\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> T;

  while (T > 0) {
    string s, field;
    int N;
    cin >> s;
    cin >> N;
    cin >> field;
    if (N == 0) {
      bool isError = false;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] =='D') {
          isError = true;
          break;
        }
      }
      if (!isError)cout << "[]" << '\n';
      else cout << "error" << '\n';
    }
    else {
      bool isError = false;
      bool isRight = true;
      deque<int> v = makeVector(field);
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
          isRight = !isRight;
        }
        else if (s[i] == 'D') {
          if (v.empty()) {
            isError = true;
            break;
          }
          if (isRight) {
            v.pop_front();
          }
          else {
            v.pop_back();
          }
        }
      }
      if (isError) cout << "error" << '\n';
      else {
        makeAnswer(v, isRight);
      }
    }
    
    T--;
  }
  return 0;
}