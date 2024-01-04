#pragma once
#include "MAAssetPortfolio.h"






namespace za
{
	namespace ma
	{
		namespace ap
		{

#pragma region Example1
			ResourceAlloc::ResourceAlloc(std::vector<double>& result, double& objVal)
				: m_results(result), m_objVal(objVal)
			{
			}
			ResourceAlloc::ResourceAlloc(const ResourceAlloc& p)
				: m_results(p.m_results), m_objVal(p.m_objVal)
			{
			}
			ResourceAlloc::~ResourceAlloc()
			{
			}
			ResourceAlloc& ResourceAlloc::operator=(const ResourceAlloc& p)
			{
				if (this != &p)
				{
					m_results = p.m_results;
					m_objVal = p.m_objVal;
				}
				return *this;
			}
			void ResourceAlloc::solveProblem()
			{
				static const double cost_array[][5] = {
					// Years:
					// 1 2 3 4 5
					{1.81, 2.4, 2.5, 0.97, 1.5}, // proj 1
					{1.29, 1.8, 2.3, 0.56, 0.5}, // proj 2
					{1.22, 1.2, 0.1, 0.48, 0 }, // proj 3
					{1.43, 1.4, 1.2, 1.2, 1.2}, // proj 4
					{1.62, 1.9, 2.5, 2.0, 1.8}, // proj 5
				};
				za::ma::com::Matrix costs(5, 5); // cost matrix
				for (int i = 0; i < 5; ++i) 
				{
					for (int j = 0; j < 5; ++j) 
					{
						costs[j][i] = cost_array[i][j];
					}
				}
				std::vector<double> returns = { 12.13, 3.95, 7.2, 4.21, 11.39 };
				// investment returns
				std::vector<double> budgets = { 5.1, 6.4, 6.84, 4.5, 3.8 }; // annual budgets
				
				za::ma::com::MIPSolver solver(costs, budgets, returns);
				solver.setMaximization();
				for (int i = 0; i < 5; ++i)
				{
					solver.setColBinary(i);
				}
				// --- solve the problem
				solver.solve(m_results, m_objVal);
			}
#pragma endregion Example1

#pragma region Example2
			ModifiedCAP::ModifiedCAP(int N, int T, double R, za::ma::com::Matrix& expectedRet, const std::vector<double>& ret)
				: m_N(N),
				m_T(T),
				m_R(R),
				m_retMatrix(expectedRet),
				m_assetRet(ret)
			{
			}
			ModifiedCAP::ModifiedCAP(const ModifiedCAP& p)
				: m_N(p.m_N),
				m_T(p.m_T),
				m_R(p.m_R),
				m_retMatrix(p.m_retMatrix),
				m_assetRet(p.m_assetRet)
			{
			}
			ModifiedCAP::~ModifiedCAP()
			{
			}
			ModifiedCAP& ModifiedCAP::operator=(const ModifiedCAP& p)
			{
				if (this != &p)
				{
					m_N = p.m_N;
					m_T = p.m_T;
					m_R = p.m_R;
					m_retMatrix = p.m_retMatrix;
					m_assetRet = p.m_assetRet;
				}
				return *this;
			}
			void ModifiedCAP::solveModel(std::vector<double>& results, double& objVal)
			{
				za::ma::com::Matrix A(2 * m_T + 2 + 1, m_T + m_N);
				std::vector<double> c(m_T + m_N, 0);

				// objective function
				for (int i = m_N; i < m_N + m_T; ++i)
				{
					c[i] = 1;
				}
				// right-hand side vector
				std::vector<double> b(2 * m_T + 2 + 1, 0);
				b[2 * m_T] = 1;
				b[2 * m_T + 1] = -1;
				b[2 * m_T + 2] = -m_R;
				// matrix A
				for (int i = 0; i < m_T; ++i)
				{
					for (int j = 0; j < m_N; ++j)
					{
						A[i][j] = m_retMatrix[j][i] - m_assetRet[j];
					}
					A[i][m_N + i] = -1;
				}

				for (int i = m_T; i < 2 * m_T; ++i)
				{
					for (int j = m_N; j < 2 * m_N; ++j)
					{
						A[i][j] = -m_retMatrix[j - m_N][i - m_T] + m_assetRet[j - m_N];
					}
					A[i][m_N + i - m_T] = -1;
				}

				for (int j = 0; j < m_N; ++j)
				{
					A[2 * m_T][j] = 1;
					A[2 * m_T + 1][j] = -1;
					A[2 * m_T + 2][j] = -m_assetRet[j];
				}
				za::ma::com::LPSolver solver(A, b, c);
				solver.setMinimization();
				solver.solve(results, objVal);
			}

			void ModifiedCAP::solveExtendedModel(std::vector<double>& results, double& objVal)
			{
				std::vector<double> c(m_T + m_N, 0);
				// objective function
				for (int i = m_N; i < m_N + m_T; ++i)
				{
					c[i] = 1;
				}
				const double M = 0.37; // maximum of each asset
				const double K_L = 0.15; // minimum of combined assets 1 and 2
				// right-hand side vector
				std::vector<double> b(2 * m_T + 2 + 1 + m_N + 1, 0);
				b[2 * m_T] = 1;
				b[2 * m_T + 1] = -1;
				b[2 * m_T + 2] = -m_R;
				for (int i = 2 * m_T + 3; i < 2 * m_T + 3 + m_N; ++i)
				{
					b[i] = M;
				}
				b[2 * m_T + 3 + m_N] = -K_L;
				// matrix A
				za::ma::com::Matrix A(2 * m_T + 2 + 1 + m_N + 1, m_T + m_N);
				for (int i = 0; i < m_T; ++i)
				{
					for (int j = 0; j < m_N; ++j)
					{
						A[i][j] = m_retMatrix[j][i] - m_assetRet[j];
					}
					A[i][m_N + i] = -1;
				}
				for (int i = m_T; i < 2 * m_T; ++i)
				{
					for (int j = m_N; j < 2 * m_N; ++j)
					{
						A[i][j] = -m_retMatrix[j - m_N][i - m_T] + m_assetRet[j - m_N];
					}
					A[i][m_N + i - m_T] = -1;
				}
				for (int j = 0; j < m_N; ++j)
				{
					A[2 * m_T][j] = 1;
					A[2 * m_T + 1][j] = -1;
					A[2 * m_T + 2][j] = -m_assetRet[j];
				}
				// constraints for percentage limit
				for (int i = 2 * m_T + 3; i < 2 * m_T + 3 + m_N; ++i)
				{
					A[i][i - (2 * m_T + 3)] = 1;
				}
				// constraints for assets 1 and 2
				A[2 * m_T + 3 + m_N][0] = -1;
				A[2 * m_T + 3 + m_N][1] = -1;
				za::ma::com::LPSolver solver(A, b, c);
				solver.setMinimization();
				solver.solve(results, objVal);
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