#pragma once
#include "MAMonteCarlo.h"



namespace za
{
	namespace ma
	{
		namespace mc
		{

#pragma region Example1


			MonteCarloIntegration::MonteCarloIntegration(za::ma::com::MathFunction<double>& f)
				: m_f(f), m_numSamples(DEFAULT_NUM_SAMPLES)
			{
			}
			MonteCarloIntegration::MonteCarloIntegration(za::ma::com::MathFunction<double>& f, int num_samples)
				: m_f(f), m_numSamples(num_samples)
			{
			}
			MonteCarloIntegration::MonteCarloIntegration(const MonteCarloIntegration&
				p)
				: m_f(p.m_f), m_numSamples(p.m_numSamples)
			{
			}
			MonteCarloIntegration::~MonteCarloIntegration()
			{
			}

			MonteCarloIntegration& MonteCarloIntegration::operator =(const MonteCarloIntegration& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
					m_numSamples = p.m_numSamples;
				}
				return *this;
			}
			void MonteCarloIntegration::setNumSamples(int n)
			{
				m_numSamples = n;
			}
			double MonteCarloIntegration::integrateRegion(double a, double b, double min, double max)
			{
				std::uniform_real_distribution<> xDistrib(a, b);
				std::uniform_real_distribution<> yDistrib(min, max);
				int pointsIn = 0;
				int pointsOut = 0;
				bool positive = max > 0;
				for (int i = 0; i < m_numSamples; ++i)
				{
					double x = xDistrib(za::ma::com::random_generator);
					double y = m_f(x);
					double ry = yDistrib(za::ma::com::random_generator);
					if (positive && min <= ry && ry <= y)
					{
						pointsIn++;
					}
					else if (!positive && y <= ry && ry <= max)
					{
						pointsIn++;
					}
					else
					{
						pointsOut++;
					}
				}
				double percentageArea = 0;
				if (pointsIn + pointsOut > 0)
				{
					percentageArea = pointsIn / double(pointsIn + pointsOut);
				}
				if (percentageArea > 0)
				{
					return (b - a) * (max - min) * percentageArea;
				}
				return 0;
			}
			double MonteCarloIntegration::getIntegral(double a, double b)
			{
				std::uniform_real_distribution<> distrib(a, b);
				double max = 0;
				double min = 0;
				for (int i = 0; i < m_numSamples; ++i)
				{
					double x = distrib(za::ma::com::random_generator);
					double y = m_f(x);
					if (y > max)
					{
						max = y;
					}
					if (y < min)
					{
						min = y;
					}
				}
				double positiveIntg = max > 0 ? integrateRegion(a, b, 0, max) : 0;
				double negativeIntg = min < 0 ? integrateRegion(a, b, min, 0) : 0;
				return positiveIntg - negativeIntg;
			}
			FSin::~FSin()
			{
			}
			double FSin::operator()(double x)
			{
				return sin(x);
			}
#pragma endregion Example1

#pragma region Example2
			RandomWalk::RandomWalk(int size, double start, double step)
				: m_size(size),
				m_step(step),
				m_start(start)
			{
			}
			RandomWalk::RandomWalk(const RandomWalk& p)
				: m_size(p.m_size),
				m_step(p.m_step),
				m_start(p.m_start)
			{
			}
			RandomWalk::~RandomWalk()
			{
			}
			RandomWalk& RandomWalk::operator=(const RandomWalk& p)
			{
				if (this != &p)
				{
					m_size = p.m_size;
					m_step = p.m_step;
					m_start = p.m_start;
				}
				return *this;
			}
			std::vector<double> RandomWalk::getWalk()
			{
				std::vector<double> walk;
				double prev = m_start;
				for (int i = 0; i < m_size; ++i)
				{
					int r = rand() % 3;
					double val = prev;
					if (r == 0) val += (m_step * val);
					else if (r == 1) val -= (m_step * val);
					walk.push_back(val);
					prev = val;
				}
				return walk;
			}

#pragma endregion Example2

#pragma region Example3
			OptionsProbabilities::OptionsProbabilities(double initialPrice, double strike, double avgStep, int nDays)
				: m_initialPrice(initialPrice),
				m_strike(strike),
				m_avgStep(avgStep),
				m_numDays(nDays),
				m_numIterations(NUM_ITERATIONS)
			{
			}
			OptionsProbabilities::OptionsProbabilities(const OptionsProbabilities& p)
				: m_initialPrice(p.m_initialPrice),
				m_strike(p.m_strike),
				m_avgStep(p.m_avgStep),
				m_numDays(p.m_numDays),
				m_numIterations(p.m_numIterations)
			{
			}
			OptionsProbabilities::~OptionsProbabilities()
			{
			}
			OptionsProbabilities& OptionsProbabilities::operator=(const OptionsProbabilities& p)
			{
				if (this != &p)
				{
					m_initialPrice = p.m_initialPrice;
					m_strike = p.m_strike;
					m_avgStep = p.m_avgStep;
					m_numDays = p.m_numDays;
					m_numIterations = p.m_numIterations;
				}
				return *this;
			}
			void OptionsProbabilities::setNumIterations(int n)
			{
				m_numIterations = n;
			}
			double OptionsProbabilities::probFinishAboveStrike()
			{
				int nAbove = 0;
				for (int i = 0; i < m_numIterations; ++i)
				{
					double val = getLastPriceOfWalk();
					if (val >= m_strike)
					{
						nAbove++;
					}
				}
				return nAbove / (double)m_numIterations;
			}
			double OptionsProbabilities::probFinishBelowStrike()
			{
				int nBelow = 0;
				for (int i = 0; i < m_numIterations; ++i)
				{
					double val = getLastPriceOfWalk();
					if (val <= m_strike)
					{
						nBelow++;
					}
				}
				return nBelow / (double)m_numIterations;
			}
			double OptionsProbabilities::probFinalPriceBetweenPrices(double lowPrice, double highPrice)
			{
				int nBetween = 0;
				for (int i = 0; i < m_numIterations; ++i)
				{
					double val = getLastPriceOfWalk();
					if (lowPrice <= val && val <= highPrice)
					{
						nBetween++;
					}
				}
				return nBetween / (double)m_numIterations;
			}
			double OptionsProbabilities::gaussianValue(double mean, double sigma)
			{
				std::normal_distribution<> distrib(mean, sigma);
				return distrib(za::ma::com::random_generator);
			}
			double OptionsProbabilities::getLastPriceOfWalk()
			{
				double prev = m_initialPrice;
				for (int i = 0; i < m_numDays; ++i)
				{
					double stepSize = gaussianValue(0, m_avgStep);
					int r = rand() % 2;
					double val = prev;
					if (r == 0) val += (stepSize * val);
					else val -= (stepSize * val);
					prev = val;
				}
				return prev;
			}
			std::vector<double> OptionsProbabilities::getWalk()
			{
				std::vector<double> walk;
				double prev = m_initialPrice;
				for (int i = 0; i < m_numDays; ++i)
				{
					double stepSize = gaussianValue(0, m_avgStep);
					int r = rand() % 2;
					double val = prev;
					if (r == 0) val += (stepSize * val);
					else val -= (stepSize * val);
					walk.push_back(val);
					prev = val;
				}
				return walk;
			}
#pragma endregion Example3

#pragma region Example4
			//different book
			//c++ for quants 
			//close form solution

			double normPdf(const double& x)
			{
//#define _USE_MATH_DEFINES

				double M_PI = za::ma::com::pi();
			
				return (1.0 / std::pow(2 * M_PI, 0.5))*std::exp(-0.5*x*x);
			}
			//an approximation to the cumulative distribution function 
			//for the standard normal distribution 
			//note: this is a recursive function 
			double normCdf(const double& x)
			{
				double M_PI = za::ma::com::pi();
				double k = 1.0 / (1.0 + 0.2316419 * x);
				double kSum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429* k))));

				if (x >= 0.0)
				{
					return (1.0 -(1.0 / (std::pow(2* M_PI, 0.5))) * exp(-0.5*x*x) * kSum);
				}
				else
				{
					return 1.0 - normCdf(-x);
				}
			}
			//this term appears in the closed form solution for the european cal or put price 
			double dJ(const int& j, const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				return (std::log(s / k) + (r + (std::pow(-1, j - 1)) * 0.5* v*v) *t) / (v *(std::pow(t, 0.5)));

			}
			//vanilla european call 
			double callPrice(const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				return s * normCdf(dJ(1, s, k, r, v, t))- k*exp(-r * t) * normCdf(dJ(2, s, k, r, v, t));

			}
			//vanilla european put 
			double putPrice(const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				return -s* normCdf(-dJ(1, s, k, r, v, t)) + k*exp(-r *t) * normCdf(-dJ(2, s, k, r, v, t));
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

			double monteCarloCallPrice(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				double sAdjust = s * exp(t * (r - 0.5 * v * v));
				double sCur = 0.0;
				double payoffSum = 0.0;
				for (int i = 0; i < numSims; i++)
				{
					double gaussBm = gaussianBoxMuller();
					sCur = sAdjust * std::exp(sqrt(v * v * t) * gaussBm);
					payoffSum += std::max(sCur - k, 0.0);
				}

				return (payoffSum / static_cast<double>(numSims)) * std::exp(-r * t);
			}
			double monteCarloPutPrice(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				double sAdjust = s*exp(t*(r - 0.5*v*v));
				double sCur = 0.0;
				double payoffSum = 0.0;
				for (int i = 0; i < numSims; i++) 
				{ 
					double gaussBm = gaussianBoxMuller();
					sCur = sAdjust * std::exp(sqrt(v*v*t) * gaussBm);
					payoffSum += std::max(k - sCur, 0.0);
				}

				return (payoffSum / static_cast<double>(numSims)) *std:: exp(-r * t);
			}
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