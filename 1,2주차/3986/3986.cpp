#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

bool isGoodWord(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (st.empty()) {
      st.push(s[i]);
    }
    else {
      if (st.top() == s[i]) {
        st.pop();
      }
      else {
        st.push(s[i]);
      }
    }
    
  }

  if (st.empty()) return true;
  return false;

  
 }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "rt", stdin);
  int N, count = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (isGoodWord(s)) count++;
  }

  cout << count;

  return 0;
}