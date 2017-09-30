#include <cstdlib>
using namespace std;
class moves	{
	static const long long file_a = 72340172838076673;	//bitboard with pieces at column A
	static const long long file_h = -9187201950435737472;	//bitboard with pieces at column H
	static const long long file_8 = 255;	//bitboard with pieces on 8th row
	static const long long file_4 = 1095216660480;	//bitboard with pieces on 4th row
	static const long long file_5 = 4278190080;	//bitboard with pieces on 5th row
	static long long not_white_pieces;
	static long long black_pieces;
	static long long empty;
	public:
		static string possible_pawn_white(string history, long long WP, long long BP)	{
			string list = "";
			long long pawn_moves;

			//capture right
			pawn_moves = (WP >> 7) & black_pieces & ~file_8 & ~file_a;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += (to_string(i / 8 + 1) + to_string(i % 8 - 1) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//capture left
			pawn_moves = (WP >> 9) & black_pieces & ~file_8 & ~file_h;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += (to_string(i / 8 + 1) + to_string(i % 8 + 1) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//move straight
			pawn_moves = (WP >> 8) & empty & ~file_8;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += (to_string(i / 8 + 1) + to_string(i % 8) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//move 2 straight
			pawn_moves = (WP >> 16) & (empty >> 8) & file_4;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += (to_string(i / 8 + 2) + to_string(i % 8) + to_string(i / 8) + to_string(i % 8));
				}
			}

			//promotion while capturing right
			pawn_moves = (WP >> 7) & black_pieces & file_8 & ~file_a;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += (to_string(i % 8 - 1) + to_string(i % 8) + "QP" + to_string(i % 8 - 1) + to_string(i % 8) + "RP" + to_string(i % 8 - 1) + to_string(i % 8) + "BP" + to_string(i % 8 - 1) + to_string(i % 8) + "NP");
				}
			}

			//promotion while capturing left
			pawn_moves = (WP >> 9) & black_pieces & file_8 & ~file_h;
			for(int i = 0 ; i < 64  ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += (to_string(i % 8 + 1) + to_string(i % 8) + "QP" + to_string(i % 8 + 1) + to_string(i % 8) + "RP" + to_string(i % 8 + 1) + to_string(i % 8) + "BP" + to_string(i % 8 + 1) + to_string(i % 8) + "NP");
				}
			}

			//promotion while moving forward
			pawn_moves = (WP >> 8) & empty & file_8;
			for(int i = 0 ; i < 64 ; i++)	{
				if((pawn_moves >> i) & 1 == 1)	{
					list += (to_string(i % 8) + to_string(i % 8) + "QP" + to_string(i % 8) + to_string(i % 8) + "RP" + to_string(i % 8) + to_string(i % 8) + "BP" + to_string(i % 8) + to_string(i % 8) + "NP");
				}
			}

			//en passants moves
			long long file_mask_h[8] = {
				72340172838076673, 144680345676153346, 289360691352306692, 578721382704613384, 1157442765409226768, 2314885530818453536, 4629771061636907072, -9187201950435737472
			};
			if(history.length() >= 4)	{
				if(history[history.length() - 1] == history[history.length() - 3] && abs(history[history.length() - 2] - history[history.length() - 4]) == 2)	{
					int e_file = history[history.length() - 1] - '0';
					//en passant right
					long long possibility = (WP << 1) & BP & file_5 & ~file_a & file_mask_h[e_file];	//shows piece to remove, not destination
					if(possibility != 0)	{
						int i = 0;
						while(possibility % 2 == 0)	{
							i++;
							possibility /= 2;
						}
						list += (to_string(i % 8 - 1) + to_string(i % 8) + " E");
					}
					//en passant left
					possibility = (WP >> 1) & BP & file_5 & ~file_h & file_mask_h[e_file];	//shows pieces to remove, not destination
					if(possibility != 0)	{
						int i = 0;
						while(possibility & 1 == 1)	{
							i++;
							possibility >>= 1;
						}
						list += (to_string(i % 8 + 1) + to_string(i % 8) + " E");
					}
				}
			}
			return list;
		}

		static string possible_moves_white(string history, long long WP, long long WN, long long WB, long long WR, long long WQ, long long WK, long long BP, long long BN, long long BB, long long BR, long long BQ, long long BK)	{
			not_white_pieces = ~(WP | WN | WB | WR | WQ | WK | BK);
			black_pieces = BP | BN | BB | BR | BQ;
			empty = ~(BP | BN | BB | BR | BQ | BK | WP | WN | WB | WR | WQ | WK);
			string list = possible_pawn_white(history, WP, BP);
			return list;
		}
};