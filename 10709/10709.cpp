#include <iostream> 
#include <string>
#include <vector>

using namespace std; 

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    string s;
    vector<int> ans;
    cin >> s;
    bool hasCloud = false;
    for (int i = 0; i < W; i++) ans.push_back(-1);
    int firstCloud = s.find('c');
    if (firstCloud == string::npos) {
      for (auto e : ans) cout << e << " ";
      cout << '\n';
      continue;
    }
    for (int i = firstCloud; i < W; i++) {
      if (s[i] == 'c') {
        hasCloud = true;
        ans[i] = 0;
      }
      else {
        ans[i] = ans[i - 1] + 1;
      }
    }
    for (auto e : ans) cout << e << " ";
    cout << '\n';
  }

  return 0;
}