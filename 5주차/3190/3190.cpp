#include <iostream> 
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std; 

int N, K, L, T = 0;
char status = 'R';

// int field[101][101];

deque<pair<int, int>> sneak;

vector<vector<int>> field(101, vector<int>(101, 0));

unordered_map<int, char> m;


void turnRight(vector<vector<int>> &key){
  int m = N;
  vector<vector<int>> temp(m, vector<int>(m, 0)); 
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){ 
      temp[i][j] = key[j][m - i - 1];
    } 
  }
  key = temp;
}
void turnLeft(vector<vector<int>> &key) {
  int m = N;
  vector<vector<int>> temp(m, vector<int>(m, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      temp[i][j] = key[m - j - 1][i];
    }
  }
  key = temp;
}

void changeStatus(char d) {
  if (status == 'R') {
    if (d == 'L') {
      status = 'U';
    }
    else if (d == 'D') {
      status = 'D';
    }
  }
  else if (status == 'L') {
    if (d == 'L') {
      status = 'D';
    }
    else if (d == 'D') {
      status = 'U';
    }
  }
  else if (status == 'U') {
    if (d == 'L') {
      status = 'L';
    }
    else if (d == 'D') {
      status = 'R';
    }
  }
  else if (status == 'D') {
    if (d == 'L') {
      status = 'R';
    }
    else if (d == 'D') {
      status = 'L';
    }
  }
}

bool go() {
  if (status == 'U') {
    if (sneak.front().first == 0 || field[sneak.front().first - 1][sneak.front().second] == 2) {
      return false;
    }
    sneak.push_front({sneak.front().first, sneak.front().second});
    sneak.front().first--;

    if (field[sneak.front().first][sneak.front().second] == 0) {
      field[sneak.back().first][sneak.back().second] = 0;
      sneak.pop_back();
    }
    field[sneak.front().first][sneak.front().second] = 2;
  }
  else if (status == 'D') {
    if (sneak.front().first == N - 1 || field[sneak.front().first + 1][sneak.front().second] == 2) {
      return false;
    }
    sneak.push_front({sneak.front().first, sneak.front().second});
    sneak.front().first++;

    if (field[sneak.front().first][sneak.front().second] == 0) {
      field[sneak.back().first][sneak.back().second] = 0;
      sneak.pop_back();
    }
    field[sneak.front().first][sneak.front().second] = 2;
  }
  else if (status == 'R') {
    if (sneak.front().second == N - 1 || field[sneak.front().first][sneak.front().second + 1] == 2) {
      return false;
    }
    sneak.push_front({sneak.front().first, sneak.front().second});
    sneak.front().second++;

    if (field[sneak.front().first][sneak.front().second] == 0) {
      field[sneak.back().first][sneak.back().second] = 0;
      sneak.pop_back();
    }
    field[sneak.front().first][sneak.front().second] = 2;
  }
  else if (status == 'L') {
    if (sneak.front().second == 0 || field[sneak.front().first][sneak.front().second - 1] == 2) {
      return false;
    }
    sneak.push_front({sneak.front().first, sneak.front().second});
    sneak.front().second--;

    if (field[sneak.front().first][sneak.front().second] == 0) {
      field[sneak.back().first][sneak.back().second] = 0;
      sneak.pop_back();
    }
    field[sneak.front().first][sneak.front().second] = 2;
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  cin >> K;

  for (int i = 0; i < K; i++) {
    int w, h;
    cin >> w >> h;
    field[w - 1][h - 1] = 1;
  }
  cin >> L;

  for (int i = 0; i < L; i++) {
    int t;
    char c;
    cin >> t;
    cin >> c;
    m[t] = c;
  }
  sneak.push_back({0, 0});
  field[0][0] = 2;

  // for (int i = 0; i < N; i++) {
  //     for (int j = 0; j < N; j++) {
  //       cout << field[i][j] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;

  while (1) {
    T++;
    if (!go()) break;
    if (m.find(T) != m.end()) {
      changeStatus(m[T]);
      // cout << "Time : " << T << " :  " << status << endl;
    }
    
    // cout << "Time : " << T << endl;
    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < N; j++) {
    //     cout << field[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }
  cout << T;

  return 0;
}