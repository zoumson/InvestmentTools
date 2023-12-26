#pragma once
#include "MAUtilities.h"
#include "MAFixedIncome.h"


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


		}
	}

}