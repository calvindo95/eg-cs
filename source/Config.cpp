#include <Config.h>

Config::Config(): EVENT_DIR("./"){
    update_config();
}

Config& Config::get_instance(){
    static Config config;
    return config;
}

void Config::update_config(){
    update_option(HOME_DIR, "HOME");
    update_option(EVENT_DIR, "EVENT_DIR");
    update_option(TNH_IP, "TNH_IP");
    update_option(TNH_PORT, "TNH_PORT");
}

template <typename T>
void Config::update_option(T& option, std::string env_var){
    try{
        // Check for env var
        char* buffer = getenv(env_var);
        if(buffer != NULL){
            option = static_cast<T>(getenv(env_var));
    
            ss << "Config: " << env_var << " is set as an env variable" << std::endl;
            std::cout << ss;
            //m_logger.log(Logging::severity_level::normal, ss, "GENTRACE");
        }
        // Check json if env var doesn't exist
        else{
            ss << "Config: " << env_var << " is not set as an env variable, checking settings.json" << std::endl;
            //m_logger.log(Logging::severity_level::normal, ss, "GENTRACE");
            std::cout << ss;
            ss.str(std::string());
            ss.clear();
    
            // Check settings.json
            std::ifstream ifs;
            ifs.open("./settings.json");
        
            json j = json::parse(ifs);
            std::stringstream ss;
            
            if(j.contains(env_var)){
                ss << "Config: " << env_var << " found in settings.json" << std::endl;
                //m_logger.log(Logging::severity_level::normal, ss, "GENTRACE");
                std::cout << ss;
                option = static_cast<T>(j.at(env_var));
            }
            else{
                ss << "Config: " << env_var << " not found in settings.json" << std::endl;
                std::cout << ss;
                //m_logger.log(Logging::severity_level::normal, ss, "GENTRACE");
            }
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