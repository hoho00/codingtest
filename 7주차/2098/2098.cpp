#include <iostream> 

using namespace std; 

int N;
int dp[16][1 << 16];
int dis[16][16];

int tsp(int here, int visited) {
  if (visited == (1 << N) - 1) {
    if (dis[here][0] == 0) return 987654321;
    else return dis[here][0];
  }
   if (dp[here][visited] != -1) return dp[here][visited];
   int ret = 987654321;
   for (int i = 0; i < N; i++) {
     if (visited & (1 << i)) continue;
     if (dis[here][i] == 0) continue;
     dp[here][visited] = min(ret, tsp(i, visited | (1 << i)) + dis[here][i]);
     ret = dp[here][visited];
   }
   return ret;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> dis[i][j];
    }
  }
  int l = (int)(1 << 16);
  fill(&dp[0][0], &dp[0][0] + 16 * l, -1);
  cout << tsp(0, 1);

  return 0;
}