#include "board_generation.hpp"
#include "moves.hpp"
#include "perft_debugging.hpp"

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
long long moves::occupied;
long long moves::not_black_pieces;
long long moves::white_pieces;

int perft_debugging::move_counter;
int perft_debugging::max_depth;
int perft_debugging::flag;

bool castle_white_king_side;
bool castle_black_king_side;
bool castle_white_queen_side;
bool castle_black_queen_side;
int main()	{
	long long WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK, EP;
	bool CWK = true, CWQ = true, CBK =true, CBQ = true, white_to_move = true;
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
	EP = 0;
	castle_black_king_side = castle_black_queen_side = castle_white_queen_side = castle_white_king_side = true;	//castling is possible initially
//	string list = moves::possible_moves_white(WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK, EP, castle_white_king_side, castle_white_queen_side, castle_black_king_side, castle_black_queen_side);
//	string list = moves::possible_moves_black(WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK, EP, castle_white_king_side, castle_white_queen_side, castle_black_king_side, castle_black_queen_side);
//	cout<<list<<endl;
	perft_debugging::move_counter = 0;
	perft_debugging::max_depth = 5;
	perft_debugging::flag = 1;
//	cout<<(int)'-'<<endl;
	int a = perft_debugging::debugger(WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK, EP, CWK, CWQ, CBK, CBQ, white_to_move, 0);
	cout<<a<<endl;
	cout<<perft_debugging::move_counter<<endl;
	return 0;
}
