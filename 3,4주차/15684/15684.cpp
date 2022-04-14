#include <iostream> 
#include <vector>

using namespace std; 

int N, M, H;

int ladder[34][34];

vector<pair<int, int>> v;
bool ok = false;


//ladder[세로선][가로선]
int isCorrect(int l, int m) {
  for (int i = m + 1; i <= H; i++) {
    if (ladder[l][i] != 0) {
      return isCorrect(ladder[l][i], i);
    }
  }
  return l;
}

bool isRightLadder() {
  for (int i = 1; i <= N; i++) {
    if (isCorrect(i, 0) != i) return false;
  }
  return true;
}

void pick(int L, int cnt, vector<pair<int, int>> p) {
  if (L > v.size()) return;
  if (p.size() == cnt) {
    for (auto e : p) {
      ladder[e.first][e.second] = e.first + 1;
      ladder[e.first + 1][e.second] = e.first;
    }
    if (isRightLadder()) {
      ok = true;
      return;
    }
    for (auto e : p) {
      ladder[e.first][e.second] = 0;
      ladder[e.first + 1][e.second] = 0;
    }
    return;
  }
  pick(L + 1, cnt, p);
  p.push_back(v[L]);
  pick(L + 1, cnt, p);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M >> H;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    ladder[b][a] = b + 1;
    ladder[b + 1][a] = b;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= H; j++) {
      if (ladder[i][j] == 0 && ladder[i + 1][j] == 0) {
        v.push_back({i, j});
      }
    }
  }
  if (isRightLadder()) {
    cout << "0" ;
    return 0;
  }
  if (M == 0) {
    cout << "0";
    return 0;
  }
  if(v.size() == 0) {
    cout << "-1";
    return 0;
  }
  int maxFind = 3;
  //cout << v.size() << endl;
  //if (maxFind > v.size()) maxFind = v.size();
  for (auto e : v) {
    ladder[e.first][e.second] = e.first + 1;
    ladder[e.first + 1][e.second] = e.first;
    if (isRightLadder()) {
      cout << "1";
      return 0;
    }
    ladder[e.first][e.second] = 0;
    ladder[e.first + 1][e.second] = 0;
  }
  for (int i = 2; i <= 3; i ++) {
    vector<pair<int, int>> tmp;
    pick(0, i, tmp);
    if (ok) {
      cout << i;
      return 0;
    }
  }

  cout << "-1";
  return 0;
}