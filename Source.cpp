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
	profit()
	{
		number = "0";
		days_count = 0;
	};
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

	

	int non_profit()
	{
		int non = 0;
		for (int i = 0; i < profit_per_day.size(); i++)
		{
			if (profit_per_day[i] == 0 || profit_per_day[i] == 0.0) non++;
		}
		return non;
	}

	
	
};

// перегрузка оператора >>
std::istream& operator>> (std::istream& in, profit& p)
{
	in >> p.number;
	in >> p.days_count;
	return in;
}

// перегрузка оператора <<
std::ostream& operator<< (std::ostream& out, const profit& p)
{
	out << "Branch number: " << p.number << std::endl <<"Days count: " << p.days_count << std::endl << "Profit per day: ";
	//out <<  p.number << std::endl <<  p.days_count << std::endl;
	
	for (int i = 0; i < p.profit_per_day.size(); i++)
	{
		out << p.profit_per_day[i] << " ";
	}
	out << std::endl;
	return out;
}

int cheker(int& in, std::string arg)
{
	in = 0;
	while (in != 1 && in != 2)
	{
		std::cout << "Choose " << arg << " type(file / consele)>"; std::string in_type_str; std::cin >> in_type_str;
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

void parce(std::string in, std::string& n ,int& d, std::vector<double>& v)
{
	std::istringstream input{ in };
	std::vector<std::string> result;

	while (!input.eof()) {
		std::string substring;
		input >> substring;
		result.push_back(substring);
	}

	n = result[0];
	d = stoi(result[1]);

	for (int i = 2; i < result.size(); i++)
	{
		v.push_back(atof(result[i].c_str()));
	}
}

double check_in(char f, int n, double d)
{
	if (f == 'i')
	{
		std::cout << "Enter days count > "; std::cin >> n;
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

int main()
{
	std::cout << "Information about profit" << std::endl;
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
						std::ifstream in_file;
						std::ofstream out_file;
						std::string in_name, out_name;

					repeat_in_1_1:
						std::cout << "Enter input file name>"; std::cin >> in_name;					
						in_file.open(in_name);
						if (!in_file.is_open()) { std::cout << "Can`t open input file." << std::endl; goto repeat_in_1_1; }
						std::cin.clear();
						std::cin.ignore(10000, '\n');

					repeat_out_1_1:
						std::cout << "Enter output file name>"; std::cin >> out_name;
						out_file.open(out_name);
						if (!out_file.is_open()) { std::cout << "Can`t open output file." << std::endl; goto repeat_out_1_1; }

					
						std::string file_data;
						getline(in_file,file_data);
						std::string name;
						int days;
						std::vector<double> vec;
						parce(file_data, name, days, vec);

						profit prof(name,days,vec);

						out_file << "Days without profit: " << prof.non_profit();

						in_file.close();
						out_file.close();

					break;
					}
				case 2:
					{
						std::ifstream in_file;
						std::string in_name;

					repeat_in_1_2:
						std::cout << "Enter input file name>"; std::cin >> in_name;
						in_file.open(in_name);
						if (!in_file.is_open()) { std::cout << "Can`t open input file." << std::endl; goto repeat_in_1_2; }
					
						std::string file_data;
						getline(in_file, file_data);
						std::string name;
						int days;
						std::vector<double> vec;
						parce(file_data, name, days, vec);

						profit prof(name, days, vec);

						std::cout << "Days without profit: " << prof.non_profit();

						in_file.close();
						
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
						std::ofstream out_file;
						std::string out_name;
					repeat_out_2:
						std::cout << "Enter output file name>"; std::cin >> out_name;
						out_file.open(out_name);
						if (!out_file.is_open()) std::cout << "Can`t open output file." << std::endl; goto repeat_out_2;

						std::cout << "Enter branch number> "; std::string branch; std::cin >> branch;
						double a = 0.0;
						std::cout << "Enter days count> "; int days; days = (int)check_in('i',days, a);
						std::vector<double> vec;
						int b = 0;
						for (int i = 0; i < days; i++) 
						{
							std::cout << "Enter profit in " << i + 1 << " day>"; double p;  p = check_in('d', b, p);
							vec.push_back(p);
						}

						profit prof(branch, days, vec);

						out_file << "Days without profit: " << prof.non_profit();

						out_file.close();

					break;
					}
				case 2:
					{

						std::cout << "Enter branch number> "; std::string branch; std::cin>> branch;
						double a = 0.0;
						std::cout << "Enter days count> "; int days = 0; days = (int)check_in('i', days, a);
						std::vector<double> vec;
						int b = 0;
						for (int i = 0; i < days; i++)
						{
							std::cout << "Enter profit in " << i + 1 << " day>"; double p = 0;  p = check_in('d', b, p);
							vec.push_back(p);
						}

						profit prof(branch, days, vec);

						std::cout << "Days without profit: " << prof.non_profit();
					break;
					}
			}
			break;
		}
	}

}
