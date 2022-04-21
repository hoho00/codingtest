#include <iostream> 

using namespace std; 

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N, ans = 0;
  cin >> N;
  for (int i = 6; i >= 0; i--) {
    if (N & (1 << i)) ans++;
  }
  cout << ans;
  return 0;
}