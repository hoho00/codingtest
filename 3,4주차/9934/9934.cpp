#include <iostream> 
#include <vector>
#include <cmath>

using namespace std; 

vector<int> tree[1030];
int depth;
vector<int> visit;

void go(int L, int lt, int rt) {
  int mid = (rt + lt) / 2;
  if (rt - lt == 2) {
    tree[L].push_back(visit[mid]);
    tree[L + 1].push_back(visit[lt]);
    tree[L + 1].push_back(visit[rt]);
    return;
  }
  tree[L].push_back(visit[mid]);
  go(L + 1, lt, mid - 1);
  go(L + 1, mid + 1, rt);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> depth;
  int l = pow(2, depth) - 1;
  for (int i = 0; i < l; i++) {
    int tmp;
    cin >> tmp;
    visit.push_back(tmp);
  }
  go(0, 0, l - 1);
  //cout << l ;
  for (int i = 0; i < depth; i++) {
    for (auto e: tree[i]) {
      cout << e << " ";
    }
    cout << endl;
  }
  //go(0, 0, l);

  return 0;
}