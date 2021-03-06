/*
 * Author:  Plumrain
 * Created Time:  2014/8/13 15:31:04
 * File Name: H.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool v[1010];      //visited
int match[1010];   
vector<int> an[1010];   //graph

pii tim[2010];

bool crosspath(int x){
    repf (i, 0, sz(an[x])-1){
        int p = an[x][i];
        if (!v[p]){
            v[p] = 1;
            if (match[p] == -1 || crosspath(match[p])){
                match[p] = x; return 1;
            }
        }
    }
    return 0;
}

int hungary (int n){
    int ret = 0;
    clr (match, -1);
    repf (i, 0, n-1) if (tim[i].y == 0){
        if (crosspath (i)) ++ ret;
        clr (v, 0);
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int a, b;
    scanf ("%d%d", &a, &b);

    int n; scanf ("%d", &n);
    repf (i, 0, n-1){
        int t1, t2; scanf ("%d%d", &t1, &t2);
        tim[i].x = t1; tim[i].y = t2;
    }

    repf (i, 0, n-1) an[i].clear();
    repf (i, 0, n-1) if (tim[i].y == 0){
        repf (j, i+1, n-1) if (tim[j].y == 1){
            int dif = tim[j].x - tim[i].x;
            if (dif >= a || dif <= b) an[i].pb (j);
        }
    }

    int ans = hungary (n);
    if (ans * 2 != n) puts ("Liar");
    else{
        puts ("No reason");
        repf (i, 0, n-1) if (tim[i].y == 1){
            printf ("%d %d\n", tim[match[i]].x, tim[i].x);
        }
    }
    return 0;
}
