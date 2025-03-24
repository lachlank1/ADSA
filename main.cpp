#include <iostream>
using namespace std;
#include "string"

string schoolMethodAddition(string stringl1, string stringl2, int B){
    int lenl1;
    int lenl2;

    lenl1 = stringl1.size();
    lenl2 = stringl2.size();

    while (lenl1 < lenl2){
        stringl1 = '0' + stringl1;
        lenl1++;
    }

    while (lenl2 > lenl1){
        stringl2 = '0' + stringl2;
        lenl2++;
    }

    string sum;
    int current;
    int carry = 0;

    for (int i = lenl1 - 1; i >= 0; i--){
        current = carry + (stringl1[i] - '0') + (stringl2[i] - '0');

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
    int l1;
    int l2;
    int B;

    cout<<"Please enter a number for l1: ";
    cin >> l1;
    cout<<"Please enter a number for l2: ";
    cin >> l2;
    cout<<"Please enter a number for B: ";
    cin >> B;

    string stringl1 = to_string(l1);
    string stringl2 = to_string(l2);

    string sum;
    sum = schoolMethodAddition(stringl1, stringl2, B);
    cout << sum << endl;
    return 0;
}