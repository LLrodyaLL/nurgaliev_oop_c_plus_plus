#include "rational/rational.hpp"
#include <sstream>
#include <cstdint>
#include <stdexcept>


Rational::Rational(const int32_t num) noexcept {
    num_ = num;
    denom_ = 1;
}

Rational::Rational(const int32_t num, const int32_t denom) {
    if(denom == 0){throw std::invalid_argument("Division by zero");}
    num_ = num;
    denom_ = denom;
    reduce();
}


void Rational::reduce() {
    int gcd = gcd_(num_, denom_);
    num_ /= gcd;
    denom_ /= gcd;
    if (denom_ < 0) {
        num_ = -num_;
        denom_ = -denom_;
    }
}

// метод для вычисления наибольшего общего делителя
int Rational::gcd_(int a, int b) const noexcept {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


Rational Rational::operator+=(const Rational &rhs) {
    num_ = num_ * rhs.getDenominator() + rhs.getNumerator() * denom_;
    denom_ *= rhs.getDenominator();
    reduce();
    return *this;
}

Rational Rational::operator-=(const Rational &rhs) {
    num_ = num_ * rhs.getDenominator() - rhs.getNumerator() * denom_;
    denom_ *= rhs.getDenominator();
    reduce();
    return *this;
}

Rational Rational::operator*=(const Rational &rhs) {
    num_ *= rhs.getNumerator();
    denom_ *= rhs.getDenominator();
    reduce();
    return *this;
}

Rational Rational::operator/=(const Rational &rhs) {
    num_ *= rhs.getDenominator();
    denom_ *= rhs.getNumerator();
    reduce();
    return *this;
}

Rational Rational::operator+=(const int32_t &rhs) {
    return *this += Rational(rhs);
}

Rational Rational::operator-=(const int32_t &rhs) {
    return *this -= Rational(rhs);
}

Rational Rational::operator/=(const int32_t &rhs) {
    return *this /= Rational(rhs);
}

Rational Rational::operator*=(const int32_t &rhs) {
    return *this *= Rational(rhs);
}


Rational Rational::operator++() {
    num_ += denom_;
    return *this;
};

Rational Rational::operator--() {
    num_ -= denom_;
    return *this;
};


Rational operator+(const Rational &lhs, const Rational &rhs) {
    return Rational(
            lhs.getNumerator() * rhs.getDenominator() + lhs.getDenominator() * rhs.getNumerator(),
            lhs.getDenominator() * rhs.getDenominator()
    );
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    return Rational(
            lhs.getNumerator() * rhs.getDenominator() - lhs.getDenominator() * rhs.getNumerator(),
            lhs.getDenominator() * rhs.getDenominator()
    );
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    return Rational(
            lhs.getNumerator() * rhs.getNumerator(),
            lhs.getDenominator() * rhs.getDenominator()
    );
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    return Rational(
            lhs.getNumerator() * rhs.getDenominator(),
            lhs.getDenominator() * rhs.getNumerator()
    );
}

Rational operator+(const Rational &lhs, const int32_t &rhs) {
    return Rational(lhs + Rational(rhs));
}

Rational operator-(const Rational &lhs, const int32_t &rhs) {
    return Rational(lhs - Rational(rhs));
}
Rational operator-(const Rational &lhs){
    return lhs * (-1);
}

Rational operator*(const Rational &lhs, const int32_t &rhs) {
    return Rational(lhs * Rational(rhs));
}

Rational operator/(const Rational &lhs, const int32_t &rhs) {
    return Rational(lhs / Rational(rhs));
}


std::ostream &Rational::WriteTo(std::ostream &ostrm) const noexcept {
    ostrm << num_ << separator << denom_;
    return ostrm;
}

std::istream &Rational::ReadFrom(std::istream &istrm) noexcept {
    int numerator = 0;
    int denominator = 1;
    char slash = '#';
    istrm >> numerator;
    if (istrm.peek() != '/') {
        istrm.setstate(std::ios_base::failbit);
    }
    istrm >> slash;
    if (istrm.peek() == ' '){
        istrm.setstate(std::ios_base::failbit);
    }
    istrm >> denominator;
    if (!istrm.bad() and !istrm.fail() and (denominator >= 0)) {
        *this = Rational(numerator, denominator);
    } else {
        istrm.setstate(std::ios_base::failbit);
    }
    return istrm;
}


std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) {
    return rhs.WriteTo(ostrm);
}

std::istream &operator>>(std::istream &istrm, Rational &rhs) {
    return rhs.ReadFrom(istrm);
}

bool operator==(const Rational &lhs, const Rational &rhs) {
    return (lhs.getNumerator() == rhs.getNumerator()) and (rhs.getDenominator() == lhs.getDenominator());
}

bool operator!=(const Rational &lhs, const Rational &rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rational &lhs, const Rational &rhs) {
    return (lhs.getNumerator() * rhs.getDenominator()) < (lhs.getDenominator() * rhs.getNumerator());
}

bool operator>(const Rational &lhs, const Rational &rhs) {
    return rhs < lhs;
}

bool operator<=(const Rational &lhs, const Rational &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Rational &lhs, const Rational &rhs) {
    return !(lhs < rhs);
}

