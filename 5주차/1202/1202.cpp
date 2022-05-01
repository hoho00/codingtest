#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>


using namespace std; 

typedef long long ll;

int N, K;
ll ans = 0;

vector<pair<ll, ll>> jws;
vector<ll> packs;
priority_queue<ll> pq;

bool compare(pair<ll, ll>& p1, pair<ll, ll>& p2) {
  if (p1.second == p2.second) return p1.first < p2.first;
  return p1.second > p2.second;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    ll m, v;
    cin >> m >> v;
    jws.push_back({m, v});
  }

  for (int i = 0; i < K; i++) {
    ll k;
    cin >> k;
    packs.push_back(k);
  }

  sort(packs.begin(), packs.end());
  sort(jws.begin(), jws.end());

  int jIndx = 0;
  int j = 0;

  for (int i = 0; i < packs.size(); i++) {
    while (j < N && jws[j].first <= packs[i]) {
      pq.push(jws[j].second);
      j++;
    }
    if (pq.size()) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans;


  return 0;
}