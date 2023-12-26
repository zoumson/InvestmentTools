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

					std::cout << " future value for multiple period compounding is " << res << std::endl;
					std::cout << " future value for continuous compounding is " << contRes << std::endl;
				}

				void cashFlowCalculator()
				{
					double rate = 0.05;
					CashFlowCalculator cfc(rate);
					std::vector<int> period = { 1, 2, 3, 4 };
					std::vector<double> value = { 200, 300, 500, -1000};
	

					for (int i = 0; i < period.size(); i++)
					{
						cfc.addCashPayment(value[i], period[i]);

					}
					
					double result = cfc.presentValue();
					std::cout << " The present value is " << result << std::endl;

				}

				void bondCalculator()
				{
					std::string issuer = "XYZ";
					double principal = 100000;
					double coupon = 5000;
					int num_periods = 20;
					BondCalculator bc(issuer, num_periods, principal, coupon);
					std::cout << "reading information for bond issued by " << issuer <<std::endl;
					std::cout << " the internal rate of return is " << bc.interestRate() << std::endl;

				}

			}

#pragma endregion fixedIncome


		}
	}

}