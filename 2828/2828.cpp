#include <iostream>
#include <vector>

using namespace std; 

bool isIn(int basket, int size, int apple) {
  if (basket <= apple && basket + size - 1 >= apple) return true;
  return false;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   freopen("input.txt", "rt", stdin);
   int N, M, J, ans = 0;
   vector<int> v;
   cin >> N >> M >> J;
   for (int i = 0; i < J; i++) {
     int tmp;
     cin >> tmp;
     v.push_back(tmp);
    }
    int basket = 1;

    for (int i = 0; i < J; i++) {
      if (!isIn(basket, M, v[i])) {
        if (v[i] > basket) {
          ans += v[i] - (basket + M - 1);
          basket += v[i] - (basket + M - 1);
        }
        else {
          ans += basket - v[i];
          basket -= basket - v[i];
        }
      }
    }

  cout << ans;
  return 0;
}