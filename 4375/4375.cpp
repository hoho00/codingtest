#include <iostream>

using namespace std;
int n;
int main()
{
  freopen("input.txt", "rt", stdin);
  while(scanf("%d", &n) != EOF) {
    long long ans = 1, mul = 1;
    while(1) {
      if (mul % n == 0) {
        cout << ans << '\n';
        break;
      }
      mul = mul * 10 + 1;
      //cout << mul << '\n';
      mul %= n;
      ans++;
    }
  }
  return 0;
}