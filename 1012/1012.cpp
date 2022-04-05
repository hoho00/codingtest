#include <iostream> 

using namespace std; 

int field[51][51];
int visited[51][51];

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void DFS(int h, int w, int hsize, int wsize) {
  visited[h][w] = 1;
  for (int i = 0; i < 4; i++) {
    int newH = h + dh[i];
    int newW = w + dw[i];
    if (newH < 0 || newH >= hsize || newW < 0 || newW >= wsize || visited[newH][newW] != 0 || field[newH][newW] == 0) continue;
    DFS(newH, newW, hsize, wsize);
  }
  return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   freopen("input.txt", "rt", stdin);

   int T;
   cin >> T;

   while(T--) {
     int W, H, K, count = 0;
     cin >> W >> H >> K;
     fill(&field[0][0], &field[0][0] + 51 * 51, 0);
     fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

     for (int i = 0 ; i < K; i++) {
       int w, h;
       cin >> w >> h;
       field[h][w] = 1;
       //visited[h][w] = 1;
     }

     for (int i = 0; i < H; i++) {
       for (int j = 0; j < W; j++) {
         if (field[i][j] == 1 && visited[i][j] == 0) {
           DFS(i, j, H, W);
           count++;
         }
       }
     }
     cout << count << '\n';
   }
   return 0;
}