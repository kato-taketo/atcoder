#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> left,rignt;
  vector<pair<int,int> > deletes;
  rep(i,n) {
    if(s[i]=='(') left.push_back(i);
    else if(s[i]==')') right.push_back(i);
  }
  int pre_index=-1;
  int pre_left=-1;
  rep(i,n) {
    if(s[i]==')') {
      if(pre_index==-1) pre_index=i, pre_left=1;
      else if(pre_index!=-1) {
        if(pre_left==1) pre_index=i;
        else pre_index=i, pre_left-1;
      }
    } else if(s[i]==')') {
      if(pre_index==-1) continue;
      else if(pre_index!=-1) {
        if(pre_left==1) deletes.push_back(make_pair(pre_index,i)), pre_index=
      }
    }
  }
}