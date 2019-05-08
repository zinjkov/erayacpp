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


//friendbool operator<(const Rational &lhs, const Rational &rhs) {
//    return lhs.m_denominator *rhs.m_denominator < rhs.m_numerator * m_denominator;
//}
//bool operator>(const Rational &lhs, const Rational &rhs) {
//    return lhs.m_denominator *rhs.m_denominator > rhs.m_numerator * m_denominator;
//}


int part1() {
    cout << "Part 1" << endl;
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }
    cout << "Part 1 OK" << endl;
    return 0;
}

int part2() {
    cout << "Part 2" << endl;
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    cout << "Part 2 OK" << endl;
    return 0;
}

int part3() {
    cout << "Part 3" << endl;
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "Part 3 OK" << endl;
    return 0;
}

int part4() {
    cout << "Part 4" << endl;
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "Part 4 OK" << endl;
    return 0;
}

int part5() {
    cout << "Part 5" << endl;
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "Part 5 OK" << endl;
    return 0;
}

int main() {

    if (part1() != 0) return 1;
    if (part2() != 0) return 2;
    if (part3() != 0) return 3;
    if (part4() != 0) return 4;
    if (part5() != 0) return 5;

    cout << "OK" << endl;
    return 0;
}