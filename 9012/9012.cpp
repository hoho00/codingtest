#include <iostream> 
#include <stack>
#include <vector>
#include <string>

using namespace std; 

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N;
  vector<char> v;
  
  cin >> N; 

  for (int t = 0; t < N; t++) {
    string s;
    cin >> s;
    stack<char> st;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] =='(') {
        st.push('(');
      }
      else {
        if (st.empty()) {
          cout << "NO" << '\n';
          flag = true;
          break;
        }
        else {
          st.pop();
        }
      }
    }
    if (!flag) {
      if (st.empty()) {
        cout << "YES" << '\n';
      }
      else {
        cout << "NO" << '\n';
      }
    }
  }


  return 0;
}