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
	std::ifstream file("Request.log"); // ���ļ�
	if (!file.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}

	std::vector<std::string> commandList;
	std::string line;
	while (std::getline(file, line)) { // ���ж�ȡ
		commandList.push_back(std::format("curl {}", line));
	}


	// �����������
	std::random_device rd;
	std::mt19937 gen(rd());
	// ���ʱ����
	std::uniform_int_distribution<> timeDistrib(1, 10);
	// �������index
	std::uniform_int_distribution<> indexDistrib(0, commandList.size() - 1);


	// ģ��Ĳ���
	auto operation = [](const std::string& commondLine) {
		std::cout << commondLine << std::endl;
		system(commondLine.c_str());
		};

	while (true) {
		operation(commandList[indexDistrib(gen)]);

		// �ȴ����ʱ����
		std::this_thread::sleep_for(std::chrono::seconds(timeDistrib(gen)));
	}

	return 0;
}