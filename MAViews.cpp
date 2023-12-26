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

#pragma region equities

			namespace eq
			{
				using namespace za::ma::eq;
				void maCalculator()
				{
					int num_periods = 5;
					std::vector<double> price = { 10, 11, 22, 12, 13, 23, 12, 32, 12, 3, 2, 22, 32 };

					MACalculator calculator(num_periods);
					for (int i = 0; i < price.size(); i++) 
					{
						calculator.addPriceQuote(price[i]);
					}

					std::vector<double> ma = calculator.calculateMA();

					for (int i = 0; i < ma.size(); ++i)
					{
						std::cout << "average value " << i << " = " << ma[i] << std::endl;
					}
					std::vector<double> ema = calculator.calculateEMA();
					for (int i = 0; i < ema.size(); ++i)
					{
						std::cout << "exponential average value "
							<< i << " = " << ema[i] << std::endl;
					}

				}
				void volatilityCalculator()
				{

					std::vector<double> price = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7};

					VolatilityCalculator vc;
					for (int i = 0; i < price.size(); i++)
					{
						vc.addPrice(price[i]);
					}
		
					std::cout << "range volatility is " << vc.rangeVolatility() << std::endl;
					std::cout << "average daily range is " << vc.avgDailyRange() << std::endl;
					std::cout << "standard deviation is " << vc.stdDev() << std::endl;
				}
				void correlationCalculator()
				{
					double price;
					std::vector<double> pricea = { 1.2, 2, 2.5, 4, 3, 6, 5.5, 6.3, 7.1, 5.4 };
					std::vector<double> priceb = { 3.4, 3.3, 3, 5.5, 1.2, 2.4, 3.2, 3.1, 2.9, 3.2 };
					TimeSeries tsa;
					TimeSeries tsb;

					for (int i = 0; i < pricea.size(); i++)
					{
						tsa.addValue(pricea[i]);
						tsb.addValue(priceb[i]);
					}
					
					CorrelationCalculator cCalc(tsa, tsb);
					auto correlation = cCalc.correlation();
					std::cout << "correlation is " << correlation << std::endl;
				}
					
				void fundamentalsCalc()
				{
					FundamentalsCalculator fc("AAPL", 543.99, 12.20);
					// values are in millions
					fc.setAssets(243139);
					fc.setBookValue(165234);
					fc.setEarnings(35885);
					fc.setEpsGrowth(0.22);
					fc.setExpectedEarnings(39435);
					fc.setLiabilitiesAndIntangibles(124642);
					fc.setNetIncome(37235);
					fc.setNumOfShares(891990);
					fc.setShareHoldersEquity(123549);

					std::cout << "P/E: " << fc.PE() / 1000 << std::endl; // prices in thousands
					std::cout << "forward P/E: " << fc.forwardPE() / 1000 << std::endl;
					std::cout << "book value: " << fc.bookValue() << std::endl;
					std::cout << "price to book: " << fc.priceToBookRatio() << std::endl;
					std::cout << "price earnings to growth: " << fc.priceEarningsToGrowth() << std::endl;
					std::cout << "return on equity: " << fc.returnOnEquity() << std::endl;
					std::cout << "dividend: " << fc.getDividend() << std::endl;
				}
			};

#pragma endregion equities

		}
	}

}