#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int N, L;
vector<pair<int, int>> v;
int field[10004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    int s, e;
    cin >> s >> e;
    v.push_back({s, e});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < 10000; i++) {
    
  }

  return 0;
}