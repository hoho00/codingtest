#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int field[100004];

int main()
{
  freopen("input.txt", "rt", stdin);
  int N, K;
  cin >> N >> K;
  vector<int> answer;
  vector<int> pSum(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> field[i];
    pSum[i] = pSum[i - 1] + field[i];
  }

  for (int i = K; i <= N; i++) {
    int partSum = pSum[i] - pSum[i - K];
    answer.push_back(partSum);
  }
  sort(answer.begin(), answer.end());
  cout << answer.back() ;
  return 0;
}