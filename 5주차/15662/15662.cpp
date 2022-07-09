#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int T, K;
vector<string> v;
vector<pair<int, int>> rotateVector;
int ans = 0;

void rotateMachine(string& s, int r) {
  if (r == 1) {
    rotate(s.begin(), s.end() - 1, s.end());
  }
  else {
    rotate(s.begin(), s.begin() + 1, s.end());
  }
}

int getReverse(int r) {
  if (r == 1) return -1;
  if (r == -1) return 1;
}

void rotateAll(int num, int r) {
  //to left
  int curR = r;
  // cout << v[num][6] << endl;
  if (num > 0) {
    vector<pair<int, int>> tmp;
    for (int i = num - 1; i >= 0; i--) {
      if (v[i][2] == v[i + 1][6]) break;
      // rotateMachine(v[i], getReverse(r));
      r = getReverse(r);
      tmp.push_back({i, r});
      
    }
    for (auto e : tmp) {
      rotateMachine(v[e.first], e.second);
    }
  }
  
  r = curR;
  if (num < T - 1) {
    vector<pair<int, int>> tmp;
    for (int i = num + 1; i < T; i++) {
      if (v[i - 1][2] == v[i][6]) break;
      // rotateMachine(v[i], getReverse(r));
      r = getReverse(r);
      tmp.push_back({i, r});
    }
    for (auto e : tmp) {
      rotateMachine(v[e.first], e.second);
    }
  }
  rotateMachine(v[num], curR);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> T;
  for (int i = 0; i < T; i++) {
    string tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    int num, r;
    cin >> num >> r;
    num--;
    rotateVector.push_back({num, r});
  }
  for (auto e : rotateVector) {
    // rotateMachine(v[e.first], e.second);
    rotateAll(e.first, e.second);
  }
  for (auto e : v) {
    // cout << e << endl;
    if (e[0] == '1') ans++;
  }
  cout << ans;
  return 0;
}