//https://www.acmicpc.net/problem/11003
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//input
	int N, L; cin >> N >> L;
	vector<int> vec(N);
	vector<int> D(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	//calc
	for (int i = 0; i < N; i++) {
		//get Di
		//int offset = max(i - L + 1, 0);
		/*for (auto it = vec.begin() + max(i - L + 1, 0);it!=vec.end()-(N-i-1);it++){
			cout << *it << " ";
		}*/
		cout << *min_element(vec.begin() + max(i - L + 1, 0), vec.end() - (N - i - 1)) << " ";
	}

	return 0;
}