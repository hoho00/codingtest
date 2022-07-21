#include <iostream> 
#include <unordered_map>

using namespace std; 

unordered_map<int, int> A, B;
int N, M;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    A[tmp] ++;
  }
  for (int i = 0; i < M; i++) {
    int tmp; cin >> tmp;
    if (A.find(tmp) == A.end()) {
      A[tmp]++;
    }
    else {
      A.erase(tmp);
    }
  }

  cout << A.size();
  return 0;
}