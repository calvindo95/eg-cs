#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <sstream>
#include <filesystem>

#include <json.hpp>

using json = nlohmann::json;

class Config{
    private:
        std::string HOME_DIR;
        std::string EVENT_DIR;
        std::string TNH_IP;
        std::string TNH_PORT;

        Config();
        void update_config();

        template <typename T>
        void update_option(T& option, std::string env_var);

    public:

        static Config& get_instance();

        std::string GET_HOME_DIR();
        std::string GET_EVENT_DIR();
        std::string GET_TNH_IP();
        std::string GET_TNH_PORT();
};

#endif