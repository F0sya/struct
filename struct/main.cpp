#include <iostream>
using namespace std;

typedef struct complex {
    float real;
    float imag;
} complexNumber;

complexNumber addComplexNumbers(complex, complex);
complexNumber subtractComplexNumbers(complex, complex);
complexNumber multiplyComplexNumbers(complex, complex);
complexNumber divideComplexNumbers(complex, complex);


int main() {
    complexNumber num1, num2, complexSum, complexSubtract, complexMultiply, complexDivide;
    char signOfImagSum, signOfImagSubtract, signOfImagMultiply,signOfImagDivide;

    cout << "For 1st complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> num1.real >> num1.imag;

    cout << endl
        << "For 2nd complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> num2.real >> num2.imag;

    complexSum = addComplexNumbers(num1, num2);
    complexSubtract = subtractComplexNumbers(num1, num2);
    complexMultiply = multiplyComplexNumbers(num1, num2);
    complexDivide = divideComplexNumbers(num1, num2);

    signOfImagSum = (complexSum.imag > 0) ? '+' : '-';
    signOfImagSubtract = (complexSubtract.imag > 0) ? '+' : '-';
    signOfImagMultiply = (complexMultiply.imag > 0) ? '+' : '-';
    signOfImagDivide = (complexDivide.imag > 0) ? '+' : '-';

    complexSum.imag = (complexSum.imag > 0) ? complexSum.imag : -complexSum.imag;
    complexSubtract.imag = (complexSubtract.imag > 0) ? complexSubtract.imag : -complexSubtract.imag;
    complexMultiply.imag = (complexMultiply.imag > 0) ? complexMultiply.imag : -complexMultiply.imag;
    complexDivide.imag = (complexDivide.imag > 0) ? complexDivide.imag : -complexDivide.imag;

    cout << "\nSum = " << complexSum.real << signOfImagSum << complexSum.imag << "i" << endl;
    cout << "Subtract = " << complexSubtract.real << signOfImagSubtract << complexSubtract.imag << "i" << endl;
    cout << "Multiply = " << complexMultiply.real << signOfImagMultiply << complexMultiply.imag << "i" << endl;
    cout << "Divide = " << complexDivide.real << signOfImagDivide << complexDivide.imag << "i" << endl;
    return 0;
}

complexNumber addComplexNumbers(complex num1, complex num2) {
    complex temp;
    temp.real = num1.real + num2.real;
    temp.imag = num1.imag + num2.imag;
    return (temp);
}

complexNumber subtractComplexNumbers(complex num1, complex num2) {
    complex temp;
    temp.real = num1.real - num2.real;
    temp.imag = num1.imag - num2.imag;
    return (temp);
}

complexNumber multiplyComplexNumbers(complex num1, complex num2) {
    complex temp;
    temp.real = num1.real*num2.real - num1.imag*num2.imag;
    temp.imag = num1.real*num2.imag - num2.real*num1.imag;
    return (temp);
}
complexNumber divideComplexNumbers(complex num1, complex num2) {
    complex temp;
    temp.real = (num1.real * num2.real + num1.imag * num2.imag) / ((num2.real * num2.real) + (num2.imag * num2.imag));
    temp.imag = (num1.imag*num2.real - num1.real*num2.imag) / ((num2.real * num2.real) + (num2.imag * num2.imag));
    return (temp);
}