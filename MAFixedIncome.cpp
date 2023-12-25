#include "MAFixedIncome.h"


#pragma once
namespace za
{
	namespace ma
	{
		namespace fi
		{


#pragma region Example1

			// IntRateCalculator.cpp
			//inline double IntRateCalculator::singlePeriod(double value)
			//if inline this should go with the header file 
			double IntRateCalculator::singlePeriod(double value)
			{
				double f = value * (1 + this->m_rate);
				return f;
			}

			IntRateCalculator::IntRateCalculator(double rate)
				: m_rate(rate)
			{
			}
			IntRateCalculator::~IntRateCalculator()
			{
			}
			IntRateCalculator::IntRateCalculator(const IntRateCalculator & v)
				: m_rate(v.m_rate)
			{
			}
			IntRateCalculator& IntRateCalculator::operator=(const IntRateCalculator & v)
			{
				if (&v != this)
				{
					this->m_rate = v.m_rate;
				}
				return *this;
			}
#pragma endregion Example1

#pragma region Example2
			CompoundIntRateCalculator::CompoundIntRateCalculator(double rate)
				: m_rate(rate)
			{
			}
			CompoundIntRateCalculator::~CompoundIntRateCalculator()
			{
			}
			CompoundIntRateCalculator::CompoundIntRateCalculator(const
				CompoundIntRateCalculator& v)
				: m_rate(v.m_rate)
			{
			}
			CompoundIntRateCalculator& CompoundIntRateCalculator::operator =(const
				CompoundIntRateCalculator& v)
			{
				if (this != &v)
				{
					this->m_rate = v.m_rate;
				}
				return *this;
			}

			double CompoundIntRateCalculator::multiplePeriod(double value, int
				numPeriods)
			{
				double f = value * std::pow(1 + m_rate, numPeriods);
				return f;
			}
			double CompoundIntRateCalculator::continuousCompounding(double value, int
				numPeriods)
			{
				double f = value * exp(m_rate * numPeriods);
				return f;
			}

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