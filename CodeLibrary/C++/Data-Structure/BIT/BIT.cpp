#define lowbit(x) ((x)&(-x))
int c[100005];

//�����޸ģ������ѯ
//�ѵ�x��Ȩֵ����d
void add(int x, int d)
{
    while (x <= lim) c[x] += d, x += lowbit(x);
}

//��ѯ1,2,3...x��Ȩֵ��
int sum(int x)
{
    int ret = 0;
    while (x > 0) ret += c[x], x -= lowbit(x);
    return ret;
}

int c[1005][1005];

//���޸�(x, y)
void add(int x, int y)
{
    int yy = y;
    while (x > 0){
        y = yy;
        while (y > 0){
            c[x][y] ^= 1;
            y -= lowbit(y);
        }
        x -= lowbit(x);
    }
}

//�����ѯ(1, 1) -> (x, y)
int sum(int x, int y)
{
    int ret = 0, yy = y;
    while (x <= n){
        y = yy;
        while (y <= n){
            ret ^= c[x][y];
            y += lowbit(y);
        }
        x += lowbit(x);
    }
    return ret;
}
