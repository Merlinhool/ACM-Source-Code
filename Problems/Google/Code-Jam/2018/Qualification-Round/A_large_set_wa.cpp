//Create Time: 2018-04-07 11:31:55
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define TST(x) std::cout<<(#x)<<":"<<(x)<<" "
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define DEBUG
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
int calc(string s){
    int t=1,sum=0,n=SZ(s);
    rep(i,0,n){
        if(s[i]=='C')t<<=1;
        else sum+=t;
    }
    return sum;
}
int main(){
    int _,cas=0;cin>>_;
    while(_--){
        int K;
        string s;
        cin>>K>>s;
        int ans=-1,cnt=0,n=SZ(s);
        if(calc(s)<=K)ans=0;
        while(1){
            if(~ans)break;
            bool change=0;
            per(i,n,1){
                if(s[i]=='S'&&s[i-1]=='C'){
                    change=1;
                    swap(s[i],s[i-1]);
                    ++cnt;
                    if(calc(s)<=K){
                        ans=cnt;
                    }
                    break;
                }
            }
            if(~ans || !change)break;
        }
        printf("Case #%d: ",++cas);
        if(~ans) printf("%d\n",ans);
        else puts("IMPOSSIBLE");
    }
    return 0;
}