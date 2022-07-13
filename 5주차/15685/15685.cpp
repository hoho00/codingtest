#include <iostream> 
#include <vector>
#include <unordered_set>
#include <set>

using namespace std; 

int N, ans = 0;
int field[104][104];
set<pair<int, int>> s;

vector<pair<int, int>> makeZero(pair<int, int> st, int d) {
  vector<pair<int, int>> res;
  res.push_back(st);
  switch (d)
  {
  case 0:{
    pair<int, int> tmp = st;
    tmp.first++;
    res.push_back(tmp);
    return res;
    break;  
  }
    
  case 1: {
    pair<int, int> tmp = st;
    tmp.second--;
    res.push_back(tmp);
    return res;
    break;
  }
  case 2: {
    pair<int, int> tmp = st;
    tmp.first--;
    res.push_back(tmp);
    return res;
    break;
  }
  case 3: {
    pair<int, int> tmp = st;
    tmp.second++;
    res.push_back(tmp);
    return res;
    break;
  }
  default:
    break;
  }
}

void turnPair(vector<pair<int, int>>& ps) {
  pair<int, int> st = ps.back();
  vector<pair<int, int>> newPs;
  for (int i = ps.size() - 1; i >=0; i--) {
    newPs.push_back(ps[i]);
  }
  for (int i = 0; i < newPs.size(); i++) {
    newPs[i].first -= st.first;
    newPs[i].second -= st.second;
    int tmp = newPs[i].first;
    newPs[i].first = newPs[i].second;
    newPs[i].second = tmp;
    newPs[i].first *= -1;
    newPs[i].first += st.first;
    newPs[i].second += st.second;
  }
  for (int i = 1; i < newPs.size(); i++) {
    ps.push_back(newPs[i]);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int w, h, d, g;
    cin >> w >> h >> d >> g;
    vector<pair<int, int>> curve = makeZero({w, h}, d);
    for (auto e : curve) s.insert(e);
    for (int i = 1; i <= g; i++) {
      turnPair(curve);
      for (auto e : curve) {
        // cout << e.first << e.second << endl;
        s.insert(e);
      }
      // cout << endl;
    }
    // for (auto e : curve) cout << e.first << " " << e.second << endl;
    // cout << endl;
    // cout << "pairs : "<< endl;
    // for (auto e : s) cout << e.first << e.second << endl;
    // cout << endl;
  }

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      // pair<int, int> lt = {i, j};
      if (s.find({i, j}) == s.end() || s.find({i + 1, j}) == s.end() || s.find({i, j + 1}) == s.end() || s.find({i + 1, j + 1}) == s.end()) continue;
      ans++;
    }
  }
  cout << ans;

  return 0;
}