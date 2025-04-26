#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <filesystem>
#include <random>
#include <sstream>
// #include <algorithm>
#include"httplib.h"
#include"json.hpp"
#include"loglib.hpp"
#include"yaml_to_json.h" // 使用封装后的YAML和JSON互转库

// 声明示例函数
int yaml_json_demo();

namespace fs=std::filesystem;
using json=nlohmann::json;

//日志
loglib::Log console;
//配置文件
json config;

std::string DIST_PATH="./dist";
std::string CONFIG_PATH="./config";
std::string SECRET_KEY_PATH=CONFIG_PATH+"/file_server.key";
std::string ADMIN_KEY_PATH=CONFIG_PATH+"/admin.key";
std::string DOMAIN="localhost";
std::string PORT="3000";
std::string IP="0.0.0.0";
std::string ADDRESS=DOMAIN+':'+PORT;

std::map<std::string,std::string> mimeTypes={
    { ".html","text/html" },
    { ".js","text/javascript" },
    { ".css","text/css" },
    { ".json","application/json" },
    { ".png","image/png" },
    { ".jpg","image/jpg" },
    { ".gif","image/gif" },
    { ".svg","image/svg+xml" },
    { ".wav","audio/wav" },
    { ".mp4","video/mp4" },
    { ".woff","application/font-woff" },
    { ".ttf","application/font-ttf" },
    { ".eot","application/vnd.ms-fontobject" },
    { ".otf","application/font-otf" },
    { ".wasm","application/wasm" }
};

std::string generateSecretKey(size_t length=16){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,255);

    std::stringstream ss;
    for(size_t i=0; i<length; ++i){
        ss<<std::hex<<std::setw(2)<<std::setfill('0')<<dis(gen);
    }
    return ss.str();
}



void writeSecretKeyToFile(const std::string &secretKey,std::string FILE_PATH,std::string LOG_NAME){
    std::ofstream file(FILE_PATH);

    if(file.is_open()){
        file<<secretKey;
        file.close();
        console.log(LOG_NAME+" 写入 "+SECRET_KEY_PATH);
    }
    else{
        console.log(LOG_NAME+" 写入文件时发生错误，可能是文件夹不存在，或者权限问题。",loglib::ERROR);
    }
}

std::string readFileContent(const std::string &filePath){
    std::ifstream file(filePath,std::ios::binary);
    if(!file.is_open()){
        // throw std::runtime_error("[ERROR] 未能打开文件"+filePath);
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    file.close();
    return content;
}

std::string getContentType(const std::string &ext){
    auto it=mimeTypes.find(ext);
    return it!=mimeTypes.end()?it->second:"application/octet-stream";
}

void print_addr(const httplib::Request &req){
    console.log("来自 "+req.remote_addr+" 的请求：");
}

void handleRequest(const httplib::Request &req,httplib::Response &res,const std::string &secretKey){
    // print_addr(req);
    console.tlog("来自 "+req.remote_addr+" 的请求：进行"+req.path+"文件下载");
    auto key=req.get_param_value("key");
    if(key.empty()||key!=secretKey){
        res.status=401;
        res.set_content("验证失败\n","text/html; charset=utf-8");
        return;
    }

    std::string filePath=DIST_PATH+req.path;
    std::string ext=fs::path(filePath).extension().string();
    std::string contentType=getContentType(ext);

    std::ifstream file(filePath,std::ios::binary);
    if(file.is_open()){
        std::string content((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
        res.status=200;
        res.set_content(content,contentType.c_str());
    }
    else{
        res.status=404;
        res.set_content("未找到文件\n","text/html; charset=utf-8");
    }
}

void handleControlRequest(const httplib::Request &req,httplib::Response &res,std::string &secretKey){
    // if(req.remote_addr!="127.0.0.1"){
    //     res.status=403;
    //     res.set_content("仅允许本地更改","text/html; charset=utf-8");
    //     return;
    // }
    // print_addr(req);
    console.log("来自 "+req.remote_addr+" 的请求：进行密码更改");
    auto authKey=req.get_param_value("auth_key");
    if(authKey.empty()||authKey!=readFileContent(ADMIN_KEY_PATH)){
        res.status=401;
        res.set_content("管理员验证失败\n","text/html; charset=utf-8");
        return;
    }

    std::string newSecretKey=generateSecretKey();
    secretKey=newSecretKey;
    writeSecretKeyToFile(secretKey,SECRET_KEY_PATH,"Secret Key");

    res.status=200;
    res.set_content("密钥已更新，请使用: http://lingnc.top:3002/planet?key="+newSecretKey+" 来访问文件\n","text/html; charset=utf-8");
    console.log("密钥已更新，新密钥为: "+newSecretKey);
}
//初始化
void init(){
    //初始化配置文件
    try {
        std::string config_content;
        std::ifstream config_file("./config/config.yaml");
        if (config_file.is_open()) {
            std::stringstream buffer;
            buffer << config_file.rdbuf();
            config_content = buffer.str();
            config_file.close();

            // 使用新的 ADL 机制接口从 YAML 字符串解析为 JSON
            nlohmann::from_yaml(config_content, config);
            console.log("配置文件解析成功");
        } else {
            console.log("配置文件打开失败", loglib::ERROR);
        }
    } catch (const std::exception& e) {
        console.log("配置文件解析错误: " + std::string(e.what()), loglib::ERROR);
    }

    DIST_PATH=config["dist_path"];
    CONFIG_PATH=config["config_path"];
    SECRET_KEY_PATH=CONFIG_PATH+"/file_server.key";
    ADMIN_KEY_PATH=CONFIG_PATH+"/admin.key";
    PORT=config["port"];
    DOMAIN=config["domain"];
    IP=config["ip"];
    ADDRESS=DOMAIN+':'+PORT;

    //初始化文件夹
    if(!fs::exists(CONFIG_PATH)&&!fs::exists(DIST_PATH))
        if(fs::create_directory(CONFIG_PATH)&&fs::create_directory(DIST_PATH))
            console.log("初始化文件夹成功");
        else
            console.log("初始化文件夹失败",loglib::ERROR);
    //初始化密码
    if(readFileContent(SECRET_KEY_PATH)==""){
        console.log("密钥文件不存在，正在生成...",loglib::WARNING);
        auto secretKey=generateSecretKey();
        writeSecretKeyToFile(secretKey,SECRET_KEY_PATH,"Secret Key");
    }
    if(readFileContent(ADMIN_KEY_PATH)==""){
        console.log("管理员密钥文件不存在，正在生成...",loglib::WARNING);
        auto AdminKey=generateSecretKey();
        writeSecretKeyToFile(AdminKey,ADMIN_KEY_PATH,"Admin Key");
    }
}

int main(){
    // 可选：运行YAML和JSON互转示例
    // yaml_json_demo();

    init();
    std::string secretKey=readFileContent(SECRET_KEY_PATH);

    httplib::Server svr;

    svr.Get(".*",[&](const httplib::Request &req,httplib::Response &res){
        secretKey=readFileContent(SECRET_KEY_PATH);
        handleRequest(req,res,secretKey);
        });

    svr.Post("/passwd",[&](const httplib::Request &req,httplib::Response &res){
        handleControlRequest(req,res,secretKey);
        });

    console.log("服务运行在 http://"+ADDRESS+"/file?key="+secretKey);
    console.log("请输入文件名替代file");
    svr.listen(IP,std::stod(PORT));

    return 0;
}