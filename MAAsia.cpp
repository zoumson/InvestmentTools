#include "MAAsia.h"



namespace za
{
	namespace ma
	{
		namespace as
		{

#pragma region Example1
			PayOff::PayOff() {};
			// ==========
			// PayOf fCal l
			// ==========

			PayOffCall::PayOffCall(const double& kArg) { k = kArg; };
			double PayOffCall::operator() (const double& s) const
			{ 
				return std::max(s - k, 0.0);
			};

			// =========
			// PayOffPut
			// =========
			PayOffPut::PayOffPut(const double& kArg) { k = kArg; };
			double PayOffPut::operator() (const double& s) const
			{
				return std::max(k - s, 0.0);
			};

			// =====================
			// Asian Option 
			// =====================
			AsianOption::AsianOption(PayOff* payOffArg) : payOff(payOffArg) {}
			// =====================
			// Asian Option Arithmetic
			// =====================
			AsianOptionArithmetic::AsianOptionArithmetic(PayOff* payOffArg) : AsianOption(payOffArg) 
			{

			}
			double AsianOptionArithmetic::payOffPrice(const std::vector<double>& spotPrices) const
			{
				unsigned numTimes = spotPrices.size();
				double sum = std::accumulate(spotPrices.begin(), spotPrices.end(), 0.0);
				double arithMean = sum / static_cast<double>(numTimes);
				//return (*payOff)(arithMean);
				return (*(AsianOption::payOff))(arithMean);

			}			
			
			// =====================
			// Asian Option Geometric
			// =====================
			AsianOptionGeometric::AsianOptionGeometric(PayOff* payOffArg) : AsianOption(payOffArg) {}
			double AsianOptionGeometric::payOffPrice(const std::vector<double>& spotPrices) const
			{
				unsigned numTimes = spotPrices.size();
				double logSum = 0.0;

				for (int i = 0; i < spotPrices.size(); i++)
				{
					logSum += std::log(spotPrices[i]);
				}
				double geomMean = std::exp(logSum / static_cast<double>(numTimes));
				return (*(AsianOption::payOff))(geomMean);

			}



			void calcPathSpotPrices(std::vector<double>& spotPrices, const double& r, const double& v, const double& t)
			{
				// Since the drift and volatility of the asset are  constant 
				// We will precalculate as much as possible for maximum efficiency 
				double dt = t / static_cast<double>(spotPrices.size());
				double drift = std::exp(dt * (r - 0.5 * v * v));
				double vol = std::sqrt(v * v * dt);

				for (int i = 1; i < spotPrices.size(); i++)
				{
					double gaussBm = za::ma::com::gaussianBoxMuller();
					spotPrices[i] = spotPrices[i - 1] * drift * std::exp(vol * gaussBm);
				}

			}


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