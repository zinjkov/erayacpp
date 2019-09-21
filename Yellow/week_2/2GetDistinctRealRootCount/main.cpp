#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    double D = b*b - 4 * a * c;
    if (D < 0) {
        return 0;
    } else if(D > 0) {
        return 2;
    } else {
        return 1;
    }
}

void TestAZero() {
    {
        AssertEqual(GetDistinctRealRootCount(0, 8, 1), 2, "1 2");
    }
}

void TestBZero() {
    {
        AssertEqual(GetDistinctRealRootCount(-1, 0, 2), 2, "1 2");
    }
}

void TestCZero() {
    {
        AssertEqual(GetDistinctRealRootCount(1, 2, 0), 2, "1 2");
    }
}

void TestACZero() {
    {
        AssertEqual(GetDistinctRealRootCount(0, 4, 0), 2, "1 2");
    }
}

void TestBCZero() {
    {
        AssertEqual(GetDistinctRealRootCount(-4, 0, 0), 1, "1 2");
    }
}

int main() {
    TestRunner runner;
    runner.RunTest(TestAZero, "TestAZero");
    runner.RunTest(TestBZero, "TestBZero");
    runner.RunTest(TestCZero, "TestCZero");
    runner.RunTest(TestACZero, "TestACZero");
    runner.RunTest(TestBCZero, "TestBCZero");
    return 0;
}
