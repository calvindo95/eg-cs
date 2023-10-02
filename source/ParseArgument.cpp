#include <ParseArgument.h>

ParseArgument::ParseArgument(const std::vector<std::string> argv, const std::string s_search_option): args(argv), search_option(s_search_option){
   ret_val = parse_option();
}

// Get search option from args
int ParseArgument::parse_option(){
    for(auto it = args.begin(), end = args.end(); it != end; ++it){
        if(*it == search_option){
            // Check if option is not bigger than vector, size >2, does not contain '-'
            if(it+1 != end){
                // invalid option
                if((*(it+1)).size() < 3 && (*(it+1)).find("-") != std::string::npos){
                    option = *(it+1);
                    return 1;
                }
                
                // Valid option
                option = *(it+1);
                return 0;
            }
            return 2;
        }
    }
    return 3;
}

int ParseArgument::validate_option(){
    if(ret_val != 0){
        if(ret_val == 1){
            std::cerr << "Input for flag " << search_option << " is invalid: " << option << std::endl;
            exit (ret_val);
        }
        if(ret_val == 2){
            std::cerr << "Input for flag " << search_option << " is missing " << option << std::endl;
            exit (ret_val);
        }
        if(ret_val == 3){
            std::cerr << "Flag " << search_option << " is missing " << option << std::endl;
            exit (ret_val);
        }
    }
    return 0;
}

std::string ParseArgument::get_option(){
    return option;
}