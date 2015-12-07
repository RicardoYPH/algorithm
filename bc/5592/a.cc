#include <bits/stdc++.h>

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

using namespace std;

const int N = 1e5 + 10;

int num[N];
int ans[N];

int sum[N << 2];

void pushup (int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
	if (l == r){
		sum[rt] = 1;
	   	return ;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

int update(int p, int l, int r, int rt) {
//	cout << "update" << endl;
//	cout << p << endl;
//	cout << l << " " << r << " " << sum[rt] << endl;
	if (l == r) {
		sum[rt] --;
		return l;
	}
	int mid = (l + r) >> 1;
	int res;
	if (p <= sum[rt << 1]) {
		res = update(p, lson);
	}
	else {
		res = update(p - sum[rt << 1], rson);
	}
	pushup(rt);
	return res;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		num[0] = 0;
		for (int i = 1; i <= n; i++) 
			scanf("%d", num + i);
		for (int i = n; i >= 1; i--) 
			num[i] = num[i] - num[i - 1];
		build(1, n, 1);
		for (int i = n; i >= 1; i--) {
			ans[i] = update(i - num[i], 1, n, 1); 
		}
		for (int i = 1; i <= n; i++) {
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
		}
	}

	return 0;
}
