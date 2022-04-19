#include <iostream> 
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std; 

int N;
int field[14];
vector<int> conn[14];
int area[14];
int check[14];
int ans = 987654321;

pair<int, int> DFS(int L, int a) {
  check[L] = 1;
  pair<int, int> ret = {field[L], 1};
  for (auto there : conn[L]) {
    if (area[there] != a) continue;
    if (check[there]) continue;
    pair<int, int> thereValue = DFS(there, a);
    ret.first += thereValue.first;
    ret.second += thereValue.second;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> field[i];
  }

  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    for (int j = 0; j < num; j++) {
      int tmp;
      cin >> tmp;
      conn[i].push_back(tmp);
      conn[tmp].push_back(i);
    }
  }
  for (int i = 1; i < (1 << (N)) - 1; i++) {
    fill(&area[0], &area[0] + 14, 0);
    fill(&check[0], &check[0] + 14, 0);
    int team1 = -1, team2 = -1;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        area[j + 1] = 1;
        team1 = j + 1;
      }
      else {
        team2 = j + 1;
      }
    }
    pair<int, int> comp1 = DFS(team1, 1);
    pair<int, int> comp2 = DFS(team2, 0);
    if (comp1.second + comp2.second == N) {
      ans = min(ans, abs(comp1.first - comp2.first));
    }
  }
  if (ans == 987654321) {
    cout << "-1";
    return 0;
  }
  cout << ans;
  return 0;
}