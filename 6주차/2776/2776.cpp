#include <iostream>
#include <unordered_map> 

using namespace std; 

int T;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> T;
  while (T--) {
    int N, M;
    cin >> N;
    unordered_map<int, int> A;
    for (int i = 0; i < N; i++) {
      int tmp; cin >> tmp;
      A[tmp] ++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
      int tmp; cin >> tmp;
      if (A.find(tmp) == A.end()) {
        cout << 0 << '\n';
      }
      else {
        cout << 1 << '\n';
      }
    }
  }
  return 0;
}