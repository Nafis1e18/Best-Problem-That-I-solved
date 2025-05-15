#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int last1 = v.back();
    v.pop_back();
    int second_last1 = v.back();
    v.pop_back();
    s -= 2;

    auto ok = [&](int m) {
        int res = 0, g = 0, q = 0;
        for(int i = 0; i < m; ++i) {
            res += v[i] / 3;
            if(v[i] % 3 == 2) {
                q++;
            }
            if(v[i] % 3 == 1) {
                g++;
            }
        }
        int x = min(g, q);
        res += x;
        g -= x;
        q -= x;
        res += q;
        res += (g + 1) / 2;
        return res <= s;
    };

    int l = -1, r = n - 1;
    while((r - l) > 1) {
        int m = l + (r - l) / 2;
        if(ok(m)) l = m;
        else r = m;
    }

    cout << l + 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}
