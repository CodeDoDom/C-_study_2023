#include <iostream>
#include "01_4_1_h.h"

int main(void)
{
	BestComImpl::SimpleFunc();
	std::cout << std::endl;
	ProgComImpl::SimpleFunc();
	std::cout << std::endl;
	BestComImpl::PrettyFunc();
	std::cout << std::endl;

	return 0;
}