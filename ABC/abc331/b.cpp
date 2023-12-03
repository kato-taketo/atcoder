#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,s,m,l;
  cin >> n >> s >> m >> l;

  int value=MOD, value_tmp=0;
  int num=0;
  for(int i=0; i<9; i++) {
    num=0; value_tmp=0;
    // l円をi個買う
    value_tmp += l*i;
    num += 12*i;
    int nnum = num, nvalue_tmp=value_tmp;
    for(int j=0; j<13; j++) {
      nnum = num;
      nvalue_tmp = value_tmp;
      nvalue_tmp += m*j;
      nnum += 8*j;
      int add_set = 0;
      //if(i==0&&j==2) cout << nvalue_tmp << " " << nnum << endl;
      if(nnum>=n) add_set = 0;
      else if((n-nnum)%6==0) add_set += (n-nnum)/6;
      else add_set += (n-nnum)/6+1;
      //if(i==0&&j==2) cout << nvalue_tmp << " " << nnum << endl;
      value = min(value, nvalue_tmp+s*add_set);
    }
  }
  cout << value << endl;
}