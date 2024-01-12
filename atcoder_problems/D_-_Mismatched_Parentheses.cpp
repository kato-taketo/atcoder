#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int n;
string s;
vector<int> emos;
vector<int> vec;
int main(void) {
  cin >> n >> s;

  emos.resize(n+1, 0);
  rep(i,n) {
    if(s[i]=='(') vec.push_back(i);
    else if(s[i]==')') {
      if(vec.size()==0) continue;
      else {
        emos[i+1]+=-1;
        emos[vec[vec.size()-1]]+=1;
        vec.pop_back();
      }
    }
  }
  rep(i,n) emos[i+1]+=emos[i];
  rep(i,n) {
    //cout << emos[i];
    if(emos[i]==0) cout << s[i];
  }
  cout << endl;
}