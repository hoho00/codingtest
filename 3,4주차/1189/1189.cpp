#include <iostream> 
#include <string>
#include <vector>

using namespace std; 

vector<string>field;
int H, W, K, ans = 0;
int check[7][7];

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void go(int h, int w, int cnt) {
  if (h == 0 && w == W - 1 && cnt == K) {
    ans ++;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int newH = h + dh[i];
    int newW = w + dw[i];
    if (newH < 0 || newH >= H || newW < 0 || newW >= W || check[newH][newW] != 0 || field[newH][newW] == 'T') continue;
    check[newH][newW] = 1;
    go(newH, newW, cnt + 1);
    check[newH][newW] = 0;
  }
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
  go(H - 1, 0, 1);
  cout << ans;


  return 0;
}