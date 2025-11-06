/**
 *    author:  Meet
 *    created: 04.11.2025 22:37:54
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

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,x;
    cin >> n >> x;
    arr.assign(n,0);
    for(ll i=0; i<n; ++i) cin >> arr[i];
    
    map<ll, vector<pair<ll,ll>>> inds;
    for(ll i=0; i<n; ++i) {
        for(ll j=i+1; j<n; ++j) inds[arr[i]+arr[j]].push_back({i,j});
    }

    for(ll i=0; i<n; ++i) {
        for(ll j=i+1; j<n; ++j) {
            ll rem = x - (arr[i] + arr[j]);
            if(inds.count(rem)) {
                for(auto& [i1,j1] : inds[rem]) {
                    if(i != i1 && i != j1 && j != i1 && j != j1) {
                        cout << i+1 << " " << j+1 << " " << i1+1 << " " << j1+1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}