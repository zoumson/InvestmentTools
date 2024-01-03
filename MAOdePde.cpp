#pragma once
#include "MAOdePde.h"




namespace za
{
	namespace ma
	{
		namespace od
		{

#pragma region Example1
			EulersMethod::EulersMethod(za::ma::com::MathFunction2<double>& f)
				: m_f(f)
			{
			}
			EulersMethod::EulersMethod(const EulersMethod& p)
				: m_f(p.m_f)
			{
			}

			EulersMethod::~EulersMethod()
			{
			}
			EulersMethod& EulersMethod::operator=(const EulersMethod& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
				}
				return *this;
			}
			double EulersMethod::solve(int n, double x0, double y0, double c)
			{
				// problem : y' = f(x,y) ; y(x0) = y0
				auto x = x0;
				auto y = y0;
				auto h = (c - x0) / n;
				std::cout << " h is " << h << std::endl;
				for (int i = 0; i < n; ++i)
				{
					double F = m_f(x, y);
					auto G = m_f(x + h, y + h * F);
					std::cout << " F: " << F << " G: " << G << std::endl;
					// update values of x, y
					x += h;
					y += h * (F + G) / 2;
					std::cout << " x: " << x << " y: " << y << std::endl;
				}
				return y;
			}

			F4::~F4()
			{

			}
			double F4::operator()(double x, double y)
			{
				return 3 * x + 2 * y + 1;
			}
#pragma endregion Example1

#pragma region Example2
			RungeKuttaODEMethod::RungeKuttaODEMethod(za::ma::com::MathFunction2<double>& f)
				: m_f(f)
			{
			}
			RungeKuttaODEMethod::RungeKuttaODEMethod(const RungeKuttaODEMethod& p)
				: m_f(p.m_f)
			{
			}
			RungeKuttaODEMethod::~RungeKuttaODEMethod()
			{
			}
			RungeKuttaODEMethod& RungeKuttaODEMethod::operator=(const RungeKuttaODEMethod& p)
			{
				if (this != &p)
				{
					m_f = p.m_f;
				}
				return *this;
			}
			double RungeKuttaODEMethod::solve(int n, double x0, double y0, double c)
			{
				auto x = x0;
				auto y = y0;
				auto h = (c - x0) / n;
				for (int i = 0; i < n; ++i)
				{
					auto k1 = h * m_f(x, y);
					auto k2 = h * m_f(x + (h / 2), y + (k1 / 2));
					auto k3 = h * m_f(x + (h / 2), y + (k2 / 2));
					auto k4 = h * m_f(x + h, y + k3);
					x += h;
					y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
				}
				return y;
			}

#pragma endregion Example2

#pragma region Example3

			BlackScholesForwardMethod::BlackScholesForwardMethod(double expiration, double maxPrice, double strike, double intRate)
				: m_expiration(expiration),
				m_maxPrice(maxPrice),
				m_strike(strike),
				m_intRate(intRate)
			{
			}
			BlackScholesForwardMethod::BlackScholesForwardMethod(const BlackScholesForwardMethod& p)
				: m_expiration(p.m_expiration),
				m_maxPrice(p.m_maxPrice),
				m_strike(p.m_strike),
				m_intRate(p.m_intRate)
			{
			}
			BlackScholesForwardMethod::~BlackScholesForwardMethod()
			{
			}
			BlackScholesForwardMethod& BlackScholesForwardMethod::operator=(const BlackScholesForwardMethod& p)
			{
				if (this != &p)
				{
					m_expiration = p.m_expiration;
					m_maxPrice = p.m_maxPrice;
					m_strike = p.m_strike;
					m_intRate = p.m_intRate;
				}
				return *this;
			}

			std::vector<double> BlackScholesForwardMethod::solve(double volatility, int nx,
				int timeSteps)
			{
				double dt = m_expiration / (double)timeSteps;
				double dx = m_maxPrice / (double)nx;
				std::vector<double> a(nx - 1);
				std::vector<double> b(nx - 1);
				std::vector<double> c(nx - 1);
				int i;

				for (i = 0; i < nx - 1; i++)
				{
					b[i] = 1.0 - m_intRate * dt - dt * pow(volatility * (i + 1), 2);
				}

				for (i = 0; i < nx - 2; i++)
				{
					c[i] = 0.5 * dt * pow(volatility * (i + 1), 2) + 0.5 * dt * m_intRate * (i + 1);
				}


				for (i = 1; i < nx - 1; i++)
				{
					a[i] = 0.5 * dt * pow(volatility * (i + 1), 2) - 0.5 * dt * m_intRate* (i + 1);
				}

				std::vector<double> u((nx - 1) * (timeSteps + 1));
				double u0 = 0.0;

				for (i = 0; i < nx - 1; i++)
				{
					u0 += dx;
					u[i + 0 * (nx - 1)] = std::max(u0 - m_strike, 0.0);
				}
				for (int j = 0; j < timeSteps; j++)
				{
					double t = (double)(j)*m_expiration / (double)timeSteps;
					double p = 0.5 * dt * (nx - 1) * (volatility * volatility * (nx - 1) + m_intRate) * (m_maxPrice - m_strike * exp(-m_intRate * t));

					for (i = 0; i < nx - 1; i++)
					{
						u[i + (j + 1) * (nx - 1)] = b[i] * u[i + j * (nx - 1)];
					}
					for (i = 0; i < nx - 2; i++)
					{
						u[i + (j + 1) * (nx - 1)] += c[i] * u[i + 1 + j * (nx - 1)];
					}
					for (i = 1; i < nx - 1; i++)
					{
						u[i + (j + 1) * (nx - 1)] += a[i] * u[i - 1 + j * (nx - 1)];
					}
					u[nx - 2 + (j + 1) * (nx - 1)] += p;
				}
				return u;
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