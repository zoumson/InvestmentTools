#pragma once
#include "MACommonLibraries.h"






namespace za
{
	namespace ma
	{
		namespace cl
		{

#pragma region Example1
			
#pragma endregion Example1

#pragma region Example2
			Recommendation::Recommendation()
				: m_recType(HOLD),
				m_target(0)
			{
			}
			Recommendation::Recommendation(const std::string& ticker, RecommendationType rec, double target)
				: m_ticker(ticker),
				m_recType(rec),
				m_target(target)
			{
			}
			Recommendation::~Recommendation()
			{
			}
			Recommendation::Recommendation(const Recommendation& r)
				: m_ticker(r.m_ticker),
				m_recType(r.m_recType),
				m_target(r.m_target)
			{
			}
			Recommendation& Recommendation::operator =(const Recommendation& r)
			{
				if (this != &r)
				{
					m_ticker = r.m_ticker;
					m_recType = r.m_recType;
					m_target = r.m_target;
				}
				return *this;
			}
			double Recommendation::getTarget() const
			{
				return m_target;
			}
			RecommendationType Recommendation::getRecommendation() const
			{
				return m_recType;
			}
			const std::string& Recommendation::getTicker() const
			{
				return m_ticker;
			}
#pragma endregion Example2

#pragma region Example3
			RecommendationsProcessor::RecommendationsProcessor()
			{
			}
			RecommendationsProcessor::~RecommendationsProcessor()
			{
			}
			RecommendationsProcessor::RecommendationsProcessor(const RecommendationsProcessor& r): m_recommendations(r.m_recommendations)
			{
			}
			RecommendationsProcessor& RecommendationsProcessor::operator=(const RecommendationsProcessor& r)
			{
				if (this != &r)
				{
					m_recommendations = r.m_recommendations;
				}
				return *this;
			}
			void RecommendationsProcessor::addRecommendation(const std::string& ticker, RecommendationType rec, double targetPrice)
			{
				Recommendation r(ticker, rec, targetPrice);
				m_recommendations[ticker].push_back(r);
			}
			double RecommendationsProcessor::averageTargetPrice(const std::string& ticker)
			{
				if (m_recommendations.find(ticker) == m_recommendations.end())
				{
					return 0;
				}
				auto vrec = m_recommendations[ticker];
				std::vector<double> prices;
				for (auto i = 0; i < vrec.size(); ++i)
				{
					prices.push_back(vrec[i].getTarget());
				}
				return std::accumulate(prices.begin(), prices.end(), 0) / prices.size();
			}
			RecommendationType RecommendationsProcessor::averageRecommendation(const std::string& ticker)
			{
				double avg = 0;
				if (m_recommendations.find(ticker) == m_recommendations.end())
				{
					return RecommendationType::NO_RECOMMENDATION;
				}
				auto vrec = m_recommendations[ticker];
				std::vector<int> recommendations;
				for (auto i = 0; i < vrec.size(); ++i)
				{
					recommendations.push_back((int)vrec[i].getRecommendation() + 1);
				}
				return (RecommendationType)(int)(avg / recommendations.size());
			}
#pragma endregion Example3

#pragma region Example4
			TimeSeriesTransformations::TimeSeriesTransformations(): m_prices()
			{
			}
			TimeSeriesTransformations::TimeSeriesTransformations(const TimeSeriesTransformations& s): m_prices(s.m_prices)
			{
			}
			TimeSeriesTransformations::~TimeSeriesTransformations()
			{
			}
			TimeSeriesTransformations& TimeSeriesTransformations::operator=(const TimeSeriesTransformations& v)
			{
				if (this != &v)
				{
					m_prices = v.m_prices;
				}
				return *this;
			}

			void TimeSeriesTransformations::reducePrices(double val)
			{
				std::vector<double> neg(m_prices.size());
				//std::transform(m_prices.begin(), m_prices.end(), neg.begin(), std::bind2nd(std::minus<double>(), val));
				//orignal value is kept intact 
				//new value is appened to neg 
				//std::minus<double>(double arg1, double arg2) = arg2 - arg1
				//arg1 = std::placeholders::_1, used for the price 
				//arg2 = val, used for the dicount amount 
				//always start by the first placeholder then second for representing an unkwnow 
				std::transform(m_prices.begin(), m_prices.end(), neg.begin(), [&](double& price) { return price - val; });
				//std::transform(m_prices.begin(), m_prices.end(), neg.begin(), std::bind(std::minus<double>(), std::placeholders::_1, val));
		
			    //exchange content, old by reduced one 
				m_prices.swap(neg);
			}
			void TimeSeriesTransformations::increasePrices(double val)
			{
				//std::for_each(m_prices.begin(), m_prices.end(), std::bind1st(std::plus<double>(), val));
				std::for_each(m_prices.begin(), m_prices.end(), std::bind(std::plus<double>(), std::placeholders::_1, val));
			}
			void TimeSeriesTransformations::removePricesLessThan(double val)
			{
				//std::remove_if(m_prices.begin(), m_prices.end(), std::bind2nd(std::less<double>(), val));
				std::remove_if(m_prices.begin(), m_prices.end(), std::bind(std::less<double>(), std::placeholders::_1, val));
			}
			void TimeSeriesTransformations::removePricesGreaterThan(double val)
			{
				//std::remove_if(m_prices.begin(), m_prices.end(), std::bind2nd(std::greater<double>(), val));
				std::remove_if(m_prices.begin(), m_prices.end(), std::bind(std::greater<double>(), std::placeholders::_1, val));
			}
			double TimeSeriesTransformations::getFirstPriceLessThan(double val)
			{
				auto res = std::find_if(m_prices.begin(), m_prices.end(), std::bind(std::less<double>(), std::placeholders::_1, val));
				if (res != m_prices.end())
				{
					return *res;
				}
				return 0;
			}
			void TimeSeriesTransformations::addValue(double val)
			{
				m_prices.push_back(val);
			}
			//append a vector to a vector 
			void TimeSeriesTransformations::addValues(const std::vector<double>& val)
			{
				m_prices.insert(m_prices.end(), val.begin(), val.end());
			}
#pragma endregion Example4

#pragma region Example5
			FileManager::FileManager(const std::string& basePath)
				: m_basePath(basePath)
			{
			}
			FileManager::FileManager(const FileManager& v)
				: m_basePath(v.m_basePath)
			{
			}
			FileManager::~FileManager()
			{
			}
			FileManager& FileManager::operator=(const FileManager& v)
			{
				if (this != &v)
				{
					m_basePath = v.m_basePath;
				}
				return *this;
			}
			void FileManager::removeFiles()
			{
				std::vector<std::string> files = getDirectoryContents();
				for (unsigned i = 0; i < files.size(); ++i)
				{
					std::filesystem::path aPath(files[i]);
					if (std::filesystem::is_regular_file(aPath))
					{
						std::cout << " path " << files[i] << " is not a regular file "<< std::endl;
					}
					else
					{
						std::filesystem::remove(aPath);
					}
				}
			}
			void FileManager::listContents()
			{
				std::vector<std::string> files = getDirectoryContents();
				for (unsigned i = 0; i < files.size(); ++i)
				{
					std::filesystem:: path aPath(files[i]);
					if (std::filesystem::is_regular_file(aPath))
					{
						std::cout << aPath.string() << std::endl;
					}
				}
			}
			std::vector<std::string> FileManager::getDirectoryContents()
			{
				std::vector<std::string> results;
				std::filesystem::path aPath(m_basePath);
				if (!std::filesystem::is_directory(aPath))
				{
					std::cout << " incorrect path was used " << std::endl;
				}
				else
				{
					auto iterator = std::filesystem::directory_iterator(aPath);
					std::vector <std::filesystem::path> contents;
					std::copy(std::filesystem::directory_iterator(aPath), std::filesystem::directory_iterator(), back_inserter(contents));
					for (unsigned i = 0; i < contents.size(); ++i)
					{
						results.push_back(contents[i].string());
					}
				}
				return results;
			}
			void FileManager::copyToTempDirectory(const std::string& tmpDir)
			{
				const std::filesystem::path tmpPath(tmpDir);
				std::filesystem::path aPath(m_basePath);
				if (!std::filesystem::is_directory(aPath))
				{
					std::cout << " incorrect path was used " << std::endl;
					return;
				}
				std::cout << " copying the following files: " << std::endl;
				this->listContents();
				std::vector<std::string> contents = getDirectoryContents();
				for (auto it = std::filesystem::directory_iterator(aPath); it != std::filesystem::directory_iterator(); ++it)
				{
					if (std::filesystem::is_regular_file(it->path()))
					{
						std::filesystem::copy_file(it->path(), tmpPath);
					}
				}
			}
#pragma endregion Example5

#pragma region Example6
			Date::Date(int year, int month, int day)
				: boost::gregorian::date(year, month, day),
				m_year(year),
				m_month(month),
				m_day(day)
			{
			}
			Date::~Date()
			{
			}
			bool Date::isLeapYear()
			{
				if (m_year % 4 != 0) return false;
				if (m_year % 100 != 0) return true;
				if (m_year % 400 != 0) return false;
				return true;
			}
			Date& Date::operator++()
			{
				std::vector<int> monthsWith31 = { 1, 3, 5, 7, 8, 10, 12 };
				if (m_day == 31)
				{
					m_day = 1;
					m_month++;
				}
				else if (m_day == 30 &&
					std::find(monthsWith31.begin(),
						monthsWith31.end(), m_month) == monthsWith31.end())
				{
					m_day = 1;
					m_month++;
				}
				else if (m_day == 29 && m_month == 2)
				{
					m_day = 1;
					m_month++;
				}
				else if (m_day == 28 && m_month == 2 && !isLeapYear())
				{
					m_day = 1;
					m_month++;
				}
				else
				{
					m_day++;
				}
				if (m_month > 12)
				{
					m_month = 1;
					m_year++;
				}return *this;
			}
			int Date::daysInterval(const Date& d)
			{
				//boost::gregorian::date d1(2005, 4, 1);
				Date bdate1(m_year, m_month, m_day);
				Date bdate2(d.m_year, d.m_month, d.m_day);
				//boost::gregorian::date d1(2005, 1, 1);
				//boost::gregorian::date d2(2006, 1, 1);
				//boost::gregorian::date_duration duration = d1 - d2;
				boost::gregorian::date_duration duration = (boost::gregorian::date)bdate1 - bdate2;
				//boost::gregorian::date_duration duration(bdate1 - bdate2);
				return (int)duration.days();
				//return 2;
			}
			bool Date::operator<(const Date& d)
			{
				if (m_year < d.m_year) 
				{
					return true;
				}
				if (m_year == d.m_year && m_month < d.m_month)
				{
					return true;
				}
				if (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day)
				{
					return true;
				}

				return false;
			}
			Date::DayOfWeek Date::getDayOfWeek()
			{
				int day = 1;
				Date d(1900, 1, 1);
				for (; d < *this; ++d)
				{
					if (day == 7) 
					{
						day = 1;
					}

					else 
					{
						day++;
					}

				}
				return (DayOfWeek)day;
			}
			bool Date::isTradingDay()
			{
				DayOfWeek dayOfWeek = getDayOfWeek();
				if (dayOfWeek == DayOfWeek::Sun || dayOfWeek == DayOfWeek::Sat)
				{
					return false;
				}
				return true;
			}
			std::string Date::toStringDate(Date::DayOfWeek day)
			{
				switch (day)
				{
					case DayOfWeek::Sun: return "Sunday";
					case DayOfWeek::Mon: return "Monday";
					case DayOfWeek::Tue: return "Tuesday";
					case DayOfWeek::Wed: return "Wednesday";
					case DayOfWeek::Thu: return "Thursday";
					case DayOfWeek::Fri: return "Friday";
					case DayOfWeek::Sat: return "Saturday";
				}
				throw std::runtime_error("unknown day of week");
			}

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