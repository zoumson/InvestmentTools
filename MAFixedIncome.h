#pragma once
#include "MAUtilities.h"

namespace za
{
	namespace ma
	{
		namespace fi
		{


#pragma region Example1

				// IntRateCalculator.h
			
			/*
			* Interest rates determine how much a financial institution is going to pay in exchange for 
			* holding a cash deposit over a period of time.
			* IntRateCalculator determines the calculation of single - period interest rates.
			* V = P(1+R)
			* V is the future value after a single period, and 
			* P is the present value of the deposit, or the principal.
			* The amount of the original fixed income loan or investment. 
			* This is the value over which the interest rate is calculated
			* in the case of a fixed income investment such as a bond.
			*/

				class IntRateCalculator 
				{
				public:
					IntRateCalculator(double rate);
					IntRateCalculator(const IntRateCalculator& v);
					IntRateCalculator& operator =(const IntRateCalculator& v);
					~IntRateCalculator();
					double singlePeriod(double value);
				private:
					double m_rate;
			};

#pragma endregion Example1

#pragma region Example2

				/*
				* 
				* Compound interest: Interest that is accrued over time and added to
				* the principal as regular interest payments are made at each period.
				* The amount of compound interest is regulated by the interval between interest payments.
				* The formula for discrete compounded interest rate is
				* V =  P*(1 + R)^N
				* where P is the present value,
				* V is the future value,
				* R is the interest rate, and
				* N is the number of periods.
				* 
				* Continuous compounding: As the number of periods increase,
				* the effect of compound interest becomes more pronounced. 
				* For example, compound interest paid at the end of every month will
				* produce more than at a yearly payment schedule. 
				* In theory, this compounding process could happen in a continuous schedule, and 
				* the resulting compound interest can be calculated using a simple formula
				* 
				* V = P*exp(RN)				
				*/

				class CompoundIntRateCalculator 
				{
				public:
					CompoundIntRateCalculator(double rate);
					CompoundIntRateCalculator(const CompoundIntRateCalculator& v);
					CompoundIntRateCalculator& operator =(const CompoundIntRateCalculator& v);
					~CompoundIntRateCalculator();
					double multiplePeriod(double value, int numPeriods);
					double continuousCompounding(double value, int numPeriods);
				private:
					double m_rate;
				};

#pragma endregion Example2

#pragma region Example3


#pragma endregion Example3

#pragma region Example4
			

#pragma endregion Example4

#pragma region Example5

#pragma endregion Example5

#pragma region Example6


#pragma endregion Example6
		
		}
	}
}