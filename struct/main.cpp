#include <iostream>
#include <math.h>
using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

long long gcd(long long int a, long long int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

int* multiply(const Fraction& f1, const Fraction& f2) {
	int new_numerator = f1.numerator * f2.numerator;
	int new_denominator = f1.denominator * f2.denominator;

	int result[2] = { new_numerator,new_denominator };

	return result;
}

int* divider(const Fraction& f1, const Fraction& f2) {
	int new_numerator = f1.numerator * f2.denominator;
	int new_denominator = f1.denominator * f2.numerator;

	int result[2] = { new_numerator,new_denominator };

	return result;
}

int* sum(const Fraction& f1, const Fraction& f2) {
	
	int first_x = lcm(f1.denominator, f2.denominator) / f1.denominator;
	int second_x = lcm(f1.denominator, f2.denominator) / f2.denominator;

	int new_numerator = first_x * f1.numerator + second_x * f2.numerator;
	

	int result[2] = { new_numerator,lcm(f1.denominator, f2.denominator)};
	
	return result;
}

int* subtraction(const Fraction& f1, const Fraction& f2) {

	int first_x = lcm(f1.denominator, f2.denominator) / f1.denominator;
	int second_x = lcm(f1.denominator, f2.denominator) / f2.denominator;

	int new_numerator = first_x * f1.numerator - second_x * f2.numerator;


	int result[2] = { new_numerator,lcm(f1.denominator, f2.denominator) };

	return result;
}

void array_filler(int result_list[], int *input_list) {
	for (int i = 0; i < 2; i++) {
		result_list[i] = input_list[i];
	}
}


int main() {
	int numerator; cout << "Enter a numerator for first fraction:"; cin >> numerator;
	int denominator; cout << "Enter a denominator y for first fraction:"; cin >> denominator;

	Fraction first_fraction = { numerator, denominator };

	cout << "Enter a numerator for second fraction:"; cin >> numerator;
	cout << "Enter a denominator for second fraction:"; cin >> denominator;

	Fraction second_fraction = { numerator, denominator };

	cout << "\nFirst fraction: " << "(" << first_fraction.numerator << "/" << first_fraction.denominator << ")" << endl;
	cout << "Second fraction: " << "(" << second_fraction.numerator << "/" << second_fraction.denominator << ")" << endl;

	int* multiply_result = multiply(first_fraction, second_fraction);
	int multiply_result_list[2];
	
	array_filler(multiply_result_list, multiply_result);

	int* divide_result = divider(first_fraction, second_fraction);
	int divide_result_list[2];

	array_filler(divide_result_list, divide_result);

	int* sum_result = sum(first_fraction, second_fraction);
	int sum_result_list[2];

	array_filler(sum_result_list, sum_result);

	int* subtraction_result = subtraction(first_fraction, second_fraction);
	int subtraction_result_list[2];

	array_filler(subtraction_result_list, subtraction_result);


	cout << "\nOperations result:\n";
	cout << "Multiply result: " << "(" << multiply_result_list[0] / gcd(multiply_result_list[0],multiply_result_list[1]) << "/" << multiply_result_list[1] / gcd(multiply_result_list[0], multiply_result[1]) << ")" << endl;
	cout << "Divide result: " << "(" << divide_result_list[0] / gcd(divide_result_list[0], divide_result_list[1]) << "/" << divide_result_list[1] / gcd(divide_result_list[0], divide_result_list[1]) << ")" << endl;
	cout << "Sum result: " << "(" << sum_result_list[0] / gcd(sum_result_list[0], sum_result_list[1]) << "/" << sum_result_list[1] / gcd(sum_result_list[0], sum_result_list[1]) << ")" << endl;
	cout << "Subtraction result: " << "(" << subtraction_result_list[0] / gcd(subtraction_result_list[0], subtraction_result_list[1]) << "/" << subtraction_result_list[1] / gcd(subtraction_result_list[0], subtraction_result_list[1]) << ")" << endl;
	


	return 0;
}