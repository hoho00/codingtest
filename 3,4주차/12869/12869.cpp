#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std; 

int scv[64][64][64];
vector<vector<int>> attacks;
int N;
queue<tuple<int, int, int>> q;

void BFS() {

  while(!q.empty()) {
    int a, b, c;
    tie(a, b, c) = q.front();
    if (a == 0 && b == 0 && c == 0) break;
    q.pop();
    for (int i = 0; i < attacks.size(); i++) {
      int newA = max(0, a - attacks[i][0]);
      int newB = max(0, b - attacks[i][1]);
      int newC = max(0, c - attacks[i][2]);
      if (scv[newA][newB][newC] == 0) {
        q.push(make_tuple(newA, newB, newC));
        scv[newA][newB][newC] = scv[a][b][c] + 1;
      }
    }
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);


  cin >> N;

  int a[3] = {0, 0, 0};

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  scv[a[0]][a[1]][a[2]] = 1;

  vector<int> oneAttack = {9, 3, 1};
  do {
    attacks.push_back(oneAttack);
  } while(prev_permutation(oneAttack.begin(), oneAttack.end()));
  q.push(make_tuple(a[0], a[1], a[2]));
  BFS();
  cout << scv[0][0][0] - 1;

  return 0;
}