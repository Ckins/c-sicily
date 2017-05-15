#include <stdio.h>
#include <string.h>

int main() {
	int count = 0;
	char str[20], buf[100];
	scanf("%s", str);
	for (int abc = 100; abc <= 999; abc++) {
		for (int de = 10; de < 99; de++) {
			int e = de % 10;
			int d = de / 10;
			int z = abc * de;
			sprintf(buf, "%d%d%d%d%d", abc, de, d, e, z);
			int ok = 1;
			for (int i = 0; i < strlen(buf); i++) {
				if(strchr(str, buf[i]) == NULL) ok = 0;
			}
			if (ok) {
				printf("%d\n", ++count);
				printf("%5d\nX%4d\n-----\n%5d\n%4d \n-----\n%5d\n",
					abc, de, abc*e, abc*d, z);
			}
		}
	}
	return 0;
}