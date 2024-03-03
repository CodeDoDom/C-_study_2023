#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

enum { LANK_A = 1, LANK_B = 2, LANK_C = 3 };	// 신용 등급

enum { NORMAL = 1, CREDIT = 2 };	// 계좌 종류
