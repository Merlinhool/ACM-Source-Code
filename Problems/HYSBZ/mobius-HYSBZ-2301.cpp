/*
 * Author:  Plumrain
 * Created Time:  2014-04-02 13:44
 * File Name: mobius-HYSBZ-2301.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
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
const int maxn = 50000;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

bool check[maxn];
int prm[maxn+5], mu[maxn+5], sum_mu[maxn];

void mobius(int n){
    clr (check, 0); check[1] = 1; mu[1] = 1;
    int tot = 0;
    repf (i, 2, n){
        if (!check[i]) prm[tot++] = i, mu[i] = -1;
        repf (j, 0, tot-1){
            int tmp = prm[j] * i;
            if (tmp > n) break;
            check[tmp] = 1;
            if (i % prm[j]) mu[tmp] = -mu[i];
            else{
                mu[tmp] = 0; break;
            }
        }
    }

    clr (sum_mu, 0);
    repf (i, 1, n) sum_mu[i] += sum_mu[i-1] + mu[i];
}

int64 calc (int n, int m){
    if (n > m) swap (n, m);
    int64 ret = 0;
    for (int i = 1, last = 0; i <= n; i = last+1){
        last = min (n/(n/i), m/(m/i));
        ret += 1LL * (sum_mu[last] - sum_mu[i-1]) * (n/i) * (m/i);
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    mobius (maxn);

    int T;
    scanf ("%d", &T);
    while (T--){
        int a, b, c, d, k;
        scanf ("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int64 ans = calc (b/k, d/k) - calc (b/k, (c-1)/k) - calc ((a-1)/k, d/k) + calc ((a-1)/k, (c-1)/k);
        printf ("%lld\n", ans);
    }
    return 0;
}
