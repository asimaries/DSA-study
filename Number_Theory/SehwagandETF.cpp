#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1000001;
vector<int> prime = {2}, num(MAX);
int i;
void __sieve(int n = 1000000)
{
    vector<bool> __PRIME;
    __PRIME.resize(n + 1, true);
    __PRIME[0] = __PRIME[1] = 0;
    int sqtn = sqrt(n);
    for (int p = 2; p <= sqtn; ++p)
        if (__PRIME[p])
            for (i = p * p; i <= n; i += p)
                __PRIME[i] = false;

    for (i = 3; i < __PRIME.size(); i += 2)
        if (__PRIME[i])
            prime.emplace_back(i);
    return;
}
vector <int> phi(MAX);
signed main()
{
    __sieve();
    cout << fixed << setprecision(6);
    int t = 1;
        int a, b, k;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> k;
        if (k == 1)
        {
            cout << 1.0 << endl;
            continue;
        }
        for (i = a; i <= b; i++)
        {
            phi[i - a] = i;
            num[i - a] = i;
        }
        for (i = 0; prime[i] * prime[i] <= b; i++)
        {
            int base = a / prime[i] * prime[i];
            while (base < a)
                base += prime[i];
            while (base < prime[i])
                base += prime[i];
            if (base == prime[i])
                base += prime[i];
            for (int j = base; j <= b; j += prime[i])
            {
                while (num[j - a] % prime[i] == 0)
                    num[j - a] /= prime[i];
                phi[j - a] -= phi[j - a] / prime[i];
            }
        }
        for (i = a; i <= b; i++)
        {
            if (num[i - a] > 1)
                phi[i - a] -= phi[i - a] / num[i - a];
            num[i - a] = 1;
        }
        int c = 0;
        for (i = a; i <= b; i++)
        {
            if (phi[i - a] % k == 0)
                c++;
        }
        double ans = c;
        ans /= (b - a + 1);
        cout << ans << endl;
    }
    return 0;
}
