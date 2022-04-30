#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int N, ans = 0;

vector<pair<int, int>> v;

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
  if (p1.second == p2.second) return p1.first >p2.first;
  return p1.second < p2.second;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int p, d;
    cin >> p >> d;
    v.push_back({p, d});
  }

  sort (v.begin(), v.end(), compare);

  // for (auto e : v) {
  //   cout << e.first << " " << e.second << endl;
  // }

  int day = 1;
  int indx = 0;
  while (indx < v.size()) {
    if (v[indx].second >= day) {
      ans += v[indx].first;
      indx++;
      day++;
    }
    else {
      indx++;
    }
  }
  cout << ans; 
  return 0;
}