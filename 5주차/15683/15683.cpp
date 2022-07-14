#include <iostream> 
#include <unordered_map>
#include <vector>

using namespace std; 

int H, W, ans = 987654321;
int field[9][9];
int initfield[9][9];

vector<pair<int, int>> v;
vector<int> a;

void makeFill(int h, int w, char d) {
  switch (d) {
    case 'r' : {
      if (w == W - 1) return;
      for (int i = w + 1; i < W; i++) {
        if (field[h][i] == 6) return;
        if (field[h][i] == 0) field[h][i] = -1;
      }
      return;
    }
    
    case 'l' : {
      if (w == 0) return;
      for (int i = w - 1; i >= 0; i--) {
        if (field[h][i] == 6) return;
        if (field[h][i] == 0) field[h][i] = -1;
      }
      return;
    }

    case 'u' : {
      if (h == 0) return;
      for (int i = h - 1; i >= 0; i--) {
        if (field[i][w] == 6) return;
        if (field[i][w] == 0) field[i][w] = -1;
      }
      return;
    }

    case 'd' : {
      if (h == H - 1) return;
      for (int i = h + 1; i < H; i++) {
        if (field[i][w] == 6) return;
        if (field[i][w] == 0) field[i][w] = -1;
      }
      return;
    }
    default:
      break;
  }
}

void fillObserve(int h, int w, int dir) {
  int type = field[h][w];
  switch (type)
  {
  case 1: {
    //right
    if (dir == 1) {
      makeFill(h, w, 'r');
    }
    //left
    else if (dir == 2) {
      makeFill(h, w, 'l');
    }
    //up
    else if (dir == 3) {
      makeFill(h, w, 'u');
    }
    //down
    else if (dir == 4) {
      makeFill(h, w, 'd');
    }
    break;
  }
  case 2: {
    if (dir == 1 || dir == 2) {
      makeFill(h, w, 'r');
      makeFill(h, w, 'l');
    }
    else if (dir == 3 || dir == 4) {
      makeFill(h, w, 'u');
      makeFill(h, w, 'd');
    }
    break;
  }
  case 3: {
    if (dir == 1) {
      makeFill(h, w, 'u');
      makeFill(h, w, 'r');
    }
    else if (dir == 2) {
      makeFill(h, w, 'd');
      makeFill(h, w, 'r');
    }
    else if (dir == 3) {
      makeFill(h, w, 'd');
      makeFill(h, w, 'l');
    }
    else if (dir == 4) {
      makeFill(h, w, 'u');
      makeFill(h, w, 'l');
    }
    break;
  }
  case 4: {
    if (dir == 1) {
      // makeFill(h, w, 'u');
      makeFill(h, w, 'd');
      makeFill(h, w, 'r');
      makeFill(h, w, 'l');
    }
    else if (dir == 2) {
      makeFill(h, w, 'u');
      // makeFill(h, w, 'd');
      makeFill(h, w, 'r');
      makeFill(h, w, 'l');
    }
    else if (dir == 3) {
      makeFill(h, w, 'u');
      makeFill(h, w, 'd');
      // makeFill(h, w, 'r');
      makeFill(h, w, 'l');
    }
    else if (dir == 4) {
      makeFill(h, w, 'u');
      makeFill(h, w, 'd');
      makeFill(h, w, 'r');
      // makeFill(h, w, 'l');
    }
    break;
  }
  case 5: {
    makeFill(h, w, 'u');
    makeFill(h, w, 'd');
    makeFill(h, w, 'r');
    makeFill(h, w, 'l');
    break;
  }
  default:
    break;
  }
}

void observe(int index, int dir) {
  int h = v[index].first;
  int w = v[index].second;
  fillObserve(h, w, dir);
}

void DFS(int L, vector<int>& t) {
  if (L >= t.size()) {
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        field[i][j] = initfield[i][j];
      }
    }
    for (int i = 0; i < t.size(); i++) {
      // cout << v[i].first << ", " << v[i].second << " / ";
      observe(i, t[i]);
    }
    // cout << endl;
    int tmpSum = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (field[i][j] == 0) tmpSum++;
        // cout << field[i][j] << " ";
      }
      // cout << endl;
    }
    ans = min(ans, tmpSum);
    // cout << endl;
    return;
  }
  for (int i = 1; i <= 5; i++) {
    t[L] = i;
    DFS(L + 1, t);
    t[L] = 0;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
      initfield[i][j] = field[i][j];
      if (field[i][j] != 0 && field[i][j] != 6) {
        a.push_back(0);
        v.push_back({i, j});
      }
    }
  }

  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) {
  //     cout << field[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // for (int i = 0; i < 4; i++) a.push_back(i);

  DFS(0, a);

  cout << ans;

  return 0;
}