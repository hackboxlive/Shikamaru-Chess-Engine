#include <cstdlib>
using namespace std;
class moves	{
	static const long long file_a = 72340172838076673;	//bitboard with pieces at column A
	static const long long file_h = -9187201950435737472;	//bitboard with pieces at column H
	static const long long file_8 = 255;	//bitboard with pieces on 8th row
	static const long long file_4 = 1095216660480;	//bitboard with pieces on 4th row
	static const long long file_5 = 4278190080;	//bitboard with pieces on 5th row

	static long long occupied;
	static long long not_white_pieces;
	static long long black_pieces;
	static long long empty;
	
	public:

		static void draw_board(long long bits)	{
			string chess_[8][8];
			cout<<bits<<endl;
			for(int i=0;i<64;i++)	{
				if(((bits>>i) & 1) == 1)	{
					chess_[i/8][i%8]="P";
				}
				else	{
					chess_[i/8][i%8]=" ";
				}
			}
			for(int i=0;i<8;i++)	{
				for(int j=0;j<8;j++)	{
					cout<<chess_[i][j];
				}
				cout<<endl;
			}	//for debugging purposes only
		}

		static long long reverse_long(long long v)	{
			long long ans = 0;
			for(int i = 0 ; i < 64 ; i++)	{
				ans = ans << 1;
				ans |= ((v >> i) & 1);
			}
			return ans;
		}

		static long long horizontal_and_vertical_moves(int s)	{
			long long file_mask_8[8] = {
				255, 65280, 16711680, 4278190080, 1095216660480, 280375465082880, 71776119061217280, -72057594037927936
			};
			long long file_mask_h[8] = {
				72340172838076673, 144680345676153346, 289360691352306692, 578721382704613384, 1157442765409226768, 2314885530818453536, 4629771061636907072, -9187201950435737472
			};
			long long binary = 1LL << s;
			long long possible_horizontal = (occupied - (binary << 1)) ^ reverse_long(reverse_long(occupied) - (reverse_long(binary) << 1));
			long long possible_vertical = ((occupied & file_mask_h[s % 8]) - (binary << 1)) ^ reverse_long(reverse_long(occupied & file_mask_h[s % 8]) - (reverse_long(binary) << 1));
			possible_horizontal = possible_horizontal & file_mask_8[s / 8];
			possible_vertical = possible_vertical & file_mask_h[s % 8];
			return (possible_horizontal | possible_vertical);
		}

		static long long diagonal_and_antidiagonal_moves(int s)	{
			long long diagonal_mask_8[16] = {
				1, 258, 66052, 16909320, 4328785936, 1108169199648, 283691315109952, 72624976668147840, 145249953336295424, 290499906672525312, 580999813328273408, 1161999622361579520, 2323998145211531264, 4647714815446351872, (1LL<<63)
			};
			long long antidiagonal_mask_8[16] = 	{
				128, 32832, 8405024, 2151686160, 550831656968, 141012904183812, 36099303471055874, -9205322385119247871, 4620710844295151872, 2310355422147575808, 1155177711073755136, 577588855528488960, 288794425616760832, 144396663052566528, 72057594037927936
			};
			long long binary = 1LL <<s;
			long long possible_diagonal = ((occupied & diagonal_mask_8[(s % 8) + (s / 8)]) - (binary << 1)) ^ reverse_long(reverse_long(occupied & diagonal_mask_8[(s / 8) + (s % 8)]) - (reverse_long(binary) << 1));
			long long possible_antidiagonal = ((occupied & antidiagonal_mask_8[(s / 8) + 7 - (s % 8)]) - (binary << 1)) ^ reverse_long(reverse_long(occupied & antidiagonal_mask_8[(s / 8) + 7 - (s % 8)]) - (reverse_long(binary) << 1));
			possible_diagonal = possible_diagonal & diagonal_mask_8[(s / 8) + (s % 8)];
			possible_antidiagonal = possible_antidiagonal & antidiagonal_mask_8[(s / 8) + 7 - (s % 8)];
			return (possible_antidiagonal | possible_diagonal);
		}

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

		static string possible_bishop_white(long long occupied, long long WB)	{
			string list = "";
			for(int i = 0 ; i < 64 ; i++)	{
				if((WB >> i) & 1 == 1)	{
					long long k = diagonal_and_antidiagonal_moves(i) & not_white_pieces;
					draw_board(k);
					for(int j = 0 ; j < 64 ; j++)	{
						if((k >> j) & 1 == 1)	{
							list += to_string(i / 8) + to_string(i % 8) + to_string(j / 8) + to_string(j % 8);
						}
					}
				}
			}
			return list;
		}

		static string possible_moves_white(string history, long long WP, long long WN, long long WB, long long WR, long long WQ, long long WK, long long BP, long long BN, long long BB, long long BR, long long BQ, long long BK)	{
			not_white_pieces = ~(WP | WN | WB | WR | WQ | WK | BK);
			black_pieces = BP | BN | BB | BR | BQ;
			occupied = BP | BN | BB | BR | BQ | BK | WP | WN | WB | WR | WQ | WK;
			empty = ~occupied;
			string list = possible_pawn_white(history, WP, BP) + possible_bishop_white(occupied, WB);
			return list;
		}
};