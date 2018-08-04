#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int g_buffer[100000];

int main(){
	stack<int> st;
	vector<char> output;
	
	int length;
	cin >> length;
	

	for (int i = 0; i < length; i++) { //	8	|	4	3	6	8	7	5	2	1
		//cin >> g_buffer[i];
		int input;
		cin >> input; // 1 <= X <= length

		if (st.size()+1 == input) {
			st.pop();
			output.push_back('-');
		} else if (st.size() < input) {
			while (st.size() < input) {
				st.push(st.size() + 1);
				output.push_back('+');
			}
			st.pop();
			output.push_back('-');
		} else {

		}
	}

	//output
	for (int i = 0; i < output.size(); i++) {
		cout << output[i];
	}


	return 0;
}