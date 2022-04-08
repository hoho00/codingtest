#include <iostream> 
#include <string>

using namespace std;

int N;
char field[65][65];

string quad(int h, int w, int size) {
  if (size == 1) return string(1, field[h][w]);
  string ret = "";
  for (int i = h; i < h + size; i++) {
    for (int j = w; j < w + size; j++) {
      if (field[h][w] != field[i][j]) {
        ret += '(';
        ret += quad(h, w, size / 2);
        ret += quad(h, w + size / 2, size / 2);
        ret += quad(h + size / 2, w, size / 2);
        ret += quad(h + size / 2 , w + size / 2, size / 2);
        ret +=  ')';
        return ret;
      }
    }
  }
  return string(1, field[h][w]);
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   freopen("input.txt", "rt", stdin);

   cin >> N;
   for (int i = 0; i < N; i++) {
     string s;
     cin >> s;
     for (int j = 0; j < N; j++) {
       field[i][j] = s[j];
     }
   }

  //  for (int i = 0; i < N; i++) {
  //    for (int j = 0; j < N; j++) {
  //      cout << field[i][j] << " ";
  //    }
  //    cout << endl;
  //  }

   cout << quad(0, 0, N);


   return 0;
}