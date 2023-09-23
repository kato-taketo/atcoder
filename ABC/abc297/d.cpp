#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  ll a,b;
  cin >> a >> b;

  ll cnt=0,tmp;
  while(a!=b) {
    if(a<b) tmp=a, a=b, b=tmp;
    if(b==1) {
      cnt += (a-1); break;
    }
    if(a%b==0) {
      cnt += a/b-1; break;
    }
    cnt += a/b;
    a = a%b;
  }
  cout << cnt << endl;
}