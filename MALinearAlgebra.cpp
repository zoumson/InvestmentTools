#pragma once
#include "MALinearAlgebra.h"






namespace za
{
	namespace ma
	{
		namespace la
		{

#pragma region Example1
			//VectorOperations::VectorOperations(const std::vector<double>& p)
			//	: m_data(p)
			//{
			//}

			//VectorOperations::VectorOperations(const VectorOperations& p)
			//	: m_data(p.m_data)
			//{
			//}
			//VectorOperations::~VectorOperations()
			//{
			//}
			//VectorOperations& VectorOperations::operator=(const VectorOperations& p)
			//{
			//	if (this != &p)
			//	{
			//		m_data = p.m_data;
			//	}
			//	return *this;
			//}
			//std::vector<double> VectorOperations::scalarMult(double scalar)
			//{
			//	boost::numeric::ublas::vector<double> vx;
			//	std::copy(m_data.begin(), m_data.end(), vx.end());
			//	boost::numeric::ublas::vector<double> res = vx * scalar;
			//	std::vector<double> v;
			//	std::copy(res.begin(), res.end(), v.end());
			//	return v;
			//}
			//std::vector<double> VectorOperations::addVector(const std::vector<double>& vec)
			//{
			//	//using namespace boost::numeric::ublas;
			//	boost::numeric::ublas::vector<double> v1;
			//	std::copy(m_data.begin(), m_data.end(), v1.end());
			//	boost::numeric::ublas::vector<double> v2;
			//	std::copy(vec.begin(), vec.end(), v2.end());
			//	boost::numeric::ublas::vector<double> v3 = v1 + v2;
			//	std::vector<double> v;
			//	std::copy(v3.begin(), v3.end(), v.end());
			//	return v;
			//}
			//double VectorOperations::norm()
			//{
			//	//using namespace boost::numeric::ublas;
			//	boost::numeric::ublas::vector<double> v1;
			//	std::copy(m_data.begin(), m_data.end(), v1.end());
			//	double res = boost::numeric::ublas::norm_2(v1);
			//	return res;
			//}
			//std::vector<double> VectorOperations::subtractVector(const std::vector<double>& vec)
			//{
			//	//using namespace boost::numeric::ublas;
			//	boost::numeric::ublas::vector<double> v1;
			//	std::copy(m_data.begin(), m_data.end(), v1.end());
			//	boost::numeric::ublas::vector<double> v2;
			//	std::copy(vec.begin(), vec.end(), v2.end());
			//	boost::numeric::ublas::vector<double> v3 = v1 - v2;
			//	std::vector<double> v;
			//	std::copy(v3.begin(), v3.end(), v.end());
			//	return v;
			//}
			//double VectorOperations::dotProd(const std::vector<double>& v)
			//{
			//	//using namespace boost::numeric::ublas;
			//	boost::numeric::ublas::vector<double> v1;
			//	std::copy(m_data.begin(), m_data.end(), v1.end());
			//	boost::numeric::ublas::vector<double> v2;
			//	std::copy(v.begin(), v.end(), v2.end());
			//	double res = boost::numeric::ublas::inner_prod(v1, v2);
			//	return res;
			//}
#pragma endregion Example1

#pragma region Example2
			/*Matrix::Matrix(int size)
			{
				for (unsigned i = 0; i < size; ++i)
				{
					std::vector<double> row(size, 0);
					m_rows.push_back(row);
				}
			}
			Matrix::Matrix(int size, int size2)
			{
				for (unsigned i = 0; i < size; ++i)
				{
					std::vector<double> row(size2, 0);
					m_rows.push_back(row);
				}
			}
			Matrix::Matrix(const Matrix& s)
				: m_rows(s.m_rows)
			{
			}
			Matrix::~Matrix()
			{
			}
			Matrix& Matrix::operator=(const Matrix& s)
			{
				if (this != &s)
				{
					m_rows = s.m_rows;
				}
				return *this;
			}
			Matrix::Row& Matrix::operator[](int pos)
			{
				return m_rows[pos];
			}
			void Matrix::transpose()
			{
				std::vector<Row> rows;
				for (unsigned i = 0; i < m_rows[0].size(); ++i)
				{
					std::vector<double> row;
					for (unsigned j = 0; j < m_rows.size(); ++j)
					{
						row[j] = m_rows[j][i];
					}
					rows.push_back(row);
				}
				m_rows.swap(rows);
			}
			double Matrix::trace()
			{
				if (m_rows.size() != m_rows[0].size())
				{
					return 0;
				}
				double total = 0;
				for (unsigned i = 0; i < m_rows.size(); ++i)
				{
					total += m_rows[i][i];
				}
				return total;
			}
			void Matrix::add(const Matrix& s)
			{
				if (m_rows.size() != s.m_rows.size() ||
					m_rows[0].size() != s.m_rows[0].size())
				{
					throw new std::runtime_error("invalid matrix dimensions");
				}
				for (unsigned i = 0; i < m_rows.size(); ++i)
				{
					for (unsigned j = 0; j < m_rows[0].size(); ++j)
					{
						m_rows[i][j] += s.m_rows[i][j];
					}
				}
			}
			void Matrix::subtract(const Matrix& s)
			{
				if (m_rows.size() != s.m_rows.size() ||
					m_rows[0].size() != s.m_rows[0].size())
				{
					throw new std::runtime_error("invalid matrix dimensions");
				}
				for (unsigned i = 0; i < m_rows.size(); ++i)
				{
					for (unsigned j = 0; j < m_rows[0].size(); ++j)
					{
						m_rows[i][j] += s.m_rows[i][j];
					}
				}
			}
			void Matrix::multiply(const Matrix& s)
			{
				if (m_rows[0].size() != s.m_rows.size())
				{
					throw new std::runtime_error("invalid matrix dimensions");
				}
				std::vector<Row> rows;
				for (unsigned i = 0; i < m_rows.size(); ++i)
				{
					std::vector<double> row;
					for (unsigned j = 0; j < s.m_rows.size(); ++j)
					{
						double Mij = 0;
						for (unsigned k = 0; k < m_rows[0].size(); ++k)
						{
							Mij += m_rows[i][k] * s.m_rows[k][j];
						}
						row.push_back(Mij);
					}
					rows.push_back(row);
				}
				m_rows.swap(rows);
			}
			Matrix operator+(const Matrix& s1, const Matrix& s2)
			{
				Matrix s(s1);
				s.subtract(s2);
				return s;
			}
			Matrix operator-(const Matrix& s1, const Matrix& s2)
			{
				Matrix s(s1);
				s.subtract(s2);
				return s;
			}
			Matrix operator*(const Matrix& s1, const Matrix& s2)
			{
				Matrix s(s1);
				s.multiply(s2);
				return s;
			}*/




			//namespace ublas = boost::numeric::ublas;
			//using std::cout;
			//using std::endl;
			//MatrixOperations::MatrixOperations()
			//{
			//}
			//MatrixOperations::~MatrixOperations()
			//{
			//}


			//void MatrixOperations::addRow(const std::vector<double>& row)
			//{
			//	m_rows.push_back(row);
			//}
			//static Matrix fromMatrix(const boost::numeric::ublas::matrix<double>& mp)
			//{
			//	//using namespace ublas;
			//	int d1 = mp.size1();
			//	int d2 = mp.size2();
			//	Matrix res(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			res[i][j] = mp(i, j);
			//		}
			//	}
			//	return res;
			//}
			//Matrix MatrixOperations::elementwiseMultiply(Matrix& m)
			//{
			//	//using namespace ublas;
			//	int d1 = m_rows.size();
			//	int d2 = m_rows[0].size();
			//	boost::numeric::ublas::matrix<double> M(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M(i, j) = m_rows[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::matrix<double> M2(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M2(i, j) = m[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::matrix<double> mp = boost::numeric::ublas::element_prod(M, M2);
			//	return fromMatrix(mp);
			//}
			//Matrix MatrixOperations::transpose()
			//{
			//	//using namespace ublas;
			//	int d1 = m_rows.size();
			//	int d2 = m_rows[0].size();
			//	boost::numeric::ublas::matrix<double> M(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M(i, j) = m_rows[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::matrix<double> mp = boost::numeric::ublas::trans(M);
			//	return fromMatrix(mp);
			//}
			//Matrix MatrixOperations::multiply(Matrix& m)
			//{
			//	//using namespace ublas;
			//	int d1 = m_rows.size();
			//	int d2 = m_rows[0].size();
			//	boost::numeric::ublas::matrix<double> M(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M(i, j) = m_rows[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::matrix<double> M2(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M2(i, j) = m[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::matrix<double> mp = boost::numeric::ublas::prod(M, M2);
			//	return fromMatrix(mp);
			//}
			//Matrix MatrixOperations::scalarMultiply(double scalar)
			//{
			//	//using namespace ublas;
			//	int d1 = m_rows.size();
			//	int d2 = m_rows[0].size();
			//	boost::numeric::ublas::matrix<double> M(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M(i, j) = m_rows[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::matrix<double> mp = scalar * M;
			//	return fromMatrix(mp);
			//}
			//std::vector<double> MatrixOperations::preMultiply(const std::vector<double>& v)
			//{
			//	//using namespace ublas;
			//	boost::numeric::ublas::vector<double> vec;
			//	std::copy(v.begin(), v.end(), vec.end());
			//	int d1 = m_rows.size();
			//	int d2 = m_rows[0].size();
			//	boost::numeric::ublas::matrix<double> M(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M(i, j) = m_rows[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::vector<double> pv = boost::numeric::ublas::prod(vec, M);
			//	std::vector<double> res;
			//	std::copy(pv.begin(), pv.end(), res.end());
			//	return res;
			//}
			//std::vector<double> MatrixOperations::postMultiply(const std::vector<double>& v)
			//{
			//	//using namespace ublas;
			//	boost::numeric::ublas::vector<double> vec;
			//	std::copy(v.begin(), v.end(), vec.end());
			//	int d1 = m_rows.size();
			//	int d2 = m_rows[0].size();
			//	boost::numeric::ublas::matrix<double> M(d1, d2);
			//	for (int i = 0; i < d1; ++i)
			//	{
			//		for (int j = 0; j < d2; ++j)
			//		{
			//			M(i, j) = m_rows[i][j];
			//		}
			//	}
			//	boost::numeric::ublas::vector<double> pv = prod(M, vec);
			//	std::vector<double> res;
			//	std::copy(pv.begin(), pv.end(), res.end());
			//	return res;
			//}


#pragma endregion Example2

#pragma region Example3
//				int getDeterminantSign(const boost::numeric::ublas::permutation_matrix<std::size_t>& pm)
//				{
//					int sign = 1;
//					for (int i = 0; i < pm.size(); ++i)
//					{
//						if (i != pm(i))
//						{
//							sign *= -1.0;
//						}
//					}
//					return sign;
//
//				}
//// returns the value of the determinant for matrix m
//				double computeDeterminant(boost::numeric::ublas::matrix<double>& m)
//				{
//					boost::numeric::ublas::permutation_matrix<std::size_t> pm(m.size1());
//					double det = 1.0;
//					if (boost::numeric::ublas::lu_factorize(m, pm))
//					{
//						det = 0.0;
//					}
//					else
//					{
//						for (int i = 0; i < m.size1(); i++)
//						{
//							det *= m(i, i);
//						}
//						det = det * getDeterminantSign(pm);
//					}
//					return det;
//				}

			//void determinantSample()
			//{
			//	boost::numeric::ublas::matrix<double> M(3, 3);
			//	for (unsigned i = 0; i < M.size1(); ++i)
			//	{
			//		for (unsigned j = 0; j < M.size2(); ++j)
			//		{
			//			M(i, j) = sin(3 * j);
			//		}
			//	}
			//	double determinant = computeDeterminant(M);
			//	std::cout << " determinant value is " << determinant
			//		<< " for matrix " << M << std:: endl;
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