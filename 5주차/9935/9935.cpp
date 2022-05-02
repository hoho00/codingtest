#include <iostream> 
#include <string>
#include <stack>

using namespace std; 

string field;
string bomb;
string ss;
int check[1000001];


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> field;
  cin >> bomb;

  for (int i = 0; i < field.size(); i++) {
    ss += field[i];
    if (ss.size() >= bomb.size() && ss.substr(ss.size() - bomb.size(), bomb.size()) == bomb) {
      ss.erase(ss.begin() + (ss.size() - bomb.size()), ss.end());
    }
  }

  if (ss.size() == 0) {
    cout << "FRULA";
  }
  else {
    cout << ss;
  }
  return 0;
}