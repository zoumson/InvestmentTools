#pragma once
#include "MAUtilities.h"
#define _USE_MATH_DEFINES


namespace za
{
	namespace ma
	{
		namespace mc
		{

#pragma region Example1
			class MonteCarloIntegration 
			{
			public:
				MonteCarloIntegration(za::ma::com::MathFunction<double>& f);
				MonteCarloIntegration(za::ma::com::MathFunction<double>& f, int num_samples);
				MonteCarloIntegration(const MonteCarloIntegration& p);
				~MonteCarloIntegration();
				MonteCarloIntegration& operator=(const MonteCarloIntegration& p);
				void setNumSamples(int n);
				double getIntegral(double a, double b);
				double integrateRegion(double a, double b, double min, double max);
			private:
				za::ma::com::MathFunction<double>& m_f;
				int m_numSamples;
			};
			const int DEFAULT_NUM_SAMPLES = 1000;
			/*static std::default_random_engine random_generator;*/

			class FSin : public za::ma::com::MathFunction<double>
			{
			public:
				~FSin();
				double operator()(double x);
			};
			
#pragma endregion Example1

#pragma region Example2
			class RandomWalk 
			{
			public:
				RandomWalk(int size, double start, double step);
				RandomWalk(const RandomWalk& p);
				~RandomWalk();
				RandomWalk& operator=(const RandomWalk& p);
				std::vector<double> getWalk();
			private:
				int m_size; // number of steps
				double m_step; // size of each step (in percentage)
				double m_start; // starting price
			};
#pragma endregion Example2

#pragma region Example3
			class OptionsProbabilities 
			{
			public:
				OptionsProbabilities(double initialPrice, double strike, double
					avgStep, int nDays);
				OptionsProbabilities(const OptionsProbabilities& p);
				~OptionsProbabilities();
				OptionsProbabilities& operator=(const OptionsProbabilities& p);
				void setNumIterations(int n);
				double probFinishAboveStrike();
				double probFinishBelowStrike();
				double probFinalPriceBetweenPrices(double lowPrice, double highPrice);
				std::vector<double> getWalk();
			private:
				double m_initialPrice;
				double m_strike;
				double m_avgStep;
				int m_numDays;
				int m_numIterations;
				double gaussianValue(double mean, double sigma);
				double getLastPriceOfWalk();
			};

			const int NUM_ITERATIONS = 1000;
#pragma endregion Example3

#pragma region Example4
			//c++ for quants 
			//close form solution
			double normPdf(const double& x);
			double normCdf(const double& x);
			double dJ(const int& j, const double& s, const double& k, const double& r, const double& v, const double& t);
			double callPrice(const double& s, const double& k, const double& r, const double& v, const double& t);
			double putPrice(const double& s, const double& k, const double& r, const double& v, const double& t);
#pragma endregion Example4

#pragma region Example5
			double gaussianBoxMuller();
			double monteCarloCallPrice(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t);
			double monteCarloPutPrice(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t);
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