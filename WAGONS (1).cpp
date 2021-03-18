#include <bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000];
int i,n,m=0;
stack<int> s;
int main()
{
    freopen("wagons.inp","r",stdin);
    freopen("wagons.out","w",stdout);
    cin>>n;
    s.push(1e9);
    for(i=1;i<=n;++i) cin>>a[i];
    int t=a[n];
    b[n]=t;
    for(i=n-1;i>=1;--i)
        {
            if(t>a[i]) t=a[i];
            b[i]=t;
        }
    for(i=1;i<=n;++i)
    {
        if(!s.empty())
        {
                t=s.top();
                while(t<=b[i])
                {
                 c[++m]=t;
                 s.pop();
                 if(!s.empty()) t=s.top();
                }

        }
        s.push(a[i]);
    }
    int k=m;
    if(n>m)
        for(i=1;i<=n-m;++i)
        {
            t=s.top();
            c[++k]=t;
            s.pop();
        }
        for(i=1;i<=n;++i)
    cout <<c[i] << " ";
    return 0;
}
