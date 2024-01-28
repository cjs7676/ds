//Digit extraction:
#include<iostream>
int digit_extraction(int key)
{
int key_length = 0;
int first_digit = 0;
int fourth_digit = 0;
first_digit = key % 10000000;
first_digit = first_digit / 1000000;
fourth_digit = key % 1000;
fourth_digit = fourth_digit / 100;
std::cout << key << " key would be hashed at location " << first_digit << fourth_digit <<
std::endl;
}
int main()
{
digit_extraction(1347878); // 18
digit_extraction(1234678); // 16
std::cout << "\n\n  ";
return 0;
}
