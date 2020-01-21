/*
CodeForces - 1130A
BePositive
*/
#include<iostream>
#include<cmath>
int main(){
    int array_length, input_value, 
        positive_values_counter, negative_values_counter;
    std::cin >> array_length;
    positive_values_counter = 0;
    negative_values_counter = 0;
    for(int index = 0; index < array_length; index++){
        std::cin >> input_value;
        if(input_value > 0)
            positive_values_counter++;
        else if(input_value < 0)
            negative_values_counter++;
    }
    int ceil_half_length = std::ceil(array_length/2.0);
    if(ceil_half_length <= positive_values_counter)
        std::cout << static_cast<int>(positive_values_counter) << std::endl;
    else if(ceil_half_length <= negative_values_counter)
        std::cout << (static_cast<int>(negative_values_counter)) * (-1) << std::endl;
    else 
        std::cout << 0 << std::endl;
}