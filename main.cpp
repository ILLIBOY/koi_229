#include <cstdio>

int x, y;
char arr[110][110];
char a;

void input();
void solve();

int main()
{
    input();
    
}

void input()
{
    scanf("%d %d", &x, &y);
    x*=2;
    for (int i=1; i<=x; i++) {
        for (int j=1; j<=y; j++) {
            scanf("%c", &arr[i][j]);
        }
    }
}

void solve()
{
    for (int i=1; i<=x; i++) {
        for (int j=1; j<=y; j++) {
            <#statements#>
        }
    }
}