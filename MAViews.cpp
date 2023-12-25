#include "MAViews.h"

namespace za
{
	namespace ma
	{
		namespace ex
		{

#pragma region fixedIncome

			namespace fi
			{
				using namespace za::ma::fi;

				void interestRateCalculator()
				{
					
					double rate = 0.08;
					double value = 10000;

					IntRateCalculator irCalculator(rate);
					double res = irCalculator.singlePeriod(value);
					std::cout << " result is " << res << std::endl;


				};

				void compoundInterestRateCalculator()
				{
					double rate = 0.05;
					double value = 1000;
					int num_periods = 4;//in years 
					CompoundIntRateCalculator cIRCalc(rate);
					double res = cIRCalc.multiplePeriod(value, num_periods);
					double contRes = cIRCalc.continuousCompounding(value, num_periods);

					std::cout << " future value for multiple period compounding is " << res
						<< std::endl;
					std::cout << " future value for continuous compounding is " << contRes
						<< std::endl;
				}

			};

#pragma endregion fixedIncome


		}
	}

}