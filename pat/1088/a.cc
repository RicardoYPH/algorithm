#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a1, a2, b1, b2;

void print(ll a, ll b) {
	if (b < 0) {a = -a;	b = -b;}
	if (a == 0) {
		printf("%lld", a);
		return;
	}
	if (a < 0) printf("(-");
	ll la = llabs(a), lb = llabs(b);
	if (la >= lb) {
		printf("%lld", la / lb);
		if (la % lb != 0){
			printf(" %lld/%lld", la % lb, lb);
		}
	}
	else {
		printf("%lld/%lld", la, lb);
	}
	if (a < 0)	printf(")");
}

void pans(char ch) {
	print(a1, b1);
	printf(" %c ", ch);
	print(a2, b2);
	printf(" = ");
	ll ansa, ansb;
	ll ansd;
	switch(ch) {
		case '+':
			ansa = a1 * b2 + a2 * b1;
			ansb = b1 * b2;
			break;
		case '-':
			ansa = a1 * b2 - a2 * b1;
			ansb = b1 * b2;
			break;
		case '*':
			ansa = a1 * a2;
			ansb = b1 * b2;
			break;
		case '/':
			ansa = a1 * b2;
			ansb = a2 * b1;
			break;
	}
	if (ansb == 0 || ansa == 0) ansd = 1;
	else {
		ansd = __gcd(ansa, ansb);
	}
	ansa /= ansd; ansb /= ansd;
	if (ansb != 0) 
		print(ansa, ansb);
	else 
		printf("Inf");
	puts("");
}

int main() {
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	ll d;
	if (a1 == 0) d = 1;
	else d = __gcd(a1, b1);
	a1 /= d, b1 /= d;

	if (a2 == 0) d = 1;
	else d = __gcd(a2, b2);
	a2 /= d, b2 /= d;
	pans('+');
	pans('-');
	pans('*');
	pans('/');
	return 0;
}
