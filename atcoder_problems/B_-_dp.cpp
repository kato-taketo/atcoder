#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int N;
string S,tmp,res;
int main(void) {
  cin >> N;
  cin >> S;
  tmp = S; res = S;
  int li=-1;
  rep(i,N) if(S[i]=='p') {
    li=i; break;
  }
  if(li==-1) {
    cout << S << endl; return 0;
  }
  for(int ri=li; ri<N; ri++) {
    tmp = S;
    for(int i=li; i<=ri; i++) {
      if(S[ri-(i-li)]=='d') tmp[i] = 'p';
      else tmp[i] = 'd';
    }
    res = min(res, tmp);
  }
  cout << res << endl;
}