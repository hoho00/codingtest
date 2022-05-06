#include <iostream> 
#include <map>
#include <vector>
#include <unordered_map>

using namespace std; 

int N, K, ans = 0;

unordered_map<int, int> plug;
unordered_map<int, int> cnt;
vector<int> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt", "rt", stdin);

  cin >> N >> K;

  for (int i = 0; i < K; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
    cnt[tmp]++;
  }

  for (int i = 0; i < K; i++) {
    if (plug.size() >= N) {
      if (plug.find(v[i]) == plug.end()) {
        int mustLeave = 0;
        int mustLeaveIndex = 0;
        for (auto e : plug) {
          int thisLeave = 0;
          int thisIndex = 987654321;
          for (int j = i + 1; j < K; j++) {
            if (e.first == v[j]) {
              thisIndex = j;
              thisLeave = v[j];
              break;
            }
          }
          if (mustLeaveIndex < thisIndex) {
            mustLeaveIndex = thisIndex;
            mustLeave = e.first;
            //break;
          }
        }
        // cout << "plug : " << endl;
        // for (auto e : plug) {
        //   cout << e.first << " ";
        // }
        // cout << endl;

        // cout << "leave : " << mustLeave << endl;
        plug.erase(mustLeave);
        plug[v[i]] = 1;
        ans++;
      }
    }
    else {
      if (plug.find(v[i]) == plug.end()) {
        plug[v[i]] = 1;
      }
    }
  }

  cout << ans;



  return 0;
}