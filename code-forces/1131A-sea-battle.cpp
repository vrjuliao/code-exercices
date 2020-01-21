/**
CodeForces - 1131A
Sea Battle
*/
#include <iostream>
int main(){
	int w1, h1, w2, h2;
	std::cin >> w1 >> h1 >> w2 >> h2;
	std::cout << ((h1+h2+2) * 2) + (w1 *2);
}