#include <iostream> 
#include <queue>

using namespace std; 

priority_queue<double, vector<double>, greater<double> > pq;

int N;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    double tmp;
    scanf("%lf", &tmp);
    pq.push(tmp);
  }
  for (int i = 0; i < 7; i++) {
    printf("%.3f\n", pq.top());
    pq.pop();
  }
  return 0;
}