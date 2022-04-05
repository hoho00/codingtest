#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int A, B, C;

ll daq(ll a, ll b) {
  if (b == 1) return a % C;
  ll c = daq(a, b / 2);
  c = (c * c) % C;
  if (b % 2 == 1) c = (c * a) % C;
  return c;
}

int main()
{
  freopen("input.txt", "rt", stdin);
  cin >> A >> B >> C;

  cout << daq(A, B);
  
  return 0;
}