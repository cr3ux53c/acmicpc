//https://www.acmicpc.net/problem/1003

#include <iostream>
#include <string>
using namespace std;

int count0 = 0;
int count1 = 0;

//sample function
int fibonacci(int n) {
	if (n == 0) {
		count0++;
		return 0;
	} else if (n == 1) {
		count1++;
		return 1;
	} else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int getFibonacci(int n) {
	int a = 0, b = 1;
	int tmp;

	if (n == 0) {
		count0 = 1;
		count1 = 0;
		return b;
	}
	for (int i = 0; i < n - 1; i++) {
		tmp = b;
		b = a + b;
		a = tmp;
	}
	count0 = a;
	count1 = b;
	return b;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		getFibonacci(n);

		cout << count0 << " " << count1 << '\n';
		count0 = 0; count1 = 0;
	}
	return 0;
}

/*규칙
40
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
*/