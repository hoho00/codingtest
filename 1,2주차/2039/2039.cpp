#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "rt", stdin);
  vector<int> v(10);
  vector<int> pSum(10);

  for (int i = 1; i < 10; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (int i = 1; i < 10; i++) {
    pSum[i] = v[i] + pSum[i - 1];
  }
  int maxSum = pSum[9];

  pair<int, int> notShort;

  for (int i = 1; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      int checkValue = maxSum;
      checkValue -= (v[i] + v[j]);
      if (checkValue == 100) {
        notShort = {i, j};
      }
    }
  }

  for (int i = 1; i < 10; i++) {
    if (i == notShort.first || i == notShort.second) {
      continue;
    }
    cout << v[i] << '\n';
  }


  return 0;
}
