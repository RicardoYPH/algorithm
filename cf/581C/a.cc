#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct node {
	int data;
	int need;
	bool operator < (node b) const {
		return need < b.need;	
	}
};

node num[N];

int main() {
	
	int n, k;

	scanf("%d%d", &n, &k);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i].data);	
		int tmp = num[i].data / 10;
		ans += tmp;
		if (num[i].data != 100) 
			num[i].need = (tmp + 1) * 10 - num[i].data;		
	}

	sort(num, num + n);

	for (int i = 0; i < n; i++) {
		if (k < num[i].need) break;
		k -= num[i].need;
		num[i].data += num[i].need;
		if (num[i].need != 0)
			ans ++;
	}

	for (int i = 0; i < n; i++) {
		if (k < 10) break;	
		if (num[i].data < 100) {
			if (100 - num[i].data <= k) {
				k -= 100 - num[i].data; 
				ans += (100 - num[i].data) / 10;
				num[i].data = 100;
			}
			else {
				num[i].data += (k / 10) * 10;
				ans += k / 10;
				k -= (k / 10) * 10;
			}

		}
	}

	printf("%d\n", ans);
	return 0;

}
