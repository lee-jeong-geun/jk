#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, Left, Right, M, seq[25], memo[25][25][25];

int func(int idx, int l, int r)
{
    if(idx == M)
    {
        return 0;
    }
    int &ret = memo[idx][l][r];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    if(l == seq[idx] || r == seq[idx])
    {
        ret = min(ret, func(idx + 1, l, r));
    }
    else if(seq[idx] < l)
    {
        ret = min(ret, func(idx, l - 1, r) + 1);
    }
    else if(r < seq[idx])
    {
        ret = min(ret, func(idx, l, r + 1) + 1);
    }
    else if(l < seq[idx] && seq[idx] < r)
    {
        ret = min(ret, func(idx, l + 1, r) + 1);
        ret = min(ret, func(idx, l, r - 1) + 1);
    }
    return ret;
}

int main()
{
    scanf("%d %d %d %d", &N, &Left, &Right, &M);
    if(Left > Right)
    {
        int temp;
        temp = Left;
        Left = Right;
        Right = temp;
    }
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &seq[i]);
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, Left, Right));
}