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