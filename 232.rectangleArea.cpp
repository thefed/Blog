// LC 232, compute the two rectangles' area (deduct overlapping region if any)

#include <iostream>
#include <cassert>
using namespace std;
// rectangle1: bottom left coordinate (A,B): (-3,0), top right (C,D):(3,4)
// rectangle2: bottom left coordinate (E,F): (0,-1), top right (G,H):(9,2)
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int area1 = (C - A) * (D - B), area2 = (G - E) * (H - F);
	// no overlap
	if (C <= E || G <= A || D <= F || B >= H) return area1 + area2;
	else {	// deduct overlap
		int left = max(A, E), right = min(C, G);	// left/right position of overlap
		int top = min(D, H), bottom = max(B, F);
		return area1 + area2 - (right - left) * (top - bottom);
	}
}
int main() {
	int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	int exp = 6 * 4 + 9 * 3 - 3*2;	// 45
	assert(computeArea(A, B, C, D, E, F, G, H) == exp);
	return 0;
}