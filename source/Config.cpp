#include <Config.h>

Config::Config(): EVENT_DIR("./"){
    update_config();
}

Config& Config::get_instance(){
    static Config config;
    return config;
}

void Config::update_config(){
    update_option(EVENT_DIR, "EVENT_DIR");
    update_option(TNH_IP, "TNH_IP");
    update_option(TNH_PORT, "TNH_PORT");
}

template <typename T>
void Config::update_option(T& option, std::string env_var){
    try{
        // Get env_var
        char* buffer = std::getenv(env_var.c_str());

        if(buffer != NULL){
            option = static_cast<T>(buffer);
        }
        else{
            std::stringstream ss;
            ss << "Environment variable: " << env_var << " does not exist, now checking settings.json" << std::endl;
            //std::cerr << ss.str();
        }

        // Check settings.json
        std::ifstream ifs;
        ifs.open("./settings.json");

        json j = json::parse(ifs);

        if(j.contains(env_var)){
            option = static_cast<T>(j.at(env_var));
        }
        else{
            std::stringstream ss;
            ss << "Setting: " << env_var << " does not have environment variable set or not in settings.json" << std::endl;
            throw ss; 
        }
    }
    catch(std::exception const& e){
        std::cerr << e.what() << std::endl;
    }
}

std::string Config::GET_EVENT_DIR(){
    return EVENT_DIR;
}

std::string Config::GET_TNH_IP(){
    return TNH_IP;
}

std::string Config::GET_TNH_PORT(){
    return TNH_PORT;
}