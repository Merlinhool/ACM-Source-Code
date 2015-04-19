/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 23:04:53
 * File Name: inv.cpp
 * calculate all inv[i], i = 1 to n
 * Time: O(n)
 */
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)

//fac[i]��inv[i]����i�ĳ˷���
//by the way��n!����Ԫ����1��n��������Ԫ֮������Ϊ��Ԫ����ȫ���Ժ���
//����Ҫע�⣬����0�Ľ׳˵���ԪΪ1

const int mod = ; //mod is prime

void inv_init(int n){
    inv[1] = 1; fac[1] = 1;
    for (int t, k, i = 2; i <= n; ++ i){
        t = mod / i; k = mod - t * i; 
        inv[i] = ((long long)i * t % mod) * t % mod;
        inv[i] = ((long long)inv[i] * inv[k] % mod) * inv[k] % mod;

        fac[i] = (long long)(mod - mod / i) * fac[mod%i] % mod;
    }
}
