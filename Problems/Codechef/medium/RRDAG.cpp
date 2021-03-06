#include<bits/stdc++.h>
const int N = 1501;
int num[N];
bool ans[N][N], f[N];
char s[N][N];
int main(){
    int n, sum = 0;
    scanf ("%d", &n);
    for (int i = 0, j; i < n; ++ i){
        scanf ("%s", s[i]);
        for (j = 0; j < n; ++ j)
            s[i][j]=='1' ? (++num[i], ++sum) : 0;
    }
    std::priority_queue<int> q;
    for (int i = 0; i < n; ++ i) if (!num[i]) q.push (i);
    for (int x, i; (int)q.size (); ){
        x = q.top(); q.pop (); f[x] = 1;
        for (i = 0; i < n; ++ i)
            if (s[i][x] == '0'){
                if (!f[i]) ans[i][x] = 1;
            } else if (!--num[i]) q.push (i);
    }

    printf ("%d\n", n * (n-1) / 2 - sum);
    for (int i = 0, j; i < n; ++ i)
        for (j = 0; j < n; ++ j) if (ans[i][j])
            printf ("%d %d\n", i + 1, j + 1);
    return 0;
}
