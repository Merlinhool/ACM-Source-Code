#include<bits/stdc++.h>
#define posin(x,y) ((x) >= 0 && (x) < n && (y) >= 0 && (y) < m)
#define Id(x,y) (x*m+y)
#define foreach(it,T) for(__typeof((T).begin()) it = (T).begin(); it != (T).end(); ++ it)
using namespace std;
template<class T> bool chmin (T &a, const T &b){ return a > b ? a = b, 1 : 0;}
const int Dx[] = {1, -1, 0, 0}, Dy[] = {0, 0, 1, -1};
template <class T> struct dinic{
    const static int maxn = 15555;
    const static int maxe = maxn * 20;
    const static T inf = 1LL << 60;

    struct edge{
        int s, e;
        T cap, f;
        edge *nxt;
        void add (int _s, int _e, T c, edge *t){
            f = 0; s = _s; e = _e; cap = c; nxt = t;
        }
        T flow(){ return cap - f;}
    };

    T flow;
    int n, m, s, t;         // 0,1,2...n-1
    edge memo[maxe];        //edge
    edge *bat, *head[maxn], *cur[maxn];
    int d[maxn]; // distance
    bool vis[maxn];    

    void init(){
        bat = memo;
        memset (head, 0, sizeof head);
    }
    void add (int s, int e, T cap){
        bat -> add (s, e, cap, head[s]); head[s] = bat++;
        bat -> add (e, s, 0, head[e]); head[e] = bat++;
    }
    bool bfs(){
        queue<int> q;
        q.push (s); d[s] = 0;
        memset (vis, 0, sizeof vis); vis[s] = 1; 
        while (q.size ()){
            int x = q.front(); q.pop();
            for (edge *e = head[x]; e; e = e->nxt){
                if (!vis[e->e] && e->flow() > 0){
                    q.push (e->e);
                    vis[e->e] = 1;
                    d[e->e] = d[x] + 1;
                }
            }
        }
        return vis[t];
    }
    T dfs (int x, T rf){
        if (x == t || rf == 0) return rf;
        T flow = 0, ff;
        for (edge *&e = cur[x]; e; e = e->nxt){
            T tmp = rf; chmin (tmp, e->flow());
            if (d[e->e] == d[x] + 1 && (ff = dfs (e->e, tmp)) > 0){
                e->f += ff;
                memo[(e-memo)^1].f -= ff;
                flow += ff; rf -= ff;
                if (rf == 0) break;
            }
        }
        return flow;
    }
    T maxflow(int _n, int _s, int _t){
        n = _n; flow = 0;
        s = _s; t = _t;
        while (bfs()){
            //clr (cur, 0);
            for (int i = 0; i < n; ++ i) cur[i] = head[i];
            flow += dfs (s, inf);
        }
        return flow;
    }
};
dinic<long long> gao;

int n, m, a[55][55], b[55][55][5];
const int inf = 6e8;
int main(){
    int T; scanf ("%d", &T);
    while (T--){
        scanf ("%d%d", &n, &m);
        int sx, sy, tx, ty, s, t;
        scanf ("%d%d%d%d", &sx, &sy, &tx, &ty);
        -- sx; -- sy; -- tx; -- ty;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                scanf ("%d", &a[i][j]);

        int ans = 0;
        for (int i = 0; i < 4; ++ i)
            if (sx + Dx[i] == tx && sy + Dy[i] == ty && a[sx][sy] >= a[tx][ty]){
                ans = -1; break;
            }
        if (ans == -1){
            puts ("-1"); continue;
        }

        s = Id (sx, sy); t = Id (tx, ty);
        int tot = n * m - 1;
        gao.init ();
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j){
                vector<pair<int, int> > v;
                for (int d = 0, x, y; d < 4; ++ d){
                    x = i + Dx[d]; y = j + Dy[d];
                    if (!posin (x, y)) continue;
                    if (a[x][y] >= a[i][j]){
                        if (Id (i, j) == t) v.push_back (make_pair (-inf, Id (x, y)));
                        else v.push_back (make_pair (-a[x][y], Id (x, y)));
                    }
                }
                sort (v.begin(), v.end());
                int now = Id (i, j);
                foreach (it, v){
                    gao.add (++tot, now, (-it->first-a[i][j]+1));
                    gao.add (it->second, now=tot, inf);
                }
            }
        printf ("%d\n", gao.maxflow (tot+1, s, t));
    }
    return 0;
}
