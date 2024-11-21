#include<string>
#include<iostream>
#include<fstream>
#include<ctime>
class Log{
    std::string log_content;
    std::string getLogLevel(int level){
        switch(level){
        case INFO:
            return "[INFO]";
            break;
        case DEBUG:
            return "[DEBUG]";
            break;
        case WARNING:
            return "[WARING]";
            break;
        case ERROR:
            return "[ERROR]";
            break;
        default:
            return "[?]";
            break;
        }
    }
    std::string getTime(){
        std::time_t now_sec=std::time(nullptr);
        auto now=*std::localtime(&now_sec);
        char timestamp[20];
        std::strftime(timestamp,sizeof(timestamp),"%Y/%m/%d-%H:%M:%S",&now);
        std::string now_time=timestamp;
        return now_time;
    }
    void file_write(std::string content){
        std::ofstream logfile(PATH+"server.log",std::ios::app);
        if(!logfile.is_open()) std::cerr<<"[ERROR] 打开日志失败！"<<std::endl;
        logfile<<content<<std::endl;
        logfile.close();
    }
public:
    std::string PATH="./";
    enum LogLevel{
        INFO=1,DEBUG,WARNING,ERROR
    };
    void log(std::string str){
        log_content=getLogLevel(1)+' '+str;
        std::cout<<log_content<<std::endl;
        file_write(log_content);
    }
    // void log(int level,std::string str){
    //     log_content=getLogLevel(level)+' '+str;
    //     std::cout<<log_content<<std::endl;
    //     if(level=ERROR) std::cerr<<log_content<<std::endl;
    //     file_write(log_content);
    // }
    void log(LogLevel level,std::string str){
        log_content=getLogLevel(level)+' '+str;
        std::cout<<log_content<<std::endl;
        if(level==ERROR) std::cerr<<log_content<<std::endl;
        file_write(log_content);
    }
    // 带时间戳的日志
    void tlog(std::string str){
        std::string timestamp=getTime();
        log_content="["+timestamp+"] "+getLogLevel(INFO)+' '+str;
        std::cout<<log_content<<std::endl;
        file_write(log_content);
    }

    // void tlog(int level,std::string str){
    //     std::string timestamp=getTime();
    //     log_content="["+timestamp+"] "+getLogLevel(level)+' '+str;
    //     std::cout<<log_content<<std::endl;
    //     if(level==ERROR){
    //         std::cerr<<log_content<<std::endl;
    //     }
    //     file_write(log_content);
    // }

    void tlog(LogLevel level,std::string str){
        std::string timestamp=getTime();
        log_content="["+timestamp+"] "+getLogLevel(level)+' '+str;
        std::cout<<log_content<<std::endl;
        if(level==ERROR){
            std::cerr<<log_content<<std::endl;
        }
        file_write(log_content);
    }
};