#include "MAEquities.h"


#pragma once
namespace za
{
	namespace ma
	{
		namespace eq
		{


#pragma region Example1
			MACalculator::MACalculator(int numPeriods)
				: m_numPeriods(numPeriods)
			{
			}
			MACalculator::~MACalculator()
			{
			}
			MACalculator::MACalculator(const MACalculator& ma)
				: m_numPeriods(ma.m_numPeriods)
			{
			}
			MACalculator& MACalculator::operator = (const MACalculator& ma)
			{
				if (this != &ma)
				{
					m_numPeriods = ma.m_numPeriods;
					m_prices = ma.m_prices;
				}
				return *this;
			}
			std::vector<double> MACalculator::calculateMA()
			{
				std::vector<double> ma;
				double sum = 0;
				for (int i = 0; i < m_prices.size(); ++i)
				{
					//adding the head including its contribution to the  current cumulative average 
					sum += m_prices[i];
					//index starts  at 0, count should have exactly the period time inside for the average 
					//if (i >= m_numPeriods)
					if (i >= m_numPeriods - 1 )
					{
						ma.push_back(sum / m_numPeriods);
						//removing the tail excluding  its contribution to the  next umulative average 
						//sum -= m_prices[i - m_numPeriods];
						sum -= m_prices[i - m_numPeriods + 1];
					}
				}
				return ma;
			}
			std::vector<double> MACalculator::calculateEMA()
			{
				std::vector<double> ema;
				double sum = 0;
				double multiplier = 2.0 / (m_numPeriods + 1);
				for (int i = 0; i < m_prices.size(); ++i)
				{
					sum += m_prices[i];
					//if (i == m_numPeriods)
					if (i == m_numPeriods - 1)
					{
						ema.push_back(sum / m_numPeriods);
						sum -= m_prices[i - m_numPeriods + 1];
					}
					//else if (i > m_numPeriods)
					else if (i > m_numPeriods - 1)
					{
						double val = (1 - multiplier) * ema.back() + multiplier * m_prices[i];
						ema.push_back(val);
					}
				}
				return ema;
			}
			void MACalculator::addPriceQuote(double close)
			{
				m_prices.push_back(close);
			}
#pragma endregion Example1

#pragma region Example2
			VolatilityCalculator::VolatilityCalculator()
			{
			}
			VolatilityCalculator::~VolatilityCalculator()
			{
			}
			VolatilityCalculator::VolatilityCalculator(const VolatilityCalculator& v)
				: m_prices(v.m_prices)
			{
			}
			VolatilityCalculator& VolatilityCalculator::operator =(const
				VolatilityCalculator& v)
			{
				if (&v != this)
				{
					m_prices = v.m_prices;
				}
				return *this;
			}
			void VolatilityCalculator::addPrice(double price)
			{
				m_prices.push_back(price);
			}
			double VolatilityCalculator::rangeVolatility()
			{
				if (m_prices.size() < 1)
				{
					return 0;
				}
				double min = m_prices[0];
				double max = min;
				for (int i = 1; i < m_prices.size(); ++i)
				{
					if (m_prices[i] < min)
					{
						min = m_prices[i];
					}
					if (m_prices[i] > max)
					{
						max = m_prices[i];
					}
				}
				return max - min;
			}
			double VolatilityCalculator::avgDailyRange()
			{
				unsigned long n = m_prices.size();
				if (n < 2)
				{
					return 0;
				}
				double previous = m_prices[0];
				double sum = 0;
				for (int i = 1; i < m_prices.size(); ++i)
				{
					double range = abs(m_prices[i] - previous);
					sum += range;
				}
				return sum / n - 1;
			}
			double VolatilityCalculator::mean()
			{
				double sum = 0;
				for (int i = 0; i < m_prices.size(); ++i)
				{
					sum += m_prices[i];
				}
				return sum / m_prices.size();
			}
			double VolatilityCalculator::stdDev()
			{
				double m = mean();
				double sum = 0;
				for (int i = 0; i < m_prices.size(); ++i)
				{
					double val = m_prices[i] - m;
					sum += val * val;
				}
				return sqrt(sum / (m_prices.size() - 1));
			}
#pragma endregion Example2

#pragma region Example3
			TimeSeries::TimeSeries()
				: m_values()
			{
			}
			TimeSeries::~TimeSeries()
			{
			}
			TimeSeries::TimeSeries(const TimeSeries& ts)
				: m_values(ts.m_values)
			{
			}
			TimeSeries& TimeSeries::operator =(const TimeSeries& ts)
			{
				if (this != &ts)
				{
					m_values = ts.m_values;
				}
				return *this;
			}
			void TimeSeries::addValue(double val)
			{
				m_values.push_back(val);
			}
			double TimeSeries::mean()
			{
				double sum = 0;
				for (int i = 0; i < m_values.size(); ++i)
				{
					sum += m_values[i];
				}
				return sum / m_values.size();
			}
			double TimeSeries::stdDev()
			{
				double m = mean();
				double sum = 0;
				for (int i = 0; i < m_values.size(); ++i)
				{
					double val = m_values[i] - m;
					sum += val * val;
				}
				return sqrt(sum / (m_values.size() - 1));
			}
			size_t TimeSeries::size()
			{
				return m_values.size();
			}
			double TimeSeries::elem(int pos)
			{
				return m_values[pos];
			}

#pragma endregion Example3

#pragma region Example4
			CorrelationCalculator::CorrelationCalculator(TimeSeries& a, TimeSeries& b)
				: m_tsA(a),
				m_tsB(b)
			{
			}
			CorrelationCalculator::~CorrelationCalculator()
			{
			}
			CorrelationCalculator::CorrelationCalculator(const CorrelationCalculator & c)
				: m_tsA(c.m_tsA),
				m_tsB(c.m_tsB)
			{
			}
			CorrelationCalculator& CorrelationCalculator::operator=(const
				CorrelationCalculator & c)
			{
				if (this != &c)
				{
					m_tsA = c.m_tsA;
					m_tsB = c.m_tsB;
				}
				return *this;
			}
			double CorrelationCalculator::correlation()
			{
				double sum = 0;
				double meanA = m_tsA.mean();
				double meanB = m_tsB.mean();
				if (m_tsA.size() != m_tsB.size()) 
				{
					std::cout << "error: number of observations is different"<< std::endl;
					return -1;
				}
				for (int i = 0; i < m_tsA.size(); ++i)
				{
					auto val = (m_tsA.elem(i) - meanA) * (m_tsB.elem(i) - meanB);
					sum += val;
				}
				double stDevA = m_tsA.stdDev();
				double stDevB = m_tsB.stdDev();
				sum /= (stDevA * stDevB);
				return sum / (m_tsB.size() - 1);
			}
#pragma endregion Example4

#pragma region Example5
			FundamentalsCalculator::FundamentalsCalculator(const std::string& ticker,
				double price, double
				dividend) :
				m_ticker(ticker),
				m_price(price),
				m_dividend(dividend),
				m_earningsEstimate(0),
				m_numShares(0),
				m_bookValue(0),
				m_assets(0),
				m_liabilitiesAndIntangibles(0),
				m_epsGrowth(0),
				m_netIncome(0),
				m_shareholdersEquity(0)
			{
			}
			FundamentalsCalculator::FundamentalsCalculator(const FundamentalsCalculator& v) :
				m_ticker(v.m_ticker),
				m_price(v.m_price),
				m_dividend(v.m_dividend),
				m_earningsEstimate(v.m_earningsEstimate),
				m_numShares(v.m_numShares),
				m_bookValue(v.m_bookValue),
				m_assets(v.m_assets),
				m_liabilitiesAndIntangibles(v.m_liabilitiesAndIntangibles),
				m_epsGrowth(v.m_epsGrowth),
				m_netIncome(v.m_netIncome),
				m_shareholdersEquity(v.m_shareholdersEquity)
			{
			}
			FundamentalsCalculator::~FundamentalsCalculator()
			{
			}
			FundamentalsCalculator& FundamentalsCalculator::operator=(const
				FundamentalsCalculator& v)
			{
				if (this != &v)
				{
					m_ticker = v.m_ticker;
					m_price = v.m_price;
					m_dividend = v.m_dividend;
					m_earningsEstimate = v.m_earningsEstimate;
					m_numShares = v.m_numShares;
					m_bookValue = v.m_bookValue;
					m_assets = v.m_assets;
					m_liabilitiesAndIntangibles = v.m_liabilitiesAndIntangibles;
					m_epsGrowth = v.m_epsGrowth;
					m_netIncome = v.m_netIncome;
					m_shareholdersEquity = v.m_shareholdersEquity;
				}
				return *this;
			}
			double FundamentalsCalculator::PE()
			{
				return (m_price * m_numShares) / m_earnings;
			}
			double FundamentalsCalculator::forwardPE()
			{
				return (m_price * m_numShares) / m_earningsEstimate;
			}
			double FundamentalsCalculator::returnOnEquity()
			{
				return m_netIncome / m_shareholdersEquity;
			}
			double FundamentalsCalculator::getDividend()
			{
				return m_dividend;
			}
			double FundamentalsCalculator::bookValue()
			{
				return m_bookValue;
			}
			double FundamentalsCalculator::priceToBookRatio()
			{
				return (m_price * m_numShares) / (m_assets -
					m_liabilitiesAndIntangibles);
			}
			double FundamentalsCalculator::priceEarningsToGrowth()
			{
				return PE() / m_epsGrowth;
			}
			void FundamentalsCalculator::setNumOfShares(int n)
			{
				m_numShares = n;
			}
			void FundamentalsCalculator::setEarnings(double val)
			{
				m_earnings = val;
			}
			void FundamentalsCalculator::setExpectedEarnings(double val)
			{
				m_earningsEstimate = val;
			}
			void FundamentalsCalculator::setBookValue(double val)
			{
				m_bookValue = val;
			}
			void FundamentalsCalculator::setEpsGrowth(double val)
			{
				m_epsGrowth = val;
			}
			void FundamentalsCalculator::setNetIncome(double val)
			{
				m_netIncome = val;
			}
			void FundamentalsCalculator::setShareHoldersEquity(double val)
			{
				m_shareholdersEquity = val;
			}
			void FundamentalsCalculator::setLiabilitiesAndIntangibles(double val)
			{
				m_liabilitiesAndIntangibles = val;
			}
			void FundamentalsCalculator::setAssets(double val)
			{
				m_assets = val;
			}
#pragma endregion Example5

#pragma region Example6


#pragma endregion Example6

		}
	}
}