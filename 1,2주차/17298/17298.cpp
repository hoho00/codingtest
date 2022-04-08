#include <iostream> 
#include <vector>
#include <algorithm>
#include <stack>

using namespace std; 
vector<int> v(1000001);
vector<int> ans(1000001);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  int N;
  cin >> N;
  stack<int>st;
  
  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    v[i] = tmp;
  }
  fill(&ans[0], &ans[0] + N + 1, - 1);
  st.push(1);
  for (int i = 2; i <= N; i++) {
    while(!st.empty() && v[st.top()] < v[i]) {
      ans[st.top()] = v[i];
      st.pop();
    }
    st.push(i);
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }


  return 0;
}