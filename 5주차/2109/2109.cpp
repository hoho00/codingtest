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
    int p, d;
    cin >> p >> d;
    v.push_back({d, p});
  }

  sort (v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    pq.push(v[i].second);
    if (pq.size() > v[i].first) {
      pq.pop();
    }
  }

  while (pq.size()) {
    //cout << pq.top() << endl;
    ans += pq.top();
    pq.pop();
  }
  cout << ans; 
  return 0;
}