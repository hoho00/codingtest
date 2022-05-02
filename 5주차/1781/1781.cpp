#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, ans = 0;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int d, c;
    cin >> d >> c;
    v.push_back({d, c});
  }

  sort (v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    pq.push(v[i].second);
    while(v[i].first < pq.size()) {
      pq.pop();
    }
  }
  while (pq.size()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans;

  return 0;
}