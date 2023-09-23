#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  string s;
  cin >> n >> s;

  // -ooooを探す
  int res=0;
  int cnt=0;
  bool pre=false; // - is used
  rep(i,n) {
    if(s[i]=='-') pre=true, res=max(res,cnt),cnt=0;
    else if(s[i]=='o'&&cnt==0&&pre==true) {
      pre=false; cnt++;
    } else if(s[i]=='o'&&cnt>0) {cnt++;  }
  }
  res = max(res,cnt);

  // oooo-を探す
  pre=false, cnt=0;
  for(int i=n-1; i>=0; i--) {
    if(s[i]=='-') pre=true, res=max(res,cnt), cnt=0;
    else if(s[i]=='o'&&cnt==0&&pre==true) {
      pre=false; cnt++;
    } else if(s[i]=='o'&&cnt>0) cnt++;
  }
  res = max(res,cnt);

  if(res==0) cout << -1 << endl;
  else cout << res << endl;
}