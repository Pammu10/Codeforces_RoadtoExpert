#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int max_chairs = 0;
    for (int i = 1; i <= n; i++)
    {
        int p_i;
        cin >> p_i;

        if (p_i <= i)
        {
            max_chairs++;
        }
    }

    cout << max_chairs << "\n";
}

int main()
{
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}