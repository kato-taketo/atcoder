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
 vector<ll> a(n);
 rep(i,n) cin >> a[i];

 vector<ll> ori_a(n);
 rep(i,n) ori_a[i] = a[i];
 sort(a.begin(), a.end());
 
 map<ll,ll> mp;  // mp[x] := y, x以下のsumがy
 ll tmp=0;
  for(int i=0; i<n; i++) {
    if(i==0) tmp=a[i];
    else if(a[i]==a[i-1]) tmp+=a[i];
    else {
      mp[a[i-1]] = tmp;
      tmp += a[i];
    }
  }
  mp[a[n-1]] = tmp;

  ll all=0;
  rep(i,n) all+=a[i];
  rep(i,n) {
    if(i!=n-1) cout << all-mp[ori_a[i]] << " ";
    else cout << all-mp[ori_a[i]] << endl;
  }
}