#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

int N, A, B, C, D;

struct Diet{
  int a;
  int b;
  int c;
  int d;
  int price;
  Diet(int a, int b, int c, int d, int price) {
    this -> a = a;
    this -> b = b;
    this -> c = c;
    this -> d = d;
    this -> price = price;
  }
};

int minPrice = 987654321;

vector<Diet> v;
vector<vector<int>> lists;

void DFS(int L, vector<int> d, int aSum, int bSum, int cSum, int dSum, int priceSum, int cnt) {
  if (L > v.size()) {
    return;
  }
  if (d.size() == cnt) {
    if (aSum >= A && bSum >= B && cSum >= C && dSum >= D) {
      if (minPrice > priceSum) {
        lists.clear();
        minPrice = priceSum;
        sort(d.begin(), d.end());
        lists.push_back(d);
        return;
      }
      if (minPrice == priceSum) {
        minPrice = priceSum;
        sort(d.begin(), d.end());
        lists.push_back(d);
        return;
      }
    }
    return;
  }

  DFS(L + 1, d, aSum, bSum, cSum, dSum, priceSum, cnt);
  d.push_back(L);
  DFS(L + 1, d, aSum + v[L].a, bSum + v[L].b, cSum + v[L].c, dSum + v[L].d, priceSum + v[L].price, cnt);
}

bool compare(vector<int>& a, vector<int>& b) {
  int minL = min(a.size(), b.size());
  for (int i = 0; i < minL; i++) {
    if (a[i] == b[i]) continue;
    return a[i] < b[i];
  }
  return a.size() < b.size();
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  cin >> A >> B >> C >> D;

  for (int i = 0; i < N; i++) {
    int a, b, c, d, price;
    cin >> a >> b >> c >> d >> price;
    v.push_back(Diet(a, b, c, d, price));
  }
  int pick = 1;
  while (pick <= N) {
    vector<int> tmp;
    //lists.clear();
    DFS(0, tmp, 0, 0, 0, 0, 0, pick);
    pick++;
  }
  if (minPrice == 987654321) {
    cout << "-1";
    return 0;
  }
  cout << minPrice << endl;
  sort(lists.begin(), lists.end(), compare);
  
  
  for (auto e : lists[0]) {
    cout << e + 1 << " ";
  }

  return 0;
}