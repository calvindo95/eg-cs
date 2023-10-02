#include <Config.h>
#include <JsonConsumer.h>

int main(){
    Config& config = Config::get_instance();

    JsonConsumer jc;
    std::cout << "Done initializing JsonConsumer" << std::endl;
}