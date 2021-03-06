#include<bits/stdc++.h>
const long long mod = 7 + (int)1e9;
int a[333], d[222][222];
void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}
long long Fac (int t1, int t2){
    long long ret = 1;
    for (int i = t1; i <= t2; ++ i) ret = ret * i % mod;
    return ret;
}
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        int n, k; scanf ("%d%d", &n, &k);
        memset (a, 0, sizeof a);
        for (int t, i = 0; i < n; ++i)
            scanf ("%d", &t), ++ a[t];
        memset (d, 0, sizeof d);
        d[201][0] = 1;
        int cnt = 0;
        for (int i = 200; i >= 1; -- i){
            if (!a[i]) for (int j = 0; j <= k; ++ j) d[i][j] = d[i+1][j];
            else{
                for (int j = 0; j <= k; ++ j){
                    add (d[i][j], d[i+1][j] * Fac (cnt, cnt + a[i] - 1) % mod);
                    if (j) add (d[i][j], ((long long)d[i+1][j-1] * a[i] % mod) * Fac (cnt+1, cnt + a[i] - 1) % mod);
                }
                cnt += a[i];
            }
        }
        int ans = 0;
        for (int i = 0; i <= k; ++ i) add (ans, d[1][i]);
        printf ("%d\n", ans);
    }
    return 0;
}
