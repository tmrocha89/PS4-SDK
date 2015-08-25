#include "module.h"

#include "pthread.h"

int (*scePthreadCreate)(ScePthread *thread, const ScePthreadAttr *attr, void *(*entry) (void *), void *arg, const char *name);
void (*scePthreadExit)(void *value);
int (*scePthreadDetach)(ScePthread thread);
int (*scePthreadJoin)(ScePthread thread, void **value_ptr);
void (*scePthreadYield)(void);
ScePthread (*scePthreadSelf)(void);
int (*scePthreadCancel)(ScePthread thread);

int (*scePthreadMutexInit)(ScePthreadMutex *mutex, const ScePthreadMutexattr *attr, const char *name);
int (*scePthreadMutexDestroy)(ScePthreadMutex *mutex);
int (*scePthreadMutexLock)(ScePthreadMutex *mutex);
int (*scePthreadMutexTrylock)(ScePthreadMutex *mutex);
int (*scePthreadMutexTimedlock)(ScePthreadMutex *mutex, SceKernelUseconds usec);
int (*scePthreadMutexUnlock)(ScePthreadMutex *mutex);

void initPthread(void)
{
	int libkernel;
	loadModule("libkernel.sprx", &libkernel);

	RESOLVE(libkernel, scePthreadCreate);
	RESOLVE(libkernel, scePthreadExit);
	RESOLVE(libkernel, scePthreadDetach);
	RESOLVE(libkernel, scePthreadJoin);
	RESOLVE(libkernel, scePthreadYield);
	RESOLVE(libkernel, scePthreadSelf);
	RESOLVE(libkernel, scePthreadCancel);

	RESOLVE(libkernel, scePthreadMutexInit);
	RESOLVE(libkernel, scePthreadMutexDestroy);
	RESOLVE(libkernel, scePthreadMutexLock);
	RESOLVE(libkernel, scePthreadMutexTrylock);
	RESOLVE(libkernel, scePthreadMutexTimedlock);
	RESOLVE(libkernel, scePthreadMutexUnlock);
}
