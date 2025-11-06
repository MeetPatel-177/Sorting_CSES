/**
 *    author:  Meet
 *    created: 30.10.2025 12:59:50
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<ll> arr, pos;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        arr.assign(n+1,0);
        pos.assign(n+1,0);

        for(ll i=1; i<=n; ++i) {
            cin >> arr[i];
            pos[arr[i]] = i;
        }
        
        ll ans = 1;
        for(ll i=2; i<=n; ++i) {
            if(pos[i] < pos[i-1]) {
                ++ans;
            }
        }

        auto check = [&](ll x) -> bool {
            if(x < 1 || x >= n) return 0;
            return (pos[x] > pos[x+1]);
        };

        while(m--) {
            ll a,b;
            cin >> a >> b;

            ll ele1 = arr[a], ele2 = arr[b];

            //affected values will only be this 4 we are using set because there can be overlapping when ele1==ele2+1 or vise versa
            set<ll> affected = {ele1-1,ele1,ele2-1,ele2};

            for(auto& aff : affected) ans -= check(aff);

            swap(pos[ele1], pos[ele2]);
            swap(arr[a], arr[b]);

            for(auto& aff : affected) ans += check(aff);
            
            cout << ans << "\n";
        }

    }
    return 0;
}