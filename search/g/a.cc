#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef unsigned long long ll;

const int HASH = 10007;
const int MAXN = 1010;
const int SEED = 131;
int Hash[HASH];
char s1[MAXN];
char s2[MAXN];
char s3[MAXN * 2];

ll getHash(char * str) {
	ll hash = 0;
	while (*str) {
		hash = hash * SEED + (*str++);	
	}
	return hash % HASH;
}

int main() {
	
	int t;
	scanf("%d", &t);
	int CASE = 1;

	while (t--) {
		memset(Hash, 0, sizeof(Hash));
		int n; 
		scanf("%d", &n);
		scanf("%s%s%s", s1, s2, s3);
		ll end = getHash(s3);
		int ans = 0;
		int flag = 0;

		while (1) {
			ans ++;	
			for (int i = 0; i < n; i++) {
				s3[i * 2] = s2[i];
				s3[i * 2 + 1] = s1[i];
			}s3[2 * n] = 0;

			ll tmp = getHash(s3);
			if (tmp == end) {
				flag = 1;
				break;
			}
			if (Hash[tmp] == 0) 
				Hash[tmp] = 1;
			else 
				break;

			for (int i = 0; i < n; i++) 
				s1[i] = s3[i];
			s1[n] = 0;
			for (int i = n; i < n * 2; i++)
				s2[i - n] = s3[i];
			s2[n] = 0;
		}

		printf("%d ", CASE++);

		if (flag)
			printf("%d\n", ans);
		else 
			printf("-1\n");


		
	}

	return 0;
}
