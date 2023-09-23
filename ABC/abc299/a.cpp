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

  int index;
  int bar1=-1,bar2=-1;
  rep(i,n) if(s[i]=='*') index=i;
  rep(i,n) if(s[i]=='|') {
    if(bar1==-1) bar1=i;
    else bar2=i;
    } 
  if(bar1<index && index < bar2) cout << "in" << endl;
  else cout << "out" << endl;
}