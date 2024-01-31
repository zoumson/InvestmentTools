#include "MANumericalClasses.h"
//#include "MAUtilities.h"


namespace za
{
	namespace ma
	{
		namespace nc
		{

#pragma region Example1

			//Matrix::Matrix(int size)
			//{
			//	for (unsigned i = 0; i < size; ++i)
			//	{
			//		std::vector<double> row(size, 0);
			//		m_rows.push_back(row);
			//	}
			//}
			//Matrix::Matrix(int size, int size2)
			//{
			//	for (unsigned i = 0; i < size; ++i)
			//	{
			//		std::vector<double> row(size2, 0);
			//		m_rows.push_back(row);
			//	}
			//}
			//Matrix::Matrix(const Matrix& s)
			//	: m_rows(s.m_rows)
			//{
			//}
			//Matrix::~Matrix()
			//{
			//}
			//Matrix& Matrix::operator=(const Matrix& s)
			//{
			//	if (this != &s)
			//	{
			//		m_rows = s.m_rows;
			//	}
			//	return *this;
			//}
			//Matrix::Row& Matrix::operator[](int pos)
			//{
			//	return m_rows[pos];
			//}
			//void Matrix::transpose()
			//{
			//	std::vector<Row> rows;
			//	for (unsigned i = 0; i < m_rows[0].size(); ++i)
			//	{
			//		std::vector<double> row;
			//		for (unsigned j = 0; j < m_rows.size(); ++j)
			//		{
			//			row[j] = m_rows[j][i];
			//		}
			//		rows.push_back(row);
			//	}
			//	m_rows.swap(rows);
			//}
			//double Matrix::trace()
			//{
			//	if (m_rows.size() != m_rows[0].size())
			//	{
			//		return 0;
			//	}
			//	double total = 0;
			//	for (unsigned i = 0; i < m_rows.size(); ++i)
			//	{
			//		total += m_rows[i][i];
			//	}
			//	return total;
			//}
			//void Matrix::add(const Matrix& s)
			//{
			//	if (m_rows.size() != s.m_rows.size() ||
			//		m_rows[0].size() != s.m_rows[0].size())
			//	{
			//		throw new std::runtime_error("invalid matrix dimensions");
			//	}
			//	for (unsigned i = 0; i < m_rows.size(); ++i)
			//	{
			//		for (unsigned j = 0; j < m_rows[0].size(); ++j)
			//		{
			//			m_rows[i][j] += s.m_rows[i][j];
			//		}
			//	}
			//}
			//void Matrix::subtract(const Matrix& s)
			//{
			//	if (m_rows.size() != s.m_rows.size() ||
			//		m_rows[0].size() != s.m_rows[0].size())
			//	{
			//		throw new std::runtime_error("invalid matrix dimensions");
			//	}
			//	for (unsigned i = 0; i < m_rows.size(); ++i)
			//	{
			//		for (unsigned j = 0; j < m_rows[0].size(); ++j)
			//		{
			//			m_rows[i][j] += s.m_rows[i][j];
			//		}
			//	}
			//}
			//void Matrix::multiply(const Matrix& s)
			//{
			//	if (m_rows[0].size() != s.m_rows.size())
			//	{
			//		throw new std::runtime_error("invalid matrix dimensions");
			//	}
			//	std::vector<Row> rows;
			//	for (unsigned i = 0; i < m_rows.size(); ++i)
			//	{
			//		std::vector<double> row;
			//		for (unsigned j = 0; j < s.m_rows.size(); ++j)
			//		{
			//			double Mij = 0;
			//			for (unsigned k = 0; k < m_rows[0].size(); ++k)
			//			{
			//				Mij += m_rows[i][k] * s.m_rows[k][j];
			//			}
			//			row.push_back(Mij);
			//		}
			//		rows.push_back(row);
			//	}
			//	m_rows.swap(rows);
			//}
			//Matrix operator+(const Matrix& s1, const Matrix& s2)
			//{
			//	Matrix s(s1);
			//	s.subtract(s2);
			//	return s;
			//}
			//Matrix operator-(const Matrix& s1, const Matrix& s2)
			//{
			//	Matrix s(s1);
			//	s.subtract(s2);
			//	return s;
			//}
			//Matrix operator*(const Matrix& s1, const Matrix& s2)
			//{
			//	Matrix s(s1);
			//	s.multiply(s2);
			//	return s;
			//}



#pragma endregion Example1

#pragma region Example2
			void showFactorial()
			{
				std::cout << " Some factorial values: " << std::endl;
				std::cout << "fact(5)= " << Factorial<5>::result;
				std::cout << "fact(7)= " << Factorial<7>::result;
				std::cout << "fact(9)= " << Factorial<9>::result;
			}
#pragma endregion Example2

#pragma region Example3
			boost::ratio<1, 2> one_half;
			boost::ratio<1, 3> one_third;
			void createCalmarRatio()
			{
				CalmarRatio<CalmarRatioPerc> ratio(0.15, 11);
			}
			void printRatios()
			{
				std::cout << "one_third numerator: " << one_third.num << " denominator: " << one_third.den;
			}
#pragma endregion Example3

#pragma region Example4

			//using boost::math::quantile;

			//static boost::rand48 random_generator;

			DistributionData::DistributionData()
			{
			}
			DistributionData::~DistributionData()
			{
			}
			std::vector<double> DistributionData::gaussianData(int nPoints, double mean, double sigma)
			{
				std::vector<double> data;
				boost::random::normal_distribution<> distrib(mean, sigma);
				for (int i = 0; i < nPoints; ++i)
				{
					double val = distrib(za::ma::com::boost_random_generator);
					data.push_back(val);
				}
				return data;
			}

			std::vector<double> DistributionData::exponentialData(int nPoints, double rate)
			{
				std::vector<double> data;
				boost::random::exponential_distribution<> distrib(rate);
				for (int i = 0; i < nPoints; ++i)
				{
					double val = distrib(za::ma::com::boost_random_generator);
					data.push_back(val);
				}
				return data;
			}
			std::vector<double> DistributionData::logNormalData(int nPoints, double mean, double sigma)
			{
				std::vector<double> data;
				boost::random::lognormal_distribution<> distrib(mean, sigma);
				for (int i = 0; i < nPoints; ++i)
				{
					double val = distrib(za::ma::com::boost_random_generator);
					data.push_back(val);
				}
				return data;
			}
			std::vector<double> DistributionData::chiSquaredData(int nPoints, int degreesOfFreedom)
			{
				std::vector<double> data;
				boost::random::chi_squared_distribution<> distrib(degreesOfFreedom);
				for (int i = 0; i < nPoints; ++i)
				{
					double val = distrib(za::ma::com::boost_random_generator);
					data.push_back(val);
				}
				return data;
			}
			double DistributionData::gaussianQuantile(double x, double mean, double sigma)
			{
				boost::math::normal_distribution<> dist(mean, sigma);
				return quantile(dist, x);
			}
			double DistributionData::chiSquaredQuantile(double x, int degreesOfFreedom)
			{
				boost::math::chi_squared_distribution<> dist(degreesOfFreedom);
				return boost::math::quantile(dist, x);
			}
			double DistributionData::exponentialQuantile(double x, double rate)
			{
				boost::math::exponential_distribution<> dist(rate);
				return boost::math::quantile(dist, x);
			}
			double DistributionData::logNormalQuantile(double x, double mean, double sigma)
			{
				boost::math::lognormal_distribution<> dist(mean, sigma);
				return boost::math::quantile(dist, x);
			}

#pragma endregion Example4

#pragma region Example5
			double gaussianBoxMuller()
			{
				double x = 0.0;
				double y = 0.0;
				double euclidSq = 0.0;
				//continue generating two uniform random variables 
				//until the square of their euclidean distance is less than unity 
				do
				{
					x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
					y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;

					euclidSq = x * x + y * y;
				} while (euclidSq >= 1.0);

				return x * std::sqrt(-2 * std::log(euclidSq) / euclidSq);

			}






#pragma endregion Example5

#pragma region Example6

			// This uses the Park Miller algorithm found in "Numerial Recipes in C"
			// Define the constants for the Park Miller algorithm 

			const unsigned long a = 16807; // 7^5
			const unsigned long m = 2147483647; // 2^32( and thus prime)

			// Schrage's algorithm constants
			const unsigned long q = 127773;
			const unsigned long r = 2836;


			// Parameter constructor 
			LinearCongruentialGenerator::LinearCongruentialGenerator(unsigned long numDrawsArg, unsigned long initSeedArg): RandomNumberGenerator(numDrawsArg, initSeedArg)
			{
				if (initSeedArg == 0)
				{
					initSeed = 1;
					curSeed = 1;
				}

				maxMultiplier = 1.0 / (1.0 + (m - 1));
			}

			// Obtain a random unsigned long integer 
	

			// Obtain a random integer (needed for creating random uniforms) 
			 // dont mark this function const as it modifying the current seed 
			unsigned long LinearCongruentialGenerator::getRandomInteger() 
			{				
				unsigned long k = 0; 
				k = curSeed / q;
				curSeed = (unsigned long )a * (curSeed - k * q) - r * k;


				if (curSeed < 0)
				{
					curSeed += m;
				}

				return curSeed;

			}

			// Fill a vector with uniform random variables on the open interval (0, 1)
			void LinearCongruentialGenerator::getUniformDraws(std::vector<double>& draws)
			{
				for (int long i = 0; i < numDraws; i++)
				{
					draws[i] = getRandomInteger() * maxMultiplier;
				}
			}

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