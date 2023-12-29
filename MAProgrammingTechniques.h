#pragma once
#include "MAUtilities.h"





namespace za
{
	namespace ma
	{
		namespace pt
		{

#pragma region Example1
			class BondInstrument {
			public:
				BondInstrument(double principal, double monthlyPayment);
				~BondInstrument();
				BondInstrument(const BondInstrument& a);
				BondInstrument& operator =(const BondInstrument& a);
				double getMonthlyPayment();
				double getPrincipal();
			private:
				double
					m_monthlyPay,
					m_principal;
			};
#pragma endregion Example1

#pragma region Example2
			class MortgageInstrument 
			{
			public:
				MortgageInstrument(double monthlyPay, double propertyValue, double
					downpayment);
				~MortgageInstrument();
				MortgageInstrument(const MortgageInstrument& a);
				MortgageInstrument& operator =(const MortgageInstrument& a);
				double getMonthlyPayment();
				double getPrincipal();
				// other methods here...
			private:
				double
					m_monthlyPay,
					m_propertyValue,
					m_downPayment;
			};
#pragma endregion Example2

#pragma region Example3
			//use optional for default template data member initialization 
			template <class T>
			class IntRateEngine 
			{
			public:
				IntRateEngine() = default;
				~IntRateEngine();
				IntRateEngine(const IntRateEngine<T>& a);
				IntRateEngine<T>& operator =(const IntRateEngine<T>& a);
				void setInstrument(T& inv);
				double getAnnualIntRate();
			private:
				std::optional<T>m_instrument;

			};
	
			template <class T>
			IntRateEngine<T>::~IntRateEngine()
			{
			}
			template <class T>
			IntRateEngine<T>::IntRateEngine(const IntRateEngine<T>& a)
				: m_instrument(a.m_instrument)
			{
			}
			template <class T>
			IntRateEngine<T>& IntRateEngine<T>::operator =(const IntRateEngine<T>& a)
			{
				if (this != &a)
				{
					m_instrument = a.m_instrument;
				}
				return *this;
			}
			template <class T>
			void IntRateEngine<T>::setInstrument(T& inv)
			{
				m_instrument = inv;
			}
			template <class T>
			double IntRateEngine<T>::getAnnualIntRate()
			{
				//optional is pointer
				double payment = (*m_instrument).getMonthlyPayment();
				double principal = (*m_instrument).getPrincipal();
				return (12 * payment) / principal;
			}
#pragma endregion Example3

#pragma region Example4
			class FinancialStatement 
			{
			public:
				FinancialStatement();
				~FinancialStatement();
				FinancialStatement(const FinancialStatement&);
				FinancialStatement& operator=(FinancialStatement&);
				double getReturn();
				void addTransaction(const std::string& security, double val);
			private:
				double m_return;
				std::vector<std::pair<std::string, double> > m_transactions;
			};
			std::unique_ptr<FinancialStatement> getSampleStatement();
			void transferFinancialStatement(std::unique_ptr<FinancialStatement>& statement);
			//void transferFinancialStatement();
#pragma endregion Example4

#pragma region Example5
			class CreditRisk 
			{
				
			public:
				// these are risk grades, as determined by rating agencies
				enum RiskType 
				{
					AAA,
					AAPlus,
					AA,
					APlus,
					A,
					BPlus,
					B,
					CPlus,
					C
				};
				// other methods here ...
				RiskType getRating();
				void setRating(RiskType& risk);
			private:
				RiskType m_risk;
			};


#pragma endregion Example5

#pragma region Example6
			class RiskCalculator 
			{
			public:
				RiskCalculator();
				~RiskCalculator();
				RiskCalculator(const RiskCalculator&);
				RiskCalculator& operator =(const RiskCalculator&);
				void addCreditRisk(std::shared_ptr<CreditRisk> risk);
				CreditRisk::RiskType portfolioMaxRisk();
				CreditRisk::RiskType portfolioMinRisk();
			private:
				std::vector<std::shared_ptr<CreditRisk> > m_creditRisks;
			};

#pragma endregion Example6

#pragma region Example7
			enum TransactionType 
			{
				TRANSACTION_SELL,
				TRANSACTION_BUY,
				TRANSACTION_SHORT,
			};

#pragma endregion Example7


#pragma region Example8
			class FileError :public std::runtime_error 
			//class FileError :public std::exception
			{
				//std::string what_message;
			public:
				FileError(const std::string& s);
				//const char* what() const override;
			};

#pragma endregion Example8


#pragma region Example9
			class TransactionTypeError :public std::runtime_error 
			{
			public:
				TransactionTypeError(const std::string& s);
			};

#pragma endregion Example9

#pragma region Example10
			class TransactionHandler 
			{
			public:
				static const std::string SELL_OP;
				static const std::string BUY_OP;
				static const std::string SHORT_OP;
				TransactionHandler(const std::string& fileName);
				TransactionHandler(const TransactionHandler&);
				~TransactionHandler();
				TransactionHandler& operator=(const TransactionHandler&);
				void handleTransactions();
			private:
				std::string m_fileName;
			};

#pragma endregion Example10
			
#pragma region Example11

			class NumVector 
			{
			public:
				NumVector();
				~NumVector();
				NumVector(const NumVector&);
				NumVector& operator =(const NumVector&);
				void add(double val);
				void removeLast();
				double get(int pos) const;
				size_t size() const;
			private:
				std::vector<double> m_values;
			};
			NumVector operator +(const NumVector& a, const NumVector& b);
			NumVector operator -(const NumVector& a, const NumVector& b);
			NumVector operator *(const NumVector& a, const NumVector& b);
#pragma endregion Example11	


#pragma region Example12


#pragma endregion Example12

#pragma region Example13


#pragma endregion Example13

		}
	}
}