#pragma once
#include "MAOptimization.h"






namespace za
{
	namespace ma
	{
		namespace op
		{

#pragma region Example1


			//LPSolver::LPSolver(za::ma::com::Matrix& m, const std::vector<double>& b, const std::vector<double>& c)
			//	: m_M(m.getRow()),
			//	m_N(m[0].size()),
			//	m_c(c),
			//	m_b(b),
			//	m_A(m),
			//	m_lp(glp_create_prob())
			//{
			//	initProblem(m_M, m_N);
			//}
			//LPSolver::LPSolver(za::ma::com::Matrix& m, const std::vector<double>& b,const std::vector<double>& c, const std::string& probname)
			//	: m_M(m.getRow()),
			//	m_N(m[0].size()),
			//	m_c(c),
			//	m_b(b),
			//	m_A(m),
			//	m_lp(glp_create_prob())
			//{
			//	initProblem(m_M, m_N);
			//	glp_set_prob_name(m_lp, probname.c_str());
			//}
			//LPSolver::LPSolver(const LPSolver& p)
			//	: m_M(p.m_M),
			//	m_N(p.m_N),
			//	m_c(p.m_c),
			//	m_b(p.m_b),
			//	m_A(p.m_A),
			//	m_lp(glp_create_prob())
			//{
			//	initProblem(m_M, m_N);
			//}
			//// performs necessary initialization of the given values
			//void LPSolver::initProblem(size_t M, size_t N)
			//{
			//	if (!m_lp) return;
			//	setRowBounds();
			//	setColumnCoefs();
			//	std::vector<int> I, J;
			//	std::vector<double> V;
			//	// indices in GLPK start on 1
			//	I.push_back(0);
			//	J.push_back(0);
			//	V.push_back(0);
			//	for (int i = 0; i < M; ++i)
			//	{
			//		for (int j = 0; j < N; ++j)
			//		{
			//			I.push_back(i + 1);
			//			J.push_back(j + 1);
			//			V.push_back(m_A[i][j]);
			//		}
			//	}
			//	glp_load_matrix(m_lp, (int)(m_M * m_N), &I[0], &J[0], &V[0]);
			//}
			//LPSolver::~LPSolver()
			//{
			//	glp_delete_prob(m_lp);
			//}
			//LPSolver& LPSolver::operator=(const LPSolver& p)
			//{
			//	if (this != &p)
			//	{
			//		m_M = p.m_M;
			//		m_N = p.m_N;
			//		m_c = p.m_c;
			//		m_b = p.m_b;
			//		m_A = p.m_A;
			//		m_lp = glp_create_prob();
			//		initProblem(m_M, m_N);
			//	}

			//	return *this;
			//}
			//void LPSolver::setName(const std::string& s)
			//{
			//	glp_set_prob_name(m_lp, s.c_str());
			//}
			//bool LPSolver::isValid()
			//{
			//	return m_lp != NULL;
			//}
			//void LPSolver::setMaximization()
			//{
			//	glp_set_obj_dir(m_lp, GLP_MAX);
			//}
			//void LPSolver::setMinimization()
			//{
			//	glp_set_obj_dir(m_lp, GLP_MIN);
			//}
			//void LPSolver::setRowBounds()
			//{
			//	glp_add_rows(m_lp, (int)m_M);
			//	for (int i = 0; i < m_M; ++i)
			//	{
			//		glp_set_row_bnds(m_lp, i + 1, GLP_UP, 0.0, m_b[i]);
			//	}
			//}
			//void LPSolver::setColumnCoefs()
			//{
			//	glp_add_cols(m_lp, (int)m_N);
			//	for (int j = 0; j < m_N; ++j)
			//	{
			//		glp_set_col_bnds(m_lp, j + 1, GLP_LO, 0.0, 0.0);
			//		glp_set_obj_coef(m_lp, j + 1, m_c[j]);
			//	}
			//}
			//LPSolver::ResultType LPSolver::solve(std::vector<double>& result, double& objValue)
			//{
			//	glp_simplex(m_lp, NULL);
			//	result.resize(m_N, 0);
			//	objValue = glp_get_obj_val(m_lp);
			//	for (int j = 0; j < m_N; ++j)
			//	{
			//		result[j] = glp_get_col_prim(m_lp, j + 1);
			//	}
			//	return LPSolver::FEASIBLE;
			//}
			//glp_prob* LPSolver::getLP()
			//{
			//	return m_lp;
			//}
			//int LPSolver::getNumCols()
			//{
			//	return (int)m_N;
			//}
			//int LPSolver::getNumRows()
			//{
			//	return (int)m_M;
			//}
#pragma endregion Example1

#pragma region Example2
			TwoDimensionalLPSolver::TwoDimensionalLPSolver(const Vector& c, const Vector& A1, const Vector& A2, const Vector& b)
				: m_c(c),
				m_A1(A1),
				m_A2(A2),
				m_b(b)
			{
			}
			TwoDimensionalLPSolver::TwoDimensionalLPSolver(const TwoDimensionalLPSolver& p)
				: m_c(p.m_c),
				m_A1(p.m_A1),
				m_A2(p.m_A2),
				m_b(p.m_b)
			{
			}
			TwoDimensionalLPSolver::~TwoDimensionalLPSolver()
			{
			}
			TwoDimensionalLPSolver& TwoDimensionalLPSolver::operator=(const TwoDimensionalLPSolver& p)
			{
				if (this != &p)
				{
					m_c = p.m_c;
					m_A1 = p.m_A1;
					m_A2 = p.m_A2;
					m_b = p.m_b;
				}
				return *this;
			}
			bool TwoDimensionalLPSolver::solveProblem(Vector& res, double& objVal)
			{
				int size = m_b.size();
				za::ma::com:: Matrix A(size, 2);
				for (int j = 0; j < size; ++j)
				{
					A[j][0] = m_A1[j];
					A[j][1] = m_A2[j];
				}
				za::ma::com::LPSolver solver(A, m_b, m_c);
				solver.setMaximization();
				return solver.solve(res, objVal) == za::ma::com::LPSolver::ResultType::FEASIBLE;
			}
#pragma endregion Example2

#pragma region Example3

			//MIPSolver::MIPSolver(za::ma::com::Matrix& A, const std::vector<double>& b, const std::vector<double>& c): LPSolver(A, b, c)
			//{
			//}

			//MIPSolver::MIPSolver(const MIPSolver& p) : LPSolver(p)
			//{
			//}

			//MIPSolver::~MIPSolver()
			//{
			//}

			//MIPSolver& MIPSolver::operator=(const MIPSolver& p)
			//{
			//	return *this;
			//}

			//void MIPSolver::setColInteger(int colNum)
			//{
			//	glp_set_col_kind(getLP(), colNum + 1, GLP_IV);
			//}

			//void MIPSolver::setColBinary(int colNum)
			//{
			//	glp_set_col_kind(getLP(), colNum + 1, GLP_BV);
			//}
			//void MIPSolver::setMaximization()
			//{
			//	za::ma::com::LPSolver::setMaximization();
			//}			
			//
			//void MIPSolver::setMinimization()
			//{
			//	za::ma::com::LPSolver::setMinimization();
			//}


			//za::ma::com::LPSolver::ResultType MIPSolver::solve(std::vector<double>& result, double& objValue)
			//{
			//	glp_simplex(getLP(), NULL);
			//	int res = glp_intopt(getLP(), NULL);
			//	if (res != 0)
			//	{
			//		std::cout << "res = " << res << " \n";
			//	}
			//	result.resize(getNumCols(), 0);
			//	objValue = glp_mip_obj_val(getLP());
			//	for (int i = 0; i < getNumCols(); ++i)
			//	{
			//		result[i] = glp_mip_col_val(getLP(), i + 1);
			//	}
			//	return za::ma::com::LPSolver::FEASIBLE;
			//}

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