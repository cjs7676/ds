#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include <iostream>
#include <cmath>

int count_digits(int key) {
    int count = 0;
    while (key != 0) {
        key /= 10;
        ++count;
    }
    return count;
}

int fold_shift(int key, int size) {
    int key_roll = key;
    int key_sum = 0;
    int key_fac = 0;
    int key_length = 0;
    int fraction = size;
    key_length = count_digits(key_roll);
    
    while(key_length > 0) {
        if(key_length > fraction) {
            key_fac = key_roll / (int)pow(10, (key_length - fraction));
            key_sum += key_fac;
            key_roll = key_roll % (int)pow(10, (key_length - fraction));
            key_length = key_length - fraction;
        } else {
            key_sum += key_roll;
            break;
        }
    }
    return key_sum % (int)pow(10, fraction);
}

int main() {
    int result1 = fold_shift(12789, 3);
    int result2 = fold_shift(12345678, 1);
    int result3 = fold_shift(5678, 2);
	int result4 = fold_shift(325678123, 2);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;
	std::cout << "Result 3: " << result3 << std::endl;
	std::cout << " ";
    return 0;
}
