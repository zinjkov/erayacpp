#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    throw runtime_error("[eq");
    return "[eq";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            LastFetchedTime = AskTimeServer();
        } catch (system_error &e) {
            cout << e.what() << endl;
        }
        return LastFetchedTime;
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {

    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}