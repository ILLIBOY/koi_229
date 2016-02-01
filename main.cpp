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
    //solve();
    for (int i=0; i<y; i++) {
        for (int j=1; j<=x; j++) {
            printf("%d %d %c\n",i,j, arr[i][j]);
        }
    }
    printf("%d", sum);
}

void input()
{
    scanf("%d %d", &x, &y);
    for (int i=0; i<y; i++) {
        for (int j=0; j<=x; j++)
        {
            scanf("%c", &arr[i][j]);
            if (arr[i][j]==32) {
                scanf("%c", &arr[i][j]);
            }
        }
    }
}

void solve()
{
    for (int i=0; i<x; i++) {
        for (int j=1; j<y; j++) {
            if (arr[i][j]=='L') {
                bfs(i, j);
                sum++;
            }
        }
    }
}

void bfs(int i, int j)
{
    arr[i][j]='.';
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