#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define lINF 100000000000000000
#define int long long
#define ld long double
#define ull unsigned long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
/*-------------------ASIMARIES--------------------*/
vector<int> primes;
void __sieve(int n = 1000009)
{
    vector<bool> __PRIME;
    __PRIME.resize(n + 1, true);
    __PRIME[0] = __PRIME[1] = 0;
    int sqtn = sqrt(n);
    for (int p = 2; p <= sqtn; p++)
        if (__PRIME[p])
            for (int i = p * p; i <= n; i += p)
                __PRIME[i] = false;

    for (int i = 0; i < n; i++)
        if (__PRIME[i])
            primes.emplace_back(i);

    return;
}

signed main()
{
    freopen("in.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<pair<int, int>> kp;
    int k_bkp = k;
    for (int i = 2; i * i <= k_bkp; i++)
    {
        if ((k_bkp % i) == 0)
        {
            int cnt = 0;
            while (k_bkp % i == 0)
            {
                k_bkp /= i;
                cnt++;
            }
            kp.push_back({i, cnt});
        }
    }

    if (k_bkp != 1)
        kp.push_back({k_bkp, 1});

    vector<pair<int, int>> ep = kp;
    for (int i = 0; i < ep.size(); i++)
    {
        ep[i].second = 0;
    }
    int ans = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < ep.size(); x++)
        {
            if ((arr[i] % ep[x].first) == 0)
            {
                int f = ep[x].first;
                int num = arr[i];
                int cnt = 0;
                while (num % f == 0)
                {
                    num /= f;
                    cnt++;
                }
                ep[x].second += cnt;
            }
        }

        while (j <= i)
        {
            int flag = 0;
            for (int x = 0; x < kp.size(); x++)
            {
                if (ep[x].second < kp[x].second)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                ans += n - i;
                for (int x = 0; x < ep.size(); x++)
                {
                    if (arr[j] % ep[x].first == 0)
                    {
                        int f = ep[x].first;
                        int num = arr[j];
                        int cnt = 0;
                        while (num % f == 0)
                        {
                            num /= f;
                            cnt++;
                        }
                        ep[x].second -= cnt;
                    }
                }
            }
            else
            {
                break;
            }
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
