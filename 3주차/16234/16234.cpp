#include <iostream> 
#include <queue>
#include <cmath>

using namespace std; 

int N, L, R, days = 0;
int field[51][51];
int check[51][51];
queue<pair<int, int>>q;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void BFS() {
  vector<pair<int, int>> open;
  int ret = 0;
  while(!q.empty()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    open.push_back({h, w});
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= N || newW < 0 || newW >= N || check[newH][newW] != 0) continue;
      if (abs(field[newH][newW] - field[h][w]) <= R && abs(field[newH][newW] - field[h][w]) >= L) {
        q.push({newH, newW});
        check[newH][newW] = 1;
      }
    }
  }
  int p = 0;
  for (auto e : open) {
    p += field[e.first][e.second];
  }
  p = p / open.size();
  for (auto e : open) {
    field[e.first][e.second] = p;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0 ; j < N; j++) {
      cin >> field[i][j];
    }
  }
  while(1) {
    bool flag = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i < N - 1 && abs(field[i][j] - field[i + 1][j]) <= R && abs(field[i][j] - field[i + 1][j]) >= L) {
          flag = false;
          break;
        }
        if (j < N - 1 && abs(field[i][j] - field[i][j + 1]) <= R && abs(field[i][j] - field[i][j + 1]) >= L) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) break;

    fill(&check[0][0], &check[0][0] + 51 * 51, 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (check[i][j] == 0) {
          q.push({i, j});
          check[i][j] = 1;
          BFS();
        }
      }
    }

    days++;
  }

  cout << days;
  return 0;
}