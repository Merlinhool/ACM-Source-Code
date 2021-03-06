#include<bits/stdc++.h>
const int N = 9 + (int)2e5;
int head[N], nxt[N], to[N], w[N], tot;
void adde (int u, int v, int c){
    nxt[tot] = head[u]; to[tot] = v; w[tot] = c; head[u] = tot++;
}
struct nod{
    nod *ch[2];
    void clear (){ ch[0] = ch[1] = 0;}
}memo[30*N], *bat, *rt;
int dig[40];
void insert (){
    nod *x = rt;
    for (int i = 30; i >= 0; -- i){
        if (!x->ch[dig[i]]){
            bat->clear ();
            x->ch[dig[i]] = bat++;
        }
        x = x->ch[dig[i]];
    }
}
int ans;
void find (){
    nod *x = rt;
    int tmp = 0;
    for (int i = 30; i >= 0; -- i){
        if (x->ch[dig[i]^1]){
            tmp = tmp<<1|1;
            x = x->ch[dig[i]^1];
        } else{
            tmp <<= 1;
            x = x->ch[dig[i]];
        }
    }
    ans = std::max (ans, tmp);
}

void calc (int x){
    int cnt;
    for (cnt = 0; x; x >>= 1) dig[cnt++] = x & 1;
    while (cnt <= 30) dig[cnt++] = 0;
}
int val[N], last;
void dfs (int x, int pre){
    val[x] = last;
    for (int p = head[x]; p; p = nxt[p]) if (to[p] != pre){
        last ^= w[p]; dfs (to[p], x); last ^= w[p];
    }
}
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        int n; scanf ("%d", &n);
        tot = 1;
        memset (head, 0, sizeof head);
        for (int i = 0, u, v, c; i < n-1; ++ i){
            scanf ("%d%d%d", &u, &v, &c);
            adde (--u, --v, c); adde (v, u, c);
        }
        ans = last = 0;
        dfs (0, -1);
        bat = memo; rt = bat++; rt->clear ();
        for (int i = 0; i < n; ++ i){
            calc (val[i]);
            if (i) find ();
            insert ();
        }
        printf ("%d\n", ans);
    }
    return 0;
}
