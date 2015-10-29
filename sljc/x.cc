#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll exgcd (ll a, ll b, ll & x, ll & y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, y, x);
	y = y - (a / b) * x;
	return d;
}

ll Min (ll a, ll b) {
	return a < b ? a : b;
} 
ll Max (ll a, ll b) {
	return a > b ? a : b;
}

int main() {

	ll a, b, c, x1, x2, y1, y2;
	scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);

	c = -c;

	if (c < 0) {a = -a; b = -b; c = -c;}
	if (a < 0) {a = -a; ll t = -x1; x1 = -x2; x2 = t;}
	if (b < 0) {b = -b; ll t = -y1; y1 = -y2; y2 = t;}

	if (a == 0 && b == 0) {
		if (c == 0) {
			cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
		}
		else
			cout << 0 << endl;
	}
	else if (a == 0) {
		if (c % b == 0) {
			ll t = c / b;
			if (t >= y1 && t <= y2) 
				cout << x2 - x1 + 1 << endl;
			else 
				cout << 0 << endl;
		}	
		else 
			cout << 0 << endl;
	}
	else if (b == 0) {
		if (c % a == 0) {
			ll t = c / a;
			if (t >= x1 && t <= x2) 
				cout << y2 - y1 + 1 << endl; 
			else 
				cout << 0 << endl;
		}
		else 
			cout << 0 << endl;
	}
	else {
		
		ll x, y;
		ll d = exgcd(a, b, x, y);
		if (c % d != 0) {
			cout << 0 << endl;
			return 0;
		}
		c = c / d;	a = a / d;	b = b / d;

		x = x * c;  y = y * c;

		double tx1 = x1, tx2 = x2, ty1 = y1, ty2 = y2;

		double xt[2];
		double yt[2];

		ll l, r;

		xt[0] = (tx1 - x) / double(b);
		xt[1] = (tx2 - x) / double (b);

		sort(xt, xt + 2);

		l = ceil(xt[0]);
		r = floor(xt[1]);

		
		yt[0] = (ty1 - y) / double(-a);
		yt[1] = (ty2 - y) / double(-a);

		sort(yt, yt + 2);

		l = Max(l, ceil(yt[0]));

		r = Min(r, floor(yt[1]));

		if (l <= r) {
			cout << r - l + 1 << endl;
		}
		else 
			cout << 0 << endl;

	}
	return  0;
}
