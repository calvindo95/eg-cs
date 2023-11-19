#include <iostream>
#include <thread>
#include <cstdio>
#include <chrono>

#include <ReadJson.h>
#include <TSQueue.h>
#include <Config.h>
#include <curl/curl.h>
#include <Logging.h>

class JsonConsumer{
    // start consume thread to read from queue and send to server for processing

    // get json objects from ReadJson lib and enque

    private:
        Config& config = Config::get_instance();
        TSQueue<json> json_tsq;
        Logging m_logger;

        void consumer_thread() noexcept; // thread to consume json queue and send post request
        void post_request(json j);

    public:
        JsonConsumer(); // start consumer thread here
        void monitor_thread() noexcept; // thread to monitor queue dir and enque json object and delete file
};