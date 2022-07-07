#include <iostream> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std; 

int N, M, K;
int res = INT_MAX;

vector<vector<int>> field;
vector<vector<int>> initField;
vector<vector<int>> rcs;
vector<int>rcsIndex;

void turnRight(pair<int, int> tl, pair<int, int> br) {
  if (tl.first >= br.first) return;
  int prev = field[tl.first][tl.second];
  int vSize = br.second - tl.second;
  for (int i = 1; i <= vSize; i++) {
    int tmp = field[tl.first][tl.second + i];
    field[tl.first][tl.second + i] = prev;
    prev = tmp;
  }
  vSize = br.first - tl.first;
  for (int i = 1; i <= vSize; i++) {
    int tmp = field[tl.first + i][br.second];
    field[tl.first + i][br.second] = prev;
    prev = tmp;
  }
  vSize = br.second - tl.second;
  for (int i = 1; i <= vSize; i++) {
    int tmp = field[br.first][br.second - i];
    field[br.first][br.second - i] = prev;
    prev = tmp;
  }
  vSize = br.first - tl.first;
  for (int i = 1; i <= vSize; i++) {
    int tmp = field[br.first - i][tl.second];
    field[br.first - i][tl.second] = prev;
    prev = tmp;
  }
  turnRight({tl.first + 1, tl.second + 1}, {br.first - 1, br.second - 1});
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M >> K;

  for (int i = 0 ; i < N; i++) {
    vector<int> tmp;
    for (int j = 0; j < M; j++) {
      int a;
      cin >> a;
      tmp.push_back(a);
    }
    field.push_back(tmp);
    initField.push_back(tmp);
  }

  for (int i = 0; i < K; i++) {
    int r, c, s;
    vector<int> tmp;
    cin >> r >> c >> s;
    r--;
    c--;
    tmp.push_back(r); tmp.push_back(c); tmp.push_back(s);
    rcs.push_back(tmp);
    rcsIndex.push_back(i);
  }

  // sort(rcs.begin(), rcs.end());

  do {
    field = initField;
    int tmpRes = INT_MAX;
    for (auto e : rcsIndex) {
      int r = rcs[e][0], c = rcs[e][1], s = rcs[e][2];
      // cout << r << c << s << endl;
      turnRight({r - s, c - s}, {r + s, c + s});
      // cout << endl;
    }
    for (int i = 0; i < N; i++) {
      int tmpSum = 0;
      for (int j = 0; j < M; j++) {
        // cout << field[i][j] << " ";
        tmpSum += field[i][j];
      }
      res = min(res, tmpSum);
      // cout << endl;
    }
  } while(next_permutation(rcsIndex.begin(), rcsIndex.end()));
  

  cout << res;

  // turnRight({0, 0},{5, 5});
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << field[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  


  return 0;
}