#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

string s;
int len;
vector<ll> U,D;
ll res=0;
int main(void) {
  cin >> s;
  len = s.length();
  U.resize(len+1,0), D.resize(len+1,0);
  rep(i,len) {
    if(i==0) {
      if(s[i]=='U') U[i]=1;
      else if(s[i]=='D') D[i]=1;
    } else {
      if(s[i]=='U') U[i]=U[i-1]+1, D[i]=D[i-1];
      else if(s[i]=='D') D[i]=D[i-1]+1, U[i]=U[i-1];
    }
  }

  rep(i,len) {
    if(s[i]=='U') {
      res += (U[len-1]-U[i])*3;  // U,U
      res += (D[len-1]-D[i])*2;  // U,D
    } else {
      res += (U[len-1]-U[i])*4;  // D,U
      res += (D[len-1]-D[i])*3;  // D,D
    }
  }
  cout << res << endl;
}