// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,L;
  cin >> N >> L;
  vector<int> a(N);
  rep(i,N) cin >> a[i];

  int all=0;
  rep(i,N) all += a[i];
  vector<bool> used(all,false);

  int f_index=0;  //2が入れる最初のindex
  if(N==1) {
    cout << "Yes" << endl;
    return 0;
  }
  rep(i,N) {
    if(f_index+1==all && a[i]==1) f_index++;
    else if(f_index+2==all && a[i]==2) f_index++;
    else if(a[i]==1) f_index+=2;
    else if(a[i]==2) f_index+=3;
    if(f_index>all && a[i]==2) {
      cout << "No" << endl; return 0;
    }
  }
  cout << "Yes" << endl;

}