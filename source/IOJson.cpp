#include <IOJson.h>

IOJson::IOJson(std::string dir){
    evt_dir = validate_dir(dir);
}

std::string IOJson::GET_EVT_DIR(){
    return evt_dir;
}

std::string IOJson::validate_dir(std::string dir){
    std::string queue_dir = dir + "/queue/";
    if(!std::filesystem::exists(queue_dir)){
        std::stringstream ss;
        ss << "Creating directory: " << dir << std::endl;
        m_logger.log(Logging::severity_level::normal, ss, "GENTRACE");
        std::filesystem::create_directory(dir);
    }

    return dir;
}