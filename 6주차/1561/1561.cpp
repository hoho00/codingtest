#include <iostream> 
#include <vector>

using namespace std; 
typedef long long ll;

ll N, M, hourPerChild;
vector<ll> v;
ll lt = 0, rt = 1e9;

bool check(ll mid) {
  ll cnt = M;
  for (int i = 0; i < v.size(); i++) {
    cnt += mid / v[i];
  }
  return cnt >= N;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;
  if (N <= M ) {cout << N; return 0;}
  for (int i = 0; i < N; i++) {
    ll tmp; cin >> tmp;
    v.push_back(tmp);
  }
  while (lt <= rt) {
    ll mid = (lt + rt) / 2;
    if (check(mid)) {
      rt = mid - 1;
      hourPerChild = mid;
    }
    else {
      lt = mid + 1;
    }
  }


  return 0;
}