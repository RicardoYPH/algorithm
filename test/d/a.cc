#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int a[N];

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) 
			scanf("%d", a + i);
		
		ll Max, Maxs, Maxe;
		ll tmp;
		tmp = Max = Maxs = Maxe = 0;
		ll ts;
		ts = 0;
		for (int i = 0; i < n; i++) {
			tmp = tmp + a[i];
			if (tmp < 0) {
				tmp = 0;	
				ts = i + 1;
				continue;
			}
			if (tmp > Max) {
				Max = tmp;
				Maxs = ts;
				Maxe = i;
			}
		}

		printf("%lld\n", Max);
	
	}


	return 0;
}
