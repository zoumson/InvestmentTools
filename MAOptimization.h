#pragma once
#include "MAUtilities.h"




namespace za
{
	namespace ma
	{
		namespace op
		{

#pragma region Example1
			//already define in glk header file 
			//struct glp_prob;


			//class LPSolver 
			//{
			//public:
			//	
			//	LPSolver(za::ma::com::Matrix& A, const std::vector<double>& b, const std::vector<double>& c);
			//	LPSolver(za::ma::com::Matrix& A, const std::vector<double>& b, const std::vector<double>& c, const std::string& probname);
			//	LPSolver(const LPSolver& p);
			//	~LPSolver();
			//	LPSolver& operator=(const LPSolver& p);
			//	enum ResultType 
			//	{
			//		INFEASIBLE,
			//		FEASIBLE,
			//		ERROR
			//	};
			//	virtual ResultType solve(std::vector<double>& result, double & objValue);
			//	void setName(const std::string& s);
			//	bool isValid();

			//	//if wanted to call these parents functions on child object override it and call it as LPSolver::setMaximization
			//	virtual void setMaximization();
			//	virtual void setMinimization();
			//private:
			//	size_t m_M;
			//	size_t m_N;
			//	std::vector<double> m_c;
			//	std::vector<double> m_b;
			//	za::ma::com::Matrix m_A;
			//	glp_prob* m_lp;
			//	void initProblem(size_t M, size_t N);
			//	void setRowBounds();
			//	void setColumnCoefs();
			//protected:
			//	glp_prob* getLP();
			//	int getNumCols();
			//	int getNumRows();
			//};
#pragma endregion Example1

#pragma region Example2

			class TwoDimensionalLPSolver 
			{
			public:
				using Vector = std::vector<double>;
				TwoDimensionalLPSolver(const Vector& c, const Vector& A1, const Vector& A2, const Vector& b);
				TwoDimensionalLPSolver(const TwoDimensionalLPSolver& p);
				~TwoDimensionalLPSolver();
				TwoDimensionalLPSolver& operator=(const TwoDimensionalLPSolver& p);
				bool solveProblem(Vector& results, double& objVal);
			private:
				std::vector<double> m_c;
				std::vector<double> m_A1;
				std::vector<double> m_A2;
				std::vector<double> m_b;
			};
#pragma endregion Example2

#pragma region Example3
			//class MIPSolver : public za::ma::com::LPSolver 
			//{
			//public:
			//	MIPSolver(za::ma::com::Matrix& A, const std::vector<double>& b, const std::vector<double>& c);
			//	MIPSolver(const MIPSolver& p);
			//	~MIPSolver();
			//	MIPSolver& operator=(const MIPSolver& p);
			//	//override in order to call it from child class 
			//	void setMaximization() override;
			//	void setMinimization()override;
			//	void setColInteger(int colNum);
			//	void setColBinary(int colNum);
			//	za::ma::com::LPSolver::ResultType solve(std::vector<double>& result, double& objValue) override;
			//};
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