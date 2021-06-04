#include <bits/stdc++.h>

using namespace std;
#define pi pair < int, int >
#define pb push_back
//#define MAX 1e15 + 1
//const int N = 1e9 + 7;



  
int main() {

  int t,T;
  cin >> T;
  for (int t = 1;t<=T;t++) {
    

    vector < pair < int, pi >> v;
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      v.pb({x,{y,i}});
      
    }
    char ans[n];
    int cend, jend;
    sort(v.begin(), v.end());
    ans[v[0].second.second] = 'C';
    cend = v[0].second.first;
    jend = 0;
    // j = v[1].second.first;
    // ans[v[1].second.second] = 'J';

    int flag = 0;
    for (int i = 1; i < n; i++) {
      int index = v[i].second.second, end = v[i].second.first, start = v[i].first;
      if (cend <= start ) {
        cend = end;
        ans[index] = 'C';
      } else if (jend <= start ) {
        jend = end;
        ans[index] = 'J';
      } else {
        cout << "Case #" << t << ": IMPOSSIBLE"<<endl; flag = 1;break;
      }

    }
    if(flag ==1)  continue;
    cout << "Case #" << t << ": ";
    for (int i = 0; i < n; i++)
     cout << ans[i];
    cout << endl;
  }
  return 0;
}