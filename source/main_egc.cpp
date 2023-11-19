#include <Config.h>
#include <ParseArgument.h>
#include <WriteJson.h>
#include <Logging.h>

#include <vector>

int main(int argc, char* argv[]){
    Logging logger;
    logger.init();

    Config& config = Config::get_instance();
    
    // parse input
    // -a app  -p pid -c code -t text
    const std::vector<std::string> args(argv+1, argv+argc);

    int ret_val = 0;
    
    ParseArgument app(args, "-a");
    app.validate_option();
 
    ParseArgument pid(args, "-p");
    pid.validate_option();

    ParseArgument code(args, "-c");
    code.validate_option();

    ParseArgument text(args, "-t");
    text.validate_option();

    WriteJson wj(config.GET_EVENT_DIR());

    wj.insert_json("Application", app.get_option());
    wj.insert_json("PID", pid.get_option());
    wj.insert_json("Code", code.get_option());
    wj.insert_json("Text", text.get_option());

    wj.write_to_file();
}