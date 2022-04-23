#include <iostream> 
#include<string>

using namespace std; 

string s;
int check[5004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> s;
  bool ok = true;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'p') {
      check[i] = 1;
      if (i + 1 >= s.size()) {
        ok = false;
        break;
      }
      if (s[i + 1] != 'i') {
        ok = false;
        break;
      }
      check[i + 1] = 1;
    }
    else if (s[i] == 'k') {
      check[i] = 1;
      if (i + 1 >= s.size()) {
        ok = false;
        break;
      }
      if (s[i + 1] != 'a') {
        ok = false;
        break;
      }
      check[i + 1] = 1;
    }
    else if (s[i] == 'c') {
      check[i] = 1;
      if (i + 2 >= s.size()) {
        ok = false;
        break;
      }
      if (s[i + 1] != 'h') {
        ok = false;
        break;
      }
      if (s[i + 2] != 'u') {
        ok = false;
        break;
      }
      check[i + 1] = check[i + 2] = 1;
    }
  }
  if (ok) {
    for (int i = 0; i < s.size(); i++) {
      if (check[i] == 0) {
        ok =false;
        break;
      }
    }
  }
  
  if (ok) cout << "YES";
  else cout << "NO";

  return 0;
}