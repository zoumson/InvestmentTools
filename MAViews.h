#pragma once
#include "MAUtilities.h"
#include "MAFixedIncome.h"
#include "MAEquities.h"
#include "MAProgrammingTechniques.h"
#include "MACommonLibraries.h"
#include "MANumerical.h"





namespace za
{
	namespace ma
	{
		namespace ex
		{

#pragma region fixedIncome

			namespace fi
			{
				void interestRateCalculator();
				void compoundInterestRateCalculator();
				void cashFlowCalculator();
				void bondCalculator();

			};

#pragma endregion fixedIncome

#pragma region equities

			namespace eq
			{
				void maCalculator();
				void volatilityCalculator();
				void correlationCalculator();
				void fundamentalsCalc();
			}

#pragma endregion equities

#pragma region programmingTechniques

			namespace pt
			{
				void intRateEngine();
				void financialStatement();
				void transactionHandler();

			};
#pragma endregion programmingTechniques

#pragma region commonLibraries

			namespace cl
			{

				void timeSeriesTransformations();
				void fileManager();
				void dateHandle();

			};
#pragma endregion commonLibraries

#pragma region numericalClasses

			namespace nc
			{
				void factorialTemplate();
				void calmarRatio();
				void distributionData();

			};
#pragma endregion numericalClasses


		}
	}

}