#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  // kよりXが大きかれば反転させる。
  int cnt=0;
  rep(i,n) if(s[i]=='X') cnt++;
  if(cnt<k) {
    k=n-k;
    rep(i,n) if(s[i]=='X') s[i]='Y'; else s[i]='X';
  }

  // sの調査 
  rep(i,n) {
    if(i!=0) vec.push_back(tmp);
  }
  int num_x=0, all_x=0, res=0, tmp=0;
  bool first=true;
  priority_queue<int,vector<int>, greater<int> > pq, pq2;
  vector<int> vec_x, vec_y;
  rep(i,n) {
    if(s[i]=='X') num_x++;
    else {
      if(s[0]=='X'&&first) pq2.push(num_x), first=false;
      else if(num_x>0) pq.push(num_x);
      vec_x.push_back(num_x);
      all_x+=num_x, num_x=0;
    }
  }
  if(num_x!=0) pq2.push(num_x), all_x+=num_x, vec_x.push_back(num_x);
  rep(i,n) {
    if(s[i]=='Y') tmp++;
    else res += max(0,(tmp-1)), vec_y.push_back(tmp),tmp=0;
  }
  if(tmp>1) res += tmp-1, vec_y.push_back(tmp);

  // change x -> y
  while(!pq.empty()) {
    int l = pq.top();
    //cout << "l : " << l << endl;
    pq.pop();
    if(k>=l) res += (l+1), k-=l;
    else {
      res += k; cout << res << endl; return 0;
    }
  }

  while(!pq2.empty()) {
    int l=pq2.top();
    pq2.pop();
    if(k>=l) res += l, k-=l;
    else {
      res += k; cout << res << endl; return 0;
    }
  }
  if(k==0) cout << res << endl;
}