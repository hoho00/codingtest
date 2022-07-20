#include <iostream> 
#include <vector>

using namespace std; 

typedef long long ll;

int N, M;
vector<ll> v;

ll psum = 0;
ll ans = 0, minNum = 1000000004;

bool check(ll mid) {
  if (mid < minNum) return false;
  ll initMid = mid;
  int cnt = 1;
  for (int i = 0; i < N; i++) {
    if (v[i] <= mid) {
      mid -= v[i];
    }
    else {
      if (v[i] > initMid) return false;
      mid = initMid;
      cnt++;
      mid -= v[i];
    }
  }

  return M >= cnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    v.push_back(tmp);
    psum += tmp;
    minNum = min(minNum, tmp);
  }

  ll lt = 0, rt = 1000000004;
  while (lt <= rt) {
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