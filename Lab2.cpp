#include <iostream>
#include <math.h>
#include <conio.h>
#include <vector>
using namespace std;


class Complex
{
private:
	double re, im, sum;

public:
	Complex() //конструктор по умолчанию
	{
		im = 0;
		re = 0;
	};

	Complex(double re) 
	{
		this->re = re;
		im = 0;
	}

	Complex(double re, double im)
	{
		this->re = re;
		this->im = im;
	}

	Complex(Complex& value)
	{
		re = value.re;
		im = value.im;
	}

	~Complex() {}

	void abs()
	{
	this->sum = sqrt(re * re + im * im);
	}

	bool operator != (Complex& other)
	{
		return !(this->sum == other.sum);
	}
	bool operator == (Complex& other)
	{
		return (this->sum == other.sum);
	}
	bool operator > (Complex& other)
	{
		return (this->sum > other.sum);
	}
	bool operator < (Complex& other)
	{
		return (this->sum < other.sum);
	}


	void operator = (Complex& other)
	{
		this->re = other.re;
		this->im = other.im;
		this->sum = other.sum;
	}

	Complex operator + (Complex& other)
	{
		Complex temp;

		temp.re = re + other.re;
		temp.im = im + other.re;

		return temp;
	}

	Complex operator - (Complex& other)
	{
		Complex temp;

		temp.re = re - other.re;
		temp.im = im - other.re;

		return temp;
	}

	Complex operator * (Complex& other)
	{
		Complex temp;

		temp.re = re * other.re;
		temp.im = im * other.re;

		return temp;
	}

	Complex operator / (Complex& other)
	{
		Complex temp;

		double r = other.re * other.re + other.im * other.im;
		temp.re = (re * other.re + im * other.im) / r;
		temp.re = (im * other.re - re * other.im) / r;

		return temp;
	}

	friend ostream& operator<<(ostream&, const Complex&); 
	friend istream& operator>>(istream&, const Complex&); 

};
ostream& operator<<(ostream& out, const Complex& other)
{
	out << other.re;
	if (other.im > 0)
		out << "+";
	out << other.im << "*i";

	return out;
}
istream& operator>>(istream& in, const Complex& other)
{
	in >> other.re >> other.im;

	return in;
}
//////////////////////////////////////////////////////////////////

class Vector
{
private:
	double* vector;
	int size;

public:
	Vector()
	{
		size = 1;
		vector = new double[size];
		for (int index = 0; index != size; index++)
			vector[index] = 0;
	}
	Vector(int size)
	{
		if (size > 0)
		{
			this->size = size;
			vector = new double[size];
			for (int index = 0; index != size; index++)
				vector[index] = 0;
		}
		else cout << "Размер не подходящий\n";
	}
	double& operator[](int index)
	{
		return vector[index];
	}
	~Vector()
	{
		delete[] vector;
	}
	Vector(Vector& other)
	{
		this->size = other.size;
		vector = new double[size];
		for (int index = 0; index != size; index++)
			vector[index] = other.vector[index];
	} 
	void operator =(Vector& other)
	{
		for (int index = 0; index != other.size; index++)
			this->vector[index] = other.vector[index];
	}
	Vector operator +(Vector& other)
	{
		if (size == other.size)
		{
			Vector temp(size);
			for (int index = 0; index != other.size; index++)
				temp.vector[index] = vector[index] + other.vector[index];
			return temp;
		}
		else cout << "Операция сложения не осуществима из-за разных размеров векторов\n";
	}
	Vector operator -(Vector& other)
	{
		if (size == other.size)
		{
			Vector temp(size);
			for (int index = 0; index != other.size; index++)
				temp.vector[index] = vector[index] - other.vector[index];
			return temp;
		}
		else cout << "Операция разности не осуществима из-за заных размеров векторов\n";
	}
	bool operator ==(Vector& other)
	{

			for (int index = 0; index != size; index++)
			{
				if (vector[index] != other.vector[index])
				{
					return 0; break;
				}
			}
			return 1;
	}
	bool operator !=(Vector& other)
	{
			for (int index = 0; index != size; index++)
			{
				if (vector[index] == other.vector[index])
				{
					return 0; break;
				}
			}
			return 1;
	}

	void scalar(Vector& other)
	{
		double sc = 0;
		for (int index = 0; index != other.size; index++)
			sc += vector[index] * other.vector[index];
		cout << "Скалярное произведение векторов: " << sc<<endl;
	}

	friend ostream& operator<<(ostream& output, const Vector& other);
	friend istream& operator>>(istream& input, const Vector& other);
};

ostream& operator<<(ostream& output, const Vector& other)
{
	cout << "{ ";
	for (int index = 0; index != other.size; index++)
		output << other.vector[index] << " ";
	cout << "}";
	return output;
}
istream& operator>>(istream& input, const Vector& other)
{
	for (int index = 0; index != other.size; index++)
	{
		input >> other.vector[index];
	}
	return input;
}
///////////////////////////////////////////////////////////

class Matrix
{
private:
	int i, j;
	double** matrix;
public:

	Matrix()
	{
		matrix = new double*[i];
		for (int index = 0; index < i; index++)
			matrix[index] = new double[j];

		for (int index_i = 0; index_i < i; index_i++)
		{
			for (int index_j = 0; index_j < j; index_j++)
				matrix[index_i][index_j] = 0;
		}
	}
	Matrix(int i, int j)
	{
		matrix = new double* [i];
		for (int index = 0; index < i; index++)
			matrix[index] = new double[j];

		for (int index_i = 0; index_i < i; index_i++)
		{
			for (int index_j = 0; index_j < j; index_j++)
				matrix[index_i][index_j] = 0;
		}
	}

	void dis()
	{
		for (int index_i = 0; index_i != i; index_i++)
		{
			for (int index_j = 0; index_j != j; index_j++)
				cout << matrix[index_i][index_j] << " ";
		}
	}

	~Matrix()
	{
		for (int index = 0; index < i; index++)
			delete[]matrix[index];
	}

	friend ostream& operator<<(ostream& output, const Matrix& other);
	friend istream& operator>>(istream& input, const Matrix& other);
};

ostream& operator<<(ostream& output, const Matrix& other)
{
	for (int index_i = 0; index_i != other.i; index_i++)
	{
		for (int index_j = 0; index_j != other.j; index_j++)
			output << other.matrix[index_i][index_j] << " ";
	}
	return output;
}
istream& operator>>(istream& input, const Matrix& other)
{
	for (int index_i = 0; index_i != other.i; index_i++)
		for (int index_j = 0; index_j != other.j; index_j++)
			input >> other.matrix[index_i][index_j];		
	return input;
}

///////////////////////////////////////////////////////////


int main()
{
	setlocale(LC_ALL,"");
	char button = '1';

	while (button != '0')
	{
		cout << "\nВведите 1 для 1-го задания\n";
		cout << "Введите 2 для 2-го задания\n";
		cout << "Введите 3 для 3-го задания\n";
		cout << "Введите 0 чтобы выйти\n";

		button = _getche();

		switch (button)
		{
		case('1'):
			{
			cout << endl;
				Complex cm1(7, 2);
				Complex cm2(3, 1);

				cout << cm1 << "; " << cm2 << endl;

				cout <<" - "<< cm1 + cm2 << endl;

				cout << " + " << cm1 - cm2 << endl;

				cout << " * " << cm1 * cm2 << endl;

				cout << " / " << cm1 / cm2 << endl;
				cm1.abs();
				cm2.abs();
				if (cm1 != cm2)cout << "\nЧисла не равны\n";
				if (cm1 < cm2)cout << "1-е число больше 2-го\n";
				if (cm1 > cm2)cout << "1-е число меньше 2-го\n";

				cm1 = cm2;

				if (cm1 == cm2)cout << "Числа равны\n";
				cout << cm1 << " = " << cm2 << endl;

			} break;

		case('2'):
		{
			cout << "\n";
			int size_v;
			cout << "введите размер векторов: "; cin >> size_v;
			Vector a(size_v);
			Vector b(size_v);
			cout << "\nВведите вектор a: ";
			cin >> a;
			cout << "\nВведите вектор b: ";
			cin >> b;

			cout <<"a: "<<a;
			cout <<"\nb: "<< b;

			if (a == b)cout << "\nВекторы равны\n";
			if (a != b)cout << "\nВекторы не равны\n";


			cout <<"\na + b: "<< a + b;
			cout <<"\na - b: "<< a - b<<endl;
			
			a.scalar(b);

		} break;

		case('3'):
			Matrix a(2,2);
			a.dis();
		}
	}


	system("pause");
	return 0;
}

