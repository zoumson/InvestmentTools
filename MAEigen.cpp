#pragma once
#include "MAEigen.h"




namespace za
{
	namespace ma
	{
		namespace eg
		{

#pragma region Example1

			void thomasAlgorithm(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d, std::vector<double>& f)
			{
				size_t N = d.size();
				//create the temporary vectors
				//note that this is inefficient as it is possible to call 
				//this function many times. A better implementation would 
				//pass these temporary matrices by non-const reference to 
				//to save axcess allocation and deallocation
				std::vector<double> cStar(N, 0.0);
				std::vector<double> dStar(N, 0.0);

				//This updates the coefficients in the first row 
				//note that we should be checking for division by zero here 
				cStar[0] = c[0] / b[0];
				dStar[0] = d[0] / b[0];

				//create the cStar and the dStar coefficients in the forward sweeep 
				for (int i = 1; i < N; i++)
				{
					double m = 1.0 / (b[i] - a[i] * cStar[i - 1]);
					cStar[i] = c[i] * m;
					dStar[i] = (d[i] - a[i] * dStar[i - 1]) * m;
					
				}
				//This is the reverse sweep, used to update the solution vector f
				//for (int i = N - 1; i > 0; i--)
				for (int i = N - 1; i-- > 0; )
				{
					f[i] = dStar[i] - cStar[i] * d[i + 1];
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