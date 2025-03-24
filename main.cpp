#include <iostream>
using namespace std;
#include "string"

string schoolMethodAddition(string stringI1, string stringI2, int B){
    int lenI1;
    int lenI2;

    lenI1 = stringI1.size();
    lenI2 = stringI2.size();

    while (lenI1 < lenI2){
        stringI1 = '0' + stringI1;
        lenI1++;
    }

    while (lenI2 > lenI1){
        stringI2 = '0' + stringI2;
        lenI2++;
    }

    string sum;
    int current;
    int carry = 0;

    for (int i = lenI1 - 1; i >= 0; i--){
        current = carry + (stringI1[i] - '0') + (stringI2[i] - '0');

        carry = current / B;

        current = current % B;

        sum = (char)(current + '0') + sum;

        if (carry > 0){
            sum = (char)(carry + '0') + sum;
        }
    }
    return sum;
}


int main(){
    string I1;
    string I2;
    int B;

    cin >> I1 >> I2 >> B;

    string sum;
    sum = schoolMethodAddition(I1, I2, B);
    cout << sum << endl;
    return 0;
}

