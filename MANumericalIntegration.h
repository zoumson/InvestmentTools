#pragma once
#include "MAUtilities.h"



namespace za
{
	namespace ma
	{
		namespace ni
		{

#pragma region Example1
			class MidpointIntegration 
			{
			public:
				MidpointIntegration(za::ma::com::MathFunction<double>& f);
				MidpointIntegration(const MidpointIntegration& p);
				~MidpointIntegration();
				MidpointIntegration& operator=(const MidpointIntegration& p);
				void setNumIntervals(int n);
				double getIntegral(double a, double b);
			private:
				za::ma::com::MathFunction<double>& m_f;
				int m_numIntervals;
			};
			class F2 : public za::ma::com::MathFunction<double>
			{
			public:
				~F2();
				double operator()(double x);
			};
			const int DEFAULT_NUM_INTERVALS = 100;
#pragma endregion Example1

#pragma region Example2
			class TrapezoidIntegration 
			{
			public:
				TrapezoidIntegration(za::ma::com::MathFunction<double>& f);
				TrapezoidIntegration(const TrapezoidIntegration& p);
				~TrapezoidIntegration();
				TrapezoidIntegration& operator=(const TrapezoidIntegration& p);
				void setNumIntervals(int n);
				double getIntegral(double a, double b);
			private:
				za::ma::com::MathFunction<double>& m_f;
				int m_numIntervals;
			};

			class F3 : public za::ma::com::MathFunction<double>
			{
			public:
				~F3();
				double operator()(double x);
			};
			
#pragma endregion Example2

#pragma region Example3
			class SimpsonsIntegration 
			{
			public:
				SimpsonsIntegration(za::ma::com::MathFunction<double>& f);
				SimpsonsIntegration(const SimpsonsIntegration& p);
				~SimpsonsIntegration();
				SimpsonsIntegration& operator=(const SimpsonsIntegration& p);
				double getIntegral(double a, double b);
				void setNumIntervals(int n);
			private:
				za::ma::com::MathFunction<double>& m_f;
				int m_numIntervals;
			};
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