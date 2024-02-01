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

			StandardNormalDistribution::StandardNormalDistribution(){}
			StandardNormalDistribution::~StandardNormalDistribution(){}
			double StandardNormalDistribution::pdf(const double& x) const
			{
				return (1.0 / std::sqrt(2.0 * za::ma::com::pi())) * std::exp(-0.5 * x * x);
			}
			double StandardNormalDistribution::cdf(const double& x) const
			{
				double k = 1.0 / (1.0 + 0.2316419);
				double kSum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
				
				if (x >= 0.0)
				{
					return (1.0 - (1.0 / (std::pow(2 * za::ma::com::pi(), 0.5))) * std::exp(-0.5 * x * x) * kSum);
				}
				else
				{
					return 1.0 - cdf(-x);
				}

			}
			double StandardNormalDistribution::invCdf(const double& quantile) const
			{
				// This is the Beasley-Springer-Moro algorithm which can be found in Glasserman 

				static double a[4] = {	2.50662823884,
										-18.61500062529, 
										41.39119773534, 
										-25.44106049637};
				
				static double b[4] = {	-8.47351093090,
										23.08336743743, 
										-21.06224101826, 
										3.13082909833};
								
				static double c[9] = {	0.3374754822726147,
										0.9761690190917186, 
										0.1607979714918209, 
										0.0276438810333863,
										0.0038405729373609,
										0.0003951896511919,
										0.0000321767881768,
										0.0000002888167364,
										0.0000003960315187};
											
				if (quantile >= 0.5 && quantile <= 0.92)
				{
					double num = 0.0;
					double denom = 1.0;

					for (int i = 0; i < 4; i++)
					{
						num += a[i] * std::pow((quantile - 0.5), 2 * i + 1);
						denom += b[i] * std::pow((quantile - 0.5), 2 * i );
					}

					return num / denom;
				}
				else if (quantile > 0.92 && quantile < 1)
				{
					double num = 0.0;
					
					for (int i = 0; i < 9; i++)
					{
						num += c[i] * std::pow((std::log(-std::log(1 - quantile))), i);
					}

					return num;
				}
				else
				{
					return -1.0 * invCdf(1 - quantile);
				}


			}
			double StandardNormalDistribution::mean() const { return 0.0; }
			double StandardNormalDistribution::var() const { return 1.0; }
			double StandardNormalDistribution::stdev() const { return 1.0; }
			void StandardNormalDistribution::randomDraws(const std::vector<double>& uniformDraws, std::vector<double>& distDraws)
			{
				//The simplest method to calculate this is with the Box-Mulller method 
				
				//Check that the uniform draws and dist draws are the same size and have an even number of elements 
				if (uniformDraws.size() != distDraws.size())
				{
					std::cout << "Draw vectors are of unequal size." << std::endl;
					return;
				}
				if (uniformDraws.size() % 2 != 0)
				{
					std::cout << "Uniform draws vector size not an even number." << std::endl;
				}

				for (int i = 0; i < uniformDraws.size() / 2; i++)
				{
					distDraws[2 * i] = std::sqrt(-2.0 * std::log(uniformDraws[2 * i])) * std::sin(2 * za::ma::com::pi() * uniformDraws[2 * i + 1]);
					distDraws[2 * i + 1] = std::sqrt(-2.0 * std::log(uniformDraws[2 * i])) * std::cos(2 * za::ma::com::pi() * uniformDraws[2 * i + 1]);
				}

			}

#pragma endregion Example7	

#pragma region Example8
			CorrelatedSND::CorrelatedSND(const double rhoArg, const std::vector<double>* uncorrDrawsArg) : rho(rhoArg), uncorrDraws(uncorrDrawsArg) {}
			CorrelatedSND::~CorrelatedSND() {}
			void CorrelatedSND::correlationCalc(std::vector<double>& distDraws)
			{
				// This carries out the actual correlation modification 
				// If rho = 0.0 then distDraws is unmodified, whereas if rho = 1.0 then 
				// distDraws is set to uncorreDraws 
				// Thus with 0 < rho < 1 we have a weighted average of each set 
				for (int i = 0; i < distDraws.size(); i++)
				{
					distDraws[i] = rho * (*uncorrDraws)[i] + distDraws[i] * std::sqrt(1 - rho * rho);
				}
			}
			void CorrelatedSND::randomDraws(const std::vector<double>& uniformDraws, std::vector<double>& distDraws)
			{
				super::randomDraws(uniformDraws, distDraws);
				//StandardNormalDistribution::randomDraws(uniformDraws, distDraws);
				// Modify the random draws via the correlation calculation 
				correlationCalc(distDraws);

			}


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