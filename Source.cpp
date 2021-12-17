#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class profit 
{
private:
	int number, days_count;
	std::vector<double> profit_per_day;
public:
	profit()
	{
		number = 0;
		days_count = 0;
	};
	profit(int num, int days, std::vector<double> day_profit)
	{
		number = num;
		days_count = days;
		profit_per_day = day_profit;
	};

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

	

	int non_profit(std::vector<double> profit_per_day)
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
		out << p.profit_per_day[i];
	}
	out << std::endl;
	return out;
}

int cheker(int& in, std::string arg)
{
	in = 0;
	while (in != 1 && in != 2)
	{
		std::cout << "Chose " << arg << " type(file / consele)>"; std::string in_type_str; std::cin >> in_type_str;
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

int main()
{
	std::cout << "Information about profit" << std::endl;
	int in_type = cheker(in_type, "input");
	int out_type = cheker(out_type, "output");

	std::cout << in_type << std::endl << out_type;
	
	
}