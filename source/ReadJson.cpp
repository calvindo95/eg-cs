#include <ReadJson.h>

ReadJson::ReadJson(std::string dir): IOJson(dir){
    
}

std::vector<std::string> ReadJson::get_files_in_dir(){
    std::vector<std::string> files;

    for(const auto& file : std::filesystem::directory_iterator(IOJson::GET_EVT_DIR())){
        //std::cout << file.path() << std::endl;
        files.push_back(file.path().c_str());
    }

    return files;
}