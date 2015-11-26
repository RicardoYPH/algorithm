#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int main() {

	char str[N];

	string res[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	scanf("%s", str);

	int len = strlen(str);
	int ans = 0;
	for (int i = 0; i < len; i++) {
		ans = ans + str[i] - '0';	
	}
	int tmp[N];
	int cnt = 0;
	while (ans != 0) {
		tmp[cnt++] = ans % 10;
		ans /= 10;
	}

	for (int i = cnt - 1; i > 0; i--) {
		cout << res[tmp[i]] << " ";
	}
	cout << res[tmp[0]] << endl;


	return 0;
}
