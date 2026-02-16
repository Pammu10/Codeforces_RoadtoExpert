#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, sz;

public:
    vector<pair<int, int>> close; // cycle edges
    vector<pair<int, int>> build; // new edges to build

    DSU(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int findUPar(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
        {
            close.push_back({u, v}); // cycle edge
            return;
        }

        if (sz[pu] < sz[pv])
        {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        }
        else
        {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
    }

    void checkBuild(int n)
    {
        vector<int> roots;

        for (int i = 1; i <= n; i++)
        {
            if (findUPar(i) == i)
                roots.push_back(i);
        }

        // connect all components to the first one
        for (int i = 1; i < (int)roots.size(); i++)
        {
            build.push_back({roots[0], roots[i]});
        }
    }
};

void solve()
{
    int n;
    cin >> n;

    DSU dsu(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu.unionBySize(a, b);
    }

    dsu.checkBuild(n);

    int days = dsu.build.size();
    cout << days << "\n";

    for (int i = 0; i < days; i++)
    {
        cout << dsu.close[i].first << " " << dsu.close[i].second << " "
             << dsu.build[i].first << " " << dsu.build[i].second << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
