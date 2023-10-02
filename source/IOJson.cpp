#include <IOJson.h>

IOJson::IOJson(std::string dir){
    evt_dir = validate_dir(dir);
}

std::string IOJson::GET_EVT_DIR(){
    return evt_dir;
}

std::string IOJson::validate_dir(std::string dir){
    if(!std::filesystem::exists(dir)){
        std::cout << "Creating directory: " << dir << std::endl;
        std::filesystem::create_directory(dir);
    }

    // Check if dir contains './' or '/' in first 1-2 chars --> remove those
    if(dir.substr(0,2) == "./"){
        dir = dir.substr(2,dir.size());
    }
    if(dir.substr(0,1) == "/"){
        dir = dir.substr(1,dir.size());
    }

    // Get absolute dir
    std::string abs_dir = std::filesystem::absolute(dir);

    // Check if last char of dir contains forward slash
    if(abs_dir.back() != '/'){
        abs_dir + '/';
        std::cout << "Appending '/' to " << dir << " --> " << abs_dir << std::endl;     // need to log this later
        
        return abs_dir;
    }

    return abs_dir;
}