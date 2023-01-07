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

  ll cnt=0;
  int tmp=0;
  rep(i,s.length()) {
    if(s[i]>='1' && s[i]<='9') {
      tmp=0;
      cnt++;
    } else if(s[i]=='0'&&tmp==0) {
      tmp++; 
      cnt++;  //'0'を押すことにする
    } else if(s[i]=='0'&&tmp==1) {
      tmp=0; 
    }
  }
  cout << cnt << endl;
}