#pragma once
#include "MAUtilities.h"


#pragma once
namespace za
{
	namespace ma
	{
		namespace eq
		{


#pragma region Example1
			/*
			* One of the most common strategies to analyze equity instruments such as stocks and ETFs is to use supply/demand methods 
			* that consider price and volume as the important variables to observe. 
			* Traders who use price/volume-based strategies call this set of methods technical analysis (TA). 
			* With TA, traders look at special price points that have been defined by previous price movements, such as support, resistance, trend lines,
			* and moving averages, with the objective of identifying pricing regions with a higher probability of profit.
			* For example, support and resistance values are typically used to determine price areas that are considered to be of importance for a given instrument. 
			* If a stock reaches a certain price when moving up and reverses course, the high price point is considered to be a resistance price. 
			* In the future, when the price again reaches the same area, traders will tend to sell around in the same region, creating an even stronger resistance point. 
			* Similarly, support prices are formed when traders buy the same stock or ETF in a well-known region.
			* A similar type of pattern occurs with moving averages. 
			* The moving average can be calculated using a simple average formula that is repeated for each new period. 
			* Given prices p1, p2, ..., pN, the general formula for a particular time period is given by
			* MA = (1/N) (p1 + p2 + ... + pN)
			* 
			* The exponential moving average (EMA) is different from the simple moving average because each new value is multiplied by a factor. 
			* This factor is used to give more weight to new values, as compared to older observations. 
			* As a result, the EMA is more responsive to changes in the observed values, and it can indicate new trends sooner and with better accuracy. 
			* This may be an advantage if you want to quickly spot changes in trend.
			* The main step of the EMA calculation is the addition of new values that are weighted by the multiplier. 
			* The default multiplier r for EMA computation is given by: 
			* rho = 2/(N + 1)

			*/
			class MACalculator 
			{
			public:
				MACalculator(int period);
				MACalculator(const MACalculator&);
				MACalculator& operator = (const MACalculator&);
				~MACalculator();
				void addPriceQuote(double close);
				std::vector<double> calculateMA();
				std::vector<double> calculateEMA();
			private:
				// number of periods used in the calculation
				int m_numPeriods;
				std::vector<double> m_prices;
			};

#pragma endregion Example1

#pragma region Example2
			/*
			* Volatility is also an important concept when comparing investment options. 
			* Forexample, an Internet stock will vary in price much more widely than a traditional food producer. 
			* Their volatility profiles will be completely different.
			* The first strategy is computing the range of values observed during that period. 
			* This is probably the simplest way to view volatility: calculate the highest and lowest observed values and return its difference.
			* The second strategy is calculating the average range for a given time period. 
			* For example, many investment strategies use the idea of looking at the past few days and taking an average of the observed ranges.
			* Finally, a more sophisticated way to gauge the variation of values for an equity instrument is to use the statistical definition of standard deviation.
			* 1/(N - 1)* sum(xi - u)^2
			* N is the number of data points (prices) and u is the average of these
			* 
			*/
			class VolatilityCalculator
			{
			public:
				VolatilityCalculator();
				~VolatilityCalculator();
				VolatilityCalculator(const VolatilityCalculator&);
				VolatilityCalculator& operator=(const VolatilityCalculator&);
				void addPrice(double price);
				double rangeVolatility();
				double stdDev();
				double mean();
				double avgDailyRange();
			private:
				std::vector<double> m_prices;
			};
#pragma endregion Example2

#pragma region Example3

			/*
			* TimeSeries represents the often-used concept of a set of numbers that apply to a certain quantity over a given period of time. 
			* This concept is commonly referred to as a time series. 
			* The TimeSeries class is responsible for calculating values that are specific to a single time series, such as the average, or the standard deviation.
			*/
			class TimeSeries
			{
			public:
				TimeSeries();
				TimeSeries(const TimeSeries&);
				TimeSeries& operator=(const TimeSeries&);
				~TimeSeries();
				void addValue(double val);
				double stdDev();
				double mean();
				size_t size();
				double elem(int i);
			private:
				std::vector<double> m_values;
			};

#pragma endregion Example3

#pragma region Example4
			/*
			* CorrelationCalculator is responsible for collecting data for the desired time series and computing the correlation using the formula
			* 1/(N - 1)*sum((xi - xavg)*(yi - yavg)/(xstd*ystd))
			* N is the number of observations, 
			* xi is the i-th observation of the first time-series, 
			* yi is the i-th observation of the second time-series, 
			* xavg and yavg are the mean(average) of the two sequences of prices, 
			* xstd is the standard deviation of the x values, and
			* ystd is the standard deviation of the y values.
			*/
			class CorrelationCalculator
			{
			public:
				CorrelationCalculator(TimeSeries& a, TimeSeries& b);
				~CorrelationCalculator();
				CorrelationCalculator(const CorrelationCalculator&);
				CorrelationCalculator& operator =(const CorrelationCalculator&);
				double correlation();
			private:
				TimeSeries& m_tsA;
				TimeSeries& m_tsB;
			};
#pragma endregion Example4

#pragma region Example5
			/*
			* Fundamental indicators are one of the most common ways of analyzing the quality of a stock. 
			For example, earnings per share are a fundamental indicator that tells how much profit is being generated per period 
			* (usually a quarter or a year) for each share of the stock.
			*/


			/*
			* Price-earnings ratio (P/E): This is calculated as the price of the total stock of the company divided by the earnings as published in 
			* the last-quarter earnings release. 
			* This ratio can be interpreted as a measure of the cost of the company stock as compared to other companies with similar earnings.
			*/

			/*
			* Book value: The book value corresponds to the amount of assets currently on the company balance sheet. 
			* This is in essence an accounting measure of the value of the company, without considering market factors such as future earnings, for example.
			*/
			
			/*
			* Price-to-book ratio (P/B): This ratio is determined by dividing the stock price by the assets minus liabilities. 
			* The following accounting formula can be used:
			* StockPrice/(Assets − Liablities and IntangibleAssets)
			* Notice that only tangible assets, the ones that can be eventually sold, are considered in this equation.
			*/
						
			/*
			* Price-earnings to growth (PEG): This indicator can be used to compare companies with similar P/E but different growth rates.
			* The formula to calculate this value is simply
			* (P/E)/(EPS annual growth)
			*/
									
			/*
			* Earnings before interest, taxes, depreciation, and amortization
			* (EBITDA): This is a measure that can be used to determine how a company is making a profit, and it is based on accounting information 
			* provided by the company in every earnings release.
			* The value simply represents how much profit the company made before items such as taxes and related expenses were paid.
			*/	

			/*
			* Return on equity (ROE): This ratio is used to determine the percentage of net income generated based on shareholders’equity. 
			* Investors are usually interested in companies able to generate higher income on the same amount of equity. 
			* The value is simply calculated as
			* NetIncome/ShareholdersEquity
			*/

			/*
			* Forward P/E: This number is similar to the P/E ratio, but instead of being calculated based on existing revenue data, it is a
			* prediction for the next quarter made by analysts. 
			* When compared to P/E, this number can be used to determine if analysts expect
			* the revenue to increase, decrease, or stay at the same levels.
			*/


			class FundamentalsCalculator {
			public:
				FundamentalsCalculator(const std::string& ticker, double price, double
					dividend);
				~FundamentalsCalculator();
				FundamentalsCalculator(const FundamentalsCalculator&);
				FundamentalsCalculator& operator=(const FundamentalsCalculator&);
				void setNumOfShares(int n);
				void setEarnings(double val);
				void setExpectedEarnings(double val);
				void setBookValue(double val);
				void setAssets(double val);
				void setLiabilitiesAndIntangibles(double val);
				void setEpsGrowth(double val);
				void setNetIncome(double val);
				void setShareHoldersEquity(double val);
				double PE();
				double forwardPE();
				double bookValue();
				double priceToBookRatio();
				double priceEarningsToGrowth();
				double returnOnEquity();
				double getDividend();
			private:
				std::string m_ticker;
				double m_price;
				double m_dividend;
				double m_earningsEstimate;
				int m_numShares;
				double m_earnings;
				double m_bookValue;
				double m_assets;
				double m_liabilitiesAndIntangibles;
				double m_epsGrowth;
				double m_netIncome;
				double m_shareholdersEquity;
			};
#pragma endregion Example5

#pragma region Example6


#pragma endregion Example6

		}
	}
}