#include<bits/stdc++.h>
int tot, n, m;
int x[55], y[55], idx[55][55];
char str[55][55];
bool ok (int sta){
    std::vector<int> vec;
    for (int j, i = n-1, sz, t1, t2, use = 0; i >= 0; -- i){
        for (j = 0; j < tot; ++ j) if (x[j] == i && (sta & (1<<j))) use |= 1<<y[j];
        t1 = 0, t2 = 0;
        vec.clear ();
        for (j = 0; j < m; ++ j){
            if (str[i][j] == '.') continue;
            if (str[i][j] == 'E' && (use & (1<<j))) continue;
            if (str[i][j] == 'L' && (sta & (1<<idx[i][j]))) continue;
            vec.push_back (str[i][j] == 'E' ? (t1=1, 0) : (++t2, 1));
        }
        sz = vec.size ();
        //if (!i) for (j = 0; j < sz; ++ j) printf ("%d\n", vec[j]);
        if (!t1 || vec[0] || vec[sz-1] || t2>1) continue;
        return 0;
    }
    return 1;
}
int main(){
    int _; scanf ("%d", &_);
    while (_--){
        scanf ("%d%d", &n, &m);
        tot = 0;
        for (int j, i = 0; i < n; ++ i){
            scanf ("%s", str[i]);
            for (j = 0; j < m; ++ j){
                if (str[i][j] == 'L')
                    idx[i][j] = tot, x[tot] = i, y[tot++] = j;
            }
        }
        
        bool ans = 0;
        for (int i = 0; i < (1<<tot); ++ i) if (ok (i)){
            ans = 1; break;
        }
        puts (ans ? "Possible" : "Impossible");
    }
    return 0;
}
