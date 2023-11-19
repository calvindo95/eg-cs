#include <Config.h>
#include <JsonConsumer.h>
#include <Logging.h>

int main(){
    Logging log;
    log.init();

    Config& config = Config::get_instance();

    JsonConsumer jc;
    log.log(Logging::severity_level::normal, std::string("Done initializing JsonConsumer"), "GENTRACE");
    jc.monitor_thread();
}