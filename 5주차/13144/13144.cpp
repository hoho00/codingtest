#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std; 

long long N, ans = 0;
vector<long long> v;
unordered_map<long long, long long> m;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  //ans = ((N + 1) * N) / 2; 

  for (int i = 0; i < N; i++) {
    long long tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  int lt = 0, rt = 0;
  //m[v[lt]] = 1;
  while (rt < N) {
    //if (rt >= N) break;
    if (m[v[rt]] == 0) {
      m[v[rt]] = 1;
      rt ++;
    }
    else {
      // for (int i = lt; i <= rt; i++) {
      //   cout << v[i] << " ";
      // }
      //cout << endl;
      ans += (rt - lt);
      m[v[lt]] = 0;
      lt ++;
    }
  }
  ans += ((long long) (rt - lt) * (long long) (rt - lt + 1)) / 2;
  cout << ans;


  return 0;
}