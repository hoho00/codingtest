#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "rt", stdin);
  int N, count = 0;
  cin >> N;
  vector<int> v;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());
  int i = 0;
  int teamCount = 0;
  while (1) {
    if (i >= v.size()) {
      break;
    }
    if (teamCount == 0){
      teamCount = v[i];
      count++;
    } 
    i ++;
    teamCount--;
  }
  cout << count;
  return 0;
}
