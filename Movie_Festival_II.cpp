/**
 *    author:  Meet
 *    created: 06.11.2025 15:41:41
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<array<ll,2>> arr;
    ll n,k;
    cin >> n >> k;
    for(ll i=0; i<n; ++i) {
        ll a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    
    sort(whole(arr), [](auto& a, auto& b) {
        return a[1] < b[1];
    });

    ll ans = 0;
    multiset<ll> freetime;
    for(ll i=0; i<k; ++i) freetime.insert(0);

    for(auto& [st,en] : arr) {
        auto it = freetime.upper_bound(st);
        if(it == freetime.begin()) continue;
        --it;
        ++ans;
        freetime.erase(it);
        freetime.insert(en);
    }

    cout << ans << "\n";
    return 0;
}