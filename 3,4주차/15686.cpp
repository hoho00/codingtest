#include <iostream> 
#include <vector>
#include <queue>
#include <cmath>

using namespace std; 

int N, M, ans = 987654321;

int field[54][54];
int check[54][54];
queue<pair<int, int>>q;

vector<pair<int, int>> chicken;

vector<pair<int, int>> home;

vector<vector<pair<int, int>>> chosen;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void DFS(int L, vector<pair<int, int>> p) {
  if (L > chicken.size()) return;
  if (p.size() == M) {
    chosen.push_back(p);
    return;
  }
  DFS(L + 1, p);
  p.push_back(chicken[L]);
  DFS(L + 1, p);
}

int getDis(int h, int w, vector<pair<int, int>> cs) {
  int ret = 987654321;
  for (auto e : cs) {
    int dis = abs(e.first - h) + abs(e.second - w);
    ret = min(ret, dis);
  }
  return ret;
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> field[i][j];
      if (field[i][j] == 2){ 
        chicken.push_back({i, j});
        //field[i][j] = 0;
      }
    }
  }

  vector<pair<int, int>> tmp;
  DFS(0, tmp);

  for (auto e: chosen) {
    int minDis = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (field[i][j] == 1) {
          minDis += getDis(i, j, e);
        }
      }
    }
    ans = min(ans, minDis);
    // cout << endl;
  }

  cout << ans;


  return 0;
}