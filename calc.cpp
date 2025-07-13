#include "iostream"
#include <cstdlib>
#include <string>
#include <cstdint>

#include "calculator.hpp"

using namespace std;

int main(int argc, char** argv){
    char t;
    uint32_t limit, upper_limit;
    cout << "What should be the upper limit? ";
    cin >> upper_limit;
    Calculator obj(upper_limit);
    cout << "Welcome to calculator. Current upper limit is " << obj.upper_limit() << endl;

    while(true){
        cout << "How many calculations you want to practice in this run? ";
        cin >> limit;
        cout << "Do you want to randomize(r) / Addition(a) / Multiplication(m) / Substraction(s) / Division(d) ? ";
        cin >> t;
        while(limit--){
            obj.determine_result(t);
            obj.handle_input();
        }
        cout << "Final score : " << obj.correct() << "/" << obj.total() << endl;
        cout << "Do you want to continue? (y/n) " << endl;
        cin >> t;
        if(tolower(t) != 'y') break;
    }
    return 0;
}
