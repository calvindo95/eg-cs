#include <JsonConsumer.h>

JsonConsumer::JsonConsumer(){
    std::thread consumer(&JsonConsumer::consumer_thread, this);
    consumer.detach();
}

void JsonConsumer::consumer_thread() noexcept{
    while(true){
        json j = json_tsq.pop();
        
        post_request(j);
    }
}

void JsonConsumer::post_request(json j){
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl){
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers, "charset: utf-8");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        std::stringstream ss;
        ss << "http://" << config.GET_TNH_IP() << ":" << config.GET_TNH_PORT() << "/post_json";
        
        curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str());
        curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, j.dump().c_str());

        res = curl_easy_perform(curl);

        if(res != CURLE_OK){
            std::cerr << "curl_easy_perform failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

}

void JsonConsumer::monitor_thread() noexcept{
    std::string evt_dir = config.GET_EVENT_DIR();

    ReadJson rj(evt_dir);

    while(true){
        std::vector<std::string> files = rj.get_files_in_dir();

        for(int i = 0; i < files.size(); i++){
            std::stringstream ss;
            ss << "File Monitor thread found file: " << files[i] << std::endl;
            m_logger.log(Logging::severity_level::trace, ss, "GENTRACE");
            ss.str(std::string());
            ss.clear();

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
            ss << "File Monitor thread deleting file: " << files[i] << std::endl;
            m_logger.log(Logging::severity_level::trace, ss, "GENTRACE");
            std::filesystem::remove(files[i]);

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}