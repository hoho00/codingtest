#include <iostream> 
#include <vector>
#include <string>

using namespace std; 

int N, K, pick = 0, ans = 0;

int check[26];

vector<string> words;

void DFS(int L, int cnt, vector<int> v) {
  if (L > 26) return;
  if (cnt == pick) {
    int curCount = 0;
    for (auto e : words) {
      bool flag = true;
      for (int i = 0; i < e.size(); i++) {
        if (check[e[i] - 'a'] == 0) {
          flag = false;
          break;
        }
      }
      if (flag) curCount++;
      //cout << e << " : " << flag << endl;
    }
    ans = max(ans, curCount);
    return;
  }
  DFS(L + 1, cnt, v);
  if (check[L] == 0) {
    check[L] = 1;
    v.push_back(L);
    DFS(L + 1, cnt + 1, v);
    check[L] = 0;
  }

}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> K;
  pick = K - 5;
  if (K < 5) {
    cout << "0";
    return 0;
  }
  check['a' - 'a'] = 1;
  check['n' - 'a'] = 1;
  check['t' - 'a'] = 1;
  check['i' - 'a'] = 1;
  check['c' - 'a'] = 1;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    words.push_back(s);
  }
  // for (int i = 0; i < 25; i++) cout << check[i] << " ";

  vector<int> tmp;
  DFS(0, 0, tmp);

  cout << ans;

  return 0;
}