#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> v;
int N, target, ans = 0;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  cin >> target;

  sort(v.begin(), v.end());

  int lt = 0, rt = N - 1;

  while(lt < rt) {
    if (v[lt] + v[rt] < target) {
      lt++;
    }
    else if (v[lt] + v[rt] > target) {
      rt--;
    }
    else if (v[lt] + v[rt] == target) {
      ans ++;
      lt ++;
      rt --;
    }
  }

  cout << ans;

  return 0;
}