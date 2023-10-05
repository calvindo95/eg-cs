#include <JsonConsumer.h>

JsonConsumer::JsonConsumer(){
    std::thread consumer(&JsonConsumer::consumer_thread, this);
    consumer.detach();
}

void JsonConsumer::consumer_thread() noexcept{
    while(true){
        json j = json_tsq.pop();

        std::cout << j.dump(4) << std::endl;
    }
}

void JsonConsumer::monitor_thread() noexcept{
    std::string evt_dir = config.GET_EVENT_DIR();

    ReadJson rj(evt_dir);

    while(true){
        std::vector<std::string> files = rj.get_files_in_dir();

        for(int i = 0; i < files.size(); i++){
            std::cout << "File Monitor thread found file: " << files[i] << std::endl;
            // Open json file and load into json object
            std::ifstream ifs;
            ifs.open(files[i]);

            // Skip file if can't open file
            if(!static_cast<bool>(ifs)){
                continue;
            }

            json j = json::parse(ifs);
            json_tsq.push(j);

            // Delete file after parsing json
            std::cout << "File Monitor thread deleting file: " << files[i] << std::endl;
            std::filesystem::remove(files[i]);
        }
    }
    
}