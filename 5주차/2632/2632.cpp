#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std; 
int pSize, M, N, ans = 0;

vector<int> p1, p2;
unordered_map<int, int> m1, m2;

void slicePizza(vector<int>& v, unordered_map<int, int>& m) {
  vector<int> sumV;
  sumV.push_back(v[0]);
  for (int i = 1; i < v.size(); i++) {
    int s = sumV.back() + v[i];
    sumV.push_back(s);
  }
  for (int i = 0; i < v.size(); i++) {
    int s = sumV.back() + v[i];
    sumV.push_back(s);
  }
  // for (auto e : sumV) cout << e << " ";
  // cout << endl;
  for (int piece = 1; piece < v.size(); piece++) {
    // cout << "p : " << piece << endl;
    if (piece == 1) {
      for (int i = 0; i < v.size(); i++) {
        m[v[i]] ++;
        // cout << v[i] << " ";
      }
    }
    else {
      for (int i = 0; i < v.size() ; i++) {
        if (i == 0) {
          m[sumV[i + piece - 1]]++;
          // cout << sumV[i + piece - 1] << " ";
        }
        else {
          m[sumV[i + piece - 1] - sumV[i - 1]]++;
          // cout << sumV[i + piece - 1] - sumV[i - 1] << " ";
        }
      }
    }
    // cout << endl;
  }
  m[sumV[v.size() - 1]] ++;
  // cout << "p : " << v.size() << sumV[v.size() - 1];
  // cout << endl;
}

void solve() {
  ans += m1[pSize];
  ans += m2[pSize];
  for (int i = 1; i < pSize; i++) {
    int j = pSize - i;
    ans += m1[i] * m2[j];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> pSize >> M >> N;
  for (int i = 0; i < M; i++) {
    int tmp;
    cin >> tmp;
    p1.push_back(tmp);
  }
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    p2.push_back(tmp);
  }

  slicePizza(p1, m1);
  slicePizza(p2, m2);

  solve();
  cout << ans;
  return 0;
}