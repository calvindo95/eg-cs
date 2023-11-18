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
        std::cout << "Creating directory: " << dir << std::endl;
        std::filesystem::create_directory(dir);
    }

    return dir;
}