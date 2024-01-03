#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <vector>
#include <regex>
#include <numeric>
#include <utility>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <concepts>
#include <cstdint>
#include <variant>
#include <set>
#include <map>
#include <iterator>
#include <functional>
#include <stack>
#include <cmath>
#include <optional>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/ratio.hpp>
#include <boost/math/distributions.hpp>
#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <glpk.h>

namespace za
{
	namespace ma
	{
		namespace com
		{
			//define constructor inside header 
			template <class Res>
			class MathFunction
			{
			public:
				MathFunction()
				{

				};
				virtual ~MathFunction()
				{

				};
				virtual Res operator()(Res value) = 0;
			};			
			
			template <class Res>
			class MathFunction2
			{
			public:
				MathFunction2()
				{

				};
				virtual ~MathFunction2()
				{

				};
				virtual Res operator()(Res val1, Res val2) = 0;
			};

			class Matrix
			{
			public:
				typedef std::vector<double> Row;
				Matrix(int size, int size2);
				Matrix(int size);
				Matrix(const Matrix& s);
				~Matrix();
				Matrix& operator=(const Matrix& s);
				int getRow();
				int getCol();
				void transpose();
				double trace();
				void add(const Matrix& s);
				void subtract(const Matrix& s);
				void multiply(const Matrix& s);
				Row& operator[](int pos);
			private:
				std::vector<Row> m_rows;
			};
			Matrix operator+(const Matrix& s1, const Matrix& s2);
			Matrix operator-(const Matrix& s1, const Matrix& s2);
			Matrix operator*(const Matrix& s1, const Matrix& s2);

		}
	}

}