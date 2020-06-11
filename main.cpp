#include <iostream>
#include <map>
#include "fraction.h"
#include <functional>






int main() {


    Fraction d1(5225,87);
    Fraction d2(7490,113);
    Fraction r(d1+d2);

    Fraction s1(5);
    Fraction s2(5.0);

    Fraction dr(11.5);
    Fraction as=7.18+dr;
    double dd=double(7.18+dr);
    std::cout<<(double)as<<std::endl;
    Fraction a(3,5);
    (a=a+Fraction(4,5));
    std::cout<<a<<std::endl;
//    std::cout<<2+a<<std::endl;

    return 0;
}