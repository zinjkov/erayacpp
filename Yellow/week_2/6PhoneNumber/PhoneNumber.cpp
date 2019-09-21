//
// Created by zinjk on 22.09.2019.
//

#include "PhoneNumber.h"
#include <algorithm>
#include <exception>
#include <stdexcept>


PhoneNumber::PhoneNumber(const string &international_number) {
    if (international_number[0] != '+') {
        throw invalid_argument("not +");
    }
    auto end_of_country_code = international_number.find("-");
    if (end_of_country_code == string::npos){
        throw invalid_argument("bad country code");
    }
    country_code_ = international_number.substr(1, end_of_country_code - 1);

    auto end_of_city_code = international_number.find("-", end_of_country_code + 1);
    if (end_of_city_code == string::npos) {
        throw invalid_argument("bad city code");
    }
    city_code_ = international_number.substr(end_of_country_code + 1, end_of_city_code - end_of_country_code - 1);
    local_number_ = international_number.substr((end_of_city_code + 1));

}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
