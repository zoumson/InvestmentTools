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