#include <iostream>
#include "01_4_1_h.h"

void BestComImpl::SimpleFunc(void)
{
	std::cout << "BestCom�� ������ SimpleFunc" << std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void)
{
	std::cout << "So Pretty!" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout << "ProgCom�� ���ǵ� SimpleFunc" << std::endl;
}