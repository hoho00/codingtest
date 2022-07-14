#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int N, M, T, ans = 0;

typedef struct {
  int x;
  int d;
  int k;
}Order;

vector<vector<int>> field;
vector<Order> orders;

int deleteField[54][54];

void rotateField(Order o) {
  if (o.d == 0) {
    for (int i = 0; i < N; i++) {
      if ((i + 1) % o.x != 0) continue;
      rotate(field[i].begin(), field[i].end() - o.k, field[i].end());
    }
  }
  else if (o.d == 1) {
    for (int i = 0; i < N; i++) {
      if ((i + 1) % o.x != 0) continue;
      rotate(field[i].begin(), field[i].begin() + o.k, field[i].end());
    }
  }
}

bool deleteFriend() {
  fill(&deleteField[0][0], &deleteField[0][0] + 54 *54, 0);
  bool res = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M - 1; j++) {
      if (field[i][j] != -1 && field[i][j] == field[i][j + 1]) {
        deleteField[i][j] = 1; deleteField[i][j + 1] = 1;
        res = true;
      }
    }
    if (field[i][M - 1] != -1 && field[i][M - 1] == field[i][0]) {
      deleteField[i][M - 1] = 1; deleteField[i][0] = 1;
      res = true;
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (field[j][i] != -1 && field[j][i] == field[j + 1][i]) {
        deleteField[j][i] = 1; deleteField[j + 1][i] = 1;
        res = true;
      }
    }
  }
  if (res) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (deleteField[i][j] == 1) field[i][j] = -1;
      }
    }
  }
  return res;
}


void makeFlat() {
  float sum = 0;
  float cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (field[i][j] == -1) continue;
      sum += field[i][j];
      cnt++;
    }
  }
  float avg = sum / cnt;
  // cout << avg << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (field[i][j] == -1) continue;
      if (field[i][j] > avg) {
        field[i][j] -=1;
      }
      else if (field[i][j] < avg) {
        field[i][j] += 1;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M >> T;

  for (int i = 0; i < N; i++) {
    vector<int> tmpV;
    for (int j = 0; j < M; j++) {
      int tmp;
      cin >> tmp;
      tmpV.push_back(tmp);
    }
    field.push_back(tmpV);
  }

  for (int i = 0; i < T; i++) {
    Order tmp;
    cin >> tmp.x >> tmp.d >> tmp.k;
    orders.push_back(tmp);
  }
  // for (auto e : field) {
  //   for (auto k : e) {
  //     cout << k << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  for (auto e : orders) {
    rotateField(e);
    bool b = deleteFriend();
    // cout << "b: " << b << endl;
    if (!b) {
      makeFlat();
    }

    // for (auto e : field) {
    //   for (auto k : e) {
    //     cout << k << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }
  for (auto e : field) {
    for (auto k : e) {
      // cout << k << " ";
      if (k == -1) continue;
      ans += k;
    }
    // cout << endl;
  }
  cout << ans;
  return 0;
}