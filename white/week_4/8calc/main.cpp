#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;


long gcd04(long a, long b) {

    long nod = 1L;
    for (long i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            nod = i;
            break;
        }
    }
    return nod;
}

class Rational {
public:
    Rational() : m_numerator(0), m_denominator(1) {

    }

    Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
        if (m_denominator == 0) throw invalid_argument("denominator == 0");
        int g = gcd04(abs(m_numerator), abs(m_denominator));
        if (g != 0) {
            m_numerator /= g;
            m_denominator /= g;
        }
        if (m_denominator < 0) {
            m_denominator *= -1;
            m_numerator *= -1;
        }
        if (m_numerator == 0) {
            m_denominator = 1;
        }
    }

    int Numerator() const {
        return m_numerator;
    }

    int Denominator() const {
        return m_denominator;
    }

    friend bool operator==(const Rational &lhs, const Rational &rhs) {
        return lhs.m_numerator == rhs.m_numerator;
    }

    friend bool operator<(const Rational &lhs, const Rational &rhs) {
        return lhs.m_numerator *rhs.m_denominator < rhs.m_numerator * lhs.m_denominator;
    }
    friend bool operator>(const Rational &lhs, const Rational &rhs) {
        return lhs.m_numerator *rhs.m_denominator > rhs.m_numerator * lhs.m_denominator;
    }


    Rational operator+(const Rational &rhs) {
        return { m_numerator*rhs.m_denominator + rhs.m_numerator*m_denominator, m_denominator*rhs.m_denominator};
    }
    Rational operator-(const Rational &rhs) {
        return { m_numerator*rhs.m_denominator - rhs.m_numerator*m_denominator, m_denominator*rhs.m_denominator};
    }

    Rational operator*(const Rational &rhs) {
        return { m_numerator * rhs.m_numerator, m_denominator*rhs.m_denominator};
    }
    Rational operator/(const Rational &rhs) {
        if (rhs.m_numerator == 0) throw domain_error("rhs == 0");
        return { m_numerator * rhs.m_denominator, m_denominator*rhs.m_numerator};
    }

    friend ostream &operator<<(ostream &os, const Rational &rat) {
        os << rat.m_numerator << "/" << rat.m_denominator;
        return os;
    }
    friend istream &operator>>(istream &is, Rational &rat) {
        char c;
        is >> rat.m_numerator >> c >> rat.m_denominator;
        rat = Rational(rat.m_numerator, rat.m_denominator);
        return is;
    }

private:
    int m_numerator;
    int m_denominator;
};


int main() {
    while(true){
        try {
            Rational r1, r2;
            char op = 0;
            cin >> r1 >> op >> r2;
            if (op == '+') {
                cout << r1 + r2 << endl;
            }
            if (op == '-') {
                cout << r1 - r2 << endl;
            }
            if (op == '*') {
                cout << r1 * r2 << endl;
            }
            if (op == '/') {
                cout << r1 / r2 << endl;
            }
        } catch (exception & ex) {
            cout << ex.what() << endl;
        }
    }
    cout << "OK" << endl;
    return 0;
}