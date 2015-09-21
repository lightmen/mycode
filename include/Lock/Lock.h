/*
 * Author: lightmen
 * Date: 2015/09/22
 * Description: the header file is used to defined the
 *  class Mutex and  Lock, which is used to implement the
 *  auto lock function.
*/

#ifndef __LOCK_H__
#define __LOCK_H__
#include <pthread.h>

class Mutex {
public:
	Mutex();
	~Mutex();
	void lock();
	void unlock();
	bool isLock();

private:
	pthread_mutex_t mutex_lock;
	bool mIsLock;
};

class Lock {
public:
	Lock(Mutex& mutex);
	~Lock();

	operator bool () const;
	void setLock();
	void setUnlock();

private:
	Mutex& m_mutex;
	bool m_locked;
};

#endif //__LOCK_H__
