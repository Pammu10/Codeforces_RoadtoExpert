# 🚀 DSA Master Cheat Sheet — C++ (India Interview Standard)

> Revise this daily. Pattern recognition > memorization. Focus on **what to use when**.

---

## 📦 TEMPLATE BOILERPLATE

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define MOD 1e9+7
#define INF 1e18
#define endl '\n'

void solve() {
    // your code
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
```

---

## 1. 🔢 ARRAYS & STRINGS

### Prefix Sum
```cpp
// 1D prefix sum
vi prefix(n+1, 0);
for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
// range sum [l, r] (0-indexed)
int sum = prefix[r+1] - prefix[l];

// 2D prefix sum
vector<vector<int>> psum(m+1, vector<int>(n+1, 0));
for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        psum[i][j] = a[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
// query (r1,c1) to (r2,c2) 1-indexed
int q = psum[r2][c2] - psum[r1-1][c2] - psum[r2][c1-1] + psum[r1-1][c1-1];
```

### Sliding Window
```cpp
// Fixed window of size k
int wsum = 0, maxsum = 0;
for (int i = 0; i < k; i++) wsum += arr[i];
maxsum = wsum;
for (int i = k; i < n; i++) {
    wsum += arr[i] - arr[i-k];
    maxsum = max(maxsum, wsum);
}

// Variable window (e.g., longest subarray with sum <= k)
int l = 0, cur = 0, ans = 0;
for (int r = 0; r < n; r++) {
    cur += arr[r];
    while (cur > k) cur -= arr[l++];
    ans = max(ans, r - l + 1);
}
```

### Two Pointers
```cpp
// Pair with target sum in sorted array
int l = 0, r = n-1;
while (l < r) {
    int s = a[l] + a[r];
    if (s == target) { /* found */ l++; r--; }
    else if (s < target) l++;
    else r--;
}

// 3Sum
sort(all(a));
for (int i = 0; i < n-2; i++) {
    if (i > 0 && a[i] == a[i-1]) continue;
    int l = i+1, r = n-1;
    while (l < r) {
        int s = a[i]+a[l]+a[r];
        if (s == 0) { /* store */ l++; r--; }
        else if (s < 0) l++;
        else r--;
    }
}
```

### Kadane's Algorithm (Max Subarray)
```cpp
int maxSum = INT_MIN, cur = 0;
for (int x : arr) {
    cur = max(x, cur + x);
    maxSum = max(maxSum, cur);
}
```

### Next Greater Element (Monotonic Stack)
```cpp
vi nge(n, -1);
stack<int> st; // stores indices
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
        nge[st.top()] = arr[i];
        st.pop();
    }
    st.push(i);
}
```

### Largest Rectangle in Histogram
```cpp
int largestRect(vi& h) {
    stack<int> st;
    int ans = 0, n = h.size();
    for (int i = 0; i <= n; i++) {
        int cur = (i == n) ? 0 : h[i];
        while (!st.empty() && h[st.top()] > cur) {
            int ht = h[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, ht * w);
        }
        st.push(i);
    }
    return ans;
}
```

---

## 2. 🔍 BINARY SEARCH

```cpp
// Standard lower/upper bound
auto lb = lower_bound(a.begin(), a.end(), x); // first >= x
auto ub = upper_bound(a.begin(), a.end(), x); // first > x

// Binary search on answer template
int lo = 0, hi = 1e9, ans = -1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) { ans = mid; lo = mid + 1; } // or hi = mid-1 for min
    else hi = mid - 1;
}

// Rotated sorted array search
int searchRotated(vi& a, int t) {
    int l = 0, r = a.size()-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (a[m] == t) return m;
        if (a[l] <= a[m]) { // left sorted
            if (a[l] <= t && t < a[m]) r = m-1;
            else l = m+1;
        } else { // right sorted
            if (a[m] < t && t <= a[r]) l = m+1;
            else r = m-1;
        }
    }
    return -1;
}
```

---

## 3. 🔗 LINKED LIST

```cpp
struct Node { int val; Node* next; Node(int x): val(x), next(nullptr){} };

// Reverse
Node* reverse(Node* head) {
    Node *prev = nullptr, *cur = head;
    while (cur) { Node* nx = cur->next; cur->next = prev; prev = cur; cur = nx; }
    return prev;
}

// Find middle (slow-fast)
Node* middle(Node* head) {
    Node *s = head, *f = head;
    while (f->next && f->next->next) { s = s->next; f = f->next->next; }
    return s;
}

// Detect cycle
bool hasCycle(Node* head) {
    Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next; f = f->next->next;
        if (s == f) return true;
    }
    return false;
}

// Merge two sorted lists
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val <= b->val) { a->next = merge(a->next, b); return a; }
    else { b->next = merge(a, b->next); return b; }
}

// LRU Cache
class LRUCache {
    int cap;
    list<pii> dl; // {key, val}
    unordered_map<int, list<pii>::iterator> mp;
public:
    LRUCache(int c): cap(c) {}
    int get(int key) {
        if (!mp.count(key)) return -1;
        dl.splice(dl.begin(), dl, mp[key]);
        return mp[key]->second;
    }
    void put(int key, int val) {
        if (mp.count(key)) dl.erase(mp[key]);
        dl.push_front({key, val});
        mp[key] = dl.begin();
        if ((int)dl.size() > cap) { mp.erase(dl.back().first); dl.pop_back(); }
    }
};
```

---

## 4. 📚 STACK & QUEUE

```cpp
// Min Stack
class MinStack {
    stack<pii> st; // {val, min}
public:
    void push(int v) { st.push({v, st.empty() ? v : min(v, st.top().second)}); }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};

// Monotonic deque for sliding window max
vi maxSliding(vi& a, int k) {
    deque<int> dq; vi res;
    for (int i = 0; i < (int)a.size(); i++) {
        while (!dq.empty() && dq.front() < i-k+1) dq.pop_front();
        while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) res.pb(a[dq.front()]);
    }
    return res;
}
```

---

## 5. 🌳 TREES

```cpp
struct TreeNode { int val; TreeNode *left, *right; };

// DFS traversals
void inorder(TreeNode* r, vi& res) {
    if (!r) return;
    inorder(r->left, res); res.pb(r->val); inorder(r->right, res);
}

// BFS (Level order)
vector<vi> levelOrder(TreeNode* root) {
    vector<vi> res;
    if (!root) return res;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        int sz = q.size(); vi level;
        for (int i = 0; i < sz; i++) {
            auto n = q.front(); q.pop();
            level.pb(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        res.pb(level);
    }
    return res;
}

// Height
int height(TreeNode* r) {
    if (!r) return 0;
    return 1 + max(height(r->left), height(r->right));
}

// Diameter of tree
int dia = 0;
int dfs(TreeNode* r) {
    if (!r) return 0;
    int l = dfs(r->left), ri = dfs(r->right);
    dia = max(dia, l + ri);
    return 1 + max(l, ri);
}

// Lowest Common Ancestor
TreeNode* lca(TreeNode* r, TreeNode* p, TreeNode* q) {
    if (!r || r == p || r == q) return r;
    auto l = lca(r->left, p, q), ri = lca(r->right, p, q);
    return l && ri ? r : (l ? l : ri);
}

// BST operations
bool isValid(TreeNode* r, long lo = LONG_MIN, long hi = LONG_MAX) {
    if (!r) return true;
    if (r->val <= lo || r->val >= hi) return false;
    return isValid(r->left, lo, r->val) && isValid(r->right, r->val, hi);
}
```

---

## 6. 🔺 HEAPS / PRIORITY QUEUE

```cpp
// Max heap (default)
priority_queue<int> maxpq;
// Min heap
priority_queue<int, vector<int>, greater<int>> minpq;
// Custom
priority_queue<pii, vector<pii>, greater<pii>> custpq; // min by first

// K largest elements
vi kLargest(vi& a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : a) {
        pq.push(x);
        if ((int)pq.size() > k) pq.pop();
    }
    vi res;
    while (!pq.empty()) { res.pb(pq.top()); pq.pop(); }
    return res;
}

// Median from stream
priority_queue<int> lo; // max heap (lower half)
priority_queue<int, vector<int>, greater<int>> hi; // min heap (upper half)
void addNum(int n) {
    lo.push(n);
    hi.push(lo.top()); lo.pop();
    if (hi.size() > lo.size()) { lo.push(hi.top()); hi.pop(); }
}
double getMedian() {
    return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top()) / 2.0;
}
```

---

## 7. 📊 GRAPHS

```cpp
// Adjacency list
int n, m;
vector<vector<pii>> adj(n); // {neighbor, weight}
// adj[u].push_back({v, w});

// BFS
vi bfs(int src, vector<vi>& adj, int n) {
    vi dist(n, -1); dist[src] = 0;
    queue<int> q; q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (dist[v] == -1) { dist[v] = dist[u]+1; q.push(v); }
    }
    return dist;
}

// DFS
vi visited(n, 0);
void dfs(int u, vector<vi>& adj) {
    visited[u] = 1;
    for (int v : adj[u])
        if (!visited[v]) dfs(v, adj);
}

// Cycle detection (directed - DFS colors)
// 0=white,1=gray,2=black
bool dfsCycle(int u, vector<vi>& adj, vi& color) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 1) return true;
        if (color[v] == 0 && dfsCycle(v, adj, color)) return true;
    }
    color[u] = 2; return false;
}

// Topological Sort (Kahn's BFS)
vi topoSort(int n, vector<vi>& adj) {
    vi indeg(n, 0);
    for (int u = 0; u < n; u++) for (int v : adj[u]) indeg[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++) if (!indeg[i]) q.push(i);
    vi order;
    while (!q.empty()) {
        int u = q.front(); q.pop(); order.pb(u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    return order; // if order.size() != n → cycle exists
}

// Dijkstra
vi dijkstra(int src, vector<vector<pii>>& adj, int n) {
    vi dist(n, INT_MAX); dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u])
            if (dist[u]+w < dist[v]) { dist[v] = dist[u]+w; pq.push({dist[v], v}); }
    }
    return dist;
}

// Bellman-Ford (handles negative weights)
vi bellmanFord(int src, vector<tuple<int,int,int>>& edges, int n) {
    vi dist(n, INT_MAX); dist[src] = 0;
    for (int i = 0; i < n-1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] != INT_MAX && dist[u]+w < dist[v])
                dist[v] = dist[u]+w;
    return dist;
}

// Floyd Warshall (all pairs shortest path)
void floydWarshall(vector<vi>& dist, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

// Union-Find (DSU)
struct DSU {
    vi parent, rank;
    DSU(int n): parent(n), rank(n, 0) { iota(all(parent), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

// Kruskal's MST
ll kruskal(int n, vector<tuple<int,int,int>>& edges) {
    sort(all(edges));
    DSU dsu(n); ll mst = 0; int cnt = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) { mst += w; if (++cnt == n-1) break; }
    }
    return mst;
}

// Prim's MST
ll prims(int src, vector<vector<pii>>& adj, int n) {
    vi visited(n, 0); ll mst = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = 1; mst += w;
        for (auto [v, wt] : adj[u]) if (!visited[v]) pq.push({wt, v});
    }
    return mst;
}

// Number of islands (BFS/DFS grid)
int numIslands(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size(), cnt = 0;
    auto bfs = [&](int r, int c) {
        queue<pii> q; q.push({r,c}); grid[r][c] = '0';
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]=='1') {
                    grid[nx][ny]='0'; q.push({nx,ny});
                }
            }
        }
    };
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '1') { bfs(i, j); cnt++; }
    return cnt;
}
```

---

## 8. 🔄 DYNAMIC PROGRAMMING

### 1D DP Patterns
```cpp
// Fibonacci / Climbing stairs
vi dp(n+1); dp[0]=1; dp[1]=1;
for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

// Coin change (min coins)
vi dp(amount+1, INT_MAX);
dp[0] = 0;
for (int i = 1; i <= amount; i++)
    for (int c : coins)
        if (c <= i && dp[i-c] != INT_MAX)
            dp[i] = min(dp[i], dp[i-c]+1);

// House robber
vi dp(n); dp[0]=a[0]; dp[1]=max(a[0],a[1]);
for (int i = 2; i < n; i++) dp[i] = max(dp[i-1], dp[i-2]+a[i]);
```

### 2D DP Patterns
```cpp
// 0/1 Knapsack
vector<vi> dp(n+1, vi(W+1, 0));
for (int i = 1; i <= n; i++)
    for (int w = 0; w <= W; w++) {
        dp[i][w] = dp[i-1][w];
        if (wt[i-1] <= w)
            dp[i][w] = max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]);
    }

// Unbounded knapsack (same but dp[i][...] instead of dp[i-1][...])
for (int i = 1; i <= n; i++)
    for (int w = 0; w <= W; w++) {
        dp[i][w] = dp[i-1][w];
        if (wt[i-1] <= w)
            dp[i][w] = max(dp[i][w], dp[i][w-wt[i-1]] + val[i-1]);
    }

// Longest Common Subsequence
vector<vi> dp(m+1, vi(n+1, 0));
for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        dp[i][j] = (s[i-1]==t[j-1]) ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);

// Edit Distance
vector<vi> dp(m+1, vi(n+1));
for (int i = 0; i <= m; i++) dp[i][0] = i;
for (int j = 0; j <= n; j++) dp[0][j] = j;
for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        dp[i][j] = (s[i-1]==t[j-1]) ? dp[i-1][j-1] : 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});

// Longest Increasing Subsequence O(n log n)
vi lis;
for (int x : a) {
    auto it = lower_bound(all(lis), x);
    if (it == lis.end()) lis.pb(x);
    else *it = x;
}
int lisLen = lis.size();

// Matrix Chain Multiplication
vector<vi> dp(n, vi(n, 0));
for (int len = 2; len < n; len++)
    for (int i = 0; i < n-len; i++) {
        int j = i+len; dp[i][j] = INT_MAX;
        for (int k = i+1; k < j; k++)
            dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+dims[i]*dims[k]*dims[j]);
    }

// Partition DP (boolean)
vi dp(sum+1, 0); dp[0] = 1;
for (int x : a) for (int j = sum; j >= x; j--) dp[j] |= dp[j-x];
```

### DP on Strings
```cpp
// Palindrome partitioning (min cuts)
vi dp(n, 0);
for (int i = 0; i < n; i++) {
    dp[i] = i; // max cuts = i
    for (int j = 0; j <= i; j++)
        if (isPalin(s, j, i)) dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1]+1);
}
```

---

## 9. 🔤 TRIES

```cpp
struct TrieNode {
    TrieNode* ch[26] = {};
    bool isEnd = false;
};

struct Trie {
    TrieNode* root = new TrieNode();
    void insert(string& s) {
        auto n = root;
        for (char c : s) {
            if (!n->ch[c-'a']) n->ch[c-'a'] = new TrieNode();
            n = n->ch[c-'a'];
        }
        n->isEnd = true;
    }
    bool search(string& s) {
        auto n = root;
        for (char c : s) {
            if (!n->ch[c-'a']) return false;
            n = n->ch[c-'a'];
        }
        return n->isEnd;
    }
    bool startsWith(string& s) {
        auto n = root;
        for (char c : s) {
            if (!n->ch[c-'a']) return false;
            n = n->ch[c-'a'];
        }
        return true;
    }
};
```

---

## 10. 🌲 SEGMENT TREE

```cpp
struct SegTree {
    int n; vi tree;
    SegTree(int n): n(n), tree(4*n) {}
    void build(vi& a, int node, int l, int r) {
        if (l == r) { tree[node] = a[l]; return; }
        int m = (l+r)/2;
        build(a, 2*node, l, m); build(a, 2*node+1, m+1, r);
        tree[node] = tree[2*node] + tree[2*node+1]; // change op here
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = val; return; }
        int m = (l+r)/2;
        if (idx <= m) update(2*node, l, m, idx, val);
        else update(2*node+1, m+1, r, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0; // identity for op
        if (ql <= l && r <= qr) return tree[node];
        int m = (l+r)/2;
        return query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);
    }
};
// Usage: SegTree st(n); st.build(a, 1, 0, n-1);
// st.query(1, 0, n-1, l, r); st.update(1, 0, n-1, idx, val);
```

---

## 11. 🌲 BINARY INDEXED TREE (FENWICK)

```cpp
struct BIT {
    int n; vi tree;
    BIT(int n): n(n), tree(n+1, 0) {}
    void update(int i, int val) { for (i++; i <= n; i += i & -i) tree[i] += val; }
    int query(int i) { int s = 0; for (i++; i > 0; i -= i & -i) s += tree[i]; return s; }
    int query(int l, int r) { return query(r) - (l ? query(l-1) : 0); }
};
```

---

## 12. 🔄 SORTING ALGORITHMS

```cpp
// Merge Sort (+ count inversions)
ll mergeCount(vi& a, int l, int r) {
    if (l >= r) return 0;
    int m = (l+r)/2; ll cnt = 0;
    cnt += mergeCount(a, l, m) + mergeCount(a, m+1, r);
    vi tmp;
    int i = l, j = m+1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp.pb(a[i++]);
        else { cnt += m-i+1; tmp.pb(a[j++]); }
    }
    while (i <= m) tmp.pb(a[i++]);
    while (j <= r) tmp.pb(a[j++]);
    for (int k = l; k <= r; k++) a[k] = tmp[k-l];
    return cnt;
}

// Quick Sort
void quickSort(vi& a, int l, int r) {
    if (l >= r) return;
    int pivot = a[r], i = l;
    for (int j = l; j < r; j++) if (a[j] <= pivot) swap(a[i++], a[j]);
    swap(a[i], a[r]);
    quickSort(a, l, i-1); quickSort(a, i+1, r);
}
```

---

## 13. 🔢 MATH & NUMBER THEORY

```cpp
// GCD / LCM
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Fast Power (Modular Exponentiation)
ll power(ll base, ll exp, ll mod) {
    ll result = 1; base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod; exp >>= 1;
    }
    return result;
}

// Sieve of Eratosthenes
vi sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i*i; j <= n; j += i) isPrime[j] = false;
    vi primes;
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes.pb(i);
    return primes;
}

// Modular Inverse (Fermat's little theorem, mod must be prime)
ll modinv(ll a, ll mod) { return power(a, mod-2, mod); }

// nCr with mod
ll fact[MAXN], inv_fact[MAXN];
void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact[n] = modinv(fact[n], MOD);
    for (int i = n-1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}
```

---

## 14. 🔠 STRING ALGORITHMS

```cpp
// KMP (Pattern matching)
vi kmpLPS(string& pat) {
    int m = pat.size(); vi lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}
vi kmpSearch(string& txt, string& pat) {
    vi lps = kmpLPS(pat), occ;
    int n = txt.size(), m = pat.size();
    for (int i = 0, j = 0; i < n;) {
        if (txt[i] == pat[j]) { i++; j++; }
        if (j == m) { occ.pb(i-j); j = lps[j-1]; }
        else if (i < n && txt[i] != pat[j]) {
            if (j) j = lps[j-1]; else i++;
        }
    }
    return occ;
}

// Z-algorithm
vi zFunction(string& s) {
    int n = s.size(); vi z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) z[i] = min(r-i, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i] > r) { l = i; r = i+z[i]; }
    }
    return z;
}

// Rabin-Karp rolling hash
vi rabinKarp(string& txt, string& pat) {
    int n = txt.size(), m = pat.size();
    const int BASE = 31, MOD = 1e9+7;
    ll ph = 0, th = 0, pw = 1; vi occ;
    for (int i = 0; i < m-1; i++) pw = pw * BASE % MOD;
    for (int i = 0; i < m; i++) {
        ph = (ph * BASE + pat[i] - 'a' + 1) % MOD;
        th = (th * BASE + txt[i] - 'a' + 1) % MOD;
    }
    for (int i = 0; i <= n-m; i++) {
        if (ph == th) occ.pb(i); // verify if needed
        if (i < n-m) {
            th = (th - (txt[i]-'a'+1) * pw % MOD + MOD) % MOD;
            th = (th * BASE + txt[i+m]-'a'+1) % MOD;
        }
    }
    return occ;
}
```

---

## 15. 🎯 BACKTRACKING

```cpp
// Subsets
void subsets(vi& nums, int i, vi& cur, vector<vi>& res) {
    res.pb(cur);
    for (int j = i; j < (int)nums.size(); j++) {
        cur.pb(nums[j]);
        subsets(nums, j+1, cur, res);
        cur.pop_back();
    }
}

// Permutations
void permute(vi& nums, int start, vector<vi>& res) {
    if (start == (int)nums.size()) { res.pb(nums); return; }
    for (int i = start; i < (int)nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start+1, res);
        swap(nums[start], nums[i]);
    }
}

// N-Queens
bool isSafe(vector<string>& board, int r, int c, int n) {
    for (int i = r-1; i >= 0; i--) if (board[i][c]=='Q') return false;
    for (int i=r-1,j=c-1; i>=0&&j>=0; i--,j--) if (board[i][j]=='Q') return false;
    for (int i=r-1,j=c+1; i>=0&&j<n; i--,j++) if (board[i][j]=='Q') return false;
    return true;
}
void solveNQ(int r, int n, vector<string>& board, vector<vector<string>>& res) {
    if (r == n) { res.pb(board); return; }
    for (int c = 0; c < n; c++) {
        if (isSafe(board, r, c, n)) {
            board[r][c] = 'Q';
            solveNQ(r+1, n, board, res);
            board[r][c] = '.';
        }
    }
}

// Sudoku Solver
bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') continue;
        for (char c = '1'; c <= '9'; c++) {
            // check row, col, box
            bool ok = true;
            for (int k = 0; k < 9 && ok; k++)
                if (board[i][k]==c || board[k][j]==c || board[3*(i/3)+k/3][3*(j/3)+k%3]==c) ok=false;
            if (ok) {
                board[i][j] = c;
                if (solveSudoku(board)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    return true;
}
```

---

## 16. 🌊 GREEDY PATTERNS

```cpp
// Activity Selection (max non-overlapping)
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
int cnt = 0, end = INT_MIN;
for (auto& i : intervals) if (i[0] >= end) { cnt++; end = i[1]; }

// Jump Game II (min jumps)
int jumps = 0, curEnd = 0, farthest = 0;
for (int i = 0; i < n-1; i++) {
    farthest = max(farthest, i + nums[i]);
    if (i == curEnd) { jumps++; curEnd = farthest; }
}

// Gas Station
int gas_start(vi& gas, vi& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
        tank += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (tank < 0) { start = i+1; tank = 0; }
    }
    return total >= 0 ? start : -1;
}
```

---

## 17. 📐 BIT MANIPULATION

```cpp
// Common tricks
x & (x-1)    // clear lowest set bit
x & (-x)     // isolate lowest set bit
x | (1<<k)   // set bit k
x & ~(1<<k)  // clear bit k
x ^ (1<<k)   // toggle bit k
__builtin_popcount(x)   // count set bits
__builtin_ctz(x)        // count trailing zeros

// XOR tricks
// a ^ a = 0, a ^ 0 = a
// Find single number in array where all others appear twice
int single = 0; for (int x : a) single ^= x;

// Count subsets with XOR = k
int countSubsetsXOR(vi& a, int k) {
    unordered_map<int,int> mp; mp[0] = 1;
    int pre = 0, cnt = 0;
    for (int x : a) { pre ^= x; cnt += mp[pre ^ k]; mp[pre]++; }
    return cnt;
}
```

---

## 🧩 COMMON INTERVIEW PATTERNS QUICK REFERENCE

| Pattern | Use When |
|---|---|
| **Sliding Window** | Subarray/substring with constraint |
| **Two Pointers** | Sorted array, pair sum, palindrome |
| **Binary Search** | Sorted data, "minimum max" problems |
| **BFS** | Shortest path (unweighted), level order |
| **DFS/Backtrack** | All paths, combinations, permutations |
| **Dijkstra** | Shortest path (weighted, non-negative) |
| **DP (1D)** | Decisions at each index |
| **DP (2D)** | Two sequences, grid problems |
| **Monotonic Stack** | Next greater/smaller element |
| **Prefix Sum** | Range sum queries |
| **DSU** | Connected components, cycle detection |
| **Trie** | Prefix matching, autocomplete |
| **Segment Tree** | Range queries + point updates |

---

## ⏱️ COMPLEXITY CHEAT SHEET

| Structure/Algo | Time | Space |
|---|---|---|
| Array access | O(1) | — |
| Binary Search | O(log n) | O(1) |
| Sorting | O(n log n) | O(n) |
| BFS / DFS | O(V + E) | O(V) |
| Dijkstra | O(E log V) | O(V) |
| DP (2D) | O(n²) | O(n²) |
| Segment Tree | O(log n) query/update | O(n) |
| Trie insert/search | O(L) where L=length | O(ALPHABET × n) |
| FFT | O(n log n) | O(n) |

---

*🔁 Revise this sheet daily. The goal is instant pattern recognition — when you read a problem, the solution structure should click immediately.*
