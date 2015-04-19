/*
 * Author:  Plumrain
 * Created Time:  2014/5/18 16:27:34
 * Algorithm: �����ʷ�
 */
#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

struct edge{
    int s, e, cost, nxt;
};

struct HLD{
    const static int maxn = ;

    int n, r, id;
    int tot;           //�߶����ڵ���Ϊ1��tot
    int head[maxn];    //ͷ���
    edge pat[2*maxn];  //graph
    int son[maxn];     //�ض��ӽڵ���
    int siz[maxn];    //��uΪ���������Ľڵ���
    int dep[maxn];    //u������,��Ϊ0
    int fa[maxn];     //���׽ڵ�
    int hson_idx[maxn]; //���ض��ӵ�������pat�е���һ��
    int top[maxn];    //���������Ķ��˽ڵ�
    int pos[maxn];    //���߶����е�λ��

    void init(int _n, int _r){ n = _n; r = _r; id = 0; clr (son, -1); clr (head, -1); }
    //use twice
    void add (int s, int e, int w){
        pat[id].s = s; pat[id].e = e; pat[id].cost = w;
        pat[id].nxt = head[s]; head[s] = id ++;
    }
    void calc (){
        dfs1 (r, -1);
        tot = 0; top[r] = r; dfs2 (r, -1);
        clr (seg.ma, 0); seg.build(1, tot, 1);
    }
    void dfs1 (int u, int pre){
        fa[u] = pre; dep[u] = (pre==-1 ? 0 : dep[pre]) + 1;
        
        siz[u] = 1;
        int ma = 0, pos = -1, idx = -1;
        for (int i = head[u]; i != -1; i = pat[i].nxt){
            int v = pat[i].e; if (v == pre) continue;
            dfs1 (v, u);
            siz[u] += siz[v];
            if (ma < siz[v]) ma = siz[v], pos = v, idx = i;
        }
        son[u] = pos; hson_idx[u] = idx;
    }
    void dfs2 (int u, int pre){
        if (son[u] != -1){
            top[son[u]]= top[u]; pos[son[u]] = ++tot;
            seg.num[pos[son[u]]] = pat[hson_idx[u]].cost;
            dfs2 (son[u], u);
        }

        for (int i = head[u]; i != -1; i = pat[i].nxt){
            int v = pat[i].e;
            if (son[u] == v || v == pre) continue;
            top[v] = v;
            pos[v] = ++tot; seg.num[pos[v]] = pat[i].cost;
            dfs2 (v, u);
        }
    }

    //����Сֵ�����ο�
    int ask (int t1, int t2){
        if (t1 == t2) return 0;
        int f1 = top[t1], f2 = top[t2];
        if (f1 == f2){
            if (dep[t1] < dep[t2]) swap (t1, t2);
            return seg.calc (pos[son[t2]], pos[t1], 0, tot, 1);
        }
        if (dep[f2] > dep[f1]) swap (t1, t2), swap (f1, f2);
 
        int tmp = f1 == t1 ? 0 : seg.calc (pos[son[f1]], pos[t1], 0, tot, 1);
        return max (max (tmp, seg.num[pos[f1]]), ask (fa[f1], t2));
    }
}tree;
