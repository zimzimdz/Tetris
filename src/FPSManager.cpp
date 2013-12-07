#include "FPSManager.h"


FPSManager::FPSManager(void)
{

}


FPSManager::~FPSManager(void)
{
}


int FPSManager::ffps()
{	
	return clock.getElapsedTime().asMilliseconds();;
}

void FPSManager::Init(){
	clock.restart();
}
