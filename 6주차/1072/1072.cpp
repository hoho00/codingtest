#include <iostream> 
#include <vector>
#include <climits>

using namespace std; 

typedef long long ll;

ll X, Y, Z;
ll lt = 0, rt = 1e9;
ll ans;

bool check(ll mid) {
  ll tmpZ = (((Y + mid) * 100) / (X + mid)) ;
  // cout << mid << ", " << tmpZ << endl;
  return tmpZ > Z;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> X >> Y;
  Z =(Y * 100) / X;
  // cout << Z << endl;
  if (X == Y) {
    cout << -1;
    return 0;
  }
  while (lt <= rt) {
    ll mid = (lt  + rt) / 2;
    if (check(mid)) {
      rt = mid - 1;
      ans = mid;
    }
    else {
      lt = mid + 1;
    }
  }
  if (ans == 0) {
    cout << -1;
    return 0;
  }
  cout << ans;
  return 0;
}