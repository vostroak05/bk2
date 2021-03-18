#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[1000005];
int n, d[1000005], c[1000005];

void insertbit(int a[], int x)
{
    while (x <= 2 * n)
    {
        a[x]++;
        x += x & (-x);
    }
}

int getbit(int a[], int x)
{
    int tg = 0;
    while (x > 0)
    {
        tg += a[x];
        x -= x & (-x);
    }
    return tg;
}

void updatebit(int a[], int x)
{
    while (x <= 2 * n)
    {
        a[x]--;
        x += x & (-x);
    }
}

int main()
{
    freopen("CHORDS.inp", "r", stdin);
    freopen("CHORDS.out", "w", stdout);
    
    cin >> n;
    int u, v;
    int kq = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        p[i].first = u;
        p[i].second = v;
        insertbit(d, u);
        insertbit(c, v);
    }
    
    sort(p + 1, p + n + 1);
    
    for (int i = 1; i <= n; i++)
    {
        kq += getbit(d, p[i].second) - getbit(c, p[i].second);
        updatebit(d, p[i].first);
        updatebit(c, p[i].second);
    }
    
    cout << kq;
    return 0;
}