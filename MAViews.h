#pragma once
#include "MAUtilities.h"
#include "MAFixedIncome.h"
#include "MAEquities.h"
#include "MAProgrammingTechniques.h"
#include "MACommonLibraries.h"
#include "MANumerical.h"
#include "MALinearAlgebra.h"
#include "MAInterpolation.h"
#include "MARoot.h"
#include "MANumericalIntegration.h"
#include "MAOdePde.h"
#include "MAOdePde.h"
#include "MAOptimization.h"
#include "MAAssetPortfolio.h"
#include "MAMonteCarlo.h"
#include "MAMultithreading.h"
#include "MAFunctionObject.h"
#include "MAEigen.h"


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
#pragma region linearAgebra

			//namespace la
			//{
			//	//void matrixOperations();

			//};
#pragma endregion linearAgebra

#pragma region interpolation

			namespace it
			{
				void linearInterpolation();
				void polynomialInterpolation();

			};
#pragma endregion interpolation

#pragma region root

			namespace re
			{
				void bisectionMethod();
				void secantMethod();
				void newtonMethod();

			};
#pragma endregion root

#pragma region numericalIntegration

			namespace ni
			{
				using namespace za::ma::ni;
				void midpointIntegration();
				void trapezoidIntegration();
				void simpsonsIntegration();
			}

#pragma endregion numericalIntegration

#pragma region OdePde

			namespace od
			{
				using namespace za::ma::od;
				void eulersMethod();
				void rungeKuttaODEMethod();
				void blackScholescloseForm();
				void blackScholesForwardMethod();
				void blackScholesGreeksCloseForm();
				void blackScholesMonteCarlo();
				void blackScholesGreeksFiniteDifferenceMethod();
				void blackScholesGreeksMonteCarloFDM();
			}

#pragma endregion OdePde
#pragma region Optimization

			namespace op
			{
				using namespace za::ma::op;
				void lpSolver();
				void twoDimensionalLPSolver();
				void mipSolver();
			}

#pragma endregion Optimization

#pragma region assetPortfolio

			namespace ap
			{
				using namespace za::ma::ap;
				void resourceAlloc();
				void modifiedCAP();

			}

#pragma endregion assetPortfolio
#pragma region monteCarlo

			namespace mc
			{
				using namespace za::ma::mc;
				void monteCarloIntegration();
				void randomWalk();
				void optionsProbabilities();
				//void closeFormBlackHole();
				//void monteCarloBlackHole();
				//void calcGreeks();
			}

#pragma endregion monteCarlo

#pragma region mutltithreading

			namespace mt
			{
				using namespace za::ma::mt;
				void testThread();
				void parallelRandomWalk();
				void mutexTestThread();

			}

#pragma endregion mutltithreading

#pragma region functionObject

			namespace fo
			{
				using namespace za::ma::fo;
				void functionPointer();
				void functionObject();

			}

#pragma endregion functionObject
#pragma region eigenLib

			namespace eg
			{
				using namespace za::ma::eg;
				void basicUsage();

				void basicLinearAlgebra1();
				void basicLinearAlgebra2();
				void basicLinearAlgebra3();
				void basicLinearAlgebra4();
				void basicLinearAlgebra5();
				void basicLinearAlgebra6();
				void basicLinearAlgebra7();

				void advancedLinearAlgebra1();
				void advancedLinearAlgebra2();
				void advancedLinearAlgebra3();
				void advancedLinearAlgebra4();


			}

#pragma endregion eigenLib

		}
	}

}