#pragma once
#include "MANumericalIntegration.h"



namespace za
{
	namespace ma
	{
		namespace ni
		{

#pragma region Example1
			MidpointIntegration::MidpointIntegration(za::ma::com::MathFunction<double>& f)
				: m_f(f),
				m_numIntervals(DEFAULT_NUM_INTERVALS)
			{
			}
			MidpointIntegration::MidpointIntegration(const MidpointIntegration& p)
				: m_f(p.m_f),
				m_numIntervals(p.m_numIntervals)
			{
			}
			MidpointIntegration::~MidpointIntegration()
			{
			}
			MidpointIntegration& MidpointIntegration::operator=(const MidpointIntegration& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
					m_numIntervals = p.m_numIntervals;
				}
				return *this;
			}
			void MidpointIntegration::setNumIntervals(int n)
			{
				m_numIntervals = n;
			}

			double MidpointIntegration::getIntegral(double a, double b)
			{
				double S = 0;
				double intSize = (b - a) / m_numIntervals;
				double x = a;
				for (int i = 0; i < m_numIntervals; ++i)
				{
					double midpt = m_f(x + (intSize / 2));
					S += intSize * midpt;
					x += intSize;
				}
				return S;
			}
			F2::~F2()
			{
			}
			double F2::operator ()(double x)
			{
				return x * x + 1;
			}
#pragma endregion Example1

#pragma region Example2
			TrapezoidIntegration::TrapezoidIntegration(za::ma::com::MathFunction<double>& f)
				: m_f(f),
				m_numIntervals(DEFAULT_NUM_INTERVALS)
			{
			}
			TrapezoidIntegration::TrapezoidIntegration(const TrapezoidIntegration& p)
				: m_f(p.m_f),
				m_numIntervals(p.m_numIntervals)
			{
			}

			TrapezoidIntegration::~TrapezoidIntegration()
			{
			}
			TrapezoidIntegration& TrapezoidIntegration::operator=(const TrapezoidIntegration& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
					m_numIntervals = p.m_numIntervals;
				}
				return *this;
			}
			void TrapezoidIntegration::setNumIntervals(int n)
			{
				m_numIntervals = n;
			}
			double TrapezoidIntegration::getIntegral(double a, double b)
			{
				double S = 0;
				double intSize = (b - a) / m_numIntervals;
				double x = a;
				for (int i = 0; i < m_numIntervals; ++i)
				{
					double midpt = (m_f(x) + m_f(x + intSize)) / 2;
					S += intSize * midpt;
					x += intSize;
				}
				return S;
			}

			F3::~F3()
			{
			}
			double F3::operator()(double x)
			{
				return std::sin(x);
			}
#pragma endregion Example2

#pragma region Example3
			SimpsonsIntegration::SimpsonsIntegration(za::ma::com::MathFunction<double>& f)
				: m_f(f),
				m_numIntervals(DEFAULT_NUM_INTERVALS)
			{
			}
			SimpsonsIntegration::SimpsonsIntegration(const SimpsonsIntegration& p)
				: m_f(p.m_f),
				m_numIntervals(p.m_numIntervals)
			{
			}
			SimpsonsIntegration::~SimpsonsIntegration()
			{
			}
			SimpsonsIntegration& SimpsonsIntegration::operator=(const SimpsonsIntegration& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
					m_numIntervals = p.m_numIntervals;
				}
				return *this;
			}
			double SimpsonsIntegration::getIntegral(double a, double b)
			{
				double S = 0;
				double intSize = (b - a) / m_numIntervals;
				double x = a;
				for (int i = 0; i < m_numIntervals; ++i)
				{
					S += (intSize / 6) * (m_f(x) + m_f(x + intSize) + 4 * m_f((x +
						x + intSize) / 2));
					x += intSize;
				}
				return S;
			}
			void SimpsonsIntegration::setNumIntervals(int n)
			{
				m_numIntervals = n;
			}


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