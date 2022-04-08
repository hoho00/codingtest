#include <iostream> 

using namespace std; 

int getZeroCount(int num) {
  int div = 5;
  int cnt = 0;
  while(div <= num) {
    cnt += num / div;
    div *= 5;
  }
  return cnt;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    cout << getZeroCount(num) << '\n';
  }
  return 0;
}