#include <iostream> 
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std; 

int N;
int maxAns = INT_MIN, minAns = INT_MAX;

vector<int> v;
vector<int> opOrder;
int op[4]; 
stack<int> st;
stack<int> initSt;

int cal(int f, int s, int op) {
  switch (op)
  {
  case 0:
    return f + s;
    /* code */
    break;
  case 1:
    return f - s;
    /* code */
    break;
  case 2:
    return f * s;
    /* code */
    break;
  case 3:
    return f / s;
    /* code */
    break;

  default:
    return 0;
    break;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
    // st.push(tmp);
    // initSt.push(tmp);
  } 
  for (int i = N - 1; i >= 0; i--) {
    st.push(v[i]);
    initSt.push(v[i]);
  }
  for (int i = 0; i < 4; i++) {
    cin >> op[i];
  }

  for (int i = 0; i < 4; i++) {
    if (op[i] == 0) {
      opOrder.push_back(-1);
      continue;
    }
    for (int j = 0; j < op[i]; j++) {
      opOrder.push_back(i);
    }
  }
  // for (auto e : opOrder) cout << e;
  sort(opOrder.begin(), opOrder.end());
  do {
    st = initSt;
    for (auto e : opOrder) {
      if (e == -1) continue;
      int f = st.top();
      st.pop();
      int s = st.top();
      st.pop();
      int res = cal(f, s, e);
      st.push(res);
      // cout << f << ", "<< e << ", " << s << " = " << st.top();
      // cout << endl;
    }
    // cout << " : " << st.top();
    // cout << endl;
    maxAns = max(maxAns, st.top());
    minAns = min(minAns, st.top());
  } while(next_permutation(opOrder.begin(), opOrder.end()));
  cout << maxAns << endl << minAns;
  return 0;
}