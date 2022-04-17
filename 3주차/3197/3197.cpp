#include <iostream> 
#include <string>
#include <queue>
#include <vector>

using namespace std; 
vector<string> field;
int check[1504][1504];
int meetCheck[1504][1504];
bool isOK = false;

int H, W, ans = 0;
queue<pair<int, int>> q;
queue<pair<int, int>> tmp;
queue<pair<int, int>> mq;
queue<pair<int, int>> mtmp;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

vector<pair<int, int>> b;

void BFS() {
  while(!q.empty()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || check[newH][newW]) continue;
      if (field[newH][newW] == 'X') {
        tmp.push({newH, newW});
        field[newH][newW] = '.';
      }
      // else if (field[newH][newW] == '.') {
      //   q.push({newH, newW});
      //   check[newH][newW] = 1;
      // }
    }
  }
}

void isMeet() {
  while(!mq.empty()) {
    int h = mq.front().first;
    int w = mq.front().second;
    mq.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || meetCheck[newH][newW]) continue;
      if (field[newH][newW] == 'L') {
        isOK = true;
        return;
      }
      if (field[newH][newW] == '.') {
        mq.push({newH, newW});
      }
      if (field[newH][newW] == 'X') {
        mtmp.push({newH, newW});
      }
      meetCheck[newH][newW] = 1;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> H >> W;

  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    field.push_back(s);
    for (int j = 0; j < s.size(); j++) {
      if (field[i][j] == 'L' || field[i][j] == '.') {
        q.push({i, j});
        check[i][j] = 1;
      }
      if (field[i][j] == 'L') {
        b.push_back({i, j});
        //mq.push({i, j});
        //meetCheck[i][j] = 1;
      }
    }
  }
  mq.push({b[0].first, b[0].second});
  meetCheck[b[0].first][b[0].second] = 1;
  
  
  while (!isOK) { 
    isMeet();
    if (isOK) {
      break;
    }
    mq = mtmp;
    mtmp = queue<pair<int, int>>();
    BFS();
    q = tmp;
    tmp = queue<pair<int, int>>();
    // for (int i = 0; i < H; i++) {
    //   for (int j = 0; j < W; j++) {
    //     cout << field[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    ans ++;
  }

  cout << ans;
  return 0;
}