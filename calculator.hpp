#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

class Calculator{
  public:
    Calculator(uint32_t digits)
      : digits_(digits),
        correct_(0),
        total_(0) {
        srand(time(0));
    }

    uint32_t get_digits() { return digits_; }
    uint32_t get_correct() { return correct_; }
    uint32_t get_total() { return total_; }

    void update_digits(uint32_t digits){
        if(digits > 8) {
            std::cout << "More than 8 digits not supported" << std::endl;
            exit(1);
        }
        digits_ = digits;
    }

    void calculate_result(){
        uint32_t upper_limit = pow(10, digits_);
        uint32_t op = rand() % 4;
        std::vector<std::string> op_str = {" + ", " - ", " * ", " / "};
        uint32_t num_1, num_2, result;
        num_1 = rand() % upper_limit;
        num_2 = rand() % upper_limit;
        switch(op){
            case 0:
                result_ = num_1 + num_2;
                break;
            case 1:
                if(num_1 <= 1) num_1 = 40;
                num_2 = rand() % num_1;
                result_ = num_1 - num_2;
                break;
            case 2:
                result_ = num_1 * num_2;
                break;
            case 3:
                num_1 = num_2 * (rand() % upper_limit);
                result_ = num_1 / num_2;
                break;
            default:
                exit(1);
        };
        std::cout << num_1 << op_str[op] << num_2 << " = ";
    }

    void handle_input(){
        uint32_t input;
        std::cin >> input;
		if(!std::cin){
            std::cout << "Input only numbers!!!" << std::endl;
            std::cin.clear(); // reset failbit
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            std::cin >> input;
		}
        total_++;
        if(result_ == input){
            std::cout << " Correct" << std::endl;
            correct_++;
        }else{
            std::cout << " Wrong : Correct = " << result_ << std::endl;
        }
    }


  private:
    uint32_t digits_;
    uint32_t correct_;
    uint32_t total_;
    uint32_t result_;
};
#endif
