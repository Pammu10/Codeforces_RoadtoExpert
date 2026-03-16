#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Store tasks as pairs of {c_i, p_i}
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    // Work backwards from the last task
    double max_points = 0.0; 
    
    for (int i = n - 1; i >= 0; --i) {
        double c = tasks[i].first;
        double p = tasks[i].second;
        
        // Option 1: Complete the task
        double take_task = c + (1.0 - p / 100.0) * max_points;
        
        // Option 2: Skip the task
        double skip_task = max_points;
        
        // Take the maximum of both choices
        max_points = max(take_task, skip_task);
    }

    // Output with high precision to satisfy the 10^-6 error requirement
    cout << fixed << setprecision(9) << max_points << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}