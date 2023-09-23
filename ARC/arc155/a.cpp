#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int t;
  cin >> t;
  vector<bool> res(t);
  rep(i,t) {
    ll n;
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;

    bool key=true;
    if(k<=n) {
      // 先頭からk, 後ろのk
      rep(j,k) {
        if(s[j]!=s[n-k+j]) {
          key=false; break;
        }
      }
      // 先頭から(n-k)/2, 後ろからk+(n-k)/2
      rep(j,(n-k)/2) {
        if(s[j]!=s[n-1-k-j]) {
          key=false; break;
        }
      }
      // 先頭からk+(n-k)/2, 後ろから(n-k)/2
      rep(j,(n-k)/2) {
        if(s[k+j]!=s[n-1-j]) {
          key=false; break;
        }
      }
      
    } else if(k>n&&n*2>k) {
      // 先頭からn*2-k
      rep(j,n*2-k) if(s[j]!=s[n*2-k-j]) {key=false; break;}
      // 先頭から(k-n)/2, 後ろからn*2-k+(k-n)/2
      rep(j,(k-n)/2) if(s[j]!=s[n-1-(n*2-k)-j]) {key=false; break;}
      // 先頭からn*2-k+(k-n)/2, 後ろから(k-n)/2
      //rep(j,(k-n)/2) if(s[n*2-k+(k-n)/2]!=s[n-1-j]) {key=false; break;}
      rep(j,(k-n)/2) if(s[2*n-k+j]!=s[n-1-j]) {
        key=false; break;
      }
    } else {
      ll tmp=k%n;
      tmp = min(tmp, n-tmp);
      if(tmp>n-tmp) {
        //先頭からtmpと後ろまでのtmp
        rep(j,tmp) if(s[j]!=s[n-tmp+j]) {key=false; break;}
      } else {
        // 先頭からn-2*(k%n)+k%nと、後ろからk%n
      rep(j,tmp) if(s[n-2*(tmp)+j]!=s[n-1-j]) {key=false; break;}
        // 先頭からtmpと、後ろからn-2*(tmp)+tmp
      rep(j,tmp) if(s[j]!=s[(tmp)*2-1-j]) {key=false; break;}
      }
    }
    //if(key) cout << "Yes" << endl;
    //else cout << "No" << endl;
    if(key) res[i]=true;
    else res[i]=false;
  }
  rep(i,t) if(res[i]) cout << "Yes" << endl;
  else cout << "No" << endl;
} 