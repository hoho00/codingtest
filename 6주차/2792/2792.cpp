#include <iostream> 
#include <vector>


using namespace std; 

typedef long long ll;

int N, M;
vector<ll> v;

ll ans = 1e18;

bool check(ll mid) {
  ll num = 0;
  for (auto e : v) {
    num += e / mid;
    if (e % mid) num++;
  } 
  return N >= num;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  ll low = 1;
  ll high = 0;
  ll mid = 0;
  for (auto e : v) high = max(high, e);
  while (low <= high) {
    mid = (low + high) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  cout << ans;
  return 0;
}