#include <iostream> 
#include <map>
#include <vector>

using namespace std; 

int H, W, T, sum = 0;;
int field[54][54];
int spreadingField[54][54];

int dh[] = {0, 0, -1, 1};
int dw[] = {1, -1, 0, 0};

map<pair<int, int>, int> m;
vector<pair<int, int>> airCondition;

void spread() {
  fill(&spreadingField[0][0], &spreadingField[0][0] + 54 * 54, 0);
  for (auto e : m) {
    int h = e.first.first;
    int w = e.first.second;
    int value = e.second;
    int spreadCount = 0;
    int spreading = value / 5;
    for (int i = 0; i < 4; i ++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || field[newH][newW] == -1) continue;
      spreadCount++;
      spreadingField[newH][newW] += spreading;
    }
    int remaining = value - spreading * spreadCount;
    if (remaining <= 0) {
      m.erase({h, w});
    }
    else {
      m[{h, w}] = remaining;
      field[h][w] = remaining;
    }
  }
  sum = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      field[i][j] += spreadingField[i][j];
      //if(field[i][j] != -1) sum += field[i][j];
    }
  }
}

void airConditionWork() {
  int h = airCondition[0].first;
  int w = airCondition[0].second;
  int prev = field[h][1];
  field[h][1] = 0; 
  for (int i = 2; i < W; i++) {
    int tmp = field[h][i];
    field[h][i] = prev;
    prev = tmp;
  }
  
  for (int i = h - 1; i >= 0; i--) {
    int tmp = field[i][W - 1];
    field[i][W - 1] = prev;
    prev = tmp;
  }

  for (int i = W - 2; i >= 0; i--) {
    int tmp = field[0][i];
    field[0][i] = prev;
    prev = tmp;
  }

  for (int i = 1; i <= h - 1; i++) {
    int tmp = field[i][0];
    field[i][0] = prev;
    prev = tmp;
  }
  h = airCondition[1].first;
  w = airCondition[1].second;
  prev = field[h][1];
  field[h][1] = 0;
  for (int i = 2; i < W; i++) {
    int tmp = field[h][i];
    field[h][i] = prev;
    prev = tmp;
  }
  //cout << prev << endl;

  for (int i = h + 1 ; i < H; i++) {
    int tmp = field[i][W - 1];
    field[i][W - 1] = prev;
    prev = tmp;
  }

  for (int i = W - 2; i >= 0; i--) {
    int tmp = field[H - 1][i];
    field[H - 1][i] = prev;
    prev = tmp;
  }

  for (int i = H - 2; i >= h + 1; i --) {
    int tmp = field[i][0];
    field[i][0] = prev;
    prev = tmp;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> H >> W >> T;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
      //sum += field[i][j];
      if (field[i][j] == 0) continue;
      if (field[i][j] == -1) {
        airCondition.push_back({i, j});
        continue;
      }
     // m[{i, j}] = field[i][j];
    }
  }

  while(T > 0) {
    m.clear();
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (field[i][j] == 0 || field[i][j] == -1) continue;
        m[{i, j}] = field[i][j];
      }
    }
    spread();
    // for (int i = 0; i < H; i++) {
    //   for (int j = 0; j < W; j++) {
    //     cout << field[i][j] << " ";
    //     //if (field[i][j] > 0) sum += field[i][j];
    //   }
    //   cout << endl;
    // }
    //cout << endl;
    airConditionWork();
    // for (int i = 0; i < H; i++) {
    //   for (int j = 0; j < W; j++) {
    //     cout << field[i][j] << " ";
    //     //if (field[i][j] > 0) sum += field[i][j];
    //   }
    //   cout << endl;
    // }
    T--;
  } 

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      //cout << field[i][j] << " ";
      if (field[i][j] > 0) sum += field[i][j];
    }
    //out << endl;
  }

  cout << sum;
  return 0;
}