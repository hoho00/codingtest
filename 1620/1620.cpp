#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
vector<string> v;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N, M;
  cin >> N >> M;
  
  v.push_back("");
  for (int i = 0; i < N; i++) {
    string pok;
    cin >> pok;
    v.push_back(pok);
    m[pok] = i + 1;
  }

  for (int i = 0; i < M; i++) {
    string q;
    cin >> q;
    if(q[0] >= '1' && q[0] <= '9') {
      int num = stoi(q);
      cout << v[num] << '\n';
    }
    else {
      cout << m[q] << '\n';
    }
  }
  return 0;
}