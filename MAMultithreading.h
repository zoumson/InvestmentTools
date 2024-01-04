#pragma once
#include "MAUtilities.h"



namespace za
{
	namespace ma
	{
		namespace mt
		{

#pragma region Example1
			struct ThreadData;
			class Thread 
			{
			public:
				Thread();
				virtual ~Thread();
			private:
				Thread(const Thread& p); // no copy allowed
				Thread& operator=(const Thread& p); // no assignment allowed
			public:
				virtual void run() = 0;
				void start();
				void endThread();
				void setJoinable(bool yes);
				void join();
			private:
				ThreadData* m_data;
				bool m_joinable;
			};

			class TestThread : public Thread 
			{
			public:
				virtual void run();
			};
	
#pragma endregion Example1

#pragma region Example2

			class ParallelOptionsProbabilities
			{
			public:
				ParallelOptionsProbabilities(int size, double strike, double sigma);
				ParallelOptionsProbabilities(const ParallelOptionsProbabilities& p);
				~ParallelOptionsProbabilities();
				ParallelOptionsProbabilities& operator=(const
					ParallelOptionsProbabilities& p);
				double probFinishAboveStrike();
			private:
				int m_numSteps; // number of steps
				double m_step; // size of each step (in percentage)
				double m_strikePrice; // starting price
			};
			class RandomWalkThread : public Thread
			{
			public:
				RandomWalkThread(int num_steps, double sigma, double startPrice);
				~RandomWalkThread();
				virtual void run();
				double gaussianValue(double mean, double sigma);
				double getLastPriceOfWalk();
				double result();
			private:
				int m_numberOfSteps; // number of steps
				double m_sigma; // size of each step (in percentage)
				double m_startingPrice; // starting price
				double m_result;
			};
			
#pragma endregion Example2

#pragma region Example3
			struct MutexData;
			class Mutex 
			{
			public:
				Mutex();
				~Mutex();
				void lock();
				void unlock();
			private:
				Mutex(const Mutex& p); // copy not allowed
				Mutex& operator=(const Mutex& p); // assignment not allowed
				MutexData* m_data;
			};
			class MutexAccess 
			{
			public:
				MutexAccess(Mutex& m);
				~MutexAccess();
			private:
				MutexAccess& operator=(const MutexAccess& p);
				MutexAccess(const MutexAccess& p);
				Mutex& m_mutex;
			};
			class MutexTestThread : public Thread 
			{
			public:
				MutexTestThread(double& result, double incVal);
				~MutexTestThread();
				void run();
			private:
				double& m_result;
				double m_incValue;
				static Mutex m_globalMutex;
			};
			
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