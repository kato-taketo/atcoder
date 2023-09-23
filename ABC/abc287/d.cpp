#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string s,t;
  cin >> s >> t;

  vector<int> mae(t.length()+1,false), usiro(t.length()+1,false);
  mae[0]=true; usiro[t.length()]=true;
  rep(i,t.length()) {
    if(s[i]=='?'||t[i]=='?'||s[i]==t[i]) mae[i+1]=true;
    else break;
  }
  for(int i=t.length()-1; i>=0; i--) {
    if(s[i+s.length()-t.length()]=='?'||t[i]=='?'||t[i]==s[i+s.length()-t.length()]) usiro[i]=true;
    else break;
  }

  rep(i,t.length()+1) {
    if(mae[i]&usiro[i]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}