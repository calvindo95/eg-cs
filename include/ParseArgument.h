#include <iostream>
#include <string>
#include <vector>

class ParseArgument{
    private:
        std::vector<std::string> args;
        std::string search_option;
        std::string option;

        int ret_val = 0;

        int parse_option();
        
    public:
        ParseArgument(const std::vector<std::string> argv, const std::string search_option);
        int validate_option();

        std::string get_option();
};