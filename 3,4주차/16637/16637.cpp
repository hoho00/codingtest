#include <iostream> 
#include <string>
#include <vector>

using namespace std; 

int N, ans = -987654321;
string s;

vector<int> num;
vector<char> op;

int calculate(char oper, int a, int b) {
  if (oper == '+') return a + b;
  if (oper == '-') return a - b;
  if (oper == '*') return a * b;
  //else return 0;
}

void go(int L, int n) {
  if (L == num.size() - 1) {
    ans = max(ans, n);
    return;
  }
  go(L + 1, calculate(op[L], n, num[L + 1]));
  if (L + 2 <= num.size() - 1) {
    int tmp = calculate(op[L + 1], num[L + 1], num[L + 2]);
    go(L + 2, calculate(op[L], n, tmp));
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;

  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) num.push_back(s[i] - '0');
    else op.push_back(s[i]);
  }

 
  go(0, num[0]);

  cout << ans;
  return 0;
}