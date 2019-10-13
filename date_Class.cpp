#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int get_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 || year % 100 == 0 || year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return get_day[month];
		}
	}
	Date (int year = 1900, int month = 1, int day = 1)
	{	
		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout <<"构造失败！" << endl;
		}
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date&  operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}


	bool operator<(const Date& d)
	{
		if (_year < d._year || (_year == d._year && _month < d._month) ||(_year == d._year && _month == d._month && _day < d._day))
			return true;
		return false;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day > d._day))
			return true;
		return false;
	}
	bool operator<=(const Date& d)
	{
		if (_year <= d._year || (_year == d._year && _month <= d._month) || (_year == d._year && _month == d._month && _day <= d._day))
			return true;
		return false;
	}
	bool operator>=(const Date& d)
	{
		if (_year >= d._year || (_year == d._year && _month >= d._month) || (_year == d._year && _month == d._month && _day >= d._day))
			return true;
		return false;
	}
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		return false;
	}
	bool operator!=(const Date& d)
	{
		if (_year != d._year || _month != d._month || _day != d._day)
			return true;
		return false;
	}


	Date operator+(int day)
	{
		Date x(*this);
		x._day = x._day + day;
		do
		{
			if (x._day > GetMonthDay(x._year, x._month))
			{
				x._day = x._day - GetMonthDay(x._year, x._month);
				++x._month;
				if (x._month > 12)
				{
					++x._year;
					x._month -= 12;
				}
			}
		} while (x._day > GetMonthDay(x._year, x._month));
		return x;
	}
	Date operator-(int day)
	{
		Date x(*this);
		x._day = x._day - day;
		do
		{
			if (x._day < 0)
			{
				--x._month;
				if (x._month <= 0)
				{
					--x._year;
					x._month += 12;
				}
				x._day = x._day + GetMonthDay(x._year, x._month);
				
			}
		} while (x._day < 0);
		return x;
	}
	Date operator+=(int day)
	{
		_day += day;
		do
		{
			if (_day > GetMonthDay(_year, _month))
			{
				_day = _day - GetMonthDay(_year, _month);
				++_month;
				if (_month > 12)
				{
					++_year;
					_month -= 12;
				}
			}
		} while (_day > GetMonthDay(_year, _month));
		return *this;
	}
	Date operator-=(int day)
	{
		_day -= day;
		do
		{
			if (_day < 0)
			{
				--_month;
				if (_month <= 0)
				{
					--_year;
					_month += 12;
				}
				_day += GetMonthDay(_year, _month);

			}
		} while (_day < 0);
		return *this;
	}


	// ++d d.operator++(&d)
	Date operator++()
	{
		++_day;
		do
		{
			if (_day > GetMonthDay(_year, _month))
			{
				_day = _day - GetMonthDay(_year, _month);
				++_month;
				if (_month > 12)
				{
					++_year;
					_month -= 12;
				}
			}
		} while (_day > GetMonthDay(_year, _month));
		return *this;
	}
	//d++
	Date operator++(int)
	{
		Date x = *this;
		++_day;
		do
		{
			if (_day > GetMonthDay(_year, _month))
			{
				_day = _day - GetMonthDay(_year, _month);
				++_month;
				if (_month > 12)
				{
					++_year;
					_month -= 12;
				}
			}
		} while (_day > GetMonthDay(_year, _month));
		return x;
	}


	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	~Date()
	{}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 8, 2);
	Date d2(2018, 8, 2);
	Date d3(2018, 9, 16);
	Date d4(d3);
	d1.Print();
	d3.Print();
	d4.Print();
	cout << d1.operator<(d2) << endl;
	cout << d1.operator>(d2) << endl;
	cout << d1.operator<=(d2) << endl;
	cout << d1.operator>=(d2) << endl;
	cout << d3.operator==(d4) << endl;
	cout << d1.operator!=(d2) << endl;

	Date d5 = d4.operator+(365);
	d5.Print();

	Date d6 = d5.operator-(365);
	d6.Print();


	Date d7 = d4.operator+=(365);
	d7.Print();

	Date d8 = d7.operator-=(365);
	d8.Print();


	Date d9 = d7.operator++();
	d9.Print();

	Date d10 = d8.operator++(0);
	d10.Print();
	system("pause");
	return 0;
}