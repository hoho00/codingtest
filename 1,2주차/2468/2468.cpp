#include <iostream> 

using namespace std; 
int N, ans = 0;
int minValue = 9999;
int maxValue = 0;
int field[101][101];
int check[101][101];

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void DFS(int h, int w, int v) {
  check[h][w] = 1;
  for (int i = 0; i < 4; i++) {
    int newH = h + dh[i];
    int newW = w + dw[i];
    if (newH < 0 || newH >= N || newW < 0 || newW >= N || check[newH][newW] == 1 || field[newH][newW] <= v) continue;
    DFS(newH, newW, v);
  }
  return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   freopen("input.txt", "rt", stdin);

   cin >> N;
   for (int i = 0; i < N; i++) {
     for (int j = 0; j < N; j++) {
       cin >> field[i][j];
       minValue = min(minValue, field[i][j]);
       maxValue = max(maxValue, field[i][j]);
     }
   }

   for (int v = 0; v <= maxValue; v++) {
     int cnt = 0;
     fill(&check[0][0], &check[0][0] + 101 * 101 , 0);
     for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
         if (field[i][j] > v && check[i][j] == 0) {
           DFS(i, j, v);
           cnt++;
         }
       }
     }
     ans = max(ans, cnt);
   }

   cout << ans;


   return 0;
}