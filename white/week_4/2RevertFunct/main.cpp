//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
public:
    FunctionPart(char op, double value) : op(op), value(value) {}
    void Invert() {if (op == '+') op = '-'; else op = '+';}
    double Apply(double data) const{
        if (op == '+') return value + data;
        if (op == '-') return data - value;
    }
private:
    char op;
    double value;
};

class Function {
public:
    void AddPart(char op, double data) {
        parts.emplace_back(op, data);
    }
    void Invert() {

        for(auto &part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
    double Apply(double value) {
        for(const auto &part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
private:
    vector<FunctionPart> parts;
};


Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 46) << endl;
    return 0;
}
