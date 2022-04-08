#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N;
  cin >> N;
  map<string, int> lastNameMap;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int maxLastName = 30;
    maxLastName = min(maxLastName, (int)s.size());
    string lastName = "";
    for (int i = 0; i < maxLastName; i++) {
      lastName += s[i];
      lastNameMap[lastName] ++ ;
    }
  }
  string answer = "";
  for (auto e : lastNameMap) {
    if (e.second >= 5) answer += e.first;
  }

  if (answer == "") cout << "PREDAJA";
  else cout << answer;

  return 0;
}