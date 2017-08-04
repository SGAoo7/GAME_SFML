#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

static class FileWriter
{
public:
	FileWriter();
	~FileWriter();

	static std::vector<std::string> ReadFromFile(std::string _fileName);
	static void WriteToFile(std::string _fileName, std::string _data, bool _deletePreviousData);
};

