#pragma once
#include "MAUtilities.h"





namespace za
{
	namespace ma
	{
		namespace cl
		{

#pragma region Example1
			enum RecommendationType 
			{
				BUY,
				SELL,
				HOLD,
				NO_RECOMMENDATION
			};
#pragma endregion Example1

#pragma region Example2
			class Recommendation 
			{
			public:
				Recommendation();
				Recommendation(const std::string& ticker, RecommendationType rec,double target);
				~Recommendation();
				Recommendation(const Recommendation& r);
				Recommendation& operator =(const Recommendation& r);
				double getTarget() const;
				RecommendationType getRecommendation() const;
				const std::string& getTicker() const;
			private:
				std::string m_ticker;
				RecommendationType m_recType;
				double m_target;
			};
#pragma endregion Example2

#pragma region Example3
			class RecommendationsProcessor 
			{
			public:
				RecommendationsProcessor();
				~RecommendationsProcessor();
				RecommendationsProcessor(const RecommendationsProcessor&);
				RecommendationsProcessor& operator =(const RecommendationsProcessor&);
				void addRecommendation(const std::string& ticker, RecommendationType
					rec, double
					targetPrice);
				double averageTargetPrice(const std::string& ticker);
				RecommendationType averageRecommendation(const std::string& ticker);
			private:
				std::map<std::string, std::vector<Recommendation> > m_recommendations;
			};

#pragma endregion Example3

#pragma region Example4
			class TimeSeriesTransformations 
			{
			public:
				TimeSeriesTransformations();
				TimeSeriesTransformations(const TimeSeriesTransformations&);
				~TimeSeriesTransformations();
				TimeSeriesTransformations& operator=(const TimeSeriesTransformations&);
				void reducePrices(double val);

				void increasePrices(double val);
				void removePricesLessThan(double val);
				void removePricesGreaterThan(double val);
				double getFirstPriceLessThan(double val);
				void addValue(double val);
				void addValues(const std::vector<double>& val);


			private:
				std::vector<double> m_prices;
			};
#pragma endregion Example4

#pragma region Example5
			class FileManager 
			{
			public:
				FileManager(const std::string& basePath);
				FileManager(const FileManager&);
				~FileManager();
				FileManager& operator=(const FileManager&);
				void removeFiles();
				std::vector<std::string> getDirectoryContents();
				void listContents();
				void copyToTempDirectory(const std::string& prefix);
			private:
				std::string m_basePath;
			};
#pragma endregion Example5

#pragma region Example6
			class Date  : public boost::gregorian::date
			{
			public:
				enum class DayOfWeek 
				{
					Sun,
					Mon,
					Tue,
					Wed,
					Thu,
					Fri,
					Sat
				};
				Date(int year, int month, int day);
				~Date();
				bool isLeapYear();
				Date& operator++();
				bool operator<(const Date& d);
				DayOfWeek getDayOfWeek();
				int daysInterval(const Date&);
				bool isTradingDay();
				std::string toStringDate(Date::DayOfWeek day);
			private:
				int m_year;
				int m_month;
				int m_day;
			};

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