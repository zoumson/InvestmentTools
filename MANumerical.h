#pragma once
#include "MAUtilities.h"




namespace za
{
	namespace ma
	{
		namespace nc
		{

#pragma region Example1



			//class Matrix 
			//{
			//public:
			//	typedef std::vector<double> Row;
			//	Matrix(int size, int size2);
			//	Matrix(int size);
			//	Matrix(const Matrix& s);
			//	~Matrix();
			//	Matrix& operator=(const Matrix& s);
			//	void transpose();
			//	double trace();
			//	void add(const Matrix& s);
			//	void subtract(const Matrix& s);
			//	void multiply(const Matrix& s);
			//	Row& operator[](int pos);
			//private:
			//	std::vector<Row> m_rows;
			//};
			//Matrix operator+(const Matrix& s1, const Matrix& s2);
			//Matrix operator-(const Matrix& s1, const Matrix& s2);
			//Matrix operator*(const Matrix& s1, const Matrix& s2);


#pragma endregion Example1

#pragma region Example2

			//constexpr int factorial(const int n)
			//{
			//	return n <= 1 ? 1 : (n * factorial(n - 1));
			//}
			template <long N>
			class Factorial 
			{
			public:
				enum 
				{
					result = Factorial<N - 1>::result * N
				};
			private:
			};
			template <>
			class Factorial<0> 
			{
			public:
				enum 
				{
					result = 1
				};
			};
			template <int N, int P>
			class ChoiceNumber 
			{
			public:
				enum 
				{
					result = Factorial<N>::result / (Factorial<P>::result * Factorial<N - P>::result)
				};
			};
			void showFactorial();
#pragma endregion Example2

#pragma region Example3

			//boost::ratio<N, D>
			typedef boost::ratio<1, 1>::type CalmarRatioType;
			typedef boost::ratio<1, 100>::type CalmarRatioBPS;
			typedef boost::ratio<1, 1>::type CalmarRatioPerc;
			//template <class Ratio>
			//class CalmarRatio;


			template <class Ratio>
			class CalmarRatio 
			{
			public:
				CalmarRatio(double calmar, double ret) : m_calmar(calmar), m_return(ret) {}
				~CalmarRatio() {}
				double getReturn()
				{
					return m_return;
				}
				double getDrawDown()
				{
					return m_return / m_calmar * m_ratio.den;
				}
			private:
				Ratio m_ratio;
				double m_calmar;
				double m_return;
			};

		
			//no inline for  data member specialization 
			//also remove the empty closure template format 		
			//inline function member specialization to avoid compiler expecting it in the source file 
			//this may lead to multiple name definition 
			//also add the empty closure template format 
			template <>
			inline double CalmarRatio<CalmarRatioBPS>::getDrawDown()
			//inline double CalmarRatio<double>::getDrawDown()
			{
				return m_return / m_calmar * m_ratio.den * 100;
				//return 2.0;
			}


#pragma endregion Example3

#pragma region Example4
			class DistributionData {
			public:
				// standard constructor and destructor
				DistributionData();
				~DistributionData();
				// random data generation based on the given parameters.
				// each function returns a vector with nPoints random values.
				std::vector<double> gaussianData(int nPoints, double mean, double
					sigma);
				std::vector<double> exponentialData(int nPoints, double rate);
				std::vector<double> chiSquaredData(int nPoints, int
					degreesOfFreedom);
				std::vector<double> logNormalData(int nPoints, double mean, double
					sigma);
				// returns the quantile of the give value x, corresponding to the parameters provided.

				double gaussianQuantile(double x, double mean, double sigma);
				double chiSquaredQuantile(double x, int degreesOfFreedom);
				double exponentialQuantile(double x, double rate);
				double logNormalQuantile(double x, double mean, double sigma);
			};
			namespace
			{
				template <class T>
				void printData(const std::string& label, const T& data)
				{
					std::cout << " " << label << ": ";
					for (auto i : data)
					{
						std::cout << i << " ";
					}
					std::cout << std::endl;
				}
			}
#pragma endregion Example4

#pragma region Example5

#pragma endregion Example5

#pragma region Example6

#pragma endregion Example6

#pragma region Example7


#pragma endregion Example7	

#pragma region Example8


#pragma endregion Example8

#pragma region Example9

#pragma endregion Example9

#pragma region Example10


#pragma endregion Example10


#pragma region Example11

#pragma endregion Example11

#pragma region Example12


#pragma endregion Example12

#pragma region Example13


#pragma endregion Example13

#pragma region Example14


#pragma endregion Example14

#pragma region Example15


#pragma endregion Example15

		}
	}
}