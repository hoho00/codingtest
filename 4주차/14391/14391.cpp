#include <iostream> 
#include <vector>
#include <string>

using namespace std; 

int H, W, ans = 0;

int a[5][5] = {{1, 1, 1}, {1, 0, 0}, {1, 0, 0}, {0, 0, 0}};
int field[5][5];
int check[5][5];

string DFS(int h, int w, int ud, string str) {
  string ret = "";
  if (ud == 1) {
    for (int i = h; i < H; i++) {
      if (a[i][w] != ud) break;
      check[i][w] = 1;
      ret += to_string(field[i][w]);
    }
  }
  else {
    for (int i = w; i < W; i++) {
      if (a[h][i] != ud) break;
      check[h][i] = 1;
      ret += to_string(field[h][i]);
    }
  }
  return ret;
  
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> H >> W;
  int ls = H * W;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j <W; j++) {
      char c;
      cin >> c;
      field[i][j] = c - '0';
    }
  }

  for (int k = 0; k <= (1 << ls) - 1; k++) {
    int cnt = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        a[i][j] = ((k & (1 << cnt)) == 0);
        cnt ++;
      }
    }

    // for (int i = 0; i < H; i++) {
    //   for (int j = 0; j < W; j++) {
    //     cout << a[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    // cout << endl;
    fill(&check[0][0], &check[0][0] + 5 * 5, 0);

    int tmpAns = 0;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (check[i][j] == 0) {
          string s = DFS(i, j, a[i][j], "");
          tmpAns += stoi(s);
        }
      }
    }
    //cout << k << " : " << tmpAns << endl;
    ans = max(ans, tmpAns);

  }
  cout << ans;

//  for (int i  = 0; i < H; i++) {
//    for (int j = 0; j < W; j++) {
//      if (check[i][j] == 0) {
//        string s = DFS(i, j, a[i][j], "");
//        cout << i << ", "<< j << " : " <<s << endl;
//      }
//    }
//  }

  return 0;
}