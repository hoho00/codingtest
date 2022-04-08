#include <iostream> 
#include <algorithm>
#include <vector>
#include <map>

struct st
{
  int value;
  int count;
  int index;
};



using namespace std;

bool compare(st& st1, st& st2) {
  if (st1.count == st2.count) return st1.index < st2.index;
  return st1.count > st2.count;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N, C;
  map<int, int> m;
  map<int, int> mIndex;
  vector<st> v;

  cin >> N >> C;

  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    m[tmp]++;
    if (mIndex[tmp] == 0) mIndex[tmp] = i;
  }

  for (auto e : m) {
    st s;
    s.value = e.first;
    s.count = e.second;
    s.index = mIndex[e.first];
    v.push_back(s);
  }
  sort (v.begin(), v.end(), compare);

  for (auto e : v) {
    for (int i = 0; i < e.count; i++) {
      cout << e.value << " ";
    }
    //cout << e.value << " " << e.count << " " << e.index << endl;
  }

  return 0;
}