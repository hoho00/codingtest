#include <iostream> 
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std; 

vector<vector<int>> field;
vector<vector<int>> initField;
unordered_map<int, int> hMap;
unordered_map<int, int> wMap;
int inputBall;
int check[7][7];
int ans = 987654321;

void checkMap() {
  for (int i = 0; i < 7; i++) {
    int continuitySum = 0;
    int tmp = 0;
    bool isFirstZero = true;
    for (int j = 0; j < 7; j++) {
      if (field[i][j] != 0) {
        continuitySum++;
      }
      else {
        tmp = max(tmp, continuitySum);
        continuitySum = 0;
      }
    }
    if (continuitySum != 0) tmp = max(tmp, continuitySum);
    hMap[i] = tmp;
  }

  for (int i = 0; i < 7; i++) {
    int continuitySum = 0;
    int tmp = 0;
    bool isFirstZero = true;
    for (int j = 0; j < 7; j++) {
      if (field[j][i] != 0) {
        continuitySum++;
      }
      else {
        tmp = max(tmp, continuitySum);
        continuitySum = 0;
      }
    }
    if (continuitySum != 0) tmp = max(tmp, continuitySum);
    wMap[i] = tmp;
  }
}

void dropBall(int wLoc, int ball) {
  for (int i = 0; i < 7; i++) {
    if (field[i][wLoc] != 0) {
      field[i - 1][wLoc] = ball;
      return;
    }
  }
  field[6][wLoc] = ball;
}

void dropField() {
  for (int i = 0; i < 7; i++) {
    vector<int> tmp;
    for (int j = 0; j < 7; j++) {
      if (field[j][i] != 0) {
        tmp.push_back(field[j][i]);
      }
    }
    for (int j = 0; j < 7; j++) {
      if (j < 7 - tmp.size()) {
        field[j][i] = 0;
      }
      else {
        field[j][i] = tmp[j - (7 - tmp.size())];
      }
    }
  }
}

void chooseDelete() {
  for (auto e : hMap) {
    for (int i = 0; i < 7; i++) {
      if (e.second != 0 && field[e.first][i] == e.second) {
        check[e.first][i] = 1;
      }
    }
  }

  for (auto e : wMap) {
    for (int i = 0; i < 7; i++) {
      if (e.second != 0 && field[i][e.first] == e.second) {
        check[i][e.first] = 1;
      }
    }
  }
}

bool isChanged() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (check[i][j] != 0) return true;
    }
  }
  return false;
}

void deleteBall() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (check[i][j] == 1) {
        field[i][j] = 0;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  for (int i = 0; i < 7; i ++) {
    vector<int> tmpVector;
    for (int j = 0; j < 7; j++) {
      int tmp;
      cin >> tmp;
      tmpVector.push_back(tmp);
    }
    field.push_back(tmpVector);
    initField.push_back(tmpVector);
  }
  cin >> inputBall;
  
  for (int wLoc = 0; wLoc < 7; wLoc++) {
    field = initField;
    dropBall(wLoc, inputBall);
    
    int count = 0;
    while (1) {
      // if (wLoc == 2) {
      //   for (auto e : field) {
      //     for (auto k : e) {
      //       cout << k << " ";
      //     }
      //      cout << endl;
      //   }
      //   cout << endl;
      // }
      checkMap();
      // for (auto e : hMap) cout << e.first << " : " << e.second << endl;
      chooseDelete();
      if (!isChanged()) {
        int ballCount = 0;
        for (auto e : field) {
          for (auto k : e) {
            if (k != 0) ballCount++;
            cout << k << " ";
          }
          cout << endl;
        }
        cout << endl;
        ans = min(ans, ballCount);
        break;
      }
      deleteBall();
      dropField();
      fill(&check[0][0], &check[0][0] + 7 * 7, 0);
      count ++;
    }
    // cout<< wLoc << " : " << count << endl;
    
  }

  cout << ans;
  return 0;
}