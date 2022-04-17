#include <iostream> 
#include <queue>
#include <vector>
#include <stack>

using namespace std; 

int field[100004], prevCheck[100004];
int N, K, cnt = 0;
queue<int> q;
stack<int> trace;

void go() {
  while(!q.empty()) {
    int f = q.front();
    q.pop();
    if (f + 1<= 100000 && field[f + 1] == 0) {
      q.push(f + 1);
      field[f + 1] = field[f] + 1;
      prevCheck[f + 1] = f;
    }
    if (f - 1 >= 0 && field[f - 1] == 0) {
      q.push(f - 1);
      field[f - 1] = field[f] + 1;
      prevCheck[f - 1] = f;
    }
    if (f * 2 <= 100000 && field[f * 2] == 0) {
      q.push(f * 2);
      field[f * 2] = field[f] + 1;
      prevCheck[f * 2] = f;
    }
  }
}

void tracer(int L) {
  if (L == N) {
    trace.push(L);
    return;
  }
  trace.push(L);
  tracer(prevCheck[L]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> K;

  q.push(N);
  field[N] = 1;

  go();
  tracer(K);

  cout << field[K] - 1 << endl;
  while(!trace.empty()) {
    cout << trace.top() << " ";
    trace.pop();
  }

  return 0;
}