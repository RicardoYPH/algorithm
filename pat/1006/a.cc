#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int main() {

	int t;
	scanf("%d", &t);

	char tmp1[10], tmp2[10];
	char ans1[10], ans2[10];
	char name1[20], name2[20];
	char tname[20];

	scanf("%s", name1);
	strcpy(name2, name1);
	scanf("%s", ans1);
	scanf("%s", ans2);

	for (int i = 2; i <= t; i++) {
		scanf("%s", tname);
		scanf("%s", tmp1);
		if (strcmp(tmp1, ans1) < 0) {
			strcpy(ans1, tmp1);
			strcpy(name1, tname);
		}
		scanf("%s", tmp2);
		if (strcmp(tmp2, ans2) > 0) {
			strcpy(ans2, tmp2);
			strcpy(name2, tname);
		}
	}

	printf("%s %s\n", name1, name2);


	return 0;
}
