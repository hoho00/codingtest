#include <iostream> 
#include <vector>

using namespace std; 

int field[4000001];
vector<int> v;

int N, ans = 0;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;
  int i;
  v.push_back(0);

  for (i = 2; i <= N; i++) {
    if (field[i] == 0) {
      v.push_back(v.back() + i);
      for (int j = 2; j * i <= N; j++) {
        field[j * i] = 1;
      }
    }
    //if (v.back() >= N) break;
  }
  // for (int i = 2; i <= N; i++) {
  //   cout << i << " : " << field[i] << endl;
  // }
  int lt = 0, rt = 1;
  while(lt < rt) {
    if (rt >= v.size()) break;
    int checker = v[rt] - v[lt];
    if (checker < N) {
      rt ++;
    }
    else if (checker > N) {
      lt ++;
    }
    else if (checker == N) {
      lt ++;
      rt ++;
      ans ++;
    }
  }

  cout << ans;

  return 0;
}