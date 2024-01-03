#pragma once
#include "MARoot.h"






namespace za
{
	namespace ma
	{
		namespace re
		{

#pragma region Example1

			const double DEFAULT_ERROR = 0.001;

			BisectionMethod::BisectionMethod(za::ma::com::MathFunction<double>& f) : m_f(f), m_error(DEFAULT_ERROR)
			{
			}
			BisectionMethod::BisectionMethod(const BisectionMethod& p) : m_f(p.m_f), m_error(p.m_error)
			{
			}
			BisectionMethod::~BisectionMethod()
			{
			}
			BisectionMethod& BisectionMethod::operator =(const BisectionMethod& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
					m_error = p.m_error;
				}
				return *this;
			}

			double BisectionMethod::getRoot(double x1, double x2)
			{
				double root = 0;
				while (std::abs(x1 - x2) > m_error)
				{
					double x3 = (x1 + x2) / 2;
					root = x3;
					if (m_f(x1) * m_f(x3) < 0)
					{
						x2 = x3;
					}
					else
					{
						x1 = x3;
					}
					if (m_f(x1) * m_f(x2) > 0)
					{
						std::cout << " function does not converge " << std::endl;
						break;
					}
				}
				return root;
			}
			
			F1::~F1()
			{
			};
			double F1::operator()(double x)
			{
				return (x - 1) * (x - 1) * (x - 1);
			}

#pragma endregion Example1

#pragma region Example2
			SecantMethod::SecantMethod(za::ma::com::MathFunction<double>& f): m_f(f), m_error(DEFAULT_ERROR)
			{
			}
			SecantMethod::SecantMethod(const SecantMethod& p): m_f(p.m_f), m_error(p.m_error)
			{
			}
			SecantMethod::~SecantMethod()
			{
			}
			SecantMethod& SecantMethod::operator=(const SecantMethod& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
					m_error = p.m_error;
				}
				return *this;
			}
			double SecantMethod::getRoot(double x1, double x2)
			{
				double root = 0;
				double a = x1;
				double b = x2;

				double fa = m_f(a);
				double fb = m_f(b);
				double c = 0, fc = 0;
				do
				{
					c = b - fb * (b - a) / (fb - fa);
					root = c;
					fc = m_f(c);
					std::cout << "-> " << c << " " << fc << " " << std::endl; // this line just for demonstration
					a = b;
					fa = fb;
					b = c;
					fb = fc;
				} 
				while (std::abs(a - b) > m_error);
				return root;
			}
#pragma endregion Example2

#pragma region Example3
			NewtonMethod::NewtonMethod(za::ma::com::MathFunction<double>& f, za::ma::com::MathFunction<double>& derivative)
				: m_f(f),
				m_derivative(derivative),
				m_error(DEFAULT_ERROR)
			{
			}
			NewtonMethod::NewtonMethod(const NewtonMethod& p)
				: m_f(p.m_f),
				m_derivative(p.m_derivative),
				m_error(p.m_error)
			{
			}
			NewtonMethod::~NewtonMethod()
			{
			}
			NewtonMethod& NewtonMethod::operator=(const NewtonMethod& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
					m_derivative = p.m_derivative;
					m_error = p.m_error;
				}
				return *this;
			}
			double NewtonMethod::getRoot(double x0)
			{
				double x1 = x0;
				do
				{
					x0 = x1;
					std::cout << " x0 is " << x0 << std::endl; // this line just fordemonstration
						double d = m_derivative(x0);
					double y = m_f(x0);
					x1 = x0 - y / d;
				} 
				while (std::abs(x0 - x1) > m_error);
				return x1;
			}

			// represents the derivative of F1
			DF1::~DF1()
			{
			}
			double DF1::operator ()(double x)
			{
				return 3 * (x - 1) * (x - 1);
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