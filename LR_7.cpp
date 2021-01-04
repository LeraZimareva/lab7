#include <iostream>

using namespace std;

class Times
{
	int clock;
	int minut;
	int second;
public:
	Times(int c = 0, int m = 0, int s = 0);
	Times(const Times& t);

	void setClock(const int& c);
	void setMinut(const int& m);
	void setSecond(const int& s);

	int const getClock()const;
	int const getMinut()const;
	int const getSecond() const;

	bool chekTimes();
	friend ostream& operator <<(ostream& fout, Times&);
	friend istream& operator >>(istream& fin, Times&);
};

Times::Times(int c, int m, int s)
{
	this->clock = c;
	this->minut = m;
	this->second = s;
}

Times::Times(const Times& t)
{
	this->clock = t.clock;
	this->minut = t.minut;
	this->second = t.second;
}

void Times::setClock(const int& c)
{
	this->clock = c;
}

void Times::setMinut(const int& m)
{
	this->minut = m;
}

void Times::setSecond(const int& s)
{
	this->second = s;
}

int const Times::getClock() const
{
	return this->clock;
}

int const Times::getMinut() const
{
	return this->minut;
}

int const Times::getSecond() const
{
	return this->second;
}

bool Times::chekTimes()
{
	if (this->clock <= 12)
		if (this->minut <= 60)
			if (this->second <= 59)
				return true;

	return false;
}

ostream& operator<<(ostream& fout, Times& objf)
{
	fout << objf.getClock() << ":"
		<< objf.getMinut() << ":"
		<< objf.getSecond() << endl;
	return fout;
}

istream& operator>>(istream& fin, Times& objf)
{
	cout << "\tчч:мм:сс " << endl;
	cout << " Enter times" << endl;
	cout << " Clock "; fin >> objf.clock;
	cout << " Minuts "; fin >> objf.minut;
	cout << " Second "; fin >> objf.second;
	return fin;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Times ss;
	char ch = 0;
	do {
		rewind(stdin);
		cin >> ss;
		if (ss.chekTimes()) {
			cout << " AM. " << endl;
			cout << ss << endl;
		}
		else {
			cout << " PM. " << endl;
			cout << ss << endl;
		}
		cout << " Enter : (y) ot (n)\t> "; cin >> ch; // Хотите повтрить если да (yes) нет (not)
	} while (ch != 'n');
	return 0;
}

