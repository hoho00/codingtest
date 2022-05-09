#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

int N, ans = 987654321;
int field[24][24];
vector<int> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  for (int i = 0; i < N; i++) {
    if (i < N / 2) v.push_back(0);
    else v.push_back(1);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> field[i][j];
    }
  }

  do {
    int sum1 = 0;
    int sum2 = 0;
    //vector<pair<int, int>> t1;
    for (int i = 0 ; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (v[i] == v[j]) {
          if (v[i] == 0) {
            //cout << i << " " << j << endl;
            //t1.push_back({i, j});
            sum1 += field[i][j];
            sum1 += field[j][i];
          }
          else {
            sum2 += field[i][j];
            sum2 += field[j][i];
          }
        }
      }
    }
    ans = min(ans, abs(sum1 - sum2));

  } while (next_permutation(v.begin(), v.end()));

  cout << ans;

  return 0;
}