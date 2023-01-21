#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  long long a[300];
  string s;
  int d[300][300];
  long long val[300][300];

  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) d[i][j]=n,val[i][j]=0;
  for(int i=0; i<n; i++) d[i][i]=0,val[i][i]=0;
  for(int i=0; i<n; i++) {
    cin >> s;
    for(int j=0; j<n; j++) {
      if(s[j]=='Y') d[i][j]=1,val[i][j]=a[j];
    }
  }
  for(int j=0;j<n;j++) {
    for(int i=0; i<n; i++) {
      for(int k=0; k<n;k++) {
        if((d[i][j]+d[j][k])<d[i][k]) {
          d[i][k]=d[i][j]+d[j][k];
          val[i][k]=val[i][j]+val[j][k];
        } else if((d[i][j]+d[j][k])==d[i][k]&&(val[i][j]+val[j][k])>val[i][k]) {
          val[i][k]=val[i][j]+val[j][k];
        }
      }
    }
  }

  int q,u,v;
  cin >> q;
  for(int i=0;i<q;i++) {
    cin >> u >> v;
    if(d[u-1][v-1]==n) cout<<"Impossible\n";
    else cout<<d[u-1][v-1]<<" "<<(val[u-1][v-1]+a[u-1])<<"\n";
  }
}