#include <iostream> 

using namespace std; 

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N, count = 0;
  cin >> N;
  int i;
  for (i = 666; ; i++) {
    if (count == N) break;
    if (to_string(i).find("666") != string::npos) count++;
  }
  cout << i - 1;
  return 0;
}