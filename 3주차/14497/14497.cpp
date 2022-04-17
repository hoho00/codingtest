#include <iostream> 
#include <string>
#include <vector>
#include <queue>


using namespace std; 

int H, W, ans = 0, cnt = 1, oneCount = 0;

bool isArrived = false;

pair<int ,int> jPoint;
pair<int, int> tPoint;
vector<string> field;
int check[304][304];
queue<pair<int, int>> q;
queue<pair<int, int>> newQ;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};




void BFS() {
  while(!q.empty()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || check[newH][newW] != 0) continue;
      if (field[newH][newW] == '1') {
        newQ.push({newH, newW});
        check[newH][newW] = cnt;
        oneCount--;
        field[newH][newW] = '0';
      }
      else if (field[newH][newW] == '0') {
        q.push({newH, newW});
        check[newH][newW] = cnt;
      }
      else if (field[newH][newW] == '#') {
        ans = cnt;
        isArrived = true;
        return;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> H >> W;
  cin >> jPoint.first >> jPoint.second >> tPoint.first >> tPoint.second;
  jPoint.first --;
  jPoint.second --;
  tPoint.first --;
  tPoint.second --;

  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    field.push_back(s);
    for (int j = 0; j < s.size(); j++) {
      if (s[i] == '1') oneCount++;
    }
  }
  check[jPoint.first][jPoint.second] = 1;
  q.push({jPoint.first, jPoint.second});

  while (!isArrived) {
    BFS();
    while(newQ.size()) {
      q.push(newQ.front());
      newQ.pop();
    }
    cnt++;
  }
  // for (auto e : field) {
  //   for (auto k : e) {
  //     cout << k << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) {
  //     cout << check[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << ans;



  return 0;
}