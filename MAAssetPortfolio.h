#pragma once
#include "MAUtilities.h"






namespace za
{
	namespace ma
	{
		namespace ap
		{

#pragma region Example1
			class ResourceAlloc 
			{
			public:
				ResourceAlloc(std::vector<double>& result, double& objVal);
				ResourceAlloc(const ResourceAlloc& p);
				~ResourceAlloc();
				ResourceAlloc& operator=(const ResourceAlloc& p);
				void solveProblem();
			private:
				std::vector<double>& m_results;
				double& m_objVal;
			};
#pragma endregion Example1

#pragma region Example2
			class ModifiedCAP 
			{
			public:
				ModifiedCAP(int N, int T, double R, za::ma::com::Matrix& retMatrix, const std::vector<double>& ret);
				ModifiedCAP(const ModifiedCAP& p);
				~ModifiedCAP();
				ModifiedCAP& operator=(const ModifiedCAP& p);
				void solveModel(std::vector<double>& results, double& objVal);
				void solveExtendedModel(std::vector<double>& results, double& objVal);
			private:
				int m_N; // number of investment
				int m_T; // number of periods
				double m_R; // desired return
				za::ma::com::Matrix m_retMatrix;
				std::vector<double> m_assetRet; // single returns
			};


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