#include <iostream>
using namespace std;

string schoolMethodAddition(string stringI1, string stringI2, int B) {
    int lenI1 = stringI1.size();
    int lenI2 = stringI2.size();

    while (lenI1 < lenI2) {
        stringI1 = '0' + stringI1;
        lenI1++;
    }

    while (lenI2 < lenI1) {
        stringI2 = '0' + stringI2;
        lenI2++;
    }

    string sum = "";
    int carry = 0;

    for (int i = lenI1 - 1; i >= 0; i--) {
        int current = carry + (stringI1[i] - '0') + (stringI2[i] - '0');
        carry = current / B;
        current = current % B;
        sum = (char)(current + '0') + sum;
    }

    if (carry > 0) {
        sum = (char)(carry + '0') + sum;
    }
    return sum;
}

string multiplyOne(string stringI1, string stringI2, int B) {
    int product = (stringI1[0] - '0') * (stringI2[0] - '0');
    return to_string(product);
}

string karatsubaMultiplication(string stringI1, string stringI2, int B) {
    int lenI1 = stringI1.size();
    int lenI2 = stringI2.size();

    while (lenI1 < lenI2) {
        stringI1 = '0' + stringI1;
        lenI1++;
    }
    while (lenI2 < lenI1) {
        stringI2 = '0' + stringI2;
        lenI2++;
    }

    if (lenI1 == 1 && lenI2 == 1) {
        return multiplyOne(stringI1, stringI2, B);
    }

    int mid = lenI1 / 2;
    string firstHalfI1 = stringI1.substr(0, mid);
    string secondHalfI1 = stringI1.substr(mid);
    string firstHalfI2 = stringI2.substr(0, mid);
    string secondHalfI2 = stringI2.substr(mid);

    string p0 = karatsubaMultiplication(firstHalfI1, firstHalfI2, B);
    string p1 = karatsubaMultiplication(secondHalfI1, secondHalfI2, B);
    string p2 = karatsubaMultiplication(schoolMethodAddition(firstHalfI1, secondHalfI1, B), schoolMethodAddition(firstHalfI2, secondHalfI2, B), B);

}

int main() {
    string I1, I2;
    int B;

    cin >> I1 >> I2 >> B;

    string product = karatsubaMultiplication(I1, I2, B);
    cout << product << endl;

    return 0;
}


