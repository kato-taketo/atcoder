#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  pair<int,int> pos;
  pos=make_pair(0,0);

  map<pair<int,int>, int> mp;
  mp[pos]=1;
  rep(i,n) {
    int x,y;
    x = pos.first; y=pos.second;
    if(s[i]=='R') x++;
    else if(s[i]=='L') x--;
    else if(s[i]=='U') y++;
    else if(s[i]=='D') y--;
    pos = make_pair(x,y);
    if(mp[pos]!=0) {
      cout << "Yes" << endl; return 0;
    }
    mp[pos]=1;
  }
  cout << "No" << endl;
}