// LC 91, num of decode ways of a string
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// "12" -> AB or L, num of decoding is 2
#include <iostream>
#include <string>
using namespace std;
int numDecodings(string s) {
	if (s.empty()) return 0;
	// TODO
}
int main() {
	string s = "12";
	int res = numDecodings(s);
	printf("res: %d\n", res);
	assert(res == 2);
	return 0;
}