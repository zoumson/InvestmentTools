#pragma once
#include "MAOdePde.h"




namespace za
{
	namespace ma
	{
		namespace od
		{

#pragma region Example1
			EulersMethod::EulersMethod(za::ma::com::MathFunction2<double>& f): m_f(f)
			{
			}
			EulersMethod::EulersMethod(const EulersMethod& p): m_f(p.m_f)
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
			RungeKuttaODEMethod::RungeKuttaODEMethod(za::ma::com::MathFunction2<double>& f) : m_f(f)
			{
			}
			RungeKuttaODEMethod::RungeKuttaODEMethod(const RungeKuttaODEMethod& p) : m_f(p.m_f)
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

			//initial condition of the ODE is (x0, y0)
			//evaluate the function at x = c
			//n is the number of steps between x0 and c
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
				: m_expiration(expiration), m_maxPrice(maxPrice), m_strike(strike), m_intRate(intRate)
			{
			}
			BlackScholesForwardMethod::BlackScholesForwardMethod(const BlackScholesForwardMethod& p)
				: m_expiration(p.m_expiration), m_maxPrice(p.m_maxPrice), m_strike(p.m_strike), m_intRate(p.m_intRate)
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

			std::vector<double> BlackScholesForwardMethod::solve(double volatility, int nx, int timeSteps)
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
			//different book
//c++ for quants 
//close form solution

			double normPdf(const double& x)
			{
				//#define _USE_MATH_DEFINES

				double M_PI = za::ma::com::pi();

				return (1.0 / std::pow(2 * M_PI, 0.5)) * std::exp(-0.5 * x * x);
			}
			//an approximation to the cumulative distribution function 
			//for the standard normal distribution 
			//note: this is a recursive function 
			double normCdf(const double& x)
			{
				double M_PI = za::ma::com::pi();
				double k = 1.0 / (1.0 + 0.2316419 * x);
				double kSum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

				if (x >= 0.0)
				{
					return (1.0 - (1.0 / (std::pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * kSum);
				}
				else
				{
					return 1.0 - normCdf(-x);
				}
			}
			//this term appears in the closed form solution for the european cal or put price 
			double dJ(const int& j, const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				return (std::log(s / k) + (r + (std::pow(-1, j - 1)) * 0.5 * v * v) * t) / (v * (std::pow(t, 0.5)));

			}
			//vanilla european call 
			double callPriceCloseForm(const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				return s * normCdf(dJ(1, s, k, r, v, t)) - k * exp(-r * t) * normCdf(dJ(2, s, k, r, v, t));

			}
			//vanilla european put 
			double putPriceCloseForm(const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				return -s * normCdf(-dJ(1, s, k, r, v, t)) + k * exp(-r * t) * normCdf(-dJ(2, s, k, r, v, t));
			}
#pragma endregion Example4

#pragma region Example5

			double callDeltaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return normCdf(dJ(1, s, k, r, v, t));
			}
			double callGammaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return normPdf(dJ(1, s, k, r, v, t)) / (s*v* std::sqrt(t));

			}
			double callVegaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return s*normPdf(dJ(1, s, k, r, v, t)) * std::sqrt(t);
			}
			double callThetaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return -s * normPdf(dJ(1, s, k, r, v, t)) * v/ (2 * std::sqrt(t)) -r * k * std::exp(-r * t) * normCdf(dJ(2, s, k, r, v, t));
			}
			double callRhoCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return k*t*std::exp(-r * t) * normCdf(dJ(2, s, k, r, v, t));
			}

			double putDeltaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return normCdf(dJ(1, s, k, r, v, t)) - 1;
			}
			double putGammaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return callGammaCloseForm(s, k, r, v, t);
			}
			double putVegaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return callVegaCloseForm(s, k, r, v, t);

			}
			double putThetaCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return -(s*normPdf(dJ(1, s, k, r, v, t)) *v) / (2* std::sqrt(t)) + r *k*std::exp(-r * t) * normCdf(-dJ(2, s, k, r, v, t));
			}
			double putRhoCloseForm(const double s, const double k, const double r, const double v, const double t)
			{
				return -t*k*std::exp(-r * t) * normCdf(-dJ(2, s, k, r, v, t));
			}


#pragma endregion Example5

#pragma region Example6
			double callDeltaFDM(const double s, const double k, const double r, const double v, const double t, const double h)
			{
				return (callPriceCloseForm(s + h, k, r, v, t) - callPriceCloseForm(s, k, r, v, t)) / h;
			}
			double callGammaFDM(const double s, const double k, const double r, const double v, const double t, const double h)
			{
				return (callPriceCloseForm(s + h, k, r, v, t) - 2*callPriceCloseForm(s, k, r, v, t) + callPriceCloseForm(s - h, k, r, v, t)) / (h*h);
			}

#pragma endregion Example6

#pragma region Example7


			double callPriceMonteCarlo(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				double sAdjust = s * exp(t * (r - 0.5 * v * v));
				double sCur = 0.0;
				double payoffSum = 0.0;
				for (int i = 0; i < numSims; i++)
				{
					double gaussBm = za::ma::com::gaussianBoxMuller();
					sCur = sAdjust * std::exp(sqrt(v * v * t) * gaussBm);
					payoffSum += std::max(sCur - k, 0.0);
				}

				return (payoffSum / static_cast<double>(numSims)) * std::exp(-r * t);
			}
			double putPriceMonteCarlo(const int& numSims, const double& s, const double& k, const double& r, const double& v, const double& t)
			{
				double sAdjust = s * exp(t * (r - 0.5 * v * v));
				double sCur = 0.0;
				double payoffSum = 0.0;
				for (int i = 0; i < numSims; i++)
				{
					double gaussBm = za::ma::com::gaussianBoxMuller();
					sCur = sAdjust * std::exp(sqrt(v * v * t) * gaussBm);
					payoffSum += std::max(k - sCur, 0.0);
				}

				return (payoffSum / static_cast<double>(numSims)) * std::exp(-r * t);
			}


#pragma endregion Example7	

#pragma region Example8
			// Pricing a European vanilla call option with a Monte Carlo method 
// Create three separate paths, eahc with either an increment, non-increment or decrement based on deltaS, the stock parameter 
			void callPriceMonteCarloFDM(const int numSims, const double s, const double k, const double r, const double v, const double t,
				const double deltaS, double& spPrice, double& sPrice, double& smPriceS)
			{
				// since we wish to use the same Gaussian random draws for each path, it is 
				// necessary to create three separated adjusted stock paths for each 
				// increment / decrement of the asset 
				double spAdjust = (s + deltaS) *std::exp(t*(r - 0.5*v*v));
				double sAdjust = s*std::exp(t*(r - 0.5*v*v));
				double smAdjust = (s - deltaS) *std::exp(t*(r - 0.5*v*v));
				
				// These will store all three current prices as the monte carlo algo is carried out 
				double spCur = 0.0;
				double sCur = 0.0;
				double smCur = 0.0;

				// There are three separate payoff sums for the final price 
				double spPayoffSum = 0.0;
				double sPayoffSum = 0.0;
				double smPayoffSum = 0.0;

				// Loop over the number of simulations 
			
				for (int i = 0; i < numSims; i++)
				{
					double gaussBm = za::ma::com::gaussianBoxMuller();
					// Adjust three stock paths 
					// Adjus t t h r e e s t o c k paths
					double expGauSs = std::exp(std::sqrt(v*v*t) * gaussBm);
					spCur = spAdjust* expGauSs;
					sCur = sAdjust * expGauSs;
					smCur = smAdjust * expGauSs;
					// Calculate the continual pay off sum for each increament/decrement 
					spPayoffSum += std::max(spCur - k, 0.0);
					sPayoffSum += std::max(sCur - k, 0.0);
					smPayoffSum += std::max(smCur - k, 0.0);
				}
				// There are three separate prices  

				spPrice = (spPayoffSum / static_cast<double>(numSims)) * exp(-r *t);
				sPrice = (sPayoffSum / static_cast<double>(numSims)) * exp(-r *t);
				smPriceS = (smPayoffSum / static_cast<double>(numSims)) * exp(-r *t);
			}

			double callDeltaMonteCarloFDM(const int numSims, const double s, const double k, const double r, const double v, const double t,
				const double deltaS)
			{
				// These values will be populated via the monte carlo price function 
				// They represent the incremented sp(s + deltaS), non-incremented s 
				// and decremented sm (s - deltaS) prices
				double spPrice = 0.0;
				double sPrice = 0.0;
				double smPrice = 0.0;

				// Call the Monte Carlo pricer for each of the three stock paths 
				// we only need two for the delta

				callPriceMonteCarloFDM(numSims, s, k, r, v, t, deltaS, spPrice, sPrice, smPrice);
				return (spPrice - sPrice) / deltaS;
			}

			double callGammaMonteCarloFDM(const int numSims, const double s, const double k, const double r, const double v, const double t,
				const double deltaS)
			{
				// These values will be populated via the monte carlo price function 
				// They represent the incremented sp(s + deltaS), non-incremented s 
				// and decremented sm (s - deltaS) prices
				double spPrice = 0.0;
				double sPrice = 0.0;
				double smPrice = 0.0;

				// Call the Monte Carlo pricer for each of the three stock paths 
				// we only need two for the delta

				callPriceMonteCarloFDM(numSims, s, k, r, v, t, deltaS, spPrice, sPrice, smPrice);
				return (spPrice - 2*sPrice + smPrice) / (deltaS * deltaS);
			}

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