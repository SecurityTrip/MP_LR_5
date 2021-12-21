#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


class profit 
{
private:
	std::string number;
	int days_count;
	std::vector<double> profit_per_day;
public:
	profit(std::string num, int days, std::vector<double> day_profit)
	{
		number = num;
		days_count = days;
		profit_per_day = day_profit;
	}
	
	profit(const profit& p)// конструктор копирования
	{
		number = p.number;
		days_count = p.days_count;
		profit_per_day = p.profit_per_day;
	}
	//деструктор
	~profit()
	{

	}
	
	// укажем дружественные операторы, которым мы разрешаем доступ
	// к личным (private) данным
	friend std::ostream& operator<< (std::ostream&, const profit&);
	friend std::istream& operator>> (std::istream&, profit& c);

	std::string non_profit()
	{
		int non = 0;
		for (int i = 0; i < profit_per_day.size(); i++)
		{
			if (profit_per_day[i] == 0 || profit_per_day[i] == 0.0) non++;
		}
		return ("Days without profint in branch #" + number + " = " + std::to_string(non));
	}

};

// перегрузка оператора >>
std::istream& operator>> (std::istream& in, profit& p)
{
	in >> p.number;
	in >> p.days_count;
	//in >> p.profit_per_day;
	return in;
}

// перегрузка оператора <<
std::ostream& operator<< (std::ostream& out, const profit& p)
{
	out << "Branch number: " << p.number << " " <<"Days count: " << p.days_count << " " << "Profit per day: ";
	//out <<  p.number << std::endl <<  p.days_count << std::endl;
	
	for (int i = 0; i < p.profit_per_day.size(); i++)
	{
		out << p.profit_per_day[i] << " ";
	}
	out << std::endl;
	return out;
}

bool frepeat() {

	std::string repeatt;
	std::cout << "\nContinue? (Y/N)>";
	std::cin >> repeatt;
	while (((repeatt == "Y") || (repeatt == "y") || (repeatt == "N") || (repeatt == "n")) != 1 || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Unidentified operator, try again" << std::endl;
		std::cout << "Repeat? (Y/N) " << std::endl;
		std::cin >> repeatt;
		std::cout << std::endl;
	}
	if (repeatt == "Y" || repeatt == "y")
	{
		return true;
	}
	else
	{
		return false;
	}
}

int cheker(int& in, std::string arg)
{
	in = 0;
	while (in != 1 && in != 2)
	{
		std::cout << "Choose " << arg << " type(file / console)>"; std::string in_type_str; std::cin >> in_type_str;
		if (in_type_str == "file")
		{
			in = 1;
		}
		if (in_type_str == "console")
		{
			in = 2;
		}
		if (in == 0)
		{
			std::cout << "Wrong type, try again" << std::endl;
		}
	}
	return in;
}

void parce(std::string in, std::string& n ,int& d, std::vector<double>& v,bool& s)
{
	std::istringstream input{ in };
	std::vector<std::string> result;

	while (!input.eof()) {
		std::string substring;
		input >> substring;
		result.push_back(substring);
	}
	try
	{
		if (result.size() - 2 == stoi(result[1]))
		{
			try
			{
				n = result[0];
				d = stoi(result[1]);

				for (int i = 2; i < result.size(); i++)
				{
					for (int j = 0; j < result[i].size(); j++)
					{
						if (result[i][j] < 48 || result[i][j]>57)
						{
							if (result[i][j] != 46)
							{
								std::cout << "Error in input file";
								s = false;
								v.clear();
								break;
							}

						}
					}
					v.push_back(atof(result[i].c_str()));
				}
			}
			

			catch (...)
			{
				s = false;
				std::cout << "Error in input file";
			}
		}
		else { std::cout << "Error in input file"; s = false; }
	}
	catch (...)
	{
		s = false;
		std::cout << "Error in input file";
	}
	
}

int file_len(std::string in_s)
{
	std::string str;
	std::ifstream in;
	in.open(in_s);
	int i = 0;
	while (getline(in, str))
	{
		i++;
	}
	in.close();
	return (i-1);
}

double check_in(char f, int n, double d)
{
	if (f == 'i')
	{
		 std::cin >> n;
		while ((std::cin.fail()) || (std::cin.peek() != '\n' || n < 0))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Wrong type of input data, try again: "; std::cin >> n;
			std::cout << std::endl;
		}
		return n;
	}
	if (f == 'd')
	{
		std::cin >> d;
		while ((std::cin.fail()) || (std::cin.peek() != '\n' || n < 0))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Wrong type of input data, try again: "; std::cin >> d;
			std::cout << std::endl;
		}
		return d;
	}
}

void file_input(std::vector<profit>& p, bool& s)
{
	std::ifstream in_file;
	
	std::string in_name;

	std::cout << "Enter input file name>"; std::cin >> in_name;
	in_file.open(in_name);
	while (!in_file.is_open())
	{
		std::cout << "Can`t open input file. Try again." << std::endl;
		std::cout << "Enter input file name>"; std::cin >> in_name;
		in_file.open(in_name);

	}
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	int br;
	std::string bra;
	getline(in_file, bra);
	br = stoi(bra);
	if (br == file_len(in_name))
	{
		for (int i = 0; i < br; i++)
		{
			try
			{
				std::string file_data;
				getline(in_file, file_data);
				std::string name;
				int days;
				std::vector<double> vec;
				parce(file_data, name, days, vec, s);
				if (s)
				{
					profit prof(name, days, vec);

					p.push_back(prof);


				}
				else
				{
					break;
				}
			}
			catch (...)
			{
				s = false;
				std::cout << "Error in input file";
				break;
			}
		}
	}
	else
	{
		s = false;
		std::cout << "Error in input file";
	}
	in_file.close();
}

void console_input(std::vector<profit>& p)
{
	std::cout << "Enter number of branches>"; int br = 0; br = check_in('i', br, 0);

	
	for (int i = 0; i < br; i++)
	{
		std::cout << "Enter branch number> "; std::string branch; std::cin >> branch;
		double a = 0.0;
		std::cout << "Enter days count > "; int days = 0; days = (int)check_in('i', days, a);
		std::vector<double> vec;
		int b = 0;
		for (int i = 0; i < days; i++)
		{
			std::cout << "Enter profit in " << i + 1 << " day>"; double p = 0;  p = check_in('d', b, p);
			vec.push_back(p);
		}

		profit prof(branch, days, vec);
		p.push_back(prof);
	}
}

void file_output(std::vector<profit>& p, bool s)
{
	std::string out_name;
	std::ofstream out_file;
	std::cout << "Enter output file name>"; std::cin >> out_name;
	out_file.open(out_name);

	if (s)
	{
		std::vector<std::string> res;

		for (int i = 0; i < p.size(); i++)
		{
			res.push_back(p[i].non_profit());
			out_file << p[i];
		}

		out_file << std::endl;

		for (int i = 0; i < res.size(); i++)
		{
			out_file << res[i] << std::endl;
		}
	}

	out_file.close();
}

void console_output(std::vector<profit>& p, bool s)
{
	if (s)
	{
		std::vector<std::string> res;

		for (int i = 0; i < p.size(); i++)
		{
			res.push_back(p[i].non_profit());
			std::cout << p[i];
		}

		std::cout << std::endl;

		for (int i = 0; i < res.size(); i++)
		{
			std::cout << res[i] << std::endl;
		}
	}
}

int main()
{
	std::cout << "Information about profit" << std::endl;
	bool repeat = true;
	while (repeat)
	{
		std::vector<profit> p;
	
		std::cout << std::endl;
		int in_type = cheker(in_type, "input");
		int out_type = cheker(out_type, "output");

		switch (in_type)
		{
		case 1:
		{
			switch (out_type)
			{
			case 1:
			{
				bool s = true;
				file_input(p,s);

				file_output(p, s);

				break;
			}
			case 2:
			{
				bool s = true;
				file_input(p, s);

				console_output(p, s);

				break;
			}

			}
			break;
		}
		case 2:
		{
			switch (out_type)
			{
			case 1:
			{
				console_input(p);

				file_output(p, true);

				break;
			}
			case 2:
			{
				console_input(p);

				console_output(p, true);
				
				break;
			}
			}
			break;
		}
	}
	repeat = frepeat();
	}
}
