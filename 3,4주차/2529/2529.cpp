#include <iostream> 
#include <algorithm>
#include <vector>
#include <string>

using namespace std; 

int N;
vector<char> s;
vector<string> ans;
int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int check[10];

bool compare(char c, int a, int b) {
  if (c == '<') {
    return a < b;
  }
  if (c == '>') {
    return a > b;
  }
  return false;
}

void go(int L, string str) {
  if (str.size() == N + 1) {
    ans.push_back(str);
    return;
  }
  if (L > 10) return;
  go(L + 1, str);
  for (int i = 0; i < 10; i++) {
    if (check[i] == 1) continue;
    if (L == 0 || compare(s[L - 1], (int)(str.back() - '0'), a[i])) {
      check[i] = 1;
      go(L + 1, str + (char)(a[i] + '0'));
      check[i] = 0;
    }
  }
  
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  for (int i = 0; i < N; i++) {
    char tmp;
    cin >> tmp;
    s.push_back(tmp);
  }
  go (0, "");
  sort(ans.begin(), ans.end());
  // for (auto e : ans) {
  //   cout << e << endl;
  // }
  cout << ans.back() << endl << ans[0];
  return 0;
}