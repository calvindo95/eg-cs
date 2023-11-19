#ifndef LOGGING_H
#define LOGGING_H

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/utility/value_ref.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>

#include <string>
#include <iomanip>
#include <ostream>
#include <fstream>

class Logging{
    private:
        bool auto_flush;

    public:
        Logging();
        void init();
        
        enum severity_level{
            trace,
            info,
            normal,
            notification,
            warning,
            error,
            critical
        };
        
        // logging methods
        void log(severity_level sl,const std::stringstream& msg, const std::string& filter = "GENTRACE");
        void log(severity_level sl, const std::string& msg, const std::string& filter = "GENTRACE");
};

#endif