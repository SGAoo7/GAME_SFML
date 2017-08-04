#include "../Header Files/FileWriter.h"



FileWriter::FileWriter()
{
}


FileWriter::~FileWriter()
{
}

std::vector<std::string> FileWriter::ReadFromFile(std::string _fileName)
{
	std::string line;
	std::vector<std::string> lines;
	std::ifstream myfile(_fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			lines.push_back(line);
		}
		myfile.close();
	}

	return lines;

}

void FileWriter::WriteToFile(std::string _fileName, std::string _data, bool _deletePreviousData)
{
	std::ofstream file;

	if (!_deletePreviousData) {
		file.open(_fileName, std::ios_base::app);
	}
	else {
		file.open(_fileName);
	}
	const char* c = _data.c_str();
	file << c << std::endl;;
	file.close();
	std::cout << "saving" << std::endl;
}
