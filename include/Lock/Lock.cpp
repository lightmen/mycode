/*
 * Author: lightmen
 * Date: 2015/09/22
 * Description: the source file is used to implement the
 *  class Mutex and Lock defined in Lock.h.
*/


#include "Lock.h"

Mutex::Mutex()
{
	pthread_mutex_init(&mutex_lock, NULL);
	mIsLock = false;
}

Mutex::~Mutex()
{
	if(mIsLock)
		pthread_mutex_unlock(&mutex_lock);

	mIsLock = false;
	pthread_mutex_destroy(&mutex_lock);
}

void Mutex::lock()
{
	mIsLock = true;
	pthread_mutex_lock(&mutex_lock);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&mutex_lock);
	mIsLock = false;
}

void Mutex::isLock()
{
	return mIsLock;
}

///////////////////////////

Lock::Lock(Mutex& mutex)
	:m_mutex(mutex),m_locked(true)
{
	m_mutex.lock();
}

Lock::~Lock()
{
	m_mutex.unlock();
	m_locked = false;
}

Lock::opertor bool () const
{
	return m_locked;
}

void Lock::setLock()
{
	m_mutex.lock();
	m_locked = true;
}

void Lock::setUnlock()
{
	m_mutex.unlock();
	m_locked = false;
}
