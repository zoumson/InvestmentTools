#pragma once
#include "MAUtilities.h"






namespace za
{
	namespace ma
	{
		namespace it
		{

#pragma region Example1

			class LinearInterpolation 
			{
			public:
				LinearInterpolation();
				LinearInterpolation(const LinearInterpolation& p);
				~LinearInterpolation();
				LinearInterpolation& operator=(const LinearInterpolation& p);
				void setPoints(const std::vector<double>& xpoints, const std::vector<double>& ypoints);
				double getValue(double x);
			private:
				std::vector<double> m_x;
				std::vector<double> m_y;
			};
#pragma endregion Example1

#pragma region Example2
			class PolynomialInterpolation 
			{
			public:
				PolynomialInterpolation();
				PolynomialInterpolation(const PolynomialInterpolation& p);
				~PolynomialInterpolation();
				PolynomialInterpolation& operator=(const PolynomialInterpolation&);
				void setPoints(const std::vector<double>& x, const std::vector<double>& y);
				double getPolynomial(double x);
			private:
				std::vector<double> m_x;
				std::vector<double> m_y;
			};
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