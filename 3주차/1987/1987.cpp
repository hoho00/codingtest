#include <iostream> 

using namespace std; 
char field[24][24];
int m[30];

int H, W, ans = 0;
int dh[] = {-1, 0, 1, 0};
int dw[] = {0, 1, 0, -1};

void DFS(int h, int w, int cnt) {
  if (ans <= cnt) ans = cnt;
  for (int i = 0; i < 4; i++) {
    int newH = h + dh[i];
    int newW = w + dw[i];
    if (newH < 0 || newH >= H || newW < 0 || newW >= W) continue;
    int next = (int)(field[newH][newW] - 'A');
    if (m[next] == 0) {
      m[next] = 1;
      DFS(newH, newW, cnt + 1);
      m[next] = 0;
    }
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
  m[(int)(field[0][0] - 'A')] = 1;
  DFS(0, 0, 1);
  cout << ans;
  return 0;
}