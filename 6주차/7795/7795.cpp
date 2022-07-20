#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int T;

void solve(vector<int> &a, vector<int>&b) {
  int cnt = 0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (auto e : a) {
    cnt += (int)(lower_bound(b.begin(), b.end(), e) - b.begin());
  }
  cout << cnt << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> T;
  while (T--) {
    int numA, numB;
    cin >> numA >> numB;
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < numA; i++) {
      int tmp; cin  >> tmp;
      a.push_back(tmp);
    }
    for (int i = 0; i < numB; i++) {
      int tmp; cin >> tmp;
      b.push_back(tmp);
    }

    solve(a, b);
  }
  return 0;
}