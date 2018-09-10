#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <stack>


void operation(std::string s, std::stack <std::string> &container) {
    if (isdigit(s[0])) {
        container.push(s);

    } else if (s == "add") {
        std::string &temp1_ = container.top();
        std::string temp1 = temp1_;
        container.pop();

        std::string &temp2_ = container.top();
        std::string temp2 = temp2_;
        container.pop();

        if (temp1.find('.') != std::string::npos) {
            double first = std::stod(temp1);
            double second = std::stod(temp2);
            double result = first + second;
            container.push(std::to_string(result));

            std::cout << first << " + ";
            if (temp2.find('.') != std::string::npos) {
                std::cout << second;
            } else {
                std::cout << temp2;
            }
            std::cout << " = " << result << "\n";

        } else {
            std::cout << temp1 << " + ";
            if (temp2.find('.') != std::string::npos) {
                double first = std::stod(temp1);
                double second = std::stod(temp2);
                double result = first + second;
                container.push(std::to_string(result));

                std::cout << second << " = " << result<<"\n";


            } else {
                std::cout << temp2 ;
                int result = std::stoi(temp1) + std::stoi(temp2);
                container.push(std::to_string(result));

                std::cout << " = " << result << "\n";


            }

        }
    } else if (s == "sub") {
        std::string &temp1_ = container.top();
        std::string temp1 = temp1_;
        container.pop();

        std::string &temp2_ = container.top();
        std::string temp2 = temp2_;
        container.pop();

        if (temp1.find('.') != std::string::npos) {
            double first = std::stod(temp1);
            double second = std::stod(temp2);
            double result = first - second;
            container.push(std::to_string(result));

            std::cout << first << " - ";
            if (temp2.find('.') != std::string::npos) {
                std::cout << second;
            } else {
                std::cout << temp2;
            }
            std::cout << " = " << result << "\n";

        } else {
            std::cout << temp1 << " - ";
            if (temp2.find('.') != std::string::npos) {
                double first = std::stod(temp1);
                double second = std::stod(temp2);
                double result = first - second;
                container.push(std::to_string(result));

                std::cout << second << " = " << result<<"\n";


            } else {
                std::cout << temp2 ;
                int result = std::stoi(temp1) - std::stoi(temp2);
                container.push(std::to_string(result));

                std::cout << " = " << result << "\n";


            }

        }


    } else if (s == "mult") {
        std::string &temp1_ = container.top();
        std::string temp1 = temp1_;
        container.pop();

        std::string &temp2_ = container.top();
        std::string temp2 = temp2_;
        container.pop();

        if (temp1.find('.') != std::string::npos) {
            double first = std::stod(temp1);
            double second = std::stod(temp2);
            double result = first * second;
            container.push(std::to_string(result));

            std::cout << first << " * ";
            if (temp2.find('.') != std::string::npos) {
                std::cout << second;
            } else {
                std::cout << temp2;
            }
            std::cout << " = " << result << "\n";

        } else {
            std::cout << temp1 << " * ";
            if (temp2.find('.') != std::string::npos) {
                double first = std::stod(temp1);
                double second = std::stod(temp2);
                double result = first * second;
                container.push(std::to_string(result));

                std::cout << second << " = " << result<<"\n";


            } else {
                std::cout << temp2 ;
                int result = std::stoi(temp1) * std::stoi(temp2);
                container.push(std::to_string(result));

                std::cout << " = " << result << "\n";


            }

        }


    } else if (s == "div") {
        std::string &temp1_ = container.top();
        std::string temp1 = temp1_;
        container.pop();

        std::string &temp2_ = container.top();
        std::string temp2 = temp2_;
        container.pop();

        if (temp1.find('.') != std::string::npos) {
            double first = std::stod(temp1);
            double second = std::stod(temp2);
            double result = first/second;
            container.push(std::to_string(result));

            std::cout << first << " / ";
            if (temp2.find('.') != std::string::npos) {
                std::cout << second;
            } else {
                std::cout << temp2;
            }
            std::cout << " = " << result << "\n";

        } else {
            std::cout << temp1 << " / ";
            if (temp2.find('.') != std::string::npos) {
                double first = std::stod(temp1);
                double second = std::stod(temp2);
                double result = first/second;
                container.push(std::to_string(result));

                std::cout << second << " = " << result <<"\n";


            } else {
                std::cout << temp2 ;
                int result = std::stoi(temp1)/std::stoi(temp2);
                container.push(std::to_string(result));

                std::cout  << " = " << result << "\n";


            }

        }

    } else if (s == "sqrt") {
        std::string &temp1_ = container.top();
        std::string temp1 = temp1_;
        container.pop();


        std::cout << "sqrt ";
        if(temp1.find('.') != std::string::npos){
            double first = std::stod(temp1);
            double result = sqrt(first);
            container.push(std::to_string(result));
            std::cout << first << " = " << result << "\n";
        } else {
            int first = std::stod(temp1);
            int result = (int)sqrt(first);
            container.push(std::to_string(result));

            std::cout << first << " = " << result << "\n";

        }


    } else if (s == "pop") {
        container.pop();
    } else if (s == "reverse") {
        int reverse_count = std::stoi(container.top());
        container.pop();

        std::vector<std::string> reverse_commands;
        for(int m = 0; m != reverse_count; ++m){
            std::string &reversetemp = container.top();
            reverse_commands.push_back(reversetemp);
            container.pop();
        }

        for(auto it = reverse_commands.begin(); it != reverse_commands.end(); ++it){
            container.push(*it);
        }



    }
}

int main(int argc, char* argv[]) {

    // setup the print out format for the precision required.
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    // open the file for reading
    std::ifstream in;
    in.open(argv[1]);

    // string to be read into
    std::string s;
    //repeat flag; repeat count
    int rflag = 0;
    int rcount = 0;
    //vector contains command need to be repeated
    std::vector<std::string> repeat_commands;
    std::stack <std::string> container;
    // read the file while we have input.

    while (in >> s) {
        if(s == "repeat"){
            rcount = std::stoi(container.top());
            container.pop();
            rflag = 1;
        }
        if(s == "endrepeat") {
            //loop
            for (int i = 0; i != rcount; ++i){
                for (auto it = repeat_commands.begin(); it != repeat_commands.end(); ++it) {
                    operation(*it,container);
                }
            }
            rflag = 0;
            repeat_commands.clear();
        }

        if(rflag == 0){
            operation(s,container);
        } else {
            repeat_commands.push_back(s);

        }
    }
    in.close();
}

