#ifndef C___CODEFORSES_RATIONAL_H
#define C___CODEFORSES_RATIONAL_H

#include <iostream>

class Rational {
public:

    Rational() = default;

    explicit Rational(const int32_t num) noexcept;

    Rational(const int32_t num, const int32_t denom);

    ~Rational() = default;

    int32_t getNumerator() const {
        return num_;
    }

    int32_t getDenominator() const {
        return denom_;
    }

    Rational operator+=(const Rational &rhs);

    Rational operator-=(const Rational &rhs);

    Rational operator*=(const Rational &rhs);

    Rational operator/=(const Rational &rhs);

    Rational operator+=(const int32_t &rhs);

    Rational operator-=(const int32_t &rhs);

    Rational operator*=(const int32_t &rhs);

    Rational operator/=(const int32_t &rhs);

    Rational operator++();

    Rational operator--();

    std::ostream &WriteTo(std::ostream &ostrm) const noexcept;

    std::istream &ReadFrom(std::istream &istrm) noexcept;


private:
    int32_t num_{0};
    int32_t denom_{1};
    static const char separator{'/'};

    // метод для сокращения дроби
    void reduce();

    int gcd_(int a, int b) const noexcept;
};

Rational operator+(const Rational &lhs, const Rational &rhs);

Rational operator-(const Rational &lhs, const Rational &rhs);

Rational operator*(const Rational &lhs, const Rational &rhs);

Rational operator/(const Rational &lhs, const Rational &rhs);

Rational operator+(const Rational &lhs, const int32_t &rhs);

Rational operator-(const Rational &lhs, const int32_t &rhs);

Rational operator-(const Rational &lhs);

Rational operator*(const Rational &lhs, const int32_t &rhs);

Rational operator/(const Rational &lhs, const int32_t &rhs);

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs);

std::istream &operator>>(std::istream &istrm, Rational &rhs);

bool operator==(const Rational &lhs, const Rational &rhs);

bool operator!=(const Rational &lhs, const Rational &rhs);

bool operator<(const Rational &lhs, const Rational &rhs);

bool operator>(const Rational &lhs, const Rational &rhs);

bool operator<=(const Rational &lhs, const Rational &rhs);

bool operator>=(const Rational &lhs, const Rational &rhs);

#endif //C___CODEFORSES_RATIONAL_H
