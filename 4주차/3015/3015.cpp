#include <iostream> 
#include <vector>
#include <algorithm>
#include <stack>

using namespace std; 
typedef long long ll;

int N, ans = 0;
vector<int> v;
stack<int> st;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  //st.push(0);
  for (int i = 0; i < N; i++) {
    if (st.size() && v[st.top()] <= v[i]) {
      int cnt = 0;
      cout << i << " : " << st.size() << " : ";
      while (st.size() && v[st.top()] <= v[i]) {
        cnt ++;
        if (v[st.top()] == v[i]) {

        }
        else {
          st.pop();
        }
      }
      cout << cnt << endl;
      ans += cnt;
    }
    else if (st.size() && v[st.top()] > v[i]) {
      //st.push(i);
      ans ++;
    }
    if(st.size()) ans++;
    st.push(i);
  }
  // int cnt = 0;
  // while (st.size() && v[st.top()] < v.back()) {
  //   cnt ++;
  //   st.pop();
  // }
  // ans += cnt;
  cout << ans;


  return 0;
}