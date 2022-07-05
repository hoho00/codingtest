#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std; 

int N;
int field[24][24], fieldOrigin[24][24], ans = 0;
vector<vector<int>> combi;

void up() {
  for (int i = 0; i < N; i++) {
    stack<pair<int, int>> tmp;
    vector<int> v;
    for (int j = 0; j < N; j++) {
      if (field[j][i] == 0) continue;
      if (!tmp.empty()) {
        if (tmp.top().first == field[j][i] && tmp.top().second == 0) {
          tmp.pop();
          tmp.push({field[j][i] * 2, 1});
        }
        else {
          tmp.push({field[j][i], 0});
        }
      }
      else {
        tmp.push({field[j][i], 0});
      }
    }
    int index = 0;
    while(tmp.size()) {
      v.push_back(tmp.top().first);
      tmp.pop();
    }
    reverse(v.begin(), v.end());
    for (int j = 0; j < v.size(); j++) {
      field[j][i] = v[j];
      ans = max(ans, v[j]);
    }
    for (int j = v.size(); j < N; j++) {
      field[j][i] = 0;
    }
  }

}

void down() {
  for (int i = 0; i < N; i++) {
    stack<pair<int, int>> tmp;
    vector<int> v;
    for (int j = N - 1; j >= 0; j--) {
      if (field[j][i] == 0) continue;
      if (!tmp.empty()) {
        if (tmp.top().first == field[j][i] && tmp.top().second == 0) {
          tmp.pop();
          tmp.push({field[j][i] * 2, 1});
        }
        else {
          tmp.push({field[j][i], 0});
        }
      }
      else {
        tmp.push({field[j][i], 0});
      }
    }
    int index = 0;
    while(tmp.size()) {
      v.push_back(tmp.top().first);
      tmp.pop();
    }
    reverse(v.begin(), v.end());
    for (int j = 0; j < v.size(); j++) {
      field[N - 1 - j][i] = v[j];
      ans = max(ans, v[j]);
    }
    for (int j = v.size(); j < N; j++) {
      field[N - 1 - j][i] = 0;
    }
  }

}

void left() {
  for (int i = 0; i < N; i++) {
    stack<pair<int, int>> tmp;
    vector<int> v;
    for (int j = 0; j < N; j++) {
      if (field[i][j] == 0) continue;
      if (!tmp.empty()) {
        if (tmp.top().first == field[i][j] && tmp.top().second == 0) {
          tmp.pop();
          tmp.push({field[i][j] * 2, 1});
        }
        else {
          tmp.push({field[i][j], 0});
        }
      }
      else {
        tmp.push({field[i][j], 0});
      }
    }
    int index = 0;
    while(tmp.size()) {
      v.push_back(tmp.top().first);
      tmp.pop();
    }
    reverse(v.begin(), v.end());
    for (int j = 0; j < v.size(); j++) {
      field[i][j] = v[j];
      ans = max(ans, v[j]);
    }
    for (int j = v.size(); j < N; j++) {
      field[i][j] = 0;
    }
  }
}

void right() {
  for (int i = 0; i < N; i++) {
    stack<pair<int, int>> tmp;
    vector<int> v;
    for (int j = N - 1; j >= 0; j--) {
      if (field[i][j] == 0) continue;
      if (!tmp.empty()) {
        if (tmp.top().first == field[i][j] && tmp.top().second == 0) {
          tmp.pop();
          tmp.push({field[i][j] * 2, 1});
        }
        else {
          tmp.push({field[i][j], 0});
        }
      }
      else {
        tmp.push({field[i][j], 0});
      }
    }
    int index = 0;
    while(tmp.size()) {
      v.push_back(tmp.top().first);
      tmp.pop();
    }
    reverse(v.begin(), v.end());
    for (int j = 0; j < v.size(); j++) {
      field[i][N - 1 - j] = v[j];
      ans = max(ans, v[j]);
    }
    for (int j = v.size(); j < N; j++) {
      field[i][N - 1 - j] = 0;
    }
  }
}


void go (vector<int>& v) {
  if (v.size() == 5) {
    combi.push_back(v);
    return;
  }
  v.push_back(1);
  go(v);
  v.pop_back();
  v.push_back(2);
  go(v);
  v.pop_back();
  v.push_back(3);
  go(v);
  v.pop_back();
  v.push_back(4);
  go(v);
  v.pop_back();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> field[i][j];
      cin >> fieldOrigin[i][j];
    }
  }
  vector<int> tmp;
  go(tmp);

  for (auto e : combi) {
    for (auto k : e) {
      if (k == 1) {

      }
      else if (k == 2) {

      }
      else if (k == 3) {

      }
      else if (k == 4) {

      }
    }
    cout << endl;
  }

  //cout << combi.size();

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << field[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << ans;
  return 0;
}