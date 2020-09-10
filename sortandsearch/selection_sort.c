#include <stdio.h>

void user_made(int X[12]);
void sort(int X[12]);
void search(int X[12]);

int main() {
	int X[12];
	int num, result;
	user_made(X);
	sort(X);
	search(X);
	return 0;
}

void user_made(int X[12]) {
	int i;
	for (i = 0;i < 12;i++) {
		if (i == 0) {
			printf("Input 12 numbers. It's your %dst number :", i + 1);
			scanf_s("%d", &X[i]);
		}
		else if (i == 1) {
			printf("Input 12 numbers. It's your %dnd number :", i + 1);
			scanf_s("%d", &X[i]);
		}
		else if (i == 2) {
			printf("Input 12 numbers. It's your %drd number :", i + 1);
			scanf_s("%d", &X[i]);
		}
		else {
			printf("Input 12 numbers. It's your %dth number :", i + 1);
			scanf_s("%d", &X[i]);
		}
	}
	printf("All numbers are entered\n");
}

void sort(int X[12]) {
	int i, i1, min_key, min, temp, start;
	for (i = 0;i < 12;i++) {
		min = X[i], min_key = i;
		for (i1 = i + 1;i1 < 12;i1++) {
			if (X[i1] < min) {
				min_key = i1;
				min = X[i1];
			}
		}
		temp = X[i];
		X[i] = X[min_key];
		X[min_key] = temp;
	}
	printf("Selection sort complete.\n");
	for (i = 0;i < 12;i++) printf("%d ", X[i]);
	printf("\n");
}

void search(int X[12]) {
	int low, high, mid;
	int num;
	low = 0;
	high = 11;
	printf("What kind of number you looking for?");
	scanf_s("%d", &num);
	while (low <= high) {
		mid = (low + high) / 2;
		if (num == X[mid]) {
			if (mid == 0)
				printf("%d is %dst number of your array", num, mid + 1);
			else if (mid == 1)
				printf("%d is %dnd number of your array", num, mid + 1);
			else if (mid == 2)
				printf("%d is %drd number of your array", num, mid + 1);
			else printf("%d is %dth number of your array", num, mid + 1);
			return 0;
		}
		else if (num < X[mid]) low = mid + 1;
		else high = mid - 1;
	}
}