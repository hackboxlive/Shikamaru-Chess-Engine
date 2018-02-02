#include <iostream>
#include <cstdlib>

class board_generation	{
	
	public:
		static long long WP;
		static long long WN;
		static long long WB;
		static long long WR;
		static long long WQ;
		static long long WK;
		static long long BP;
		static long long BN;
		static long long BB;
		static long long BR;
		static long long BQ;
		static long long BK;

	public:
		static long long convert_string_to_decimal(std::string binary)	{
			long long two = 1;
			for(int i = 0 ; binary[i] != '1'; i++)	{
				two *= (long long)2;
			}
			return two;
		}

		static void chessboard_to_bitboards(std::string chess_board[8][8])	{
			std::string binary;
			for( int i = 0 ; i < 64 ; i++ )	{
				binary = "0000000000000000000000000000000000000000000000000000000000000000";
				binary[i] = '1';
				char ch = chess_board[i / 8][i % 8][0];
				if(ch == 'r')	{
					BR += convert_string_to_decimal(binary);
				}
				else if(ch == 'n')	{
					BN += convert_string_to_decimal(binary);
				}
				else if(ch == 'b')	{
					BB += convert_string_to_decimal(binary);
				}
				else if(ch == 'q')	{
					BQ += convert_string_to_decimal(binary);
				}
				else if(ch == 'k')	{
					BK += convert_string_to_decimal(binary);
				}
				else if(ch == 'p')	{
					BP += convert_string_to_decimal(binary);
				}
				else if(ch == 'R')	{
					WR += convert_string_to_decimal(binary);
				}
				else if(ch == 'N')	{
					WN += convert_string_to_decimal(binary);
				}
				else if(ch == 'B')	{
					WB += convert_string_to_decimal(binary);
				}
				else if(ch == 'Q')	{
					WQ += convert_string_to_decimal(binary);
				}
				else if(ch == 'K')	{
					WK += convert_string_to_decimal(binary);
				}
				else if(ch == 'P')	{
					WP += convert_string_to_decimal(binary);
				}
			}
		}

		static void initiate_standard_chess()	{
			WP = 0; WN = 0; WB = 0; WR = 0; WQ = 0; WK = 0; BP = 0; BN = 0; BB = 0; BR = 0; BQ = 0; BK = 0;
			//the start state of chess; we could have directly initialized the variables,
			//but for testing purpose we need this strig matrix
			std::string chess_board[8][8] = {
				{ "r" , "n" , "b" , "q" , "k" , "b" , "n" , "r" },
				{ "p" , "p" , "p" , "p" , "p" , "p" , "p" , "p" },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ "P" , "P" , "P" , "P" , "P" , "P" , "P" , "P" },
				{ "R" , "N" , "B" , "Q" , "K" , "B" , "N" , "R" }
			};
			chessboard_to_bitboards(chess_board);
		}
		
		static void initiate_chess960()	{
			std::string chess_board[8][8] = {
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ "p" , "p" , "p" , "p" , "p" , "p" , "p" , "p" },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
				{ "P" , "P" , "P" , "P" , "P" , "P" , "P" , "P" },
				{ " " , " " , " " , " " , " " , " " , " " , " " },
			};

			//initialize the random object
			srand(time(NULL));

			//Step 1: Put two bishops on the two black and white squares
			int b1 = rand() % 8;
			chess_board[0][b1] = "b";
			chess_board[7][b1] = "B";
			int b2 = rand() % 8;
			while(b1 % 2 == b2 % 2)	{
				b2 = rand() % 8;
			}
			chess_board[0][b2] = "b";
			chess_board[7][b2] = "B";

			//Step 2: Put the queen on the first empty random square
			int q = rand() % 8;
			while(q == b1 || q == b2)	{
				q = rand() % 8;
			}
			chess_board[0][q] = "q";
			chess_board[7][q] = "Q";

			//Step 3: Put the knight at any two empty positions
			int n = rand() % 5;
			for(int i = 0 ; i < 8 ; i++)	{
				if(chess_board[0][i][0] == ' ')	{
					if(n == 0)	{
						chess_board[0][i] = "n";
						chess_board[7][i] = "N";
						break;
					}
					n--;
				}
			}
			n = rand() % 4;
			for(int i = 0 ; i < 8 ; i++)	{
				if(chess_board[0][i][0] == ' ')	{
					if(n == 0)	{
						chess_board[0][i] = "n";
						chess_board[7][i] = "N";
						break;
					}
					n--;
				}
			}

			//Step 4: Put the king on the middle square of the remaining three squares
			// and rooks on the remaining two
			n = 0;
			for(int i = 0 ; i < 8 ; i++)	{
				if(chess_board[0][i][0] == ' ')	{
					if(n == 0)	{
						chess_board[0][i] = "r";
						chess_board[7][i] = "R";
						n = 1;
					}
					else if(n == 1)	{
						chess_board[0][i] = "k";
						chess_board[7][i] = "K";
						n = 2;
					}
					else if(n == 2)	{
						chess_board[0][i] = "r";
						chess_board[7][i] = "R";
						break;
					}
				}
			}
/*			for(int i=0;i<8;i++)	{
				for(int j=0;j<8;j++)	{
					printf("%c ",chess_board[i][j][0]);
				}
				printf("\n");
			}
*/			chessboard_to_bitboards(chess_board);
	
		}

};