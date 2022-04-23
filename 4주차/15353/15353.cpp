#include <iostream> 
#include <string>
#include <algorithm>

using namespace std; 

typedef long long ll;

string A, B;
int upNumber[1000004];

string addBigNumber(string a, string b) {
  string ret = "";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < b.size(); i++) {
    int sum = (a[i] - '0') + (b[i] - '0') + upNumber[i];
    if (sum >= 10) {
      upNumber[i + 1] = 1;
      sum -=10;
    }
    ret += to_string(sum);
  }
  for (int i = b.size(); i < a.size(); i++) {
    int sum = (a[i] - '0') + upNumber[i];
    if (sum >= 10) {
      upNumber[i + 1] = 1;
      sum -=10;
    }
    ret += to_string(sum);
  }
  if (upNumber[a.size()] == 1) ret += '1';
  reverse(ret.begin(), ret.end());
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> A >> B;
  if (A.size() > B.size()) cout << addBigNumber(A, B);
  else cout << addBigNumber(B, A);
  return 0;
}