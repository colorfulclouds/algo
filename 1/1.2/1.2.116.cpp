#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>
using namespace std;

class Rational
{
    private:
        int numerator; //final
        int denominator;//final
    
    public:
        Rational()
        {
            ;
        }
        Rational(int numerator , int denominator);
        Rational plus(Rational b);
        Rational minus(Rational b);
        Rational times(Rational b);
        Rational divides(Rational b);
        bool equals(Rational that);
        string toString();

        int gcd(int p , int q)
        {
            if(q == 0)
                return p;
            int r = p % q;
            return gcd(q , r);
        }

};

Rational::Rational(int numerator , int denominator)
{
    assert(denominator != 0);

    int y = gcd(numerator , denominator);
    this->numerator = numerator / y;
    this->denominator = denominator / y;
}

Rational Rational::plus(Rational b)
{
    this->numerator += b.numerator;
    this->denominator += b.denominator;

    return *this;
}

Rational Rational::minus(Rational b)
{
    this->numerator -= b.numerator;
    this->denominator -= b.denominator;

    return *this;
}

Rational Rational::times(Rational b)
{
    this->numerator *= b.numerator;
    this->denominator *= b.denominator;

    return *this;
}

Rational Rational::divides(Rational b)
{
    this->numerator /= b.numerator;
    this->denominator /= b.denominator;

    return *this;
}

bool Rational::equals(Rational that)
{
    if(this->numerator == that.numerator && this->denominator == that.denominator)
        return true;
    else
    return false;
}

string Rational::toString()
{
    char buff[BUFSIZ] = {'\0'};
    sprintf(buff , "%d/%d" , this->numerator , this->denominator);
    string s(buff);
    
    return s;
}

int main(void)
{
    Rational a(10 , 2);
    Rational b(3 , 4);

    Rational c;

    c = a.plus(b);

    printf("%s\n", c.toString().c_str());

    return 0;
}
