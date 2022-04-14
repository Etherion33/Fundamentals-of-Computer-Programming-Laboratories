#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Stats
{
public:
	int no_of_words = 0;
	int no_of_chars = 0;
	Stats(std::ifstream& inputFile) {
		char c;
		while (inputFile.get(c))
		{
			no_of_chars++;
			if (c == ' ')
				no_of_words++;

		}
	}
};
void remove_ws(std::ifstream& inputFile, std::ofstream& outputFile)
{
	std::string word;
	if (inputFile.is_open() && outputFile.is_open())
	{
		while (inputFile.good())
		{
			std::getline(inputFile >> std::ws, word);
			outputFile << word;
		}
	}
	else
	{
		std::cerr << "One of the files is not open";
	}
}

int main()
{
	float ratio;
	char c;
	std::string word;
	std::ifstream inputFile;
	std::ofstream outputFile;
	inputFile.open("input.txt", std::ios::out);
	outputFile.open("output.txt");
	remove_ws(inputFile, outputFile);
	inputFile.close();
	outputFile.close();

	std::ifstream File;
	File.open("output.txt");
	Stats fixed_file_stats(File);
	std::cout<<"Number of words in hex: " << std::hex << fixed_file_stats.no_of_words << std::endl;
	std::cout << "Number of chars in oct: " << std::oct << fixed_file_stats.no_of_chars << std::endl;
	std::cout <<"Number of words divided by number of characters: " << std::setprecision(2) << std::showpos << (float)fixed_file_stats.no_of_words / (float)fixed_file_stats.no_of_chars << std::endl;
	File.close();
	system("PAUSE");
	return 0;
}




