#include <iostream> 
#include <vector>

using namespace std; 

int H, W, ans = 0, cnt = 0;
int field[101][101];
int airCheck[101][101];

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};


void DFS(int h, int w) {
  airCheck[h][w] = 1;
  for (int i = 0; i < 4; i++) {
    int newH = h + dh[i];
    int newW = w + dw[i];
    if (newH < 0 || newH >= H || newW < 0 || newW >= W || field[newH][newW] == 1 || airCheck[newH][newW] == 1) continue;
    DFS(newH, newW);
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
    }
  }
  DFS(0, 0);
  vector<pair<int, int>> airTouch;

  while(1) {
    // for (int i = 0; i < H; i++) {
    //   for (int j = 0; j < W; j++) {
    //     cout << field[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    bool flag = false;
    for (int i = 1; i < H - 1; i++) {
      for (int j = 1; j < W - 1; j++) {
        if (field[i][j] == 1) {
          flag = true;
        }
      }
    }
    if (!flag) break;
    cnt = 0;
    airTouch.clear();
    DFS(0, 0);
    for (int i = 1; i < H - 1; i++) {
      for (int j = 1; j < W - 1; j++) {
        if (field[i][j] == 1) {
          cnt++;
          for (int d = 0; d < 4; d ++) {
            int newH = i + dh[d];
            int newW = j + dw[d];
            if (airCheck[newH][newW] == 1) {
              airTouch.push_back({i, j});
              break;
            }
          }
        }
      }
    }
    for (auto e: airTouch) {
      field[e.first][e.second] = 0;
      //airCheck[e.first][e.second] = 1;
    }
    fill(&airCheck[0][0], &airCheck[0][0] + 100 * 100, 0);
    ans++;

    
  }
  cout << ans << endl << cnt;
  return 0;
}