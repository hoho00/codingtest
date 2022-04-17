#include <iostream> 
#include <queue>

using namespace std; 

int field[100004];
long long cntCheck[100004];
int N, K, cnt = 0;


queue<int>q;

void go() {
  while(!q.empty()) {
    int f = q.front();
    q.pop();
    if (f + 1 <= 100000 ) {
      if (field[f + 1] != 0) {
        if (field[f + 1] == field[f] + 1) {
          cntCheck[f + 1] += cntCheck[f];
        }
      }
      else {
        field[f + 1] = field[f] + 1;
        cntCheck[f + 1] += cntCheck[f];
        q.push(f + 1);
      } 
    }
    if (f - 1 >= 0) {
      if (field[f - 1] != 0) {
        if (field[f - 1] == field[f] + 1){
          cntCheck[f - 1] += cntCheck[f];
        }
      }
      else {
        field[f - 1] = field[f] + 1;
        cntCheck[f - 1] += cntCheck[f];
        q.push(f - 1);
      }
    }

    if (f * 2 <= 100000) {
      if(field[f * 2] != 0) {
        if (field[f * 2] == field[f] + 1){
          cntCheck[f * 2] += cntCheck[f];
        }
      }
      else {
        field[f * 2] = field[f] + 1;
        cntCheck[f * 2] += cntCheck[f];
        q.push(f * 2);
      }
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
  field[N] = 1;
  cntCheck[N] = 1;
  go();

  cout << field[K] - 1 << endl << cntCheck[K];

  return 0;
}