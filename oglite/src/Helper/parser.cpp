#include "parser.h"

std::string oglite::parser::tryParseShader(std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::in);

	if (file.is_open()) {
		std::string res((std::istreambuf_iterator<char>(file)),
			(std::istreambuf_iterator<char>()));
		file.close();
		return res;
	}else{
		throw std::exception();
	}
}