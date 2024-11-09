#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin >> t;

   for (int i = 1; i <= t; i++)
   {
      long long ans = 0;
      int n, k;
      cin >> n >> k;
      while (n--)
      {
         long long x, y;
         cin >> x >> y;
         ans += k / x;
      }
      cout << "Case " << i << ": " << ans << endl;
   }
}