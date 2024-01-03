#include "MAInterpolation.h"


namespace za
{
	namespace ma
	{
		namespace it
		{

#pragma region Example1
			LinearInterpolation::LinearInterpolation(): m_x(),m_y()
			{
			}
			LinearInterpolation::LinearInterpolation(const LinearInterpolation& p): m_x(p.m_x), m_y(p.m_y)
			{
			}
			LinearInterpolation::~LinearInterpolation()
			{
			}
			LinearInterpolation& LinearInterpolation::operator=(const LinearInterpolation& p)
			{
				if (this != &p)
				{
					m_x = p.m_x;
					m_y = p.m_y;
				}
				return *this;
			}
			void LinearInterpolation::setPoints(const std::vector<double>& xpoints, const std::vector<double>& ypoints)
			{
				m_x = xpoints;
				m_y = ypoints;
				// update points to become sorted on x axis.
				std::sort(m_x.begin(), m_x.end());
				for (int i = 0; i < m_x.size(); ++i)
				{
					for (int j = 0; j < m_x.size(); ++j)
					{
						if (m_x[i] == xpoints[j])
						{
							m_y[i] = ypoints[j];
							break;
						}
					}
				}
			}
			double LinearInterpolation::getValue(double x)
			{
				double x0 = 0, y0 = 0, x1 = 0, y1 = 0;

				if (x < m_x[0] || x > m_x[m_x.size() - 1])
				{
					return 0; // outside of domain
				}

				for (int i = 0; i < m_x.size(); ++i)
				{
					if (m_x[i] < x)
					{
						x0 = m_x[i];
						y0 = m_y[i];
					}
					else if (m_x[i] >= x)
					{
						x1 = m_x[i];
						y1 = m_y[i];
						break;
					}
				}
				return y0 * (x - x1) / (x0 - x1) + y1 * (x - x0) / (x1 - x0);
			}

#pragma endregion Example1

#pragma region Example2
			PolynomialInterpolation::PolynomialInterpolation() : m_x(), m_y()
			{
			}
			PolynomialInterpolation::PolynomialInterpolation(const PolynomialInterpolation& p): m_y(p.m_y), m_x(p.m_x)
			{
			}
			PolynomialInterpolation::~PolynomialInterpolation()
			{
			}
			PolynomialInterpolation& PolynomialInterpolation::operator=(const PolynomialInterpolation& p)
			{
				if (this != &p)
				{
					m_x = p.m_x;
					m_y = p.m_y;
				}
				return *this;
			}
			void PolynomialInterpolation::setPoints(const std::vector<double>& x, const std::vector<double>& y)
			{
				m_x = x;
				m_y = y;
			}
			double PolynomialInterpolation::getPolynomial(double x)
			{
				double polynomialValue = 0;
				for (size_t i = 0; i < m_x.size(); ++i)
				{
					// compute the numerator
					double num = 1;
					for (size_t j = 0; j < m_x.size(); ++j)
					{
						if (j != i)
						{
							num *= x - m_x[j];
						}
					}
					// compute the denominator
					double den = 1;
					for (size_t j = 0; j < m_x.size(); ++j)
					{
						if (j != i)
						{
							den *= m_x[i] - m_x[j];
						}
					}
					// value for i-th term
					polynomialValue += m_y[i] * (num / den);
				}
				return polynomialValue;
			}
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