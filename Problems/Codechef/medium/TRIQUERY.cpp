#include<bits/stdc++.h>
const int N = 9 + (int)3e5;
struct pnt{ int x, y;}p[N];
struct que{ int x, y, d, id;}q[N];
bool cmp1 (const pnt &a, const pnt &b){
    return a.x + a.y < b.x + b.y;
}
bool cmp2 (const que &a, const que &b){
    return a.x + a.y + a.d < b.x + b.y + b.d;
}
bool cmp3 (const pnt &a, const pnt &b){
    return std::make_pair (a.x, a.y) < std::make_pair (b.x, b.y);
}
bool cmp4 (const que &a, const que &b){
    return std::make_pair (a.x, a.y) < std::make_pair (b.x, b.y);
}

#define lowbit(x) ((x)&(-x))
int ans[N], mx, c[3][N];
void add (int p, int x, int y){
    for (; x <= mx; x += lowbit(x)) c[p][x] += y;
}
int query (int p, int x){
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += c[p][x];
    return ret;
}

int main(){
    int n, m;
    mx = 0;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) scanf ("%d%d", &p[i].x, &p[i].y);
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &q[i].x, &q[i].y, &q[i].d);
        mx = std::max (mx, std::max (q[i].x, q[i].y));
        q[i].id = i;
    }
    std::sort (p, p + n, cmp1);
    std::sort (q, q + m, cmp2);
    for (int j = 0, i = 0; i < m; ++ i){
        while (j < n && p[j].x + p[j].y <= q[i].x + q[i].y + q[i].d){
            add (0, p[j].x, 1); add (1, p[j++].y, 1);
        }
        ans[q[i].id] += j - query (0, q[i].x-1) - query (1, q[i].y-1);
    }
    std::sort (p, p + n, cmp3);
    std::sort (q, q + m, cmp4);
    for (int i = 0, j = 0; i < m; ++ i){
        while (j < n && p[j].x < q[i].x)
            add (2, p[j++].y, 1);
        ans[q[i].id] += query (2, q[i].y - 1);
    }
    for (int i = 0; i < m; ++ i) printf ("%d\n", ans[i]);
    return 0;
}
