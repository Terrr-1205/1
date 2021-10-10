#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

#define int long long
const int MAXN = 1e5 + 10;
int pre[MAXN], tg[MAXN], n;
int a[MAXN];

inline bool check(int cur) {
   for(int i=1;i<=n;i++) pre[i]=a[i];
   int mx = 0, tag = 0;
   for (int i = 2; i < n; ++i)
   {
       pre[i] += tag;
       if (pre[i] - pre[i - 1]  > cur)
       {
           mx = cur - (pre[i - 1] - pre[i - 2]);
           if (mx == 0) return 0;
           if (pre[i] - pre[i - 1] - mx > cur) return 0;
           int pos = (pre[i] - pre[i - 1] - cur);
           pre[i - 1] += pos;
           tag += pos;
       }
   }
   return (((pre[n]-pre[n-1])<=cur)&&(pre[1]<=cur));
}

signed main() {
cin>>n;
   int l = 1e9, r = 0, mid, ans = 0;
   for (int i = 1; i <= n; ++i)
   {
       int x;
       cin>>x;
       a[i] = a[i - 1] + x;
       l = min(l, a[i] - a[i - 1]);
       r = max(r, a[i] - a[i - 1]);
   }
   while (l <= r)
   {
       mid = (l + r) >> 1;
      // cout<<mid<<" ";
       if (check(mid))
       {
           ans = mid;
           r = mid -1;
       } else {
           l = mid +1;
       }
   }
   printf("%d\n", ans);
   return 0;
}
