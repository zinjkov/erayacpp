#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "PhoneNumber.h"

using namespace std;

int main() {
    PhoneNumber s("5444-jjj");
    cout << s.GetCountryCode() << endl;
    cout << s.GetCityCode() << endl;
    cout << s.GetLocalNumber() << endl;
    cout << s.GetInternationalNumber() << endl;
    return 0;
}
