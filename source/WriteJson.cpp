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

    // get current time
    auto now_ms = std::chrono::system_clock::now();

    // get number of milliseconds for the current second
    // (remainder after division into seconds)
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now_ms.time_since_epoch()) % 1000;

    std::stringstream ss;

    ss << buf << "." << std::setfill('0') << std::setw(3) << ms.count();

    return ss.str();
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
    size_t uid = get_hash();
    j["UID"] = uid;
    
    // Create final file path
    std::stringstream ss;
    ss << IOJson::GET_EVT_DIR() << uid << ".json";
    
    // Create tmp file path
    std::stringstream ss1;
    ss1 << "/tmp/" << uid << ".json";
    
    // Write to tmp file path
    std::ofstream my_json;
    
    my_json.open(ss1.str());
    my_json << j.dump(4);

    my_json.close();

    // Move tmp to final file path; Prevents other process from reading before write is done
    std::rename(ss1.str().c_str(), ss.str().c_str());
}