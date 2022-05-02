#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std; 

int N;

vector<pair<int, int>> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  int endTime = v[0].first + v[0].second;

  for (int i = 1; i < N; i++) {
    endTime = max(endTime, v[i].first);
    endTime += v[i].second;
  }
  cout << endTime;

  return 0;
}