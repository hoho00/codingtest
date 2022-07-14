#include <iostream> 
#include <vector>
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
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  return 0;
}