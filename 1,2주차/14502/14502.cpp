#include <iostream> 
#include <vector>
#include <queue>

using namespace std; 
int H, W;
int field[10][10];
int check[10][10];
queue<pair<int, int>>q;
vector<pair<int, int>>v;
vector<vector<pair<int, int>>> sortOfWalls;
vector<pair<int, int>> originWalls;
int ans = 0;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};


void BFS() {
  while(!q.empty()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    //check[h][w] = 1;

    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || check[newH][newW] > 0 || field[newH][newW] == 1 || field[newH][newW] == 2) continue;
      q.push({newH, newW});
      check[newH][newW] = check[h][w] + 1;
    }
  }
}
void DFS(int L, vector<pair<int, int>> t) {
  if (L > v.size()) return ;
  if (t.size() == 3) {
    sortOfWalls.push_back(t);
    return;
  }
  DFS(L + 1, t);
  t.push_back(v[L]);
  DFS(L + 1, t);
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> H >> W;
  for (int i = 0; i < H; i ++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
      if (field[i][j] == 2) {
        q.push({i, j});
        originWalls.push_back({i, j});
      }
      else if (field[i][j] == 0) {
        v.push_back({i, j});
      }
    }
  }
  // field[0][1] = 1;
  // field[1][0] = 1;
  // field[3][5] = 1;
  //for (auto e: v) cout << e.first << " " << e.second << endl;
  vector<pair<int, int>> p;
  DFS(0, p);

  for (auto e : sortOfWalls) {
    for (auto k : e) {
      field[k.first][k.second] = 1;
    }
    fill(&check[0][0], &check[0][0] + 10 * 10, 0);
    for (auto k : originWalls) {
      check[k.first][k.second] = 1;
      q.push({k.first, k.second});
    }
    BFS();
    int cnt = 0;
    for (int i = 0; i < H; i ++) {
      for (int j = 0; j < W; j++) {
        if (field[i][j] == 0 && check[i][j] == 0) {
          cnt++;
        }
      }
    }
    ans = max(ans, cnt);
    for (auto k : e) {
      field[k.first][k.second] = 0;
    }
  }

  // for (int i = 0; i < H; i ++) {
  //   for (int j = 0; j < W; j++) {
  //     cout << check[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << ans;
  return 0;
}