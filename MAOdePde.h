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