#include "board_generation.hpp"
#include "moves.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
long long board_generation::WP = 0;
long long board_generation::WN = 0;
long long board_generation::WB = 0;
long long board_generation::WR = 0;
long long board_generation::WQ = 0;
long long board_generation::WK = 0;
long long board_generation::BP = 0;
long long board_generation::BN = 0;
long long board_generation::BB = 0;
long long board_generation::BR = 0;
long long board_generation::BQ = 0;
long long board_generation::BK = 0;

long long moves::not_white_pieces;
long long moves::black_pieces;
long long moves::empty;

int main()	{
	long long WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK;
	board_generation::initiate_standard_chess();
	WP = board_generation::WP;
	WN = board_generation::WN;
	WB = board_generation::WB;
	WR = board_generation::WR;
	WQ = board_generation::WQ;
	WK = board_generation::WK;
	BP = board_generation::BP;
	BN = board_generation::BN;
	BB = board_generation::BB;
	BR = board_generation::BR;
	BQ = board_generation::BQ;
	BK = board_generation::BK;
//	cout<<WP<<endl;
	string list = moves::possible_moves_white("1636", WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK);
	cout<<list<<endl;
	return 0;
}
