/*
CodeForces - 1133A
Middle of the Contest
*/
#include<iostream>
int main(){
    int h1, m1, h2, m2;
    char c;
    std::cin >> h1;
    std::cin >> c;
    std::cin >> m1;
    std::cin >> h2;
    std::cin >> c;
    std::cin >> m2;

    int totalMinutes, middleHours, middleMinutes;
    totalMinutes = (h1 * 60) + m1 + (h2 * 60) + m2;
    totalMinutes = totalMinutes/2;
    middleHours = totalMinutes/60;
    middleMinutes = totalMinutes % 60;
    if(middleHours < 10)
        std::cout << '0';
    std::cout << middleHours << ':';
    if(middleMinutes < 10)
        std::cout << '0';
    std::cout << middleMinutes << std::endl;
}