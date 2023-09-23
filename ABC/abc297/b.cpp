#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string s;
  cin >> s;

  int x=-1,y;
  rep(i,8) {
    if(x==-1&&s[i]=='B') x=i;
    else if(s[i]=='B') y=i;
  }
  if((x-y)%2==0) {
    cout << "No" << endl; return 0;
  }
  x=-1,y=-1;
  int z;
  rep(i,8) {
    if(x==-1&&s[i]=='R') x=i;
    else if(s[i]=='R') y=i;
    if(s[i]=='K') z=i;
  }
  if(x<z&&z<y) {
    cout << "Yes" << endl;
  } else cout << "No" << endl;
}