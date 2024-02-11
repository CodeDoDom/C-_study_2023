#include <iostream>
#include "01_4_1_h.h"

void BestComImpl::SimpleFunc(void)
{
	std::cout << "BestCom이 정의한 SimpleFunc" << std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void)
{
	std::cout << "So Pretty!" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout << "ProgCom이 정의된 SimpleFunc" << std::endl;
}