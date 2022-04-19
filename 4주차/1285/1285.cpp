#include <iostream> 
#include <string>
#include <bitset>
#include <cmath>
#include <queue>

using namespace std; 
int N;
string s = "";
int field = 0x0;
int check[2][24];
int allOne = pow(2, 21) - 1;
int allZero = 0;
int ans = 987654321;
int colFilpper = 0;
int rowFlipper = 0;
queue<pair<int, int>> q;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

int flip(int h, int w, int status) {
  //row 뒤집기
  if (h == 0) {
    int tRowFlipper = rowFlipper;
    tRowFlipper = tRowFlipper >>(w * N);
    status = status ^ tRowFlipper;
    return status;
  }
  //col 뒤집기
  else {
    int tColFlipper = colFilpper;
    tColFlipper = tColFlipper >> (w);
    //cout << bitset<9>(tColFlipper) << endl;
    status = status ^ tColFlipper;
    return status;
  }
}

void DFS(int h, int w, int status, int cnt, int visitCount) {
  cout << bitset<9>(status) << endl;
  if (visitCount > N * N) return;
  if (h < 0 || h >= 2 || w < 0 || w >= N) return;
  if (((status | allZero) == allZero) || ((status & allOne) == allOne)) {
    ans = min(ans, cnt);
    return;
  }
  if (w + 1 < N) {
    DFS(h, w + 1, status, cnt, visitCount + 1);
  }
  DFS((h + 1) % 2, w, status, cnt, visitCount + 1);
  if (check[h][w] == 0) {
    check[h][w] = 1;
    int tmp = flip(h, w, status);
    if (w + 1 < N) {
      DFS(h, w + 1, tmp, cnt + 1, visitCount + 1);
    }
    DFS((h + 1) % 2, w, tmp, cnt + 1, visitCount + 1);
    check[h][w] = 0;
  }
  
  return;
}


void makeFlipper() {
  rowFlipper = pow(2, N) - 1;
  rowFlipper = rowFlipper << (N * 2);
  int tmp = pow(2, N - 1);
  for (int i = 0; i < N - 1; i++) {
    colFilpper += tmp;
    colFilpper <<= N;
  }
  colFilpper += tmp;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;

  for (int i = 0; i < 3; i++) {
    string tmp;
    cin >> tmp;
    s += tmp;
  }
  int c = 0x1;
  for (int i = s.size() - 1; i >= 0; i --) {
    if (s[i] == 'T') {
      field |= c;
    }
    c = c << 1;
  }
  makeFlipper();
  for (int i = 0; i <2; i++) {
    for (int j = 0; j < N; j++) {
      fill(&check[0][0], &check[0][0] + 2 * N, 0);
      DFS(i, j, field, 0, 0);
    }
  }
  //DFS(0, 0, field, 0);

  //cout << bitset<9>(flip(1, 2, field)) << endl;
  cout << ans;
  //cout << ((| allZero) == allZero) << endl;
  //cout << bitset<9>(field) << endl;
  return 0;
}