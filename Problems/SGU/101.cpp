/*
 * Author:  Plumrain
 * Created Time:  2014/6/11 0:38:18
 * File Name: 101.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool vis[105];
int num[10], tot;
pair<int, char> stk[105];
vector<pair<int, pair<int, char> > > pat[10];

void euler (int u){
    repf (i, 0, sz(pat[u])-1) if (!vis[pat[u][i].y.x]){
        vis[pat[u][i].y.x] = 1;
        euler (pat[u][i].x);
        stk[ tot++ ] = pat[u][i].y;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    clr (num, 0);
    repf (i, 0, 6) pat[i].clear();
    int tx, ty;
    repf (i, 0, n-1){
        scanf ("%d%d", &tx, &ty);
        num[tx] ++, num[ty] ++;
        pat[tx].pb (mp (ty, mp (i, (char)'+')));
        pat[ty].pb (mp (tx, mp (i, (char)'-')));
    }

    int sta = -1, cnt = 0;
    repf (i, 0, 6) if (num[i] & 1) ++ cnt, sta = i;
    if (cnt == 0){
        repf (i, 0, 6) if (num[i]) sta = i;
    }
    else if (cnt != 2) sta = -1;

    if (sta == -1) {
        puts ("No solution"); return 0;
    }

    tot = 0; clr (vis, 0);
    euler (sta);
    if (tot != n) puts ("No solution"); 
    else repd (i, tot-1, 0) printf ("%d %c\n", stk[i].x+1, stk[i].y);
    
    return 0;
}
