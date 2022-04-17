#include <iostream>
#include <string>
#include <vector> 
#include <queue>

using namespace std; 

int H, W, ans = 0;
vector<string> field;
int check[51][51];
queue<pair<int, int>> q;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

int getLogestDis(int curH, int curW) {
  int ret = 0;
  fill(&check[0][0], &check[0][0] + 51 * 51, 0);
  q.push({curH, curW});
  check[curH][curW] = 1;
  while (!q.empty()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || check[newH][newW] != 0  || field[newH][newW] != 'L') continue;
      q.push({newH, newW});
      check[newH][newW] = check[h][w] + 1;
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ret = max(ret, check[i][j]);
    }
  }
  return ret - 1;
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
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (field[i][j] == 'L') {
        ans = max(ans, getLogestDis(i, j));
      }
    }
  }

  cout << ans;

  return 0;
}