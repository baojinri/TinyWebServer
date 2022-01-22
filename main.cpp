//frok

#include "config.h"

int main(int argc, char *argv[])
{
    //需要修改的数据库信�?,登录�?,密码,库名
    string user = "root";
    string passwd = "root";
    string databasename = "qgydb";

    //命令行解�?
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    //初�?�化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    

    //日志
    server.log_write();

    //数据�?
    server.sql_pool();

    //线程�?
    server.thread_pool();

    //触发模式
    server.trig_mode();

    //监听
    server.eventListen();

    //运�??
    server.eventLoop();

    return 0;
}