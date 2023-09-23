#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
string abc="abcdefghijklmnopqrstuvwxyz";
string atcoder="atcoder";

int main(void) {
  string S,T;
  cin >> S >> T;

  int abc_len=abc.length();
  vector<int> s_cnt(abc_len,0), t_cnt(abc_len,0);
  int s_att=0, t_att=0;
  rep(i,S.length()) {
    if(S[i]>='a'&&S[i]<='z') s_cnt[S[i]-'a']++;
    if(T[i]>='a'&&T[i]<='z') s_cnt[T[i]-'a']++;
    if(S[i]=='@') s_att++;
    if(T[i]=='@') t_att++;
  }
  rep(i,abc_len) {
    bool key=false;
    rep(j,atcoder.length()) {
      if(atcoder[j]==abc[i]) key=true;
    }
    if(!key) {
      if(s_cnt[i]!=t_cnt[i]) { cout << "No" << endl; return 0; }
    } else {
      if(s_cnt[i]>t_cnt[i]) t_att-=(s_cnt[i]-t_cnt[i]);
      else if(s_cnt[i]<t_cnt[i]) s_att-=(t_cnt[i]-s_cnt[i]);
      if(t_att<0||s_att<0) {
        cout << "No" << endl; return 0;
      }
    }
  }
  cout << "Yes" << endl;
}