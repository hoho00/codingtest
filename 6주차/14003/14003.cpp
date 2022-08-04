#include <iostream> 
#include <vector>
#include <algorithm>
#include <stack>

using namespace std; 

int N, maxSize = 0, maxBack = 0;
int len = 1;
vector<int> v;
vector<int> idx;
vector<int> lis(1000004);
stack<int> st;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    v.push_back(tmp);
    idx.push_back(0);
  }
  lis[0] = v[0];
  idx[0] = 0;
  for (int i = 1; i < N; i++) {
    auto l = lower_bound(lis.begin(), lis.end(), v[i]);
    int lPos = lower_bound(lis.begin(), lis.begin() + len, v[i]) - lis.begin();
    // cout << v[i] << " : " << lPos << endl;
    if (lis[lPos] == 0) len++;
    idx[i] = lPos;
    lis[lPos] = v[i];
    maxSize = max(maxSize, lPos);
  }

  // for (int i = 0; i < N; i++) {
  //   cout << lis[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < N; i++) {
  //   cout << idx[i] << " ";
  // }
  // cout << endl;
  
  for (int i = N - 1; i >= 0; i--) {
    if (maxSize == idx[i]) {
      st.push(v[i]);
      maxSize--;
    }
  }
  cout << st.size() << endl;
  while(st.size()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}