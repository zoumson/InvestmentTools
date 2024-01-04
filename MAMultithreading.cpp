#include "MAMultithreading.h"



namespace za
{
	namespace ma
	{
		namespace mt
		{

#pragma region Example1
			struct ThreadData 
			{
				pthread_t m_thread;
				pthread_attr_t m_attr;
			};

			void* thread_function(void* data)
			{
				Thread* t = reinterpret_cast<Thread*>(data);
				t->run();
				return nullptr;
			}
			
			Thread::Thread(): m_data(new ThreadData), m_joinable(false)
			{
				pthread_attr_init(&m_data->m_attr);
			}
			Thread::~Thread()
			{
				if (m_data)
				{
					delete m_data;
				}
			}

			void Thread::start()
			{
				pthread_create(&m_data->m_thread, &m_data->m_attr, thread_function, this);
			}
			void Thread::endThread()
			{
				pthread_exit(nullptr);
			}
			void Thread::setJoinable(bool yes)
			{
				pthread_attr_setdetachstate(&m_data->m_attr, yes ? PTHREAD_CREATE_JOINABLE : PTHREAD_CREATE_DETACHED);
				m_joinable = yes;
			}
			void Thread::run()
			{
				std::cout << " no concrete implementation provided " << std::endl;
			}
			void Thread::join()
			{
				if (!m_joinable)
				{
					std::cout << " thread cannot be joined " << std::endl;
				}
				else
				{
					void* result;
					pthread_join(m_data->m_thread, &result);
				}
			}

			void TestThread::run()
			{
				std::cout << " this is a test implementation " << std::endl;
				endThread();
			}
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