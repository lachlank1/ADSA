#include <iostream>
#include <string>
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

    int product = (stringI1[0] - '0') * (stringI2[0] - '0');
    string res = "";
    while (product > 0) {
        res = char(product % B + '0') + res;
        product /= B;
    }
    return res.empty() ? "0" : res;
}



string complement (string stringI1, string stringI2, int B){
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

    int n = stringI2.length();
    for (int i = 0; i < n; i++){
        int single = stringI2[i] - '0';
        int complementSingle = (B - 1) - single;
        stringI2[i] = complementSingle + '0';
    }

    stringI2 = schoolMethodAddition(stringI2, "1", B);
    return stringI2;
}   

string shift(string string, int zeros){
    for (int i = 0; i < zeros; i++){
        string.push_back('0');
    }
    return string;
}

string subtract(string stringI1, string stringI2, int B){
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

    string complementStringI2 = complement (stringI1, stringI2, B);
    string sum = schoolMethodAddition(stringI1, complementStringI2, B);

    if (sum.length() > stringI1.length()){
        sum = sum.substr(1);
    }

    return sum;

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

    int mid1 = lenI1 / 2;
    int mid2 = lenI1 - mid1;

    string firstHalfI1 = stringI1.substr(0, mid2);
    string secondHalfI1 = stringI1.substr(mid2);
    string firstHalfI2 = stringI2.substr(0, mid2);
    string secondHalfI2 = stringI2.substr(mid2);

    string p0 = karatsubaMultiplication(secondHalfI1, secondHalfI2, B);
    string p1 = karatsubaMultiplication(firstHalfI1, firstHalfI2, B);

    string p0Sum = schoolMethodAddition(secondHalfI1, firstHalfI1, B);
    string p1Sum = schoolMethodAddition(secondHalfI2, firstHalfI2, B);

    string sumP0SumP1Sum = karatsubaMultiplication(p0Sum, p1Sum, B);
    string middle = subtract(sumP0SumP1Sum, schoolMethodAddition(p0, p1, B), B);


    string subResult1 = shift(p1, 2 * mid1);
    string subResult2 = shift(middle, mid1);
    string result = schoolMethodAddition(schoolMethodAddition(subResult1, subResult2, B), p0, B);

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
}


string division(string stringI1, string I2, int B){
    return "0";
}

int main() {
    string I1, I2;
    int B;

    cin >> I1 >> I2 >> B;

    string sumResult = schoolMethodAddition(I1, I2, B);
    string productResult = karatsubaMultiplication(I1, I2, B);
    string divisionResult = division(I1, I2, B);

    cout << sumResult << " " << productResult << " " << divisionResult << endl;

    return 0;
}


