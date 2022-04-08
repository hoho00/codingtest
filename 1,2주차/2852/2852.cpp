#include <iostream> 

using namespace std; 

int timeTable[3000];

int strToSec(string str) {
  int index = str.find(':');
  int min = stoi(str.substr(0, index)) * 60;
  int sec = stoi(str.substr(index + 1));
  //cout << "min : " << min << " sec : " << sec<< endl;
  return min + sec;
}

string secToStr(int sec) {
  int minTime = sec / 60;
  int secTime  = sec % 60;
  string minStr = to_string(minTime);
  string secStr = to_string(secTime);
  if (minStr.size() <= 1) minStr = '0' + minStr;
  if (secStr.size() <= 1) secStr = '0' + secStr;
  return minStr + ':' + secStr;
}

void recordScore(string team, string scoreTime) {
  int sc = strToSec(scoreTime);
  if (team == "1") {
    for (int i = sc; i < 2880; i++) {
      timeTable[i] ++;
    }
  }
  else {
    for (int i = sc; i < 2880; i++) {
      timeTable[i] --;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string team, scoreTime;
    cin >> team >> scoreTime;
    recordScore(team, scoreTime);
  }
  int team1WinTime = 0;
  int team2WinTime = 0;
  for (int i = 0; i < 2880; i++) {
    if (timeTable[i] > 0) team1WinTime ++;
    else if (timeTable[i] < 0) team2WinTime ++;
  }
  cout << secToStr(team1WinTime) << endl;
  cout << secToStr(team2WinTime);
  return 0;
}