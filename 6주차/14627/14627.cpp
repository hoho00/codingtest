#include <iostream> 
#include <vector>

using namespace std; 
typedef long long ll;

ll N, M, ans = 0, sum = 0;
vector<ll> v;
ll lt = 1, rt = 1e9;
ll restP;


bool check (ll mid) {
  ll initNid = mid;
  ll cnt = 0;
  restP = 0;
  // cout << mid << endl;
  for (int i = 0; i < N; i++) {
    cnt += v[i] / mid;
    restP += v[i] % mid;
    // cout << v[i] << " : " << v[i] / mid << " , " << v[i] % mid << endl;
  }
  // ans = restP;
  // cout << endl;
  // if (M == cnt) ans = restP;
  return M > cnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    ll tmp; cin >> tmp;
    v.push_back(tmp);
    sum += tmp;
  }

  while (lt <= rt) {
    ll mid = (lt + rt) / 2;
    if (check(mid)) {
      rt = mid - 1;
      // ans = restP;
    }
    else {
      lt = mid + 1;
      ans = mid;
    }
  }
  cout << sum - ans * M;
  return 0;
}