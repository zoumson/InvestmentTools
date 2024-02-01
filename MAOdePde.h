#pragma once
#include "MAUtilities.h"




namespace za
{
	namespace ma
	{
		namespace od
		{

#pragma region Example1


			class EulersMethod 
			{
			public:
				EulersMethod(za::ma::com::MathFunction2<double>& f);
				EulersMethod(const EulersMethod& p);
				~EulersMethod();
				EulersMethod& operator=(const EulersMethod& p);
				double solve(int n, double x0, double y0, double c);
			private:
				za::ma::com::MathFunction2<double>& m_f;
			};


			class F4 : public za::ma::com::MathFunction2<double>
			{
			public:

				~F4();
				double operator()(double x, double y) override;
			};
#pragma endregion Example1

#pragma region Example2
			class RungeKuttaODEMethod 
			{
			public:
				RungeKuttaODEMethod(za::ma::com::MathFunction2<double>& f);
				RungeKuttaODEMethod(const RungeKuttaODEMethod& p);
				~RungeKuttaODEMethod();
				RungeKuttaODEMethod& operator=(const RungeKuttaODEMethod& p);
				double solve(int n, double x0, double y0, double c);
			private:
				za::ma::com::MathFunction2<double>& m_f;
			};


#pragma endregion Example2

#pragma region Example3
			class BlackScholesForwardMethod 
			{
			public:
				BlackScholesForwardMethod(double expiration, double maxPrice, double strike, double intRate);
				BlackScholesForwardMethod(const BlackScholesForwardMethod& p);
				~BlackScholesForwardMethod();
				BlackScholesForwardMethod& operator=(const BlackScholesForwardMethod& p);
				std::vector<double> solve(double volatility, int nx, int timeSteps);
			private:
				double m_expiration;
				double m_maxPrice;
				double m_strike;
				double m_intRate;
			};
#pragma endregion Example3

#pragma region Example4
			//c++ for quants 
//close form solution
			double normPdf(const double& x);
			double normCdf(const double& x);
			double dJ(const int& j, const double& s, const double& k, const double& r, const double& v, const double& t);
			double callPriceCloseForm(const double& s, const double& k, const double& r, const double& v, const double& t);
			double putPriceCloseForm(const double& s, const double& k, const double& r, const double& v, const double& t);
#pragma endregion Example4

#pragma region Example5

			double callDeltaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double callGammaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double callVegaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double callThetaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double callRhoCloseForm(const double s, const double k, const double r, const double v, const double t);

			double putDeltaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double putGammaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double putVegaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double putThetaCloseForm(const double s, const double k, const double r, const double v, const double t);
			double putRhoCloseForm(const double s, const double k, const double r, const double v, const double t);
#pragma endregion Example5

#pragma region Example6
			double callDeltaFDM(const double s, const double k, const double r, const double v, const double t, const double h);
			double callGammaFDM(const double s, const double k, const double r, const double v, const double t, const double h);

#pragma endregion Example6

#pragma region Example7
			//double gaussianBoxMuller();
			double callPriceMonteCarlo(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t);
			double putPriceMonteCarlo(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t);

#pragma endregion Example7	

#pragma region Example8
			// Pricing a European vanilla call option with a Monte Carlo method 
			// Create three separate paths, eahc with either an increment, non-increment or decrement based on deltaS, the stock parameter 
			void callPriceMonteCarloFDM(const int numSims, const double s, const double k, const double r, const double v, const double t, 
				const double deltaS, double& priceSp, double& priceS, double& priceSm);			
			
			double callDeltaMonteCarloFDM(const int numSims, const double s, const double k, const double r, const double v, const double t, const double deltaS);	

			double callGammaMonteCarloFDM(const int numSims, const double s, const double k, const double r, const double v, const double t, const double deltaS);

#pragma endregion Example8

#pragma region Example9

			class BlackScholesCall
			{
			private:
				double s; // Underlying asset price 
				double k; // Strike price 
				double r; // Risk-free rate 
				double t; // Time to maturity 
			public:
				BlackScholesCall(double sArg, double kArg, double rArg, double tArg);
				double optionPrice(double sigma) const;
				double optionVega(double sigma) const;
				double operator()(double sigma) const;

			};

#pragma endregion Example9

#pragma region Example10
			double callPriceJumpDiffusion(const double s, const double k, const double r, const double sigma, const double t,
										  const int n, const double m, const double lambda, const double  nu);

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