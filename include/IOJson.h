#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include <json.hpp>
#include <Logging.h>

class IOJson{
    protected:
        IOJson(std::string dir);
        std::string GET_EVT_DIR();

        Logging m_logger;
    
    private:
        std::string evt_dir;

        std::string validate_dir(std::string dir);
    public:
};