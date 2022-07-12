#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std; 
int field[104][104];
int tmpField[104][104];

typedef struct {
  int s, d, z;
} Shark;

int H, W, M, T = 0, ans = 0;
unordered_map<int, Shark> sMap;
vector<pair<int, int>> dupliPair;

void capture(int curW) {
  for (int i = 0; i < H; i++) {
    if (field[i][curW] != 0) {
      ans += sMap[field[i][curW]].z;
      sMap.erase(field[i][curW]);
      field[i][curW] = 0;
      break;
    }
  }
}

void moveShark(int h, int w, int shark) {
  int dir = sMap[shark].d;
  int v = sMap[shark].s;
  int sSize = sMap[shark].z;
  // tmpField[h][w] = 0;
  for (int i = 1; i <= v; i++) {
    if (dir == 1) {
      if (h == 0) {
        dir = 2;
        h ++;
      }
      else {
        h --;
      }
    }
    else if (dir == 2) {
      if (h == H - 1) {
        dir = 1;
        h --;
      }
      else {
        h ++;
      }
    }
    else if (dir == 3) {
      if (w == W - 1) {
        dir = 4;
        w --;
      }
      else {
        w ++;
      }
    }
    else if (dir == 4) {
      if (w == 0) {
        dir = 3;
        w ++;
      }
      else {
        w--;
      }
    }
  }
  sMap[shark].d = dir;
  if (tmpField[h][w] == 0) tmpField[h][w] = shark;
  else {
    if (sMap[tmpField[h][w]].z < sSize) {
      sMap.erase(tmpField[h][w]);
      tmpField[h][w] = shark;
    }
    else {
      sMap.erase(shark);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> H >> W >> M;
  for (int i = 1; i <= M; i++) {
    int h, w, s, d, z;
    cin >> h >> w >> s >> d >> z;
    h--; w--;
    Shark shark;
    shark.s = s;
    shark.d = d;
    shark.z = z;
    field[h][w] = i;
    sMap[i] = shark;
  }
  while (T < W) {
    T++;
    capture(T - 1);
    fill(&tmpField[0][0], &tmpField[0][0] + 104 * 104, 0);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (field[i][j] == 0) continue;
        moveShark(i, j, field[i][j]);
      }
    }
    // cout << T << endl;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        field[i][j] = tmpField[i][j];
        // cout << field[i][j] << " ";
      }
      // cout << endl;
    }
    // cout << endl;
  }
  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) {
  //     cout << field[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // moveShark(2, 2, field[2][2]);
  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) {
  //     cout << field[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << ans;
  return 0;
}