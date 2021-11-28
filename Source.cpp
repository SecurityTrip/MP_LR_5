#include <vector>
#include <iostream>
#include <fstream>

class profit
{
private:
	int number, days_count;
	std::vector<double> profit_per_day;
public:
	profit()
	{
	};
	profit(int num, int days, std::vector<double> day_profit)
	{
		number = num;
		days_count = days;
		profit_per_day = day_profit;
	};

	profit(const profit& p)				// конструктор копирования
	{
		number = p.number;
		days_count = p.days_count;
		profit_per_day = p.profit_per_day;
	}
	// деструктор
	~profit()
	{

	}
	// укажем дружественные операторы, которым мы разрешаем доступ
	// к личным (private) данным
	friend std::ostream& operator<< (std::ostream&, const profit&);
	friend std::istream& operator>> (std::istream&, profit& c);

	// перегрузка оператора >>
	std::istream& operator>> (std::istream& in, profit& c)
	{
		in >> c.number;
		in >> c.days_count;
		return in;
	}

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

int main()
{

}