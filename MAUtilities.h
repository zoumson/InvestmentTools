#pragma once

#include "MAJokers.h"
#include "MANumericalClasses.h"


//#include <algorithm>
//#include <string>
//#include <iostream>
//#include <fstream>
//#include <filesystem>
//#include <stdexcept>
//#include <vector>
//#include <regex>
//#include <numeric>
//#include <utility>
//#include <memory>
//#include <stdexcept>
//#include <unordered_map>
//#include <concepts>
//#include <cstdint>
//#include <variant>
//#include <set>
//#include <map>
//#include <iterator>
//#include <functional>
//#include <stack>
//#include <cmath>
//#include <optional>
//#include <boost/date_time/gregorian/gregorian.hpp>
//#include <boost/ratio.hpp>
//#include <boost/math/distributions.hpp>
//#include <boost/random.hpp>
//#include <boost/random/normal_distribution.hpp>
//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>
//#include <boost/numeric/ublas/lu.hpp>
//#include <glpk.h>
//#include <cstdlib>
//#include <random>
//#include <pthread.h>
//#include <Eigen/Dense>
//#include <Eigen/LU>
////in oder to use pi constant value M_PI
////#define _USE_MATH_DEFINES
//namespace za
//{
//	namespace ma
//	{
//		namespace com
//		{
//			static std::default_random_engine random_generator;
//			static boost::rand48 boost_random_generator;
//			double pi();
//			//double gaussianBoxMuller();
//			//define constructor inside header 
//			template <class Res>
//			class MathFunction
//			{
//			public:
//				MathFunction()
//				{
//
//				};
//				virtual ~MathFunction()
//				{
//
//				};
//				virtual Res operator()(Res value) = 0;
//			};			
//			
//			template <class Res>
//			class MathFunction2
//			{
//			public:
//				MathFunction2()
//				{
//
//				};
//				virtual ~MathFunction2()
//				{
//
//				};
//				virtual Res operator()(Res val1, Res val2) = 0;
//			};
//
//			class Matrix
//			{
//			public:
//				typedef std::vector<double> Row;
//				Matrix(int size, int size2);
//				Matrix(int size);
//				Matrix(const Matrix& s);
//				~Matrix();
//				Matrix& operator=(const Matrix& s);
//				int getRow();
//				int getCol();
//				void transpose();
//				double trace();
//				void add(const Matrix& s);
//				void subtract(const Matrix& s);
//				void multiply(const Matrix& s);
//				Row& operator[](int pos);
//			private:
//				std::vector<Row> m_rows;
//			};
//			Matrix operator+(const Matrix& s1, const Matrix& s2);
//			Matrix operator-(const Matrix& s1, const Matrix& s2);
//			Matrix operator*(const Matrix& s1, const Matrix& s2);
//
//
//
//			class LPSolver
//			{
//			public:
//
//				LPSolver(Matrix& A, const std::vector<double>& b, const std::vector<double>& c);
//				LPSolver(Matrix& A, const std::vector<double>& b, const std::vector<double>& c, const std::string& probname);
//				LPSolver(const LPSolver& p);
//				~LPSolver();
//				LPSolver& operator=(const LPSolver& p);
//				enum ResultType
//				{
//					INFEASIBLE,
//					FEASIBLE,
//					ERROR
//				};
//				virtual ResultType solve(std::vector<double>& result, double& objValue);
//				void setName(const std::string& s);
//				bool isValid();
//
//				//if wanted to call these parents functions on child object override it and call it as LPSolver::setMaximization
//				virtual void setMaximization();
//				virtual void setMinimization();
//			private:
//				size_t m_M;
//				size_t m_N;
//				std::vector<double> m_c;
//				std::vector<double> m_b;
//				Matrix m_A;
//				glp_prob* m_lp;
//				void initProblem(size_t M, size_t N);
//				void setRowBounds();
//				void setColumnCoefs();
//			protected:
//				glp_prob* getLP();
//				int getNumCols();
//				int getNumRows();
//			};
//
//			class MIPSolver : public LPSolver
//			{
//			public:
//				MIPSolver(Matrix& A, const std::vector<double>& b, const std::vector<double>& c);
//				MIPSolver(const MIPSolver& p);
//				~MIPSolver();
//				MIPSolver& operator=(const MIPSolver& p);
//				//override in order to call it from child class 
//				void setMaximization() override;
//				void setMinimization()override;
//				void setColInteger(int colNum);
//				void setColBinary(int colNum);
//				LPSolver::ResultType solve(std::vector<double>& result, double& objValue) override;
//			};
//
//			//double pi() { return std::atan(1) * 4; }
//			/*constexpr double pi() { return std::atan(1) * 4; }*/
//		}
//	}
//
//}