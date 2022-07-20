#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 
typedef long long ll;

int N, M, sum = 0, ans = 0;
vector<ll> v;
vector<ll> sumV;

bool check(ll mid) {
  for (int i = 0; i < N; i++) {
    if (v[i] > mid) return false;
  }
  ll cnt = 0;
  ll initMid = mid;
  for (int i = 0; i < N; i++) {
    if (mid - v[i] < 0) {
      cnt++;
      mid = initMid;
    }
    mid -= v[i];
  }
  cnt++;
  return M >= cnt;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    ll tmp; cin>> tmp;
    v.push_back(tmp);
  }

  // sort(v.begin(), v.end());
  sumV.push_back(v[0]);

  for (int i = 1; i < v.size(); i++) {
    ll tmp = sumV[i - 1] + v[i];
    sumV.push_back(tmp);
  }
  ll lt = 0, rt = sumV.back();

  while(lt <= rt) {
    ll mid = (lt + rt) / 2;
    if (check(mid)) {
      rt = mid - 1;
      ans = mid;
    }
    else {
      lt = mid + 1;
    }
  }
  cout << ans;
  return 0;
}