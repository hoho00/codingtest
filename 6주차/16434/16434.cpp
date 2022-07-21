#include <iostream> 
#include <vector>
#include <climits>

using namespace std; 
typedef long long ll;

int N;
ll Ha, Hp, Hc = LLONG_MAX;

ll lt = 1, rt = LLONG_MAX;
ll ans = 0;

typedef struct {
  ll t;
  ll a;
  ll h;
}Cave;


vector<Cave> v;

bool check(ll mid) {
  ll initHp = mid;
  ll curHp = mid;
  ll curAt = Ha;

  for (int i = 0; i < N; i++) {
    // if (curHp <= 0) return false;
    ll monHp = v[i].h;
    ll monAt = v[i].a;
    if(v[i].t == 1) {
      ll attNum = monHp / curAt ;
      if (monHp % curAt  != 0) attNum++;
      // if (curHp -  attNum * monAt <= 0) return false;
      attNum--;
      curHp -= attNum * monAt;
    }
    else {
      curHp = min(initHp, curHp + v[i].h);
      curAt += v[i].a;
    }
    if (curHp <= 0) return false; 
  }
  // if (curHp <= 0) return false;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> Ha;

  for (int i = 0; i < N; i++) {
    ll t, a, h; cin >> t >> a >> h;
    Cave c;
    c.a = a; c.h = h; c.t = t;
    v.push_back(c);
  }
  while (lt <= rt) {
    ll mid = (lt + rt) / 2;
    if (check(mid)) {
      rt = mid - 1;
      ans = mid;
    }
    else {
      lt = mid + 1;
      // ans = mid;
    }
  }
  cout << ans;
  return 0;
}