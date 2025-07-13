#include "iostream"
#include <cstdlib>
#include <string>

#include "argparse/argparse.hpp"
#include "calculator.hpp"

#define VERSION "0.1"

using namespace std;

argparse::ArgumentParser args("calculator", VERSION);

// Add and parse
void add_parse_arguments(int argc, char** argv){
    args.add_argument("--digits")
        .help("number of digits you want to practice with")
        .default_value(3)
        .implicit_value(false);
    try{
        args.parse_args(argc, argv);
    }
    catch(const std::exception& err){
        cerr << err.what() << endl;
        cerr << args;
        exit(1);
    }
}

void change_num_digits(Calculator& obj){
    cout << "Enter number of digits : ";
    uint32_t digits;
    cin >> digits;
    obj.update_digits(digits);
}

void print_welcome_message(){
    cout << "Welcome to calculator. Current default number of digits is 3" << endl;
}

int main(int argc, char** argv){
    add_parse_arguments(argc, argv);
    Calculator obj((uint32_t)args.get<int>("--digits"));
    print_welcome_message();

    while(true){
        obj.calculate_result();
        obj.handle_input();
        cout << "Continue(y) / Change Number of digits(d) / Exit(x) ? ";
        char c;
        cin >> c;
        if(tolower(c) == 'd')
            change_num_digits(obj);
        else if(tolower(c) == 'x')
            break;
    }
    cout << "Final score : " << obj.get_correct() << "/" << obj.get_total() << endl;
    return 0;
}
