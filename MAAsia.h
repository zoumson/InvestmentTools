#pragma once
#include "MAUtilities.h"



namespace za
{
	namespace ma
	{
		namespace as
		{

#pragma region Example1

			class PayOff 
			{
			public:
				PayOff(); // Default ( no parameter) constructor 
				virtual ~PayOff() {}; // Virtual destructor 
				// Overloaded () operator, turns the PayOff into an abstract function object 
				virtual double operator () (const double& s) const = 0;

			};
			
			class PayOffCall : public PayOff
			{
			private:
				// Strike price
				double k;
			public:
				PayOffCall(const double& kArg);
				virtual ~PayOffCall() {}; // Virtual destructor 
				// Virtual function is now over-ridden (not pure virtual anymore)
				virtual double operator () (const double& s) const;

			};			
			class PayOffPut : public PayOff
			{
			private:
				// Strike price
				double k;
			public:
				PayOffPut(const double& kArg);
				virtual ~PayOffPut() {}; // Virtual destructor 
				// Virtual function is now over-ridden (not pure virtual anymore)
				virtual double operator () (const double& s) const;

			};



			class AsianOption
			{
			protected: 
				// Pointer to payoff class( in this instance call or put)
				PayOff* payOff;

			public:
				AsianOption(PayOff* payOffArg);
				virtual ~AsianOption() {};
				// Pure virtual payoff operator 
				// This will determine arithmetic or geometric
				virtual double payOffPrice(const std::vector<double>& spotPrices) const = 0;


			};


			class AsianOptionArithmetic : AsianOption
			{
				//use global resolution operator to access parent member data 
			//protected: 
				// Pointer to payoff class( in this instance call or put)
				//PayOff* payOff;

			public:
				AsianOptionArithmetic(PayOff* payOffArg);
				virtual ~AsianOptionArithmetic() {};
				double payOffPrice(const std::vector<double>& spotPrices) const override;


			};

			class AsianOptionGeometric : AsianOption
			{
				//use global resolution operator to access parent member data
				//protected: 
				// Pointer to payoff class( in this instance call or put)
				//PayOff* payOff;

			public:
				AsianOptionGeometric(PayOff* payOffArg);
				virtual ~AsianOptionGeometric() {};
				double payOffPrice(const std::vector<double>& spotPrices) const override;


			};
			// This provides a vector containing sampled points of Geometric Brownian Motion stock price path 
			void calcPathSpotPrices(std::vector<double>& spotPrices, const double& r, const double& v, const double& t);

#pragma endregion Example1


#pragma region Example2
		
#pragma endregion Example2


#pragma region Example3

#pragma endregion Example3


#pragma region Example4

#pragma endregion Example4

#pragma region Example5

#pragma endregion Example5


#pragma region Example6

#pragma endregion Example6

#pragma region Example7

#pragma endregion Example7	


#pragma region Example8

#pragma endregion Example8

#pragma region Example9


#pragma endregion Example9

#pragma region Example10


#pragma endregion Example10


#pragma region Example11

#pragma endregion Example11

#pragma region Example12


#pragma endregion Example12

#pragma region Example13


#pragma endregion Example13

#pragma region Example14


#pragma endregion Example14

#pragma region Example15


#pragma endregion Example15

		}
	}
}