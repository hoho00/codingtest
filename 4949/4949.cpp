#include <iostream> 
#include <string>
#include <stack>

using namespace std; 

bool isPair(char c1, char c2) {
  if (c1 == '(' && c2 == ')') return true;
  if (c1 == '[' && c2 ==']') return true;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  while(1) {
    string s;
    
    getline(cin, s);
    if (s == ".") break;
    stack<char> st;
    int braceCount = 0;
    bool flag = false;
    //cout << s << endl;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '[') {
        st.push(s[i]);
        braceCount++;
      }
      else if (s[i] == ')' || s[i] ==']') {
        if (st.empty()) {
          cout << "no" << '\n';
          flag = true;
          break;
        }
        if (isPair(st.top(), s[i])) {
          //cout << "hit" << '\n';
          st.pop();
        }
        else {
          cout << "no" << '\n';
          flag = true;
          break;
        }
      }
    }
    if (!flag) {
      if (st.empty()) {
        cout << "yes" << '\n';
      }
      else {
        cout << "no" << '\n';
      }
    }
  }


  return 0;
}