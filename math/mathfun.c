#include <math.h>
#include <stdio.h>

long long fac(int n) {
	long long ans = 1;
	for(int i = 1; i <= n; i++) ans *= i;
	return ans;
}

// $C^m_n$
long long combination(int n, int m) {
	if (m < n -m) m = n - m;
	long long ans = 1;
	for (int i = m+1; i <= n; i++) ans *= i;
	for (int i = 1; i <= n - m; i++) ans /= i;
	return ans;
}

int is_prime(int n) {
	int q = round(sqrt(n+0.0));
	for (int i = 2; i <= q; i++) {
		if (n % q == 0) return 0;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lu\n", sizeof(long int));
	printf("%lu\n", sizeof(long long int));
	printf("%lld\n", fac(n));
	return 0;
}