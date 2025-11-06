/**
 *    author:  Meet
 *    created: 03.11.2025 15:49:03
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
    
    ll n,k;
    cin >> n >> k;

    ordered_set<ll> os;
    for(ll i=1; i<=n; ++i) os.insert(i);

    ll currpos = 0;
    while(!os.empty()) {
        ll pos = (currpos + k) % os.size();
        auto it = os.find_by_order(pos);
        cout << *it << " ";
        currpos = pos;
        os.erase(it);
    }
    cout << "\n";
    return 0;
}