#include "MAProgrammingTechniques.h"



namespace za
{
	namespace ma
	{
		namespace pt
		{

#pragma region Example1
			BondInstrument::BondInstrument(double principal, double monthlyPayment)
				: m_principal(principal), m_monthlyPay(monthlyPayment)
			{
			}
			BondInstrument::~BondInstrument()
			{
			}
			BondInstrument::BondInstrument(const BondInstrument& a)
				: m_monthlyPay(a.m_monthlyPay), m_principal(a.m_principal)
			{
			}
			BondInstrument& BondInstrument::operator =(const BondInstrument& a)
			{
				if (this != &a)
				{
					m_principal = a.m_principal;
					m_monthlyPay = a.m_monthlyPay;
				}
				return *this;
			}
			double BondInstrument::getMonthlyPayment()
			{
				return m_monthlyPay;
			}
			double BondInstrument::getPrincipal()
			{
				return m_principal;
			}
#pragma endregion Example1

#pragma region Example2
			MortgageInstrument::MortgageInstrument(double monthlyPay, double propertyValue, double downpayment)
				: m_monthlyPay(monthlyPay), m_propertyValue(propertyValue), m_downPayment(downpayment)
			{
			}
			MortgageInstrument::~MortgageInstrument()
			{
			}
			MortgageInstrument::MortgageInstrument(const MortgageInstrument& a)
				: m_downPayment(a.m_downPayment), m_propertyValue(a.m_propertyValue), m_monthlyPay(a.m_monthlyPay)
			{
			}
			MortgageInstrument& MortgageInstrument::operator =(const MortgageInstrument& a)
			{
				if (this != &a)
				{
					m_downPayment = a.m_downPayment;
					m_propertyValue = a.m_propertyValue;
					m_monthlyPay = a.m_monthlyPay;
				}
				return *this;
			}
			double MortgageInstrument::getMonthlyPayment()
			{
				return m_monthlyPay;
			}
			double MortgageInstrument::getPrincipal()
			{
				return m_propertyValue - m_downPayment;
			}
#pragma endregion Example2

#pragma region Example3


#pragma endregion Example3

#pragma region Example4
			FinancialStatement::FinancialStatement(): m_return(0)
			{
			}
			FinancialStatement::~FinancialStatement()
			{
			}
			FinancialStatement::FinancialStatement(const FinancialStatement& v)
				: m_return(v.m_return), m_transactions(v.m_transactions)
			{
			}
			FinancialStatement& FinancialStatement::operator=(FinancialStatement& v)
			{
				if (this != &v)
				{
					m_return = v.m_return;
					m_transactions = v.m_transactions;
				}
				return *this;
			}
			double FinancialStatement::getReturn()
			{
				return m_return;
			}
			void FinancialStatement::addTransaction(const std::string& security, double val)
			{
				m_transactions.push_back(std::make_pair(security, val));
			}
			// returns a sample statement that includes a few common stocks
			std::unique_ptr<FinancialStatement> getSampleStatement()
			{
				std::unique_ptr<FinancialStatement> fs(new FinancialStatement);
				fs->addTransaction("IBM", 102.2);
				fs->addTransaction("AAPL", 523.0);
				return fs;
			}
			void transferFinancialStatement(std::unique_ptr<FinancialStatement>& statement)
			//void transferFinancialStatement()
			{
				// perform transfer here
				// ...
				// statement is still valid
				std::unique_ptr<FinancialStatement> another = std::move(statement);
				// statement is released here
				std::cout << another->getReturn() << std::endl;
				//std::cout << statement->getReturn() << std::endl;
				// another is released here
				
			}
#pragma endregion Example4

#pragma region Example5
			CreditRisk::RiskType CreditRisk::getRating()
			{
				return m_risk;
			}			
			
			void CreditRisk::setRating(CreditRisk::RiskType& risk)
			{
				m_risk = risk;
			}
#pragma endregion Example5

#pragma region Example6
			RiskCalculator::RiskCalculator()
			{
			}
			RiskCalculator::~RiskCalculator()
			{
			}
			RiskCalculator::RiskCalculator(const RiskCalculator& v): m_creditRisks(v.m_creditRisks)
			{
			}
			RiskCalculator& RiskCalculator::operator =(const RiskCalculator& v)
			{
				if (this != &v)
				{
					m_creditRisks = v.m_creditRisks;
				}
				return *this;
			}
			void RiskCalculator::addCreditRisk(std::shared_ptr<CreditRisk> risk)
			{
				m_creditRisks.push_back(risk);
			}
	
			CreditRisk::RiskType RiskCalculator::portfolioMaxRisk()
			{
				auto risk = CreditRisk::RiskType::AAA;
				for (auto& p : m_creditRisks)
				{
					if (p->getRating() < risk)
					{
						risk = p->getRating();
					}
				}
				return risk;
			}

			CreditRisk::RiskType RiskCalculator::portfolioMinRisk()
			{
				CreditRisk::RiskType risk = CreditRisk::RiskType::C;
					for (int i = 0; i < m_creditRisks.size(); ++i)
					{
						if (m_creditRisks[i]->getRating() > risk)
						{
							risk = m_creditRisks[i]->getRating();
						}
					}
				return risk;
			}
#pragma endregion Example6
			
#pragma region Example7


#pragma endregion Example7	

#pragma region Example8
			FileError::FileError(const std::string& s): std::runtime_error(s)
			{
			}

#pragma endregion Example8

#pragma region Example9
			TransactionTypeError::TransactionTypeError(const std::string& s): std::runtime_error(s)
			{
			}

#pragma endregion Example9

#pragma region Example10

			const std::string TransactionHandler::SELL_OP = "SELL";
			const std::string TransactionHandler::BUY_OP = "BUY";
			const std::string TransactionHandler::SHORT_OP = "SHORT";
			TransactionHandler::TransactionHandler(const std::string& fileName): m_fileName(fileName)
			{
				std::ifstream file;

				file.open(m_fileName, std::ifstream::in);
				if (file.fail())
				{
					//dont throw exeption with new keyord, throw by value 
					throw FileError(std::string("error opening file ") + m_fileName);
				}
			}
			TransactionHandler::TransactionHandler(const TransactionHandler& a): m_fileName(a.m_fileName)
			{
			}
			TransactionHandler::~TransactionHandler()
			{
			}
			TransactionHandler& TransactionHandler::operator=(const TransactionHandler& a)
			{
				if (this != &a)
				{
					m_fileName = a.m_fileName;
				}
				return *this;
			}
			void TransactionHandler::handleTransactions()
			{
				std::ifstream file;

				file.open(m_fileName, std::ifstream::in);
				if (file.fail())
				{
					throw FileError(std::string("error opening file ") + m_fileName);
				}
				std::string op;
				file >> op;
				while (file.good() && !file.eof())
				{
					if (op != SELL_OP && op != BUY_OP && op != SHORT_OP)
					{
						throw TransactionTypeError(std::string("unknown transaction ") + op);
					}
					// process remaining transaction data...
				}
			}
#pragma endregion Example10


#pragma region Example11
			NumVector::NumVector()
			{
			}
			NumVector::~NumVector()
			{
			}
			NumVector::NumVector(const NumVector& v): m_values(v.m_values)
			{
			}
			NumVector& NumVector::operator=(const NumVector& v)
			{
				if (this != &v)
				{
					m_values = v.m_values;
				}
				return *this;
			}
			size_t NumVector::size() const
			{
				return m_values.size();
			}
			double NumVector::get(int pos) const
			{
				return m_values[pos];
			}
			void NumVector::add(double val)
			{
				m_values.push_back(val);
			}
			void NumVector::removeLast()
			{
				m_values.pop_back();
			}
			NumVector operator +(const NumVector& a, const NumVector& b)
			{
				if (a.size() != b.size())
				{
					throw std::runtime_error("vectors must have the same size");
				}

				NumVector result;
				for (int i = 0; i < a.size(); ++i)
				{
					result.add(a.get(i) + b.get(i));
				}
				return result;
			}
			NumVector operator -(const NumVector& a, const NumVector& b)
			{
				if (a.size() != b.size())
				{
					throw std::runtime_error("vectors must have the same size");
				}
				NumVector result;
				for (int i = 0; i < a.size(); ++i)
				{
					result.add(a.get(i) - b.get(i));
				}
				return result;
			}
			NumVector operator *(const NumVector& a, const NumVector& b)
			{
				if (a.size() != b.size())
				{
					throw std::runtime_error("vectors must have the same size");
				}
				NumVector result;
				for (int i = 0; i < a.size(); ++i)
				{
					result.add(a.get(i) * b.get(i));
				}
				return result;
			}
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