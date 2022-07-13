#include <iostream> 
#include <vector>

using namespace std; 

int N, sum = 0, ret = -987654321;
vector<int> v, a;

int dp[1000004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int s;
    cin >> s;
    sum += s;
    ret = max(ret, sum);
    if (sum < 0) sum = 0;
  }
  cout << ret;
  return 0;
}