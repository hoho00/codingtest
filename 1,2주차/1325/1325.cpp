#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 
int N, M;
vector<int> g[100001];
vector<int> ans(100001);
int visited[10001];

int DFS(int node) {
  visited[node] = 1;
  int ret = 1;
  for (auto e : g[node]) {
    if (visited[e]) continue;
    ret += DFS(e);
  }
  return ret;
}
bool compare(int& a, int& b) {
  return a > b;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;
    g[to].push_back(from);
  }
  int maxValue = 0;
  for (int i = 1; i <= N; i++) {
    fill(&visited[0], &visited[0] + 10001, 0);
    //memset(visited, 0, sizeof(visited));
    ans[i] = DFS(i);
    maxValue = max(maxValue, ans[i]);
  }
  
  // for (int i = 1; i <= N; i++) {
  //   maxValue = max(maxValue, ans[i]);
  // }
  // for (int i = 1; i <= N; i++) {
  //   if (ans[i] == maxValue) cout << i << " ";
  // }
  //cout << maxValue << endl;
  for (int i = 1; i <= N; i++) {
    if (ans[i] == maxValue) cout << i << " ";
  }

  return 0;
}