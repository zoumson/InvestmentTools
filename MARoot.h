#pragma once
#include "MAOdePde.h"
#include "MAUtilities.h"


namespace za
{
	namespace ma
	{
		namespace re
		{

#pragma region Example1

			//define constructor inside header 
			//template <class Res>
			//class MathFunction 
			//{
			//public:
			//	MathFunction()
			//	{

			//	};
			//	virtual ~MathFunction()
			//	{

			//	};
			//	virtual Res operator()(Res value) = 0;
			//};

			//move implementation into source file avoid compilation errors 
			class BisectionMethod 
			{
			public:
				BisectionMethod(za::ma::com::MathFunction<double>& f);
				BisectionMethod(const BisectionMethod& p);
				~BisectionMethod();
				BisectionMethod& operator=(const BisectionMethod& p);
				double getRoot(double x1, double x2);
			private:
				za::ma::com::MathFunction<double>& m_f;
				double m_error;
			};

			class F1 : public za::ma::com::MathFunction<double>
			{
				public:
				~F1();
				double operator()(double x) override;

			};

#pragma endregion Example1

#pragma region Example2
			class SecantMethod 
			{
			public:
				SecantMethod(za::ma::com::MathFunction<double>& f);
				SecantMethod(const SecantMethod& p);
				SecantMethod& operator=(const SecantMethod& p);
				~SecantMethod();
				double getRoot(double x1, double x2);
			private:
				za::ma::com::MathFunction<double>& m_f;
				double m_error;
			};

#pragma endregion Example2

#pragma region Example3
			class NewtonMethod 
			{
			public:
				NewtonMethod(za::ma::com::MathFunction<double>& f, za::ma::com::MathFunction<double>& derivative);
				NewtonMethod(const NewtonMethod& p);
				virtual ~NewtonMethod();
				NewtonMethod& operator=(const NewtonMethod& p);
				double getRoot(double initialValue);
			private:
				za::ma::com::MathFunction<double>& m_f;
				za::ma::com::MathFunction<double>& m_derivative;
				double m_error;
			};

			class DF1 : public za::ma::com::MathFunction<double>
			{
			public:
				~DF1();
				double operator()(double value) override;
			};

		
#pragma endregion Example3

#pragma region Example4
			//new quant book 
			template<typename T> 
			double intervalBisection(double yTarget, double lowerBound, double upperBound, double tolerance, T f)
			{
				// Create the intitial x mid-point value 
				// Find the mapped y value of f(x)
				double x = 0.5 * (lowerBound + upperBound);
				double y = f(x);

				// While the difference between y and the yTarget value is greater than the tolerance keep 
				// Subdividing the interval into successively smaller halves and tre-evaluate the new y

				do
				{
					if (y < yTarget)
					{
						lowerBound = x;
					}				
					
					if (y > yTarget)
					{
						upperBound = x;
					}

					x = 0.5 * (lowerBound + upperBound);
					y = f(x);
				} while (std::fabs(y - yTarget) > tolerance);

				return x;

			}
#pragma endregion Example4
			template< typename T, 
			double (T::* g)(double) const,
			double (T::* gPrime)(double) const>
			double newtonRaphson(double yTarget, double init, double tolerance, const T& f)
			{

				// Set the initial option prices and volatility
				double y = (f.*g)(init); // initial option price 
				double x = init; // initial volatility 

				// While y and yTarget are not similar enough 
				// Take the vega of the option and recalcultate 
				// A new call price based on the best linear 
				// Approximation at that particular vol value 

				while (std::fabs(y - yTarget) > tolerance)
				{
					double dX = (f.*gPrime)(x);

					x += (yTarget - y) / dX;
					y = (f.*g)(x);

				}

				return x;

			}


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