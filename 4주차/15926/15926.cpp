#include <iostream>
#include <string> 
#include <map>
#include <stack>
#include <vector>

using namespace std; 

int N, ans = 0;
string s;
stack<int> st;
map<string, int> m;
map<int, string> mIndex;

int check[200004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;
  cin >> s;
  

  for (int i = 0; i < N; i++) {
    if (s[i] == '(') {
      st.push(i);
    }
    else if (s[i] == ')') {
      if (!st.empty()) {
        check[st.top()] = 1;
        check[i] = 1;
        st.pop();
      }
    }
  }
  int sum = 0;

  for (int i = 0; i < N; i++) {
    //cout << check[i] << " ";
    if (check[i] == 1) {
      sum ++;
    }
    else {
      ans = max (ans, sum);
      sum = 0;
    }
  }
  ans = max(ans, sum);
  cout << ans;
  return 0;
}