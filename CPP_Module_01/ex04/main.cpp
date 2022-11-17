#include <iostream>
#include <fstream>

std::string	read_file(char *argv[])
{
	std::string		contents;
	std::string		tmp;
	std::ifstream	file(argv[1]);

	if (file.fail())
	{
		std::cerr << "File doesn't exist!" << std::endl;
		exit(1);
	}
	while (true)
	{
		getline(file, tmp);
		if(file.eof())
			break ;
		contents += tmp + "\n";
	}
	return (contents);
}

std::string	replace(std::string contents, std::string s1, std::string s2)
{
	std::string	result;
	size_t		start = 0;
	size_t		end = 0;

	while (true)
	{
		end = contents.find(s1, start);
		if (end == std::string::npos)
		{
			result += contents.substr(start, contents.length());
			break ;
		}
		result += contents.substr(start, end - start) + s2;
		start = end + s1.length();
	}
	return (result);
}

void	save_contents(std::string contents, std::string filename)
{
	std::ofstream	file(filename + ".replace");

	file.write(contents.c_str(), contents.length());
}

int main(int argc, char *argv[])
{
	if (argc != 4 || argv[1][0] == 0 || argv[2][0] == 0)
	{
		std::cerr << "Wrong arguments!" << std::endl;
		return (1);
	}

	std::string contents;

	contents = read_file(argv);
	contents = replace(contents, argv[2], argv[3]);
	save_contents(contents, argv[1]);
	return(0);
}
