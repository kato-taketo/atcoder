#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

vector<string> c(9);
void func(string W,  int res, int x, int y) {
  if(W=="R") {
    while(res>0&&x<9) {
      cout << c[y][x];
      res--, x++;
    }
    if(res==0) return;
    if(x==9) func("L", res, 7, y);
  }
  if(W=="L") {
    while(res>0&&x>=0) {
      cout << c[y][x];
      res--, x--;
    }
    if(res==0) return;
    if(x==-1) func("R", res, 1, y);
  }
  if(W=="U") {
    while(res>0&&y>=0) {
      cout << c[y][x];
      res--, y--;
    }
    if(res==0) return;
    if(y==-1) func("D", res, x, 1);
  }
  if(W=="D") {
    while(res>0&&y<9) {
      cout << c[y][x];
      res--, y++;
    }
    if(res==0) return;
    if(y==9) func("U", res, x, 7);
  }
  if(W=="RU") {
    while(res>0&&x<9&&y>=0) {
      cout << c[y][x];
      res--, x++, y--;
    }
    if(res==0) return;
    if(x==9&&y==-1) func("LD", res, 7, 1);
    else if(x==9) func("LU", res, 7, y);
    else if(y==-1) func("RD", res, x, 1);
  }
  if(W=="RD") {
    while(res>0&&x<9&&y<9) {
      cout << c[y][x];
      res--, x++, y++;
    }
    if(res==0) return;
    if(x==9&&y==9) func("LU", res, 7, 7);
    else if(x==9) func("LD", res, 7, y);
    else if(y==-1) func("RU", res, x, 7);
  }
  if(W=="LU") {
    while(res>0&&x>=0&&y>=0) {
      cout << c[y][x];
      res--, x--, y--;
    }
    if(res==0) return;
    if(x==-1&&y==-1) func("RD", res, 1, 1);
    else if(x==-1) func("RU", res, 1, y);
    else if(y==-1) func("LD", res, x, 1);
  }
  if(W=="LD") {
    while(res>0&&x>=0&&y<9) {
      cout << c[y][x];
      res--, x--, y++;
    }
    if(res==0) return;
    if(x==-1&&y==9) func("RU", res, 1, 7);
    else if(x==-1) func("RD", res, 1, y);
    else if(y==9) func("LU", res, x, 7);
  }
}
int main(void) {
  int x,y;
  string W;
  cin >> x >> y >> W;
  
  rep(i,9) cin >> c[i];
  x--, y--;
  func(W, 4, x, y);
  cout << endl;
}