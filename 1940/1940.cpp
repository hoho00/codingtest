#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt = 0;
vector<int> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "rt", stdin);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  int lt = 0;
  int rt = N - 1;
  while(lt < rt) {
    if (v[lt] + v[rt] == M) {
      cnt++;
      lt++;
      rt--;
    }
    else if (v[lt] + v[rt] > M) {
      rt--;
    }
    else if (v[lt] + v[rt] < M) {
      lt++;
    }
  }
  cout << cnt;
  return 0;
}