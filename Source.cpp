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
		number = 0;
		days_count = 0;
	};
	profit(int num, int days, std::vector<double> day_profit)
	{
		number = num;
		days_count = days;
		profit_per_day = day_profit;
	};

	profit(const profit& p)				// ����������� �����������
	{
		number = p.number;
		days_count = p.days_count;
		profit_per_day = p.profit_per_day;
	}
	// ����������
	~profit()
	{

	}
	
	// ������ ������������� ���������, ������� �� ��������� ������
	// � ������ (private) ������
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

// ���������� ��������� >>
std::istream& operator>> (std::istream& in, profit& p)
{
	in >> p.number;
	in >> p.days_count;
	return in;
}

// ���������� ��������� <<
std::ostream& operator<< (std::ostream& out, const profit& p)
{

	return out;
}

int main()
{

}