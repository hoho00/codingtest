#include <iostream> 
#include <queue>
#include <map>

using namespace std; 

int H, W;
int dh[] = {0, -1, 0, 1};
int dw[] = {-1, 0, 1, 0};
int check[54][54];
int field[54][54];
int maxSize = 0, ms = 0;
map<int, int>m;

queue<pair<int, int>> q;

void BFS(int room) {
  while(!q.empty()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || check[newH][newW] != 0) continue;
      if ((field[h][w] & (1 << i)) == 0) {
        q.push({newH, newW});
        check[newH][newW] = room;  
      }
    }
  }
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> W >> H;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
    }
  }
  //check[0][0] = 1;
  int r = 1;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (check[i][j] == 0) {
        check[i][j] = r;
        q.push({i, j});
        BFS(r);
        r++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      m[check[i][j]]++;
    }
  }
  for (auto e : m) {
    ms = max(ms, e.second);
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int k = 0; k < 4; k++) {
        int newH = i + dh[k];
        int newW = j + dw[k];
        if (newH < 0 || newH >= H || newW < 0 || newW >= W || check[i][j] == check[newH][newW]) continue;
        maxSize = max(maxSize, m[check[i][j]] + m[check[newH][newW]]);
      }
    }
  }
  cout << m.size() << endl;
  cout << ms << endl;
  cout << maxSize;
  return 0;
}