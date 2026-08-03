#include <bits/stdc++.h>
#define endl "\n"
#define rg(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MODX = 1e9 + 7;
const int modx = 998'244'353;

void sol() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<pii> cx(m);
	for (auto& i : a) cin >> i;
	for (auto& [c, x] : cx) cin >> c >> x;
	bool flag = true, zero = false;


	//
	for (auto& i : a) {
		if (!i) zero = true;
		if (i != a[0]) {
			flag = false;
			break;
		}
	}


	for (auto& i : a)
		if (!i) zero = true;



	// for (auto& i : a) cout << i << ' ';
	// cout << endl;
	// cout << zero;



	if (flag) {
		cout << "Yes" << endl;
		return;
	}


	int i = 0;
	if (zero) {

		//1 MEX 2 GCD
		// cout << 1;
		int last_is1 = 0;
		while (i < m && cx[i].first == 1) 
		{
			last_is1 = (cx[i].second == 1);
			i++;
		}


		if (i == m) {
			cout << "No" << endl;
			return;
		}

		if (i) 
		{
			if (i & 1) 
			{
				for (auto& j : a) 
				{
					if (j) j = 0;
					else j = last_is1 + 1;
				}
			}
			else 
			{
				for (auto& j : a) 
				{
					if (j) j = last_is1 + 1;
				}
			}
		}




		for (auto& j : a) j = gcd(j, cx[i].second);
		i++;

		if (i == m) {
			// for (auto& j : a) cout << j << ' ';
			for (auto& j : a) {
				if (j != a[0]) {
					cout << "No" << endl;
					return;
				}
			}
			// cout << 1;
			cout << "Yes" << endl;
			return;
		}




	}


	//纯gcd
	for (int j = i; j < m; j++) {
		auto& [c, x] = cx[j];
		if (c != 2) {
			cout << "Yes" << endl;
			return;
		}
	}
	int g = 0;
	for (int j = i; j < m; j++) {
		g = gcd(g, cx[j].second);
	}
	for (auto& j : a) {
		j = gcd(j, g);
		if (j != a[0]) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	// else{
		// for (auto& [c, x] : cx){
			// if (c != 2){
				// cout << "Yes" << endl;
				// return;
			// }
		// }
		// int g = 0;
		// for (auto& [c, x] : cx)
			// g = gcd(g, x);
		// for (auto& i : a){
			// i = gcd(i, g);
			// if (i != a[0]){
				// cout << "No" << endl;
				// return;
			// }
		// }
		// cout << "Yes" << endl;
	// }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) sol();
}