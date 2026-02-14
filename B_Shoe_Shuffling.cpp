#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // Your problem-solving code goes here
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    map<int, int> mpp;
    for (int i = 0; i < n; i++){
        mpp[v[i]]++;
    }
    bool breaker = 0;
    for (auto it : mpp){
        if (it.second == 1){
            breaker = 1;
            break;
        }
    }
    if (breaker){
        cout << -1 << endl;
    }
    else {
        vector<int> students(n);
        for (int i = 0; i < n; i++){
            students[i] = i + 1;
        }
        int l = 0;
        int r = 0;
        while (r < n){
            if (v[l] == v[r]){
                r++;
            }
            else {
                rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);
                l = r;
            }

        }
        rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);
        for (auto i : students) {
            cout << i << " ";
        }
        cout << endl;
    }

    // Process input and produce output
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
