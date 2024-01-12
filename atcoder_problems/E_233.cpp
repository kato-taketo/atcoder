#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

string x;
vector<int> s,res;
int len, tmp=0;
int main(void) {  
  cin >> x;
  len = x.length();
  s.resize(len+1,0);
  rep(i,len) {
    s[1] += x[i]-'0';
  }
  for(int i=len-1; i>=1; i--) {
    s[len-i+1] = s[len-i]-(x[i]-'0');
  }
  for(int i=1; i<=len; i++) {
    res.push_back(s[i]%10);
    s[i] /= 10;
    if(i!=len) s[i+1] += s[i];
  }
  tmp = s[len];
  while(tmp>0) {
    res.push_back(tmp%10);
    tmp/=10;
  }
  for(int i=res.size()-1; i>=0; i--) {
    cout << res[i];
  }
  cout << endl;
}