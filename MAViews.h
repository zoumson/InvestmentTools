#pragma once
#include "MAUtilities.h"
#include "MAFixedIncome.h"
#include "MAEquities.h"


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

			};

#pragma endregion equities


		}
	}

}