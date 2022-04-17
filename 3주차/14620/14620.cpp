#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int field[14][14];
int check[14][14];
int N, ans = 987654321;
vector<pair<int, int>> v;
int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};


void pick(int L, vector<pair<int, int>> b) {
  if (L > v.size()) return;
  if (b.size() == 3) {
    fill(&check[0][0], &check[0][0] + 14 * 14, 0);
    bool isok = true;
    for (auto e : b) {
      if (check[e.first][e.second]) {
        isok = false;
        break;
      }
      check[e.first][e.second] = 1;
      for (int i = 0; i < 4; i++) {
        int newH = e.first + dh[i];
        int newW = e.second + dw[i];
        if (check[newH][newW]) {
          isok = false;
          break;
        }
        check[newH][newW] = 1;
      }
      if(!isok) break;
    }
    if (isok) {
      int sum = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (check[i][j] == 1) {
            sum += field[i][j];
          }
        }
      }
      ans = min(ans, sum);
    }
    return;
  }
  pick(L + 1, b);
  b.push_back(v[L]);
  pick(L + 1, b);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> field[i][j];
    }
  }
  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < N - 1; j++) {
      v.push_back({i, j});
    }
  }
  vector<pair<int, int>> tmp;
  pick(0, tmp);
  cout << ans;
  return 0;
}