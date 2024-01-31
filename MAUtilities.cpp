//#include "MAUtilities.h"
////circular dependency 
//#include "MANumericalClasses.h"
//
//
//namespace za
//{
//	namespace ma
//	{
//		namespace com
//		{
//			double pi() { return std::atan(1) * 4; };
//
//			//double gaussianBoxMuller()
//			//{
//			//	double x = 0.0;
//			//	double y = 0.0;
//			//	double euclidSq = 0.0;
//			//	//continue generating two uniform random variables 
//			//	//until the square of their euclidean distance is less than unity 
//			//	do
//			//	{
//			//		x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
//			//		y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
//
//			//		euclidSq = x * x + y * y;
//			//	} while (euclidSq >= 1.0);
//
//			//	return x * std::sqrt(-2 * std::log(euclidSq) / euclidSq);
//
//			//}
//
//			Matrix::Matrix(int size)
//			{
//				for (unsigned i = 0; i < size; ++i)
//				{
//					std::vector<double> row(size, 0);
//					m_rows.push_back(row);
//				}
//			}
//			Matrix::Matrix(int size, int size2)
//			{
//				for (unsigned i = 0; i < size; ++i)
//				{
//					std::vector<double> row(size2, 0);
//					m_rows.push_back(row);
//				}
//			}
//			Matrix::Matrix(const Matrix& s)
//				: m_rows(s.m_rows)
//			{
//			}
//			Matrix::~Matrix()
//			{
//			}
//			Matrix& Matrix::operator=(const Matrix& s)
//			{
//				if (this != &s)
//				{
//					m_rows = s.m_rows;
//				}
//				return *this;
//			}			
//			
//			int Matrix::getRow()
//			{
//
//				return m_rows.size();
//
//			}
//						
//			int Matrix::getCol()
//			{
//				if (m_rows.size() == 0)
//				{
//					return 0;
//				}
//				return m_rows[0].size();
//
//			}
//
//			Matrix::Row& Matrix::operator[](int pos)
//			{
//				return m_rows[pos];
//			}
//			void Matrix::transpose()
//			{
//				std::vector<Row> rows;
//				for (unsigned i = 0; i < m_rows[0].size(); ++i)
//				{
//					std::vector<double> row;
//					for (unsigned j = 0; j < m_rows.size(); ++j)
//					{
//						row[j] = m_rows[j][i];
//					}
//					rows.push_back(row);
//				}
//				m_rows.swap(rows);
//			}
//			double Matrix::trace()
//			{
//				if (m_rows.size() != m_rows[0].size())
//				{
//					return 0;
//				}
//				double total = 0;
//				for (unsigned i = 0; i < m_rows.size(); ++i)
//				{
//					total += m_rows[i][i];
//				}
//				return total;
//			}
//			void Matrix::add(const Matrix& s)
//			{
//				if (m_rows.size() != s.m_rows.size() ||
//					m_rows[0].size() != s.m_rows[0].size())
//				{
//					throw new std::runtime_error("invalid matrix dimensions");
//				}
//				for (unsigned i = 0; i < m_rows.size(); ++i)
//				{
//					for (unsigned j = 0; j < m_rows[0].size(); ++j)
//					{
//						m_rows[i][j] += s.m_rows[i][j];
//					}
//				}
//			}
//			void Matrix::subtract(const Matrix& s)
//			{
//				if (m_rows.size() != s.m_rows.size() ||
//					m_rows[0].size() != s.m_rows[0].size())
//				{
//					throw new std::runtime_error("invalid matrix dimensions");
//				}
//				for (unsigned i = 0; i < m_rows.size(); ++i)
//				{
//					for (unsigned j = 0; j < m_rows[0].size(); ++j)
//					{
//						m_rows[i][j] += s.m_rows[i][j];
//					}
//				}
//			}
//			void Matrix::multiply(const Matrix& s)
//			{
//				if (m_rows[0].size() != s.m_rows.size())
//				{
//					throw new std::runtime_error("invalid matrix dimensions");
//				}
//				std::vector<Row> rows;
//				for (unsigned i = 0; i < m_rows.size(); ++i)
//				{
//					std::vector<double> row;
//					for (unsigned j = 0; j < s.m_rows.size(); ++j)
//					{
//						double Mij = 0;
//						for (unsigned k = 0; k < m_rows[0].size(); ++k)
//						{
//							Mij += m_rows[i][k] * s.m_rows[k][j];
//						}
//						row.push_back(Mij);
//					}
//					rows.push_back(row);
//				}
//				m_rows.swap(rows);
//			}
//			Matrix operator+(const Matrix& s1, const Matrix& s2)
//			{
//				Matrix s(s1);
//				s.subtract(s2);
//				return s;
//			}
//			Matrix operator-(const Matrix& s1, const Matrix& s2)
//			{
//				Matrix s(s1);
//				s.subtract(s2);
//				return s;
//			}
//			Matrix operator*(const Matrix& s1, const Matrix& s2)
//			{
//				Matrix s(s1);
//				s.multiply(s2);
//				return s;
//			}
//
//
//
//			LPSolver::LPSolver(Matrix& m, const std::vector<double>& b, const std::vector<double>& c)
//				: m_M(m.getRow()),
//				m_N(m[0].size()),
//				m_c(c),
//				m_b(b),
//				m_A(m),
//				m_lp(glp_create_prob())
//			{
//				initProblem(m_M, m_N);
//			}
//			LPSolver::LPSolver(Matrix& m, const std::vector<double>& b, const std::vector<double>& c, const std::string& probname)
//				: m_M(m.getRow()),
//				m_N(m[0].size()),
//				m_c(c),
//				m_b(b),
//				m_A(m),
//				m_lp(glp_create_prob())
//			{
//				initProblem(m_M, m_N);
//				glp_set_prob_name(m_lp, probname.c_str());
//			}
//			LPSolver::LPSolver(const LPSolver& p)
//				: m_M(p.m_M),
//				m_N(p.m_N),
//				m_c(p.m_c),
//				m_b(p.m_b),
//				m_A(p.m_A),
//				m_lp(glp_create_prob())
//			{
//				initProblem(m_M, m_N);
//			}
//			// performs necessary initialization of the given values
//			void LPSolver::initProblem(size_t M, size_t N)
//			{
//				if (!m_lp) return;
//				setRowBounds();
//				setColumnCoefs();
//				std::vector<int> I, J;
//				std::vector<double> V;
//				// indices in GLPK start on 1
//				I.push_back(0);
//				J.push_back(0);
//				V.push_back(0);
//				for (int i = 0; i < M; ++i)
//				{
//					for (int j = 0; j < N; ++j)
//					{
//						I.push_back(i + 1);
//						J.push_back(j + 1);
//						V.push_back(m_A[i][j]);
//					}
//				}
//				glp_load_matrix(m_lp, (int)(m_M * m_N), &I[0], &J[0], &V[0]);
//			}
//			LPSolver::~LPSolver()
//			{
//				glp_delete_prob(m_lp);
//			}
//			LPSolver& LPSolver::operator=(const LPSolver& p)
//			{
//				if (this != &p)
//				{
//					m_M = p.m_M;
//					m_N = p.m_N;
//					m_c = p.m_c;
//					m_b = p.m_b;
//					m_A = p.m_A;
//					m_lp = glp_create_prob();
//					initProblem(m_M, m_N);
//				}
//
//				return *this;
//			}
//			void LPSolver::setName(const std::string& s)
//			{
//				glp_set_prob_name(m_lp, s.c_str());
//			}
//			bool LPSolver::isValid()
//			{
//				return m_lp != NULL;
//			}
//			void LPSolver::setMaximization()
//			{
//				glp_set_obj_dir(m_lp, GLP_MAX);
//			}
//			void LPSolver::setMinimization()
//			{
//				glp_set_obj_dir(m_lp, GLP_MIN);
//			}
//			void LPSolver::setRowBounds()
//			{
//				glp_add_rows(m_lp, (int)m_M);
//				for (int i = 0; i < m_M; ++i)
//				{
//					glp_set_row_bnds(m_lp, i + 1, GLP_UP, 0.0, m_b[i]);
//				}
//			}
//			void LPSolver::setColumnCoefs()
//			{
//				glp_add_cols(m_lp, (int)m_N);
//				for (int j = 0; j < m_N; ++j)
//				{
//					glp_set_col_bnds(m_lp, j + 1, GLP_LO, 0.0, 0.0);
//					glp_set_obj_coef(m_lp, j + 1, m_c[j]);
//				}
//			}
//			LPSolver::ResultType LPSolver::solve(std::vector<double>& result, double& objValue)
//			{
//				glp_simplex(m_lp, NULL);
//				result.resize(m_N, 0);
//				objValue = glp_get_obj_val(m_lp);
//				for (int j = 0; j < m_N; ++j)
//				{
//					result[j] = glp_get_col_prim(m_lp, j + 1);
//				}
//				return LPSolver::FEASIBLE;
//			}
//			glp_prob* LPSolver::getLP()
//			{
//				return m_lp;
//			}
//			int LPSolver::getNumCols()
//			{
//				return (int)m_N;
//			}
//			int LPSolver::getNumRows()
//			{
//				return (int)m_M;
//			}
//
//			MIPSolver::MIPSolver(Matrix& A, const std::vector<double>& b, const std::vector<double>& c) : LPSolver(A, b, c)
//			{
//			}
//
//			MIPSolver::MIPSolver(const MIPSolver& p) : LPSolver(p)
//			{
//			}
//
//			MIPSolver::~MIPSolver()
//			{
//			}
//
//			MIPSolver& MIPSolver::operator=(const MIPSolver& p)
//			{
//				return *this;
//			}
//
//			void MIPSolver::setColInteger(int colNum)
//			{
//				glp_set_col_kind(getLP(), colNum + 1, GLP_IV);
//			}
//
//			void MIPSolver::setColBinary(int colNum)
//			{
//				glp_set_col_kind(getLP(), colNum + 1, GLP_BV);
//			}
//			void MIPSolver::setMaximization()
//			{
//				LPSolver::setMaximization();
//			}
//
//			void MIPSolver::setMinimization()
//			{
//				LPSolver::setMinimization();
//			}
//
//
//			LPSolver::ResultType MIPSolver::solve(std::vector<double>& result, double& objValue)
//			{
//				glp_simplex(getLP(), NULL);
//				int res = glp_intopt(getLP(), NULL);
//				if (res != 0)
//				{
//					std::cout << "res = " << res << " \n";
//				}
//				result.resize(getNumCols(), 0);
//				objValue = glp_mip_obj_val(getLP());
//				for (int i = 0; i < getNumCols(); ++i)
//				{
//					result[i] = glp_mip_col_val(getLP(), i + 1);
//				}
//				return LPSolver::FEASIBLE;
//			}
//
//		}
//	}
//
//}