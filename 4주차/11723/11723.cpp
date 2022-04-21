#include <iostream> 
#include <set>
#include <cmath>

using namespace std; 
int N;
int S = 0;
int maxNumber = (1 << 21) -1;

void oper(string s) {
  int indx = s.find(' ');
  string operation = s.substr(0, indx);
  string valueString = s.substr(indx + 1);
  //cout << operation << " : " << valueString<<  endl;
  if (operation == "add") {
    int i = stoi(valueString);
    S |= (1 << i);
  }
  else if (operation == "remove") {
    int i = stoi(valueString);
    S &= ~(1 << i);
  }
  else if (operation == "check") {
    int i = stoi(valueString);
    if ((S & (1 << i)) == 0) cout << "0" << '\n';
    else cout << "1" << '\n';
  }
  else if (operation == "toggle") {
     int i = stoi(valueString);
     S ^= (1 << i);
  }
  else if (operation == "all") {
    S = maxNumber;
  }
  else if (operation == "empty") {
    S = 0;
  }
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N;
  //cout << bitset<20>(maxNumber) << endl;
  for (int i = 0; i <= N; i++) {
    string s;
    getline(cin, s);
    oper(s);
  }
  return 0;
}