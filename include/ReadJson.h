#include <iostream>
#include <string>
#include <fstream>

#include <nlohmann/json.hpp>
#include <IOJson.h>

using json = nlohmann::json;

class ReadJson: public IOJson{
    private:

    public:
        ReadJson(std::string dir);
        std::vector<std::string> get_files_in_dir();

};