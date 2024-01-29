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
					std::vector<double> value = { 200, 300, 500, -1000 };


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
					std::cout << "reading information for bond issued by " << issuer << std::endl;
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

					std::vector<double> price = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7 };

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

					std::cout << " Day of week is " << myDate.toStringDate(dayOfWeek) << std::endl;
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

#pragma region linearAgebra



			//namespace la
			//{
			//	//using namespace za::ma::la;
			//	//void matrixOperations()
			//	//{
			//	//	//MatrixOperations op;
			//	//	//for (int i = 0; i < 5; ++i)
			//	//	//{
			//	//	//	std::vector<double> row;
			//	//	//	for (int j = 0; j < 5; ++j)
			//	//	//	{
			//	//	//		row.push_back(std::sin((double)j + i));
			//	//	//	}
			//	//	//	op.addRow(row);
			//	//	//}
			//	//	//op.transpose();
			//	//	//Matrix res = op.scalarMultiply(12);
			//	//}

			//};



#pragma endregion linearAgebra


#pragma region interpolation

			namespace it
			{
				using namespace za::ma::it;
				void linearInterpolation()
				{
					double xi = 0;
					double yi = 0;
					std::vector<double> xvals = { 10,  20, 30, 40, 49 };
					std::vector<double> yvals = { 0.6, 0.11, 1.1 , 1.62, 1.4 };
		
					double x = 27;

					LinearInterpolation li;
					li.setPoints(xvals, yvals);
					double y = li.getValue(x);
					std::cout << "interpolation result for value " << x << " is " << y << std::endl;
				}				
				
				void polynomialInterpolation()
				{
					double xi = 0;
					double yi = 0;
					std::vector<double> xvals = { 10,  20, 30, 40, 49 };
					std::vector<double> yvals = { 0.6, 0.11, 1.1 , 1.62, 1.4 };
		
					double x = 27;

					PolynomialInterpolation pi;
					pi.setPoints(xvals, yvals);
					double y = pi.getPolynomial(x);
					std::cout << "interpolation result for value " << x << " is " << y << std::endl;
				}
			}
#pragma endregion interpolation

#pragma region root

			namespace re
			{
				using namespace za::ma::re;
				void bisectionMethod()
				{
					//MathFunction m;
					F1 f;
					BisectionMethod bm(f);
					std::cout << " the root of the function is " << bm.getRoot(-100, 100) << std::endl;
				}
								
				void secantMethod()
				{
					//MathFunction m;
					F1 f;
					SecantMethod sm(f);
					std::cout << " the root of the function is " << sm.getRoot(-10, 10) << std::endl;
				}								
				void newtonMethod()
				{
					//MathFunction m;
					F1 f;
					DF1 df;
					NewtonMethod nm(f, df);
					std::cout << " the root of the function is " << nm.getRoot(100) << std::endl;
				}

			};
#pragma endregion root
#pragma region numericalIntegration

			namespace ni
			{
				using namespace za::ma::ni;
				void midpointIntegration()
				{
					F2 f;
					MidpointIntegration mpi(f);
					double integral = mpi.getIntegral(1, 5);
					std::cout << " the integral of the function is " << integral << std::endl;
					mpi.setNumIntervals(200);
					integral = mpi.getIntegral(1, 5);
					std::cout << " the integral of the function with 200 intervals is " << integral << std::endl;

				}
				void trapezoidIntegration()
				{
					F3 f;
					TrapezoidIntegration ti(f);
					double integral = ti.getIntegral(0.5, 2.5);
					std::cout << " the integral of the function is " << integral << std::endl;
					ti.setNumIntervals(200);
					integral = ti.getIntegral(0.5, 2.5);
					std::cout << " the integral of the function with 200 intervals is " << integral << std::endl;

				}				
				
				void simpsonsIntegration()
				{
					F3 f;
					SimpsonsIntegration si(f);
					double integral = si.getIntegral(0.5, 2.5);
					std::cout << " the integral of the function is " << integral << std::endl;
					si.setNumIntervals(200);
					integral = si.getIntegral(0.5, 2.5);
					std::cout << " the integral of the function with 200 intervals is " << integral << std::endl;

				}
			}

#pragma endregion numericalIntegration

#pragma region OdePde

			namespace od
			{
				using namespace za::ma::od;
				void eulersMethod()
				{
					F4 f;
					EulersMethod m(f);
					double res = m.solve(100, 0, 0.25, 2);
					std::cout << " result is " << res << std::endl;
				}				
				void rungeKuttaODEMethod()
				{
					F4 f;
					RungeKuttaODEMethod m(f);
					double res = m.solve(100, 0, 0.25, 2);
					std::cout << " result is " << res << std::endl;
				}				
				void blackScholesForwardMethod()
				{
					auto strike = 5.0;
					auto intRate = 0.03;
					auto sigma = 0.50;

					auto t1 = 1.0;
					auto numSteps = 11;
					auto numDays = 29;
					auto maxPrice = 10.0;
					BlackScholesForwardMethod bsfm(t1, maxPrice, strike, intRate);
					std::vector<double> u = bsfm.solve(sigma, numSteps, numDays);
					double minPrice = .0;
					for (int i = 0; i < numSteps - 1; i++)
					{
						double s = ((numSteps - i - 2) * minPrice + (i + 1) * maxPrice) / (double)(numSteps - 1);
						std::cout << " " << s << " " << u[i + numDays * (numSteps - 1)] << std::endl;
					}
				}
								
				void blackScholescloseForm()
				{
					// first create parameter list 
					double s = 100.0; // Option price
					double k = 100.0; // Strike price
					double r = 0.05; // Risk-free rate (5%)
					double v = 0.2; // volatility of the underlying (20%)
					double t = 1.0; // One year untill expiry 
					double call = callPriceCloseForm(s, k, r, v, t);
					double put = putPriceCloseForm(s, k, r, v, t);
					// Fi n a l l y we output the parameters and p r i c e s
					std::cout << "Underlying : " << s << std::endl;
					std::cout << " Strike : " << k << std::endl;
					std::cout << "Risk-Free Rate : " << r << std::endl;
					std::cout << " Volatility : " << v << std::endl;
					std::cout << "Maturity : " << t << std::endl;
					std::cout << "Call Price : " << call << std::endl;
					std::cout << "Put Price : " << put << std::endl;
				}				
				
				void blackScholesMonteCarlo()
				{
					// first create parameter list 
					int numSims = 10000000; // Number of s imulat ed a s s e t paths
					double s = 100.0; // Option price
					double k = 100.0; // Strike price
					double r = 0.05; // Risk-free rate (5%)
					double v = 0.2; // volatility of the underlying (20%)
					double t = 1.0; // One year untill expiry 
					// Then we calculate the call/put values 
					double call = callPriceMonteCarlo(numSims, s, k, r, v, t);
					double put = putPriceMonteCarlo(numSims, s, k, r, v, t);
					// Finally we output the parameters and prices 
					std::cout << "Underlying : " << s << std::endl;
					std::cout << " Strike : " << k << std::endl;
					std::cout << "Risk-Free Rate : " << r << std::endl;
					std::cout << " Volatility : " << v << std::endl;
					std::cout << "Maturity : " << t << std::endl;
					std::cout << "Call Price : " << call << std::endl;
					std::cout << "Put Price : " << put << std::endl;
				}
				
				void blackScholesGreeksCloseForm()
				{
						// first create parameter list 
						double s = 100.0; // Option price
						double k = 100.0; // Strike price
						double r = 0.05; // Risk-free rate (5%)
						double v = 0.2; // volatility of the underlying (20%)
						double t = 1.0; // One year untill expiry 
						// Then we calculate the call/put values  and greeks 
						double callVal = callPriceCloseForm(s, k, r, v, t);
						double callDeltaVal = callDeltaCloseForm(s, k, r, v, t);
						double callGammaVal = callGammaCloseForm(s, k, r, v, t);
						double callVegaVal = callVegaCloseForm(s, k, r, v, t);
						double callThetaVal = callThetaCloseForm(s, k, r, v, t);
						double callRhoVal = callRhoCloseForm(s, k, r, v, t);
						
						double putVal = putPriceCloseForm(s, k, r, v, t);
						double putDeltaVal = putDeltaCloseForm(s, k, r, v, t);
						double putGammaVal = putGammaCloseForm(s, k, r, v, t);
						double putVegaVal = putVegaCloseForm(s, k, r, v, t);
						double putThetaVal = putThetaCloseForm(s, k, r, v, t);
						double putRhoVal = putRhoCloseForm(s, k, r, v, t);

						//double put = monteCarloPutPrice(numSims, s, k, r, v, t);
						// Finally we output the parameters and prices 
						std::cout << "Underlying : " << s << std::endl;
						std::cout << " Strike : " << k << std::endl;
						std::cout << "Risk-Free Rate : " << r << std::endl;
						std::cout << " Volatility : " << v << std::endl;
						std::cout << "Maturity : " << t << std::endl;


						std::cout << "Call Price : " << callVal << std::endl;
						std::cout << "Call Delta : " << callDeltaVal << std::endl;
						std::cout << "Call Gamma : " << callGammaVal << std::endl;
						std::cout << "Call Vega : " << callVegaVal << std::endl;
						std::cout << "Call Theta : " << callThetaVal << std::endl;
						std::cout << "Call Rho : " << callRhoVal << std::endl;

						std::cout << "Put Price : " << putVal << std::endl;
						std::cout << "Put Delta : " << putDeltaVal << std::endl;
						std::cout << "Put Gamma : " << putGammaVal << std::endl;
						std::cout << "Put Vega : " << putVegaVal << std::endl;
						std::cout << "Put Theta : " << putThetaVal << std::endl;
						std::cout << "Put Rho : " << putRhoVal << std::endl;
				}	

				void blackScholesGreeksFiniteDifferenceMethod()
				{
					// first create parameter list 
					double s = 100.0; // Option price
					double deltaS = 0.001;
					double k = 100.0; // Strike price
					double r = 0.05; // Risk-free rate (5%)
					double v = 0.2; // volatility of the underlying (20%)
					double t = 1.0; // One year untill expiry 
					double callDeltaVal = callDeltaFDM(s, k, r, v, t, deltaS);
					double callGammaVal = callGammaFDM(s, k, r, v, t, deltaS);
					//double put = monteCarloPutPrice(numSims, s, k, r, v, t);
										// Finally we output the parameters and prices 
					std::cout << "Underlying : " << s << std::endl;
					std::cout << "Delta Underlying : " << deltaS << std::endl;
					std::cout << " Strike : " << k << std::endl;
					std::cout << "Risk-Free Rate : " << r << std::endl;
					std::cout << " Volatility : " << v << std::endl;
					std::cout << "Maturity : " << t << std::endl;


					std::cout << "Call Delta : " << callDeltaVal << std::endl;
					std::cout << "Call Gamma : " << callGammaVal << std::endl;

				}

				void blackScholesGreeksMonteCarloFDM()
				{
					// first create parameter list 
					double s = 100.0; // Option price
					double deltaS = 0.001;
					double k = 100.0; // Strike price
					double r = 0.05; // Risk-free rate (5%)
					double v = 0.2; // volatility of the underlying (20%)
					double t = 1.0; // One year untill expiry 
					int numSim = 100000000;
					double callDeltaVal = callDeltaMonteCarloFDM(numSim, s, k, r, v, t, deltaS);
					double callGammaVal = callGammaMonteCarloFDM(numSim, s, k, r, v, t, deltaS);
					//double put = monteCarloPutPrice(numSims, s, k, r, v, t);
										// Finally we output the parameters and prices 
					std::cout << "Underlying : " << s << std::endl;
					std::cout << "Delta Underlying : " << deltaS << std::endl;
					std::cout << " Strike : " << k << std::endl;
					std::cout << "Risk-Free Rate : " << r << std::endl;
					std::cout << " Volatility : " << v << std::endl;
					std::cout << "Maturity : " << t << std::endl;


					std::cout << "Call Delta : " << callDeltaVal << std::endl;
					std::cout << "Call Gamma : " << callGammaVal << std::endl;

				}
					
			}

#pragma endregion OdePde
#pragma region Optimization

			namespace op
			{
				using namespace za::ma::op;

				//move to common functions 
				void lpSolver()
				{
					za::ma::com::Matrix A(3);
					A[0][0] = 1; A[0][1] = 1; A[0][2] = 1;
					A[1][0] = 10; A[1][1] = 2; A[1][2] = 4;
					A[2][0] = 2; A[2][1] = 5; A[2][2] = 6;

					std::vector<double> c = { 10, 6, 4 };
					std::vector<double> b = { 100, 600, 300 };
					za::ma::com::LPSolver solver(A, b, c);
					solver.setMaximization();
					std::vector<double> results;
					double objVal;
					solver.solve(results, objVal);
					for (int i = 0; i < results.size(); ++i)
					{
						std::cout << " x" << i << ": " << results[i];
					}
					std::cout << " max: " << objVal << std::endl;
				}


				void twoDimensionalLPSolver()
				{
					std::vector<double> A1 = { -2.1, 3.1, 7.9 };
					std::vector<double> A2 = { 1, 1, 1 };
					std::vector<double> c = { 5.3, 7.1 };
					std::vector<double> b = { 3.4, 4.3, 6 };
					TwoDimensionalLPSolver solver(c, A1, A2, b);
					std::vector<double> results;
					double objVal;
					solver.solveProblem(results, objVal);
					std::cout << "objVal : " << objVal << std::endl;
					for (int i = 0; i < results.size(); ++i)
					{
						std::cout << " x" << i << ": " << results[i];
					}
					std::cout << std::endl;
				}

				void mipSolver()
				{

					za::ma::com::Matrix A(2, 2);
					std::vector<double> b = { 2, 3 };
					std::vector<double> c = { 1, 1 };
					A[0][0] = 1;
					A[0][1] = 2;
					A[1][0] = 3;
					A[1][1] = 4;
					za::ma::com::MIPSolver solver(A, b, c);
					solver.setMaximization();
					solver.setColInteger(0);

					std::vector<double> result;
					double objVal;
					solver.solve(result, objVal);
					std::cout << "optimum: " << objVal << std::endl;
					std::cout << " x0: " << result[0] << " x1: " << result[1] << std::endl;
				}
			}

#pragma endregion Optimization

#pragma region assetPortfolio

			namespace ap
			{
				using namespace za::ma::ap;


				void resourceAlloc()
				{
					std::vector<double> result;
					double objVal;
					ResourceAlloc ra(result, objVal);
					ra.solveProblem();
					std::cout << " optimum: " << objVal;

					for (int i = 0; i < result.size(); ++i)
					{
						std::cout << " x" << i << ": " << result[i];
					}
					std::cout << std::endl;
				}

				void modifiedCAP()
				{
					// sample problem: 4 assets and 5 periods
					// build the expected return matrix
					double val[][5] = {
					{0.051, 0.050, 0.049, 0.051, 0.05},
					{0.10, 0.099, 0.102, 0.100, 0.101},
					{0.073, 0.077, 0.076, 0.075, 0.076},
					{0.061, 0.06, 0.059, 0.061, 0.062},
					};
					za::ma::com::Matrix retMatrix(4, 5);
					for (int i = 0; i < 4; ++i)
					{
						for (int j = 0; j < 5; ++j)
						{
							retMatrix[i][j] = val[i][j];
						}
					}

					std::vector<double> assetReturns = { 0.05, 0.10, 0.075, 0.06 };
					ModifiedCAP mc(4, 5, 0.08, retMatrix, assetReturns);
					std::vector<double> results;
					double objVal;
					//use one of the solver 
					//mc.solveModel(results, objVal);
					mc.solveExtendedModel(results, objVal);
					std::cout << "obj value: " << objVal / 5 << std::endl;
					for (int i = 0; i < results.size(); ++i)
					{
						std::cout << " x" << i << ": " << results[i];
					}
					std::cout << std::endl;

				}
			

			}

#pragma endregion assetPortfolio

#pragma region monteCarlo

			namespace mc
			{
				using namespace za::ma::mc;


				void monteCarloIntegration()
				{
					std::cout << "starting" << std::endl;
					FSin f;
					MonteCarloIntegration mci(f);
					double integral = mci.getIntegral(0.5, 4.9);

					std::cout << " the integral of the function is " << integral << std::endl;
					mci.setNumSamples(200000);
					integral = mci.getIntegral(0.5, 4.9);
					std::cout << " the integral of the function with 20000 intervals is " << integral << std::endl;
				}


				void randomWalk()
				{
					RandomWalk rw(100, 30, 0.01);
					std::vector<double> walk = rw.getWalk();
					for (int i = 0; i < walk.size(); ++i)
					{
						std::cout << ", " << i << ", " << walk[i];
					}
					std::cout << std::endl;
				}

				void optionsProbabilities()
				{
					OptionsProbabilities optP(30, 35, 0.01, 100);
					std::cout << " above strike prob: " << optP.probFinishAboveStrike() << std::endl;
					std::cout << " below strike prob: " << optP.probFinishBelowStrike() << std::endl;
					std::cout << " between 28 and 32 prob: " << optP.probFinalPriceBetweenPrices(28, 32) << std::endl;
				}


				//void closeFormBlackHole()
				//{
				//	// first create parameter list 
				//	double s = 100.0; // Option price
				//	double k = 100.0; // Strike price
				//	double r = 0.05; // Risk-free rate (5%)
				//	double v = 0.2; // volatility of the underlying (20%)
				//	double t = 1.0; // One year untill expiry 
				//	double call = closeFormCallPrice(s, k, r, v, t);
				//	double put = closeFormPutPrice(s, k, r, v, t);
				//	// Fi n a l l y we output the parameters and p r i c e s
				//	std::cout << "Underlying : " << s << std::endl;
				//	std::cout << " Strike : " << k << std::endl;
				//	std::cout << "Risk-Free Rate : " << r << std::endl;
				//	std::cout << " Volatility : " << v << std::endl;
				//	std::cout << "Maturity : " << t << std::endl;
				//	std::cout << "Call Price : " << call << std::endl;
				//	std::cout << "Put Price : " << put << std::endl;
				//}
				//
				//
				//void monteCarloBlackHole()
				//{
				//	// first create parameter list 
				//	int numSims = 10000000; // Number of s imulat ed a s s e t paths
				//	double s = 100.0; // Option price
				//	double k = 100.0; // Strike price
				//	double r = 0.05; // Risk-free rate (5%)
				//	double v = 0.2; // volatility of the underlying (20%)
				//	double t = 1.0; // One year untill expiry 
				//	// Then we calculate the call/put values 
				//	double call = monteCarloCallPrice(numSims, s, k, r, v, t);
				//	double put = monteCarloPutPrice(numSims, s, k, r, v, t);
				//	// Finally we output the parameters and prices 
				//	std::cout << "Underlying : " << s << std::endl;
				//	std::cout << " Strike : " << k << std::endl;
				//	std::cout << "Risk-Free Rate : " << r << std::endl;
				//	std::cout << " Volatility : " << v << std::endl;
				//	std::cout << "Maturity : " << t << std::endl;
				//	std::cout << "Call Price : " << call << std::endl;
				//	std::cout << "Put Price : " << put << std::endl;
				//}		


				//void calcGreeks()
				//{
				//	// first create parameter list 
				//	double s = 100.0; // Option price
				//	double k = 100.0; // Strike price
				//	double r = 0.05; // Risk-free rate (5%)
				//	double v = 0.2; // volatility of the underlying (20%)
				//	double t = 1.0; // One year untill expiry 
				//	// Then we calculate the call/put values  and greeks 
				//	double callVal = closeFormCallPrice(s, k, r, v, t);
				//	double callDeltaVal = callDelta(s, k, r, v, t);
				//	double callGammaVal = callGamma(s, k, r, v, t);
				//	double callVegaVal = callVega(s, k, r, v, t);
				//	double callThetaVal = callTheta(s, k, r, v, t);
				//	double callRhoVal = callRho(s, k, r, v, t);					
				//	
				//	double putVal = closeFormPutPrice(s, k, r, v, t);
				//	double putDeltaVal = putDelta(s, k, r, v, t);
				//	double putGammaVal = putGamma(s, k, r, v, t);
				//	double putVegaVal = putVega(s, k, r, v, t);
				//	double putThetaVal = putTheta(s, k, r, v, t);
				//	double putRhoVal = putRho(s, k, r, v, t);
		
				//	//double put = monteCarloPutPrice(numSims, s, k, r, v, t);
				//	// Finally we output the parameters and prices 
				//	std::cout << "Underlying : " << s << std::endl;
				//	std::cout << " Strike : " << k << std::endl;
				//	std::cout << "Risk-Free Rate : " << r << std::endl;
				//	std::cout << " Volatility : " << v << std::endl;
				//	std::cout << "Maturity : " << t << std::endl;


				//	std::cout << "Call Price : " << callVal << std::endl;
				//	std::cout << "Call Delta : " << callDeltaVal << std::endl;
				//	std::cout << "Call Gamma : " << callGammaVal << std::endl;
				//	std::cout << "Call Vega : " << callVegaVal << std::endl;
				//	std::cout << "Call Theta : " << callThetaVal << std::endl;
				//	std::cout << "Call Rho : " << callRhoVal << std::endl;

				//	std::cout << "Put Price : " << putVal << std::endl;
				//	std::cout << "Put Delta : " << putDeltaVal << std::endl;
				//	std::cout << "Put Gamma : " << putGammaVal << std::endl;
				//	std::cout << "Put Vega : " << putVegaVal << std::endl;
				//	std::cout << "Put Theta : " << putThetaVal << std::endl;
				//	std::cout << "Put Rho : " << putRhoVal << std::endl;
				//	
				//}


			}

#pragma endregion monteCarlo
#pragma region mutltithreading

			namespace mt
			{
				using namespace za::ma::mt;
				void testThread()
				{
					ParallelOptionsProbabilities rw(100, 50.0, 52.0);
					double r = rw.probFinishAboveStrike();
					std:: cout << " result is " << r << std::endl;
				}							
				void parallelRandomWalk()
				{
					ParallelOptionsProbabilities rw(100, 50.0, 52.0);
					double r = rw.probFinishAboveStrike();
					std::cout << " result is " << r << std::endl;
				}				
				void mutexTestThread()
				{
					int nThreads = 10;
					std::vector<Thread*> threads(nThreads);
					double price = rand() % 25;
					for (int i = 0; i < nThreads; ++i)
					{
						threads[i] = new MutexTestThread(price, (double)(rand() % 10));
						threads[i]->setJoinable(true);
						threads[i]->start();
					}
					for (int i = 0; i < nThreads; ++i)
					{
						threads[i]->join();
					}
					std::cout << " final price is " << price << std::endl;
				}

			}

#pragma endregion mutltithreading

#pragma region functionObject

			namespace fo
			{
				using namespace za::ma::fo;
				void functionPointer()
				{
					double a = 5.0;
					double b = 10.0;
					std::cout << "Add : " << binaryOp1(a, b, addOp) << std::endl;
					std::cout << "Multiply: " << binaryOp1(a, b, multiplyOp) << std::endl;
				}

				void functionObject()
				{
					double a = 5.0;
					double b = 10.0;
					BinaryFunctionOp* pAdd = new AddOp();
					BinaryFunctionOp* pMultiply = new MultiplyOp();
					std::cout << "Add : " << binaryOp2(a, b, pAdd) << std::endl;
					std::cout << "Multiply: " << binaryOp2(a, b, pMultiply) << std::endl;
					delete pAdd;
					delete pMultiply;
				}

			}

#pragma endregion functionObject

#pragma region eigenLib

			namespace eg
			{
				using namespace za::ma::eg;
				void basicUsage()
				{
					Eigen::MatrixXd m(3, 3);
					m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
					std::cout << m << std::endl;
				}


				void basicLinearAlgebra1()
				{
					///*
					//* Expression Templates
					//*/
					////lazy evaluation 
					//Eigen::VectorXd p(10), q(10), r(10), s(10);
					////compute p = 5*q + 11*r - 7*s
					//for (unsigned i = 0; i < 10; i++)
					//{
					//	p[i] = 5 * q[i] + 11 * r[i] - 7 * s[i];
					//}

				}
				void basicLinearAlgebra2()
				{
					/*
					* Matrix and Scalar Arithmetic
					*/
					//Define two matrices, both 3 by 3 
					Eigen::Matrix3d p;
					Eigen::Matrix3d q;
					//Define two three-dimensional vectors 
					//The constructor provides initialisation
					Eigen::Vector3d r(1, 2, 3);
					Eigen::Vector3d s(4, 5, 6);

					p << 1, 2, 3,
						4, 5, 6,
						7, 8, 9;

					q << 10, 11, 12,
						13, 14, 15,
						16, 17, 18;

					//Arithmetic operations for matrices
					std::cout << "p + q = \n" << p + q << std::endl;
					std::cout << "p - q = \n" << p - q << std::endl;


					//Arithmetic operations for vectors
					std::cout << "r + s = \n" << r + s << std::endl;
					std::cout << "r - s = \n" << r - s << std::endl;
				}
				void basicLinearAlgebra3()
				{

					/*
					* Scalar Multiplication and division
					*/
					//Define a 3 by 3 matrix and initialise 
					Eigen::Matrix3d pp;
					pp << 1, 2, 3,
						4, 5, 6,
						7, 8, 9;

					std::cout << "pp * 3.14159 = \n" << pp * 3.14159 << std::endl;
					std::cout << "pp / 2.71828 = \n" << pp / 2.71828 << std::endl;
				}
				void basicLinearAlgebra4()
				{
					/*
					* Matrix transpose
					*/
					//Declare a 3 by 3 matrix with random entries 
					Eigen::Matrix3d p = Eigen::Matrix3d::Random(3, 3);
					std::cout << "p^T = \n" << p.transpose() << std::endl;
					//in place transpose of p
					p.transposeInPlace();
					std::cout << "p^T = \n" << p << std::endl;
				}

				void basicLinearAlgebra5()
				{
					/*
					* Matrix/Matrix and Matrix/Vector Multiplication
					*/
					//Define a 3 by 3 matrix and two 3- dimensional vector
					Eigen::Matrix3d p;

					p << 1, 2, 3,
						4, 5, 6,
						7, 8, 9;

					Eigen::Vector3d r(10, 11, 12);
					Eigen::Vector3d s(13, 14, 15);

					//Matrix/Matrix multiplication 
					std::cout << "p * p:\n" << p * p << std::endl;


					//Matrix/vector multiplication 
					std::cout << "p * r\n" << p * r << std::endl;
					std::cout << "r^T * p\n" << r.transpose() * p << std::endl;

					//Vector/vector multiplication(inner product)
					std::cout << "r^T * s:\n" << r.transpose() * s << std::endl;
				}
				void basicLinearAlgebra6()
				{
					/*
					* vector operations: dot and cross products
					*/
					//Declare and initialise two 3D vectors 
					Eigen::Vector3d r(10, 20, 30);
					Eigen::Vector3d s(40, 50, 60);

					std::cout << "r . s =\n" << r.dot(s) << std::endl;
					std::cout << "r x s =\n" << r.cross(s) << std::endl;

				}
				void basicLinearAlgebra7()
				{
					/*
					* Reduction
					*/
					Eigen::Matrix3d p;
					p << 1, 2, 3,
						 4, 5, 6,
						 7, 8, 9;

					std::cout << "p.sum() " << p.sum() << std::endl;
					std::cout << "p.prod() " << p.prod() << std::endl;
					std::cout << "p.mean() " << p.mean() << std::endl;
					std::cout << "p.minCoeff() " << p.minCoeff() << std::endl;
					std::cout << "p.maxCoeff() " << p.maxCoeff() << std::endl;
					std::cout << "p.trace() " << p.trace() << std::endl;

				}


				void advancedLinearAlgebra1()
				{
					typedef Eigen::Matrix<double, 4, 4> Matrix4x4;
					Matrix4x4 p;

					p << 7, 3, -1, 2,
						 3, 8, 1, -4,
						-1, 1, 4, -1,
						 2, -4, -1, 6;

					std::cout << "Matrix p: \n" << p << std::endl << std::endl;
					//LU Decomposition template object for p 
					Eigen::PartialPivLU<Matrix4x4> lu(p);
					std::cout << "LU matrix: \n" << lu.matrixLU() << std::endl << std::endl;

					//L, the lower triangular matrix 
					Matrix4x4 l = Eigen::MatrixXd::Identity(4, 4);
					l.block<4, 4>(0, 0).triangularView < Eigen::StrictlyLower>() = lu.matrixLU();
					std::cout << "l matrix: \n" << l << std::endl << std::endl;
					//U, the upper triangular matrix 
					Matrix4x4 u = lu.matrixLU().triangularView < Eigen::Upper>();
					std::cout << "u matrix: \n" << u << std::endl << std::endl;

				

				}
				void advancedLinearAlgebra2()
				{
					/*
					* This function uses a tridiagonal system from a Boundary Value Problem (BVP)
					* This is the discretisation of the 1D heat equation
					*/

					//create a Finite Difference Method(FDM) mesh with 13 points 
					//using the Crank-Nicolson method to solve the discretised heat equation 
					size_t N = 13;

					double deltaX = 1.0 / static_cast<double>(N);

					double deltaT = .001;
					double r = deltaT / (deltaX * deltaX);

					//std::vector<double> a(N - 1, -r / 2.0);
					std::vector<double> a(N, -r / 2.0);
					std::vector<double> b(N, 1.0 + r);
					std::vector<double> c(N, -r / 2.0);
					//std::vector<double> c(N - 1, -r / 2.0);
					std::vector<double> d(N, 0.0);
					std::vector<double> f(N, 0.0);

					//Fill in the current time step initial value 
				    //vector using three peaks with various amplitude 
					f[5] = 1;
					f[6] = 2;
					f[7] = 1;

					//f prior to a new time step 
					std::cout << "f = (";

					for (int i = 0; i < N; i++)
					{
						std::cout << f[i];
						if (i < N - 1)
						{
							std::cout << ", ";
						}
					}

					std::cout << ")" << std::endl << std::endl;
					//Fill in the current time vector step vector d 
					for (int i = 1; i < N - 1; i++)
					{
						d[i] = r * 0.5 * f[i + 1] + (1.0 - r) * f[i] + r * 0.5 * f[i - 1];
					}
					//now we solve the tridiagonal system
					thomasAlgorithm(a, b, c, d, f);
					//solution vector f 
					std::cout << "f = (";

					for (int i = 0; i < N; i++)
					{
						std::cout << f[i];
						if (i < N - 1)
						{
							std::cout << ", ";
						}
					}
					std::cout << ")" << std::endl << std::endl;

				}
				void advancedLinearAlgebra3()
				{
					/*
					* Cholesky Decomposition
					*/
					typedef Eigen::Matrix<double, 4, 4> Matrix4x4;
					
					//Declare a 4 by 4 matrix with defined entries 
					Matrix4x4 p;

					p << 6, 3, 4, 8,
						3, 6, 5, 1,
						4, 5, 10, 7,
						8, 1, 7, 25;
					std::cout << "Matrix p: \n" << p << std::endl << std::endl;

					//create L and L^T matrices (LLT)
					Eigen::LLT<Matrix4x4> llt(p);

					//lower triangular matrix 
					Matrix4x4 l = llt.matrixL();
					std::cout << "L matrix: \n" << l << std::endl << std::endl;
					//l^T the upper triangular conjugate of L
					Matrix4x4 u = l.transpose();
					std::cout << "L^T matrix: \n" << u << std::endl << std::endl;
					//check that LL^T = P
					std::cout << "LL^T matrix: \n" << l * u << std::endl << std::endl;



				}
				void advancedLinearAlgebra4()
				{
					/*
					* QR Decomposition
					* Householder Reections method below.
					*/

					//Declare a 3 by 3 matrix with defined entries 
					Eigen::MatrixXf p(3, 3);
					p << 12, -51, 4,
						6, 167, -68,
						-4, 24, -41;

					std::cout << "Matrix p: \n" << p << std::endl << std::endl;

					//create the householder QR matrix object 
					Eigen::HouseholderQR<Eigen::MatrixXf> qr(p);
					Eigen::MatrixXf q = qr.householderQ();
					std::cout << " Q matrix: \n" << q << std::endl << std::endl;;


				}

			}

#pragma endregion eigenLib

		}
	}

}
