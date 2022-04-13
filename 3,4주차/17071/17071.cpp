#include <iostream> 
#include <queue>
#include <vector>
#include <stack>

using namespace std; 

int field[500004];
int N, K, cnt = 0;
queue<int> q;
stack<int> trace;

void go() {
  while(!q.empty()) {
    int f = q.front();
    q.pop();
    if (f + 1<= 500000 && field[f + 1] == 0) {
      q.push(f + 1);
      field[f + 1] = field[f] + 1;
    }
    if (f - 1 >= 0 && field[f - 1] == 0) {
      q.push(f - 1);
      field[f - 1] = field[f] + 1;
    }
    if (f * 2 <= 500000 && field[f * 2] == 0) {
      q.push(f * 2);
      field[f * 2] = field[f] + 1;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> K;

  q.push(N);
  field[N] = 0;

  go();
  return 0;
}