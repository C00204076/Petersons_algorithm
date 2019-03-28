//
// C00204076
// Brandon Seah-Dempsey
// Started at
// Finished at
// Time taken:
// Known bugs:

#include <iostream>
#include <vector>
#include <thread>

//
std::vector<std::thread*> m_threads;
std::vector<int> m_in, m_last;

//
int m_threadCount = 6;

//
void csThread(int index);

//
int main()
{
	for (int i = 0; i < m_threadCount; i++)
	{
		m_in.push_back(0);
	}

	//
	m_last = m_in;

	//
	for (int i = 0; i < m_threadCount; i++)
	{
		m_threads.push_back(new std::thread(csThread, i));
	}

	//
	system("Pause");
}

//
void csThread(int index)
{
	while (true)
	{
		for (int k = 0; k < m_threadCount - 1; k++)
		{
			m_in[index] = k;
			m_last[k] = index;
		}

		std::cout << "Critical section of thread is: " << index + 1 << std::endl;
		m_in[index] = 0;
	}
}