#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

// Sieve to quickly grab primes
vector<long long> get_primes(int limit)
{
    vector<long long> primes;
    vector<bool> is_prime(limit + 1, true);
    for (int p = 2; p <= limit; p++)
    {
        if (is_prime[p])
        {
            primes.push_back(p);
            for (int i = p * p; i <= limit; i += p)
                is_prime[i] = false;
        }
    }
    return primes;
}

struct Candidate
{
    long long val;
    int cost;
};

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<long long> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    if (n == 1)
    {
        // Only 1 element, trivially no subarray of length >= 2
        cout << ((b[1] >= 2 || a[1] != 1) ? 1 : 0) << "\n";
        return;
    }

    vector<long long> g(n);
    for (int i = 1; i < n; i++)
    {
        g[i] = std::gcd(a[i], a[i + 1]);
    }

    vector<long long> L(n + 1);
    L[1] = g[1];
    L[n] = g[n - 1];
    for (int i = 2; i < n; i++)
    {
        // lcm(x, y) = (x / gcd(x, y)) * y
        long long current_gcd = std::gcd(g[i - 1], g[i]);
        L[i] = (g[i - 1] / current_gcd) * g[i];
    }

    vector<long long> primes = get_primes(1000);
    vector<vector<Candidate>> C(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (L[i] > b[i])
        {
            C[i].push_back({a[i], 0});
        }
        else if (a[i] != L[i])
        {
            C[i].push_back({L[i], 1});
        }
        else
        {
            // Keep unchanged base
            C[i].push_back({L[i], 0});

            // Calculate strictly forbidden prime pools of the neighbors
            long long FL = 1, FR = 1;
            if (i > 1)
            {
                if (L[i - 1] <= b[i - 1])
                    FL = L[i - 1] / g[i - 1];
                else
                    FL = a[i - 1] / g[i - 1];
            }
            if (i < n)
            {
                if (L[i + 1] <= b[i + 1])
                    FR = L[i + 1] / g[i];
                else
                    FR = a[i + 1] / g[i];
            }

            long long M = b[i] / L[i];
            int added = 0;

            // Collect up to 3 compatible primes
            for (long long p : primes)
            {
                if (p > M)
                    break;
                if (FL % p != 0 && FR % p != 0)
                {
                    C[i].push_back({p * L[i], 1});
                    added++;
                    if (added == 3)
                        break;
                }
            }
        }
    }

    // DP State: dp[value] = max_operations
    vector<pair<long long, int>> dp;
    for (auto &cand : C[1])
    {
        dp.push_back({cand.val, cand.cost});
    }

    for (int i = 2; i <= n; i++)
    {
        map<long long, int> next_dp;
        long long current_g = g[i - 1];

        for (auto &prev : dp)
        {
            for (auto &cand : C[i])
            {
                if (std::gcd(prev.first, cand.val) == current_g)
                {
                    if (next_dp.find(cand.val) == next_dp.end())
                    {
                        next_dp[cand.val] = prev.second + cand.cost;
                    }
                    else
                    {
                        next_dp[cand.val] = max(next_dp[cand.val], prev.second + cand.cost);
                    }
                }
            }
        }

        dp.clear();
        for (auto &kv : next_dp)
        {
            dp.push_back({kv.first, kv.second});
        }
    }

    int ans = 0;
    for (auto &p : dp)
    {
        ans = max(ans, p.second);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
    {
        while (t--)
            solve();
    }
    return 0;
}