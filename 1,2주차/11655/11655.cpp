#include <iostream>
#include <string>

using namespace std;

int main() 
{
  string s;
  string answer = "";

  freopen("input.txt", "rt", stdin);
  getline(cin, s);



  for (int i = 0; i < s.size(); i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
      if (toupper(s[i]) == s[i]) {
        int moving = (s[i] - 'A' + 13) % 26;
        //cout << (char)('A' + moving) << endl;
        answer += (char)('A' + moving);
      }
      else {
        int moving = (s[i] - 'a' + 13) % 26;
        //cout << moving << endl;
        answer += (char)('a' + moving);
      }
    }
    else {
      answer += s[i];
    }
  }
  cout << answer;

  return 0;
}