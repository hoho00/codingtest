#include <iostream> 
#include <vector>

using namespace std; 

int N;
vector<double> v;
double dp[10004];
double ans;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;
  for (int i = 0; i < N; i++) {
    double tmp; cin >> tmp;
    v.push_back(tmp);
  }
  dp[0] = v[0];
  double a = v[0];
  for (int i = 1; i < N; i++) {
    if (a * v[i] < v[i]) {
      a = v[i];
    }
    else {
      a *= v[i];
    }
    ans = max(ans, a);
  }
  // for (int i = 0; i < N; i++) {
  //   ans = max(ans, dp[i]);
  //   // printf("%.3f\n", dp[i]);
  // }
  printf("%.3lf", ans + 0.00001);

  return 0;
}