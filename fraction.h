//
// Created by stepanai on 24.04.19.
//

#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H



class Fraction{
    int numerator;
    int denominator;
public:
    /*explicit*/ Fraction (int num=0,int den=1);
    Fraction (double num);
    //Fraction (int num);
    Fraction (const Fraction&);
    void Set(int num=0,int den=1)&;
    int GetNumerator()const;
    int GetDenominator()const;
    void Print()const;
    friend Fraction Sum(const Fraction&,const Fraction&);
    friend Fraction Mult(const Fraction&,const Fraction&);
    explicit operator double() const;
    friend Fraction operator+(const Fraction&,const Fraction&);
    friend Fraction operator*(const Fraction&,const Fraction&);

    //Fraction& operator=(const Fraction&);
    friend std::ostream& operator<<(std::ostream &,const Fraction &);
private:
    int GCF(int,int)const; //Наибольший общий делитель
    int LCM(int,int)const; //Наименьшее общее кратное
    void Normalize();
};








#endif //FRACTION_FRACTION_H
