#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
string abc="abcdefghijklmnopqrstuvwxyz";

int main(void) {
  string s;
  cin >> s;
  
  vector<vector<int> > vecs;
  vecs.resize(s.length()+1);
  vector<bool> used(abc.length(),false);
  int index=0;
  rep(i,s.length()) {
    if(s[i]=='(') index++;
    else if(s[i]==')') {
      rep(j,vecs[index].size()) {
        used[vecs[index][j]]=false;
      }
      vecs[index].clear();
      index--;
    } else {
      if(used[s[i]-'a']) {cout << "No" << endl; return 0;}
      vecs[index].push_back(s[i]-'a');
      used[s[i]-'a']=true;
    }
  }

  cout << "Yes" << endl;
}