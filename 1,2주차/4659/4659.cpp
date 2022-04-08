#include <iostream> 
#include <string>
#include <vector>
#include <stack>

using namespace std; 

string getAnswer(string str, bool isAccept) {
  string ret = "<";
  ret += str;
  ret += ">";
  if (isAccept) {
    return ret + " is acceptable.";
  }
  else {
    return ret + " is not acceptable.";
  }
}

bool isMoum(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  return false;
}

bool isValid(string str) {
  stack<char> st;
  st.push(str[0]);
  int mCount = 0;
  if (isMoum(str[0])) mCount++;
  for (int i = 1; i < str.size(); i++) {
    if (st.size() >= 3) return false;
    bool isM = isMoum(str[i]);
    if (isM) mCount ++;
    if (st.top() == str[i]) {
      if (st.top() == 'e' || st.top() == 'o') {}
      else return false;
    }
    if (isMoum(st.top()) == isM) {
      st.push(str[i]);
    }
    else {
      while(st.size()) st.pop();
      st.push(str[i]);
    }
  }
  if (st.size() >= 3) return false;
  if (mCount == 0) return false;
  return true;
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  while (1) {
    string input;
    cin >> input;
    if (input == "end") break;
    cout << getAnswer(input, isValid(input)) << '\n';
  }
  return 0;
}