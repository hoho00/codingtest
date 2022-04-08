#include <iostream>
#include <string>
#include <vector>

using namespace std; 
vector<string> field;
int check[6][6];

int H, W, K, cnt = 0;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

int DFS(int h, int w) {
  int ret = 0;
  if (h == 0 && w == W - 1) {
    if (check[h][w] == K) return 1; 
    else return 0;
  }
  for (int i = 0; i < 4; i++) {
    int newH = h + dh[i];
    int newW = w + dw[i];
    if (newH < 0 || newH >= H || newW < 0 || newW >= W || field[newH][newW] == 'T' || check[newH][newW] != 0) continue;
    check[newH][newW] = check[h][w] + 1;
    ret += DFS(newH, newW);
    check[newH][newW] = 0;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> H >> W >> K;
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    field.push_back(s);
  }
  check[H - 1][0] = 1;
  cout << DFS(H - 1, 0);


  return 0;
}