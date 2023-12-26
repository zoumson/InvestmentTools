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
			CashFlowCalculator::CashFlowCalculator(double rate)
				: m_rate(rate)
			{
			}
			CashFlowCalculator::CashFlowCalculator(const CashFlowCalculator& v)
				: m_rate(v.m_rate)
			{
			}
			CashFlowCalculator::~CashFlowCalculator()
			{
			}
			CashFlowCalculator& CashFlowCalculator::operator =(const CashFlowCalculator
				& v)
			{
				if (this != &v)
				{
					this->m_cashPayments = v.m_cashPayments;
					this->m_timePeriods = v.m_timePeriods;
					this->m_rate = v.m_rate;
				}
				return *this;
			}
			void CashFlowCalculator::addCashPayment(double value, int timePeriod)
			{
				m_cashPayments.push_back(value);
				m_timePeriods.push_back(timePeriod);
			}
			double CashFlowCalculator::presentValue(double futureValue, int timePeriod)
			{
				double pValue = futureValue / std::pow(1 + m_rate, timePeriod);
				std::cout << " value " << pValue << std::endl;
				return pValue;
			}
			double CashFlowCalculator::presentValue()
			{
				double total = 0;
				for (int i = 0; i < m_cashPayments.size(); ++i)
				{
					total += presentValue(m_cashPayments[i], m_timePeriods[i]);
				}
				return total;
			}

#pragma endregion Example3

#pragma region Example4
			BondCalculator::BondCalculator(const std::string institution, int numPeriods,
				double principal, double couponValue)
				: m_institution(institution),
				m_numPeriods(numPeriods),
				m_principal(principal),
				m_coupon(couponValue)
			{
			}
			BondCalculator::BondCalculator(const BondCalculator& v)
				: m_institution(v.m_institution),
				m_numPeriods(v.m_numPeriods),
				m_principal(v.m_principal),
				m_coupon(v.m_coupon)
			{
			}
			BondCalculator::~BondCalculator()
			{
			}
			BondCalculator& BondCalculator::operator =(const BondCalculator& v)
			{
				if (this != &v)
				{
					this->m_institution = v.m_institution;
					this->m_principal = v.m_principal;
					this->m_numPeriods = v.m_numPeriods;
					this->m_coupon = v.m_coupon;
				}
				return *this;
			}
			double BondCalculator::interestRate()
			{
				return m_coupon / m_principal;
			}

#pragma endregion Example4

#pragma region Example5

#pragma endregion Example5

#pragma region Example6


#pragma endregion Example6

		}
	}
}