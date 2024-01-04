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
			ParallelOptionsProbabilities::ParallelOptionsProbabilities(int size, double start, double step)
				: m_numSteps(size), m_strikePrice(start), m_step(step)
			{
			}

			ParallelOptionsProbabilities::ParallelOptionsProbabilities(const ParallelOptionsProbabilities& p)
				: m_numSteps(p.m_numSteps), m_strikePrice(p.m_strikePrice), m_step(p.m_step)
			{
			}
			ParallelOptionsProbabilities::~ParallelOptionsProbabilities()
			{
			}
			ParallelOptionsProbabilities& ParallelOptionsProbabilities::operator=(const ParallelOptionsProbabilities& p)
			{
				if (this != &p)
				{
					m_numSteps = p.m_numSteps;
					m_strikePrice = p.m_strikePrice;
					m_step = p.m_step;
				}
				return *this;
			}
			double ParallelOptionsProbabilities::probFinishAboveStrike()
			{
				const int numThreads = 20;
				std::vector<RandomWalkThread*> threads(numThreads);
				for (int i = 0; i < numThreads; ++i)
				{
					threads[i] = new RandomWalkThread(m_numSteps, m_step, m_strikePrice);
					threads[i]->setJoinable(true);
					threads[i]->start();
				}
				for (int i = 0; i < numThreads; ++i)
				{
					threads[i]->join();
				}
				double nAbove = 0;
				for (int i = 0; i < numThreads; ++i)
				{
					nAbove += threads[i]->result();
					delete threads[i];
				}
				return nAbove / (double)(numThreads);
			}

			RandomWalkThread::RandomWalkThread(int numSteps, double sigma, double startingPrice)
				: m_numberOfSteps(numSteps), m_sigma(sigma), m_startingPrice(startingPrice)
			{
			}

			RandomWalkThread::~RandomWalkThread()
			{
			}
			double RandomWalkThread::gaussianValue(double mean, double sigma)
			{
				boost::random::normal_distribution<> distrib(mean, sigma);
				return distrib(za::ma::com::boost_random_generator);
			}
			double RandomWalkThread::result()
			{
				return m_result;
			}
			double RandomWalkThread::getLastPriceOfWalk()
			{
				double prev = m_startingPrice;
				for (int i = 0; i < m_numberOfSteps; ++i)
				{
					double stepSize = gaussianValue(0, m_sigma);
					int r = rand() % 2;
					double val = prev;
					if (r == 0) val += (stepSize * val);
					else val -= (stepSize * val);
					prev = val;
				}
				return prev;
			}
			void RandomWalkThread::run()
			{
				std::cout << " running thread " << std::endl;
				int nAbove = 0;
				for (int i = 0; i < m_numberOfSteps; ++i)
				{
					double val = getLastPriceOfWalk();
					if (val >= m_startingPrice)
					{
						nAbove++;
					}
				}
				m_result = nAbove / (double)m_numberOfSteps;
		}

#pragma endregion Example2

#pragma region Example3
			struct MutexData 
			{
				pthread_mutex_t m_mutex;
			};
			Mutex::Mutex(): m_data(new MutexData)
			{
				pthread_mutex_init(&m_data->m_mutex, NULL);
			}
			Mutex::~Mutex()
			{
				if (m_data)
				{
					pthread_mutex_destroy(&m_data->m_mutex);
					delete m_data;
				}
			}
			void Mutex::lock()
			{
				pthread_mutex_lock(&m_data->m_mutex);
			}
			void Mutex::unlock()
			{
				pthread_mutex_unlock(&m_data->m_mutex);
			}
			/// ----
			MutexAccess::MutexAccess(Mutex & m)
				: m_mutex(m)
			{
				m_mutex.lock();
			}
			MutexAccess::~MutexAccess()
			{
				m_mutex.unlock();
			}

			Mutex MutexTestThread::m_globalMutex; // global mutex is static
			MutexTestThread::MutexTestThread(double& result, double incVal)
				: m_result(result), m_incValue(incVal)
			{
			}
			MutexTestThread::~MutexTestThread()
			{
			}
			void MutexTestThread::run()
			{
				MutexAccess maccess(m_globalMutex); // mutex is locked here
				std::cout << " accessing data " << std::endl; 
				std::cout.flush();
				if (m_result > m_incValue)
				{
					m_result -= m_incValue;
				}
				else
				{
					m_incValue += m_incValue;
				}
				// mutex is automatically unlocked
			}


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