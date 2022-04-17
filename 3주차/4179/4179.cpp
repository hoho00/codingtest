#include <iostream> 
#include <queue>
#include <vector>
#include <string>
#include <climits>

using namespace std; 

int H, W;
vector<string> field;
int fireCheck[1001][1001];
int pCheck[1001][1001];
queue<pair<int, int>>q;
pair<int, int>p;
//pair<int, int>fire;
vector<pair<int, int>> fire;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void bfsFire() {
  
  while(!q.empty()) {
    int h = q.front().first;
    int w = q.front(). second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || fireCheck[newH][newW] != 0 || field[newH][newW] == '#')continue;
      fireCheck[newH][newW] = fireCheck[h][w] + 1;
      q.push({newH, newW});
    }
  }

}

void bfsPerson() {
  q.push(p);
  pCheck[p.first][p.second] = 1;
  while (!q.empty()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || pCheck[newH][newW] != 0 || field[newH][newW] == '#' || fireCheck[newH][newW] <= pCheck[h][w] + 1)continue;
      pCheck[newH][newW] = pCheck[h][w] + 1;
      q.push({newH, newW});
    }
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    field.push_back(s);
    for (int j = 0; j < W; j++) {
      if (s[j] == 'J') {
        p = {i, j};
      }
      if (s[j] == 'F') {
        fire.push_back({i, j});
      }
    }
  }

  if (fire.size()) {
    for (auto e : fire) {
      q.push(e);
      fireCheck[e.first][e.second] = 1;
    }
    bfsFire();
  }
  else {
    fill(&fireCheck[0][0], &fireCheck[0][0] + 1001 * 1001, INT_MAX);
  }
  bfsPerson();

  int minCount = INT_MAX;

  for (int i = 0; i < H; i++) {
    if (i == 0 || i == H - 1) {
      for (int j = 0; j < W; j++) {
        if (pCheck[i][j] != 0) {
          minCount = min(minCount, pCheck[i][j]);
        }
      }
    }
    else {
      if (pCheck[i][0] != 0) {
        minCount = min(minCount, pCheck[i][0]);
      }
      if (pCheck[i][W - 1] != 0) {
        minCount = min(minCount, pCheck[i][W - 1]);
      }
    }
  }
  if (minCount == INT_MAX) cout << "IMPOSSIBLE";
  else cout << minCount;
  return 0;
}