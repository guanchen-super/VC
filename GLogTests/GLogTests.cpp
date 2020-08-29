// GLogTests.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include "glog/logging.h"

#define LOG_DIR "./log/"


int main(int argc, char* argv[])
{
	std::string strBaseFileName{"./log/"};
	strBaseFileName.append(strrchr(argv[0], '\\') + 1).append("_");
    google::InitGoogleLogging(argv[0]);
	//google::SetLogDestination(google::GLOG_INFO, std::string(LOG_DIR).append(argv[0]).append("_").c_str());
	google::SetLogDestination(google::GLOG_INFO, strBaseFileName.c_str());
		
    //FLAGS_log_dir = "./log";
	FLAGS_logtostderr = false;  //设置日志消息是否转到标准输出而不是日志文件
	FLAGS_alsologtostderr = true;  //设置日志消息除了日志文件之外是否输出到标准输出
	FLAGS_colorlogtostderr = true;  //设置记录到标准输出的颜色消息（如果终端支持）
	FLAGS_log_prefix = true;  //设置日志前缀是否应该添加到每行输出
	FLAGS_logbufsecs = 0;  //设置可以缓冲日志的最大秒数，0指实时输出
	FLAGS_max_log_size = 10;  //设置最大日志文件大小（以MB为单位）,超过会对文件进行分割
	FLAGS_stop_logging_if_full_disk = true;  //设置是否在磁盘已满时避免日志记录到磁盘
	FLAGS_minloglevel = google::GLOG_WARNING;	//设置最小处理日志的级别

    LOG(INFO) << "GLog Tests INFO";
    LOG(WARNING) << "GLog Tests WARNING";
    LOG(ERROR) << "GLog Tests ERROR";
    //LOG(FATAL) << "GLog Tests 123";


    google::ShutdownGoogleLogging();
}
