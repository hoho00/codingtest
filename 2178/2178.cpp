#include <iostream> 
#include <queue>
#include <vector>
#include <string>

using namespace std; 

vector<string> field;
queue<pair<int, int>> q;
int check[104][104];
int H, W;

int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void BFS() {
  q.push({0, 0});
  check[0][0] = 1;
  while(q.size()) {
    int h = q.front().first;
    int w = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int newH = h + dh[i];
      int newW = w + dw[i];
      if (newH < 0 || newH >= H || newW < 0 || newW >= W || field[newH][newW] == '0' || check[newH][newW] != 0) continue;
      q.push({newH, newW});
      check[newH][newW] = check[h][w] + 1;
    }
  }
}



int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   freopen("input.txt", "rt", stdin);

   cin >> H >> W;

   for (int i = 0; i < H; i++) {
     string tmp;
     cin >> tmp;
     field.push_back(tmp);
   }
   BFS();
   cout << check[H - 1][W - 1];
   return 0;
}