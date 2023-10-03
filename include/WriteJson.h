#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <unordered_map>
#include <sstream>

#include <IOJson.h>

using json = nlohmann::json;

class WriteJson: public IOJson{
    private:
        json j;

        std::string get_time();
        size_t get_hash();

    public:
        WriteJson(std::string dir);

        void insert_json(std::string key, std::string value);
        void print_json();
        void write_to_file();
};