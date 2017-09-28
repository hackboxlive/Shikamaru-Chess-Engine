#include <cstdlib>
using namespace std;
class moves	{
	static const long long file_a = 72340172838076673;	//bitboard with pieces at column A
	static const long long file_h = -9187201950435737472;	//bitboard with pieces at column H
	static const long long file_8 = 255;	//bitboard with pieces on 8th row
	static const long long file_4 = 1095216660480;	//bitboard with pieces on 4th row
	static long long not_white_pieces;
	static long long black_pieces;
	static long long empty;
	public:
		static string possible_pawn_white(string history, long long WP)	{
			string list = "";
			long long pawn_moves;

			//capture right
			pawn_moves = (WP >> 7) & black_pieces & ~file_8 & ~file_a;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += ("right" + to_string(i / 8 + 1) + to_string(i % 8 - 1) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//capture left
			pawn_moves = (WP >> 9) & black_pieces & ~file_8 & ~file_h;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += ("left" + to_string(i / 8 + 1) + to_string(i % 8 + 1) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//move straight
			pawn_moves = (WP >> 8) & empty & ~file_8;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += ("straight" + to_string(i / 8 + 1) + to_string(i % 8) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//move 2 straight
			pawn_moves = (WP >> 16) & (empty >> 8) & file_4;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += ("2 straight" + to_string(i / 8 + 2) + to_string(i % 8) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//promotion while capturing right
			pawn_moves = (WP >> 7) & black_pieces & file_8 & ~file_a;
			cout<<pawn_moves<<endl;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += ("promotion right" + to_string(i % 8 - 1) + to_string(i % 8) + "QP" + to_string(i % 8 - 1) + to_string(i % 8) + "RP" + to_string(i % 8 - 1) + to_string(i % 8) + "BP" + to_string(i % 8 - 1) + to_string(i % 8) + "NP");
				}
			}

			//promotion while capturing left
			pawn_moves = (WP >> 9) & black_pieces & file_8 & ~file_h;
			for(int i = 0 ; i < 64  ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += ("promotion left" + to_string(i % 8 + 1) + to_string(i % 8) + "QP" + to_string(i % 8 + 1) + to_string(i % 8) + "RP" + to_string(i % 8 + 1) + to_string(i % 8) + "BP" + to_string(i % 8 + 1) + to_string(i % 8) + "NP");
				}
			}

			//promotion while moving forward
			pawn_moves = (WP >> 8) & empty & file_8;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += ("promotion forward" + to_string(i % 8) + to_string(i % 8) + "QP" + to_string(i % 8) + to_string(i % 8) + "RP" + to_string(i % 8) + to_string(i % 8) + "BP" + to_string(i % 8) + to_string(i % 8) + "NP");
				}
			}
			return list;		
		}

		static string possible_moves_white(string history, long long WP, long long WN, long long WB, long long WR, long long WQ, long long WK, long long BP, long long BN, long long BB, long long BR, long long BQ, long long BK)	{
			not_white_pieces = ~(WP | WN | WB | WR | WQ | WK | BK);
			black_pieces = BP | BN | BB | BR | BQ;
			empty = ~(BP | BN | BB | BR | BQ | BK | WP | WN | WB | WR | WQ | WK);
//			cout<<not_white_pieces<<" "<<black_pieces<<" "<<empty<<endl;
			string list = possible_pawn_white(history, WP);
			return list;
		}
};