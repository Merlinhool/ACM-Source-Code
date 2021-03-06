#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++ it)
const int N = 9 + (int)1e5;
struct nod{
    nod *ls, *rs;
    int v, l, r;
}memo[N*30], *bat=memo, Tnull, *null=&Tnull, *rt[N];
bool FG;
void insert (int p, int v, int l, int r, nod*&x){
    //printf ("%d %d %d %d FG:%d\n", p, v, l, r, FG);
    *bat = *x; x = bat++; x->l = l; x->r = r;
    x->v += v;
    if (l == r) return;
    int m = l + r >> 1;
    if (p <= m) insert (p, v, l, m, x->ls);
    else insert (p, v, m+1, r, x->rs);
}
int query (int l, int r, nod *x){
    //printf ("%d %d %d %d %d\n", x->l, x->r, x->v, x == null, x->ls == null);
    if (x == null) return 0;
    if (l <= x->l && x->r <= r) return x->v;
    int m = x->l + x->r >> 1, ret = 0;
    if (l <= m) ret = query (l, r, x->ls);
    if (r > m) ret += query (l, r, x->rs);
    return ret;
}
int ask (int s1, int s2, int t1, int t2){
    return query (s1, s2, rt[t2]) - query (s1, s2, rt[t1-1]);
}
int nxt[N], pre[N], a[N], last;
std::vector<int> vec[N];
int solve (int x){
    -- a[x];
    if (a[x]) return last;
    int ret = ask (pre[x]+1, x, x, nxt[x]-1) + last;
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
    return ret;
}
int main(){
    null->ls = null->rs = null;
    null->v = 0;

    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf ("%d", a + i);
    }
    for (int i = 1; i <= n; ++ i) 
        nxt[i] = i + 1, pre[i] = i - 1;

    for (int i = 0, t1, t2; i < m; ++ i){
        scanf ("%d%d", &t1, &t2);
        vec[t2].push_back (t1);
    }
    rt[0] = null;
    for (int i = 1; i <= n; ++ i){
        *bat = *rt[i-1], rt[i] = bat++;
        foreach (it, vec[i]) insert (*it, 1, 0, n, rt[i]);
    }

    int q, t; scanf ("%d", &q);
    for (last = 0; q; -- q){
        scanf ("%d", &t);
        printf ("%d\n", last = solve (t + last));
    }
    return 0;
}
