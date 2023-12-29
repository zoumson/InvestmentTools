#pragma once
#include "MAUtilities.h"


/*
* In a fixed income investment, a contractually defined exchange occurs between two parties. 
* Both parties agree to exchange cash flows that are assigned based on interest rates and the time of cash exchanges. 
* Fixed income investments are very diverse, but they include the following well-known types of investments vehicles:
* 1. Money market funds: These are short-term investments that offer a small rate of return but at the same time provide easy availability
* of funds at your own convenience.
* Money market funds have a very short-term horizon, and they only pay returns that are close to the spot rate practiced by banks. 
* Since money market funds have a small return that is hard to predict over a long period, they are used mostly for their liquidity.
* 2. Bonds: This is a major category of fixed income applications. 
* Bonds pay a predetermined interest rate for a well-defined period of time. 
* They are issued by a variety of institutions, including companies and all levels of government. 
* 3. Certificates of deposit: These are fixed income investments issued by
* banks to their retail customers. They are simple investments that pay a fixed interest rate for a predefined period, usually between 1 and 5 years. 
* They are used mainly for the convenience of small investors who lack access to more sophisticated fixed income markets and want to invest from their 
* own checking or savings account.

* The main reason for investors to enter the fixed income market is to take advantage
* of a relatively safe investment opportunity, where the returns are known and predictable.
* Compared to the stock market, fixed income investments have the advantage of being easier to analyze. 
* This is true because, for equity investments, for example, it is practically impossible to determine how much money a company will make in a few years from now. 
* With a fixed income investment such as a bond, however, you have a contract that guarantees the return on the investment for a specified period of time.
* Clearly, there are also risks in such fixed income investments. 
*  The big risk, which is frequently overlooked by investors, is that the rate of return will not be able to cope with inflation during the period of the investment. 
* For example, if the rate of return is 6% a year but inflation is around 4%, then your real rate of return is just 2% (and that is the return before taxes).

*/


/*
* 
• Simple interest rate calculation
• Compound interest rate calculation
• Cash flow modeling
• Determination of the present value of cash flows
• Modeling and valuation of bonds
*/
/*
* 
* Investment Science by David Luenberger 
* Investments by Zvi Bodie, Alex Kane, and Alan Marcus
* Mathematics for Finance by Marek Carpinski and Tomasz Zastawniak
*/




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

				/*
				* Cash flows are the basic tool for comparing two or more fixed income investments. 
				* A cash flow establishes the sequence of cash transfers between two interested parties. 
				* The traditional way to denote these cash exchanges is by using positive and negative values.
				* For example, consider a common loan, where a customer requests a quantity at a given interest rate. 
				* The customer will make a sequence of cash payments during the lifetime of the loan. 
				* At the end of the transaction, the payments made by both parties should be equivalent.
				* The equivalence is established using the concept of present value. 
				* The present value of a payment in the future needs to be discounted by the interest rate that would be applied to that same value. 
				In other words, discounting is the inverse concept to compounding.
				* The standard procedure is to denote values paid by
				* the two parties using positive and negative signs. For example, we can denote an initial
				* loan as a negative number and each payment of the loan as a positive number. Using this
				* approach, for a cash flow from two parties to be equivalent, the present value of all cash
				* transfers needs to add to zero.
				* For a loan, at the end of the calculation, the PV should add to zero
				* 
				* A general principle of investing is that money in your pocket today is more valuable than the same money received in the future. 
				* This general principle can be quantified using the knowledge of value compounding based on interest rates. 
				* The present value of a fixed income investment is the value that corresponds to the sum of cash flows taking place in the future, 
				* after their corresponding interest has been considered and discounted.
				* The formula for present value (PV) of a future payment is determined by
				* PV = FV / (1 + R)^N
				* PV is the desired present value, 
				* FV is the future value that we want to discount, 
				* R is the interest rate, and 
				* N is the number of periods between the present value and the future value.
				*/
				class CashFlowCalculator 
				{
				public:
					CashFlowCalculator(double rate);
					CashFlowCalculator(const CashFlowCalculator& v);
					CashFlowCalculator& operator =(const CashFlowCalculator& v);
					~CashFlowCalculator();
					void addCashPayment(double value, int timePeriod);
					double presentValue();
				private:
					std::vector<double> m_cashPayments;
					std::vector<int> m_timePeriods;
					double m_rate;
					double presentValue(double futureValue, int timePeriod);
				};

#pragma endregion Example3

#pragma region Example4
				/*
				* Bonds are a very common type of fixed income instrument. 
				* They are used by large corporations and governments all over the world to attract cash investments that will be repaid in the long term. 
				* In exchange, they offer the guaranteed payment of a periodic coupon. 
				* Most bonds mature (are paid off ) in a time period between 5 and 30 years.
				* Bonds are structured in such a way that the investor deposits the principal value at the beginning of the term of the bond. 
				* Frequently, the principal is repaid in its entirety at maturity. 
				* Between the period between the initial investment and its maturity, investors are paid a constant value, also called the coupon value, 
				* which determines the interest rate paid by the bond.
				* For example, consider a 30-year, $100,000 bond investment in company XYZ, with an annual coupon of $5,000. 
				* This translates into a fixed income investment that pays a 5% interest on the principal. 
				* Company XYZ has the right to use the principal during the specified period of time, 
				* and the total value of the principal is returned to the investor iS 30 years at maturity.
				*/
				class BondCalculator 
				{
				public:
					BondCalculator(const std::string institution, int numPeriods, double
						principal, double couponValue);
					BondCalculator(const BondCalculator& v);
					BondCalculator& operator =(const BondCalculator& v);
					~BondCalculator();
					double interestRate();
				private:
					std::string m_institution;
					double m_principal;
					double m_coupon;
					int m_numPeriods;
				};

#pragma endregion Example4

#pragma region Example5

#pragma endregion Example5

#pragma region Example6


#pragma endregion Example6
		
		}
	}
}