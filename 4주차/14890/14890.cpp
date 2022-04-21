#include <iostream> 
#include <cmath>
#include <vector>

using namespace std; 

int N, L, ans = 0;

int field[104][104];
int check[104];

bool checkRoad(vector<int> a) {
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (a[i - 1] == a[i]) {
      if (check[i] == 0) cnt++;
    }
    else if (a[i - 1] < a[i]){
      //cout << a[i] << " : " << cnt << endl;
      if (cnt < L) return false;
      if (abs(a[i - 1] - a[i]) > 1) return false;
      cnt = 1;
    }
    else if (a[i - 1] > a[i]) {
      //cout << a[i - 1] << " : " << endl;
      if (abs(a[i - 1] - a[i]) > 1) return false;
      for (int j = 0; j < L; j++) {
        //cout << a[i + j] << " ";
        check[i + j] = 1;
        if (a[i + j] != a[i]) return false;
      }
      cnt = 0;
      //cout << endl;
    }
  }

  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N >> L;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> field[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    vector<int> tmp;
    fill(&check[0], &check[0] + 104, 0);
    for (int j = 0; j < N; j++) {
      tmp.push_back(field[i][j]);
    }
    if (checkRoad(tmp)) {
      //cout << i << " ";
      ans ++;
    }
  }
  //cout << endl;

  for (int i = 0; i < N; i++) {
    vector<int> tmp;
    fill(&check[0], &check[0] + 104, 0);
    for (int j = 0; j < N; j++) {
      tmp.push_back(field[j][i]);
    }

    if (checkRoad(tmp) ) {
      //cout << i << " " ;
      ans ++;
    }
  }
  //cout << endl;
  cout << ans;


  // vector<int> tmp = {3, 2, 2, 2, 3, 3};

  // cout << checkRoad(tmp) << endl;
  // for (int i = 0; i < N; i++) cout << check[i] << " ";

  

  return 0;
}