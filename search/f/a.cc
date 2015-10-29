#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

const int N = 1e4 + 10;
bool is[N];
int first, last;
map <int, int> prime;
int vis[N];
struct node {
	int num, step;
};

void getPrime() {
	int i, j, s, e = sqrt(N);
	memset(is, true, sizeof(is));
	prime.clear();
	is[0] = is[1] = false;
	for (i = 4; i < N; i += 2) is[i] = false;
	for (i = 3; i < e; i += 2) if (is[i]) {
		for (j = i * i, s = i + i; j < N; j += s) {
			is[j] = false;
		}
	}
	for (i = 1000; i < 10000; i++) {
		if (is[i]) prime[i] = 1;
	}
}
int getD(int a, int b) {
	for (int i = 0; i < b; i++) {
		a /= 10;
	}
	return a % 10;
}

int getNum(int a, int b, int c) {
	for (int i = 0; i < b; i++) {
		c *= 10;
	}	
	return a + c;
}

int bfs() {
	node tmp = {first, 0};	
	if (first == last) return 0;
	queue<node> q;
	q.push(tmp);

	while (q.empty() != 1) {
		tmp = q.front();
		q.pop();
		node now;
		now.step = tmp.step + 1;
		for (int i = 0; i < 4; i++) {
			int j = i == 3 ? 1 : 0;
			int digit = getD(tmp.num, i);
			for (; j < 10; j++) {
				now.num = getNum(tmp.num, i, j - digit);	
				if (prime[now.num] == 1) {
					if (now.num == last) return now.step;
					if (vis[now.num] == 0){
						q.push(now);
						vis[now.num] = 1;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int t;
	getPrime();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &first, &last);
		int ans = bfs();
		memset(vis, 0, sizeof(vis));
		printf("%d\n", ans);

	}

	return 0;
}
