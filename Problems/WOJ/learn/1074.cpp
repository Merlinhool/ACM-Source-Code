#define LOCAL
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <numeric>
#include <map>
#include <iomanip>
#include <climits>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <set>
using namespace std;
#define REP(i, n) for (int i=0;i<n;++i)
#define DWN_C_N(i, b, a) for (int a____=(i=b-1,a);i>=a____;--i)
#define REP_1_C_N(i, n) for (int n____=(i=1,n);i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (int b____=(i=a,b);i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (int a____=(i=b,a);i>=a____;--i)
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define DWN(i, b, a) for (int i=b-1;i>=a;--i)
#define DWN_C(i, b, a) for (int a____=a,i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<n;++i)
#define FOR_N(i, a, b) for (i=a;i<b;++i)
#define DWN_N(i, b, a) for (i=b-1;i>=a;--i)
#define REP_SS(x, s) for (int x=s;x;x=(x-1)&s)
#define DO(n) for ( int ____n = n; ____n-->0; )
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)
#define REP_3(i, j, k, n, m, l) REP(i, n) REP(j, m) REP(k, l)
#define REP_1_C(i, n) for (int n____=n,i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=b,i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=a,i=b;i>=a____;--i)
#define REP_C_N(i, n) for (int n____=(i=0,n);i<n____;++i)
#define FOR_C_N(i, a, b) for (int b____=(i=0,b);i<b____;++i)
#define REP_1(i, n) for (int i=1;i<=n;++i)
#define FOR_1(i, a, b) for (int i=a;i<=b;++i)
#define REP_3_1(i, j, k, n, m, l) REP_1(i, n) REP_1(j, m) REP_1(k, l)
#define REP_4(i, j, k, ii, n, m, l, nn) REP(i, n) REP(j, m) REP(k, l) REP(ii, nn)
#define REP_4_1(i, j, k, ii, n, m, l, nn) REP_1(i, n) REP_1(j, m) REP_1(k, l) REP_1(ii, nn)
#define REP_1_N(i, n) for (i=1;i<=n;++i)
#define FOR_1_N(i, a, b) for (i=a;i<=b;++i)
#define DWN_1_N(i, b, a) for (i=b;i>=a;--i)
#define ALL(A) A.begin(), A.end()
#define UBD(A, x) (upper_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>
#define Ts *this
#define SZ(A) int((A).size())
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define rTs return Ts
#define fi first
#define se second
#define re real()
#define im imag()
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define LBD(A, x) (lower_bound(ALL(A), x) - A.begin())
#define REP_L(i, hd, suc) for (int i=hd;i;i=suc[i])
#define REP_G(i, u) REP_L(i,hd[u],suc)
#define DWN_1(i, b, a) for (int i=b;i>=a;--i)
#define REP_C(i, n) for (int n____=n,i=0;i<n____;++i)
#define ECH(it, A) for (__typeof((A).begin()) it=(A).begin(); it != (A).end(); ++it)
#define rECH(it, A) for (__typeof((A).rbegin()) it=(A).rbegin(); it != (A).rend(); ++it)
#define REP_S(i, str) for (char*i=str;*i;++i)
#define FOR_C(i, a, b) for (int b____=b,i=a;i<b____;++i)
#define Rush for(int ____T=RD(); ____T--;)
/******************************************************************************************************/

namespace solve {
        int a[11111];
        bool solve() {
                set<int> st;
                int n; scanf("%d", &n);
                st.clear();
                for(int i = 0; i < n; ++i) {
                        scanf("%d", a + i);
                        st.insert(a[i]);
                }
                sort(a, a + n);
                int mx = -1;
                for(int i = n-1, j, t; i >= 0 && mx == -1; --i) {
                        t = a[i] >> 1;
                        for(j = i-1; j && a[j] > t; --j) {
                                if(st.find(a[i]-a[j]) != st.end()) {
                                        mx = a[i]; break;
                                }
                        }
                        if(a[j] + a[j-1] == a[i]) mx = a[i];
                }
                printf("%d\n", mx);
                return 1;
        }
}

int main() {
#ifndef ONLINE_JUDGE
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
        int n; 
        scanf("%d", &n);
        while(1) {
                if(!solve::solve()) return 0;
                if(--n==0) return 0;
        }
}
//by Jiaxing Luo
