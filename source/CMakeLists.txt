include_directories(../include)

#ADD_LIBRARY(egc SHARED EventGenClient.cpp ${PYTHON_LIBRARIES})

add_library(config STATIC Config.cpp)

add_library(parseargument STATIC ParseArgument.cpp)

add_library(writejson STATIC IOJson.cpp WriteJson.cpp)
add_library(readjson STATIC IOJson.cpp ReadJson.cpp)

add_library(jsonconsumer STATIC JsonConsumer.cpp)

add_executable(${CLIENT} main_egc.cpp)
target_link_libraries(${CLIENT} config parseargument writejson)

add_executable(${SERVER} main_egs.cpp)
target_link_libraries(${SERVER} config jsonconsumer readjson)