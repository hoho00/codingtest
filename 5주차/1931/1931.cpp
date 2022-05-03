#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int> > pq;

int N, ans = 1;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int s, e;
    cin >> s >> e;
    v.push_back({e, s});
  }
  sort(v.begin(), v.end());

  int start = v[0].second;
  int end = v[0].first;

  for (int i = 1; i < N; i++ ){
    //pq.push(v[i].first);
    if (v[i].second >= end) {
      ans++;
      start = v[i].second;
      end = v[i].first;
    }
  }
  cout << ans;
  // while(pq.size()) {
  //   cout << pq.top() << endl;
  //   pq.pop();
  // }


  return 0;
}