#include <iostream> 
#include <map>
#include <vector>

using namespace std; 

int T, N, M;

int root[1004];

void initiateRoot() {
  for (int i = 0; i <= 1000; i++) {
    root[i] = i;
  }
}

int findRoot(int a) {
  if (root[a] == a) return a;
  return findRoot(root[a]);
}

void unionRoot(int a, int b) {
  int rootA = findRoot(a);
  int rootB = findRoot(b);
  root[rootA] = rootB;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> T;

  while(T > 0) {
    initiateRoot();
    cin >> N >> M;

    bool isTree = true;
    //cout << N << M << endl;

    if (N != M + 1) isTree = false;
    if (isTree) {
      for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        unionRoot(a, b);
      }
    }
    else {
      for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
      }
    }
    map<int, int> mm;
    for (int i = 1; i <= N; i++) {
      //cout << i << " : " << findRoot(i) << endl;
      mm[findRoot(i)];
    }
    if (mm.size() > 1) isTree = false;
    else isTree = true;

    if (isTree) {
      cout << "tree" << '\n';
    }
    else {
      cout << "graph" << '\n';
    }
    
    T--;
  }

  return 0;
}