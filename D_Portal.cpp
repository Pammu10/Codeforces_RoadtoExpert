#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<int> A, B, C;
    for (int i = 0; i < x; i++)
        A.push_back(p[i]);
    for (int i = x; i < y; i++)
        B.push_back(p[i]);
    for (int i = y; i < n; i++)
        C.push_back(p[i]);

    if (!B.empty())
    {
        auto min_it = min_element(B.begin(), B.end());
        rotate(B.begin(), min_it, B.end());
    }

    vector<int> S = A;
    S.insert(S.end(), C.begin(), C.end());

    int insert_pos = S.size();
    if (!B.empty())
    {
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] > B[0])
            {
                insert_pos = i;
                break;
            }
        }
    }

    for (int i = 0; i < insert_pos; i++)
    {
        cout << S[i] << " ";
    }
    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i] << " ";
    }
    for (int i = insert_pos; i < S.size(); i++)
    {
        cout << S[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}