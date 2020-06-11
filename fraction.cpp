//
// Created by stepanai on 24.04.19.
//

//#include <cstdlib>
#include <iostream>
#include "fraction.h"



Fraction::Fraction(int num, int den) :numerator(num),denominator(den){
    Normalize();

}

Fraction::Fraction(double num) {
    numerator=num*100000.0;
    denominator=100000;
    Normalize();
}

/*Fraction::Fraction(int num) {
    numerator=num;
    denominator=1;
    Normalize();
}*/

inline int Fraction::GetNumerator() const {
    return numerator;
}

inline int Fraction::GetDenominator() const {
    return denominator;
}

int Fraction::GCF(int a, int b) const { //Наибольший общий делитель
    if (a%b==0)
        return abs(b);
    else
        return GCF(b,a%b);
}

int Fraction::LCM(int a, int b) const { //Наименьшее общее кратное
    return (a/GCF(a,b))*b;
}

void Fraction::Normalize() {
    if (denominator == 0 || numerator == 0) {
        numerator = 0;
        denominator=1;
    }

    if(denominator<0){
        numerator*=-1;
        denominator*=-1;
    }

    int gcf=GCF(numerator,denominator);
    numerator/= gcf;
    denominator/=gcf;

}

void Fraction::Print() const {
    std::cout<<numerator<<"/"<<denominator;
}

Fraction Sum(Fraction const  &op1,Fraction const &op2){
    Fraction sum;
    int lcd=sum.LCM(op1.denominator,op2.denominator);
    sum.numerator=op1.numerator*lcd/op1.denominator+op2.numerator*lcd/op2.denominator;
    sum.denominator=lcd;
    sum.Normalize();
    return sum;
}

Fraction Mult(Fraction const  &op1,Fraction const &op2){
    Fraction mult;
    mult.numerator=op1.numerator*op2.numerator;
    mult.denominator=op1.denominator*op2.denominator;
    mult.Normalize();
    return mult;
}

Fraction operator+(const Fraction &op1, const Fraction &op2) {
    return Sum(op1,op2);
}

Fraction operator*(const Fraction &op1, const Fraction &op2) {
    return Mult(op1,op2);
}


std::ostream& operator<<(std::ostream &os,const Fraction &f){
    os<<f.numerator<<"/"<<f.denominator;
    return os;
}

Fraction::Fraction(const Fraction &op) {
    numerator=op.numerator;
    denominator=op.denominator;

}

Fraction::operator double() const {
    return double(numerator)/denominator;
}

inline void Fraction::Set(int num, int den) &{
    numerator=num;
    denominator=den;
    Normalize();
}






