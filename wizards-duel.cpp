/*
CodeForces - 591A
Wizard's Duel
*/
#include<iostream>
// #include <iomanip>
int main(){
    float harry, voldemort, distance;
    std::cin >> distance >> harry >> voldemort;
    float total = distance / (harry + voldemort);
    std::cout << total * harry << std::endl;
}