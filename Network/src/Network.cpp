#include "Network.h"
#include <fstream>
#include <string>
#include <vector>
#include <format>

#include <chrono>
#include <thread>
#include <random>

int main()
{
	std::ifstream file("Request.log"); // 打开文件
	if (!file.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}

	std::vector<std::string> commandList;
	std::string line;
	while (std::getline(file, line)) { // 逐行读取
		commandList.push_back(std::format("curl {}", line));
	}


	// 随机数生成器
	std::random_device rd;
	std::mt19937 gen(rd());
	// 随机时间间隔
	std::uniform_int_distribution<> timeDistrib(1, 10);
	// 随机请求index
	std::uniform_int_distribution<> indexDistrib(0, commandList.size() - 1);


	// 模拟的操作
	auto operation = [](const std::string& commondLine) {
		std::cout << commondLine << std::endl;
		system(commondLine.c_str());
		};

	while (true) {
		operation(commandList[indexDistrib(gen)]);

		// 等待随机时间间隔
		std::this_thread::sleep_for(std::chrono::seconds(timeDistrib(gen)));
	}

	return 0;
}