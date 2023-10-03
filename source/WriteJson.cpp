#include <WriteJson.h>

WriteJson::WriteJson(std::string dir): IOJson(dir){
    std::string time = get_time();

    insert_json("Time", time);
}

std::string WriteJson::get_time(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];

    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tstruct);

    return buf;
}

size_t WriteJson::get_hash(){
    size_t tmp_hash = std::hash<std::string>{}(j.dump());
    return tmp_hash;
}

void WriteJson::insert_json(std::string key, std::string value){
    j[key] = value;
}

void WriteJson::print_json(){
    std::cout << j.dump(4) << std::endl;
}

void WriteJson::write_to_file(){
    size_t hashed_file = get_hash();
    
    std::stringstream ss;
    ss << IOJson::GET_EVT_DIR() << hashed_file << ".json";
    
    std::ofstream my_json;

    my_json.open(ss.str());
    my_json << j.dump(4);
}