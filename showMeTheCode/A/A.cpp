#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int N, K, ans = 0;

vector<pair<int, int>> town;

void DFS(int L, int sum, int pSum, vector<int>& ss) {
  if (L >= N ) {
    
    int tmpSum = 0;
    for (int i = 0; i < ss.size(); i++) {
      for (int j = 0; j <= i; j++) {
        tmpSum += town[ss[j]].first;
      }
    }
    // for (auto k : ss) cout << k << " ";
    // cout << " : " << ans << " : " << tmpSum;
    // cout << endl;
    if (tmpSum <= K) ans = max(ans, pSum);
    return;
  }
  DFS(L + 1, sum, pSum, ss);
  ss.push_back(L);
  DFS(L + 1, sum + town[L].first, pSum + town[L].second ,ss);
  ss.pop_back();
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    town.push_back({tmp, 0});
  }
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    town[i].second = tmp;
  }
  sort(town.begin(), town.end());
  vector<int> tmp;
  DFS(0, 0, 0, tmp);
  cout << ans;
  return 0;
}