#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdint>

class Calculator{
  public:
    Calculator(uint32_t upper_limit)
      : upper_limit_(upper_limit),
        correct_(0),
        total_(0) {
        srand(time(0));
    }

    uint32_t upper_limit() { return upper_limit_; }
    uint32_t correct() { return correct_; }
    uint32_t total() { return total_; }

    void update_limit(uint32_t upper_limit){
        if(upper_limit > 1000000000000) {
            exit(1);
        }
        upper_limit_ = upper_limit;
    }

    void determine_result(char t){
        if(t == 'r')
            calculate_result(rand() % 4);
        else if(t == 'a')
            calculate_result(0);
        else if(t == 'm')
            calculate_result(1);
        else if(t == 's')
            calculate_result(2);
        else if(t == 'd')
            calculate_result(3);
        else
            exit(1);
    }

    void calculate_result(uint32_t op){
        std::vector<std::string> op_str = {" + ", " - ", " * ", " / "};
        uint32_t num_1, num_2, result;
        num_1 = rand() % upper_limit_;
        num_2 = rand() % upper_limit_;
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
                num_1 = num_2 * (rand() % upper_limit_);
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
    uint32_t upper_limit_;
    uint32_t correct_;
    uint32_t total_;
    uint32_t result_;
};
#endif
