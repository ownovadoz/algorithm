#include <stdio.h>

int x, k;
long long int offset[128];

int main(void) {

	long long int ans = 0;

	scanf("%d %d", &x, &k);

	offset[0] = 1;
	for (int i = 1; i < 128; i++) {
		offset[i] = offset[i - 1] * 2;
	}

	for (int i = 0; i < 128; i++) {
		if ((x & 1) == 0) {
			if (k & 1) {
				ans += offset[i];
			}
			k = k >> 1;
		}
		x = x >> 1;
	}

	printf("%lld\n", ans);

	return 0;
}