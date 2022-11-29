#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string S;
  cin >> S;
  string abc="abcdefghijklmnopqrstuvwxyz";
  vector<int> vec(abc.length(),0);
  rep(i,3) vec[S[i]-'a']++;
  int res=-1;
  rep(i,abc.length()) if(vec[i]==1) res=i;
  if(res==-1) cout << -1 << endl;
  else cout << char('a'+res) << endl;
}