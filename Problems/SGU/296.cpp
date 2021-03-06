/*
 * Author:  Plumrain
 * Created Time:  2014/7/13 11:29:22
 * File Name: 296.cpp
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
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int n;
bool vis[1005];
char s[1005];

void dfs (int p, int k){
    if (k == 0) return;
    int last = p;
    repf (i, p+1, n-1){
        if (n - i < k) break;
        if (s[i] > s[last]) last = i;
    }
    vis[last] = 1;
    dfs (last+1, k - 1);
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int k;
    scanf ("%s%d", s, &k);
    n = strlen(s);
    
    clr (vis, 0);
    dfs (0, n - k);
    bool u = 0;
    repf (i, 0, n-1){
        if (vis[i]){
            if (!u && s[i] == '0'){
                puts ("0"); return 0;
            }
            printf ("%c", s[i]);
        }
        u = 1;
    }
    puts ("");
    return 0;
}
