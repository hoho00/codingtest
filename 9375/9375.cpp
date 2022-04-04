#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "rt", stdin);

  int T;
  cin >> T;
  
  while (T > 0) {
    int N, count = 1;
    cin >> N;
    map<string, int> m;
    vector<int> v;
    for (int i = 0; i < N; i++) {
      string s, l;
      cin >> s >> l;
      m[l] ++;
    }
    for (auto e : m) {
      count *= (e.second + 1);
    }
    
    cout << count - 1<< '\n';
    T--;
  }
  return 0;
}