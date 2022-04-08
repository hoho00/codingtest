#include <iostream> 
#include <vector>

using namespace std; 
int N, root, deleting, ans = 0;

vector<vector<int>> tree;

void DFS(int node) {
  if (tree[node].size() == 0) {
    ans ++;
    return;
  }
  for (auto e : tree[node]) {
    if (e == -1) continue;
    DFS(e);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  for (int i = 0; i < N; i++) {
    vector<int> tmp;
    tree.push_back(tmp);
  }
  for(int i = 0; i < N; i++) {
    int node;
    cin >> node;
    if (node == -1){
      root = i;
      continue;
    }
    tree[node].push_back(i);
  }
  cin >> deleting;
  //cout << deleting << endl;

  for (int i = 0; i <tree.size(); i++) {
    for (int j = 0; j< tree[i].size(); j++) {
      if (tree[i][j] == deleting) {
        tree[i].erase(tree[i].begin() + j);
      }
    }
  }
  tree[deleting].clear();

  if (deleting == root) {
    ans = 0;
  }
  else {
    DFS(root);
  }

  cout << ans;
  
  return 0;
}

