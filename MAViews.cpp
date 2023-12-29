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
#pragma region programmingTechniques

			namespace pt
			{
				using namespace za::ma::pt;
				void intRateEngine()
				{
					//Select All configurations and All platforms in the property page. Then set C++17 and apply.
					//if (_MSVC_LANG == 202101L) std::cout << "C++23";
					//else if (_MSVC_LANG == 202002L) std::cout << "C++20";
					//else if (_MSVC_LANG == 201703L) std::cout << "C++17";
					//else if (_MSVC_LANG == 201402L) std::cout << "C++14";
					//else if (_MSVC_LANG == 201103L) std::cout << "C++11";
					//else if (_MSVC_LANG == 199711L) std::cout << "C++98";
					//else std::cout << "pre-standard C++." << _MSVC_LANG;
					

					IntRateEngine<BondInstrument> engineA;
					IntRateEngine<MortgageInstrument> engineB;
					BondInstrument bond(40000, 250);
					MortgageInstrument mortgage(250, 50000, 5000);
					engineA.setInstrument(bond);
					engineB.setInstrument(mortgage);
					
					std::cout << " bond annual int rate: " << engineA.getAnnualIntRate() * 100 << "%" << std::endl;
					std::cout << " mortgage annual int rate: " << engineB.getAnnualIntRate() * 100 << "%" << std::endl;
				}
				void financialStatement()
				{
					std::unique_ptr<FinancialStatement> fs = getSampleStatement();
					transferFinancialStatement(fs);
					//transferFinancialStatement();
					// the unique_ptr object is invalid here, the next access can crash the
					//std::cout << fs->getReturn() << "\n";

				}
				void transactionHandler()
				{
					//use shared ptr if dealing if std stl 
					//dont throw exeption using the new keyword by value instead 
					std::string fileName = "";
					try
					{
						std::cout << "hello" << std::endl;
						TransactionHandler handler(fileName);
					}
					catch (FileError& e)
					{
						std::cerr << "received a file error: " << e.what() << std::endl;
					}
					catch (TransactionTypeError& e)
					{
						std::cerr << "received a transaction error: " << e.what() << std::endl;
					}			
					catch (std::runtime_error& e)
					{
						std::cerr << "received a runtime_error error: " << e.what() << std::endl;
					}
					catch (...)
					{
						std::cerr << "received an unknown error\n";
					}

					std::cout << "world" << std::endl;
				}

			};
#pragma endregion programmingTechniques

#pragma region commonLibraries

			namespace cl
			{
				using namespace za::ma::cl;
				void timeSeriesTransformations()
				{

					TimeSeriesTransformations ts;
					std::vector<double> vals = { 7, 6.4, 2.16, 5, 3, 7 };
					ts.addValues(vals);
					ts.addValue(6.5);
					ts.reducePrices(0.5);
					std::cout << " price is " << ts.getFirstPriceLessThan(6.0) << std::endl;
				}
				void fileManager()
				{
					FileManager fm("/tmp/");
					std::vector<std::string> contents = fm.getDirectoryContents();
					std::cout << "entries: " << std::endl;
					for (std::string entry : contents)
					{
						std::cout << entry << std::endl;
					}
				}
				void dateHandle()
				{
					//Date myDate(2023, 12, 27);
					Date myDate(2015, 1, 3);
					//++myDate;
					auto dayOfWeek = myDate.getDayOfWeek();

					std::cout << " Day of week is "<< myDate.toStringDate(dayOfWeek) << std::endl;
					Date secondDate(2014, 12, 5);
					++secondDate; // test increment operator
					++secondDate;
					int interval = myDate.daysInterval(secondDate);
					std::cout << " interval is " << interval << " days" << std::endl;
				}

			};
#pragma endregion commonLibraries


#pragma region numericalClasses

			namespace nc
			{
				using namespace za::ma::nc;
				void factorialTemplate()
				{
					std::cout << "factorial(6) = " << Factorial<6>::result;
					std::cout << "\n choiceNumber(5,6) = " << ChoiceNumber<6, 2>::result;
					showFactorial();
				};
				void calmarRatio()
				{
					CalmarRatio<CalmarRatioPerc> ratio(0.110, 3.12);
					std::cout << "return: " << ratio.getReturn() << " drawdown: " << ratio.getDrawDown() << std::endl;

					CalmarRatio<CalmarRatioBPS> bpsRatio(480, 2.15);
					std::cout << "return: " << bpsRatio.getReturn() << " drawdown: " << bpsRatio.getDrawDown() << std::endl;
				}

				void distributionData()
				{
					DistributionData dData;
					auto gdata = dData.gaussianData(10, 5, 2);
					printData("gaussian data", gdata);
					auto edata = dData.exponentialData(10, 4);
					printData("exponential data", edata);
					auto kdata = dData.chiSquaredData(10, 5);
					printData("chi squared data", kdata);
					auto ldata = dData.logNormalData(10, 8, 2);
					printData("log normal data", ldata);
				}

			};
#pragma endregion numericalClasses

		}
	}

}
