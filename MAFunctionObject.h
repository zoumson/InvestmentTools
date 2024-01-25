#pragma once
#include "MAUtilities.h"




namespace za
{
	namespace ma
	{
		namespace fo
		{

#pragma region Example1

			double addOp(double left, double right);

			double multiplyOp(double left, double right);

			double binaryOp1(double left, double right, double (*f)(double, double));


#pragma endregion Example1

#pragma region Example2
			class BinaryFunctionOp
			{
			public:
				BinaryFunctionOp() {};
				virtual double operator()(double left, double right) = 0;

			};

			class AddOp : public BinaryFunctionOp
			{
			public:
				AddOp();
				virtual double operator()(double left, double right);

			};
			class MultiplyOp : public BinaryFunctionOp
			{
			public:
				MultiplyOp();
				virtual double operator()(double left, double right);

			};

			double binaryOp2(double left, double right, BinaryFunctionOp* f);
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