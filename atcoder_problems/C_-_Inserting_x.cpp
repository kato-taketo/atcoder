#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
string s,notx;
vector<int> cnt;
int tmp,res;
int main(void) {
  cin >> s;
  notx = "";
  rep(i,s.size()) {
    if(s[i]!='x') notx = notx + s[i];
  }

  rep(i,notx.size()/2) {
    if(notx[i]!=notx[notx.size()-1-i]) {
      cout << -1 << endl; return 0;
    }
  }
  tmp = 0;
  res = 0;
  rep(i,s.size()) {
    if(s[i]=='x') tmp++;
    else {
      cnt.push_back(tmp); tmp=0;
    }
  }
  cnt.push_back(tmp);
  //cout << "cnt" << endl;
  //rep(i,cnt.size()) cout << cnt[i] << " ";
  //cout << endl;
  rep(i,cnt.size()/2) {
    res += abs(cnt[i]-cnt[cnt.size()-1-i]);
  }
  cout << res << endl;
}