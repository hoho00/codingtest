#include <iostream>

using namespace std;

int parking[104];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int A, B, C, answer = 0; 
  cin >> A >> B >> C;
  for (int i = 0; i < 3; i++) {
    int a1, a2;
    cin >> a1 >> a2;
    for (int i = a1 + 1; i <= a2; i++) {
      parking[i] ++;
    }
  }

  for (int i = 1; i <= 100; i++) {
    if (parking[i] == 1) {
      answer += A;
    }
    else if (parking[i] == 2) {
      answer += B * 2;
    }
    else if (parking[i] == 3) {
      answer += C * 3;
    }
  }

  cout << answer;


  return 0;
}