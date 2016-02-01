#include <cstdio>

int x, y, sum;
char arr[110][110];
char a;

void input();
void solve();
void bfs(int i, int j);
int safe(int i, int j);

int main()
{
    input();
    solve();
    printf("%d", sum);
}

void input()
{
    scanf("%d %d", &x, &y);
    x*=2;
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            scanf("%c", &arr[i][j]);
        }
    }
}

void solve()
{
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            if (arr[i][j]=='L') {
                printf("%d %d\n", i,j);
                bfs(i, j);
                sum++;
            }
        }
    }
}

void bfs(int i, int j)
{
    arr[i][j]=0;
    if (arr[i+1][j-1]=='L'&&safe(i+1, j-1)) bfs(i+1, j-1);
    else if (arr[i+1][j+1]=='L'&&safe(i+1, j+1)) bfs(i+1, j+1);
    else if (arr[i-1][j+1]=='L'&&safe(i-1, j+1)) bfs(i-1, j+1);
    else if (arr[i-1][j-1]=='L'&&safe(i-1, j-1)) bfs(i-1, j-1);
    else if (arr[i][j-1]=='L'&&safe(i, j-1)) bfs(i, j-1);
    else if (arr[i][j+1]=='L'&&safe(i, j+1)) bfs(i, j+1);
    else if (arr[i+1][j]=='L'&&safe(i+1, j)) bfs(i+1, j);
    else if (arr[i-1][j]=='L'&&safe(i-1, j)) bfs(i-1, j);
}

int safe(int i, int j)
{
    if (i<0||j<0||i>=x||j>=y) return 0;
    else return 1;
}

//가로가 j 세로가 i
//0,1이 맨 처음