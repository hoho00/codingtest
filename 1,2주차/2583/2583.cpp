#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int H, W, K, ans = 0, cnt = 0;
vector<int> v;

int field[101][101];
int check[101][101];

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

int DFS(int h, int w) {
  check[h][w] = 1;
  int ret = 1;
  for (int i = 0; i < 4; i++) {
    int newH = h + dh[i];
    int newW = w + dw[i];
    if (newH < 0 || newH >= H || newW < 0 || newW >= W || field[newH][newW] == 1 || check[newH][newW] == 1) continue;
    ret += DFS(newH, newW);
  }
  return ret;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   freopen("input.txt", "rt", stdin);

   cin >> H >> W >> K;
   
   for (int k = 0; k < K; k++) {
     int w1, h1, w2, h2;
     cin >> w1 >> h1>> w2 >> h2;
     for (int i = h1; i < h2; i++) {
       for (int j = w1; j < w2; j++) {
         field[i][j] = 1;
       }
     }
   }

   for (int i = 0; i < H; i++) {
     for (int j = 0; j < W; j++) {
       if (field[i][j] == 0 && check[i][j] == 0) {
         v.push_back(DFS(i, j));
         cnt = 0;
         ans++;
       }
     }
   }
   cout << ans << endl;
   sort(v.begin(), v.end());
   for (auto e : v) cout << e << " ";

   return 0;
}