//#include <bits/stdc++.h>
using namespace std;
class perft_debugging	{
	public:
		static int move_counter;
		static int max_depth;
		static int flag;
	
	public:
		static string move_to_algebra(string move)	{
			string move_string = "";
			move_string += (char)(move[1] + 49);
			move_string += (char)('8' - move[0]);
			move_string += (char)(move[3]+49);
			move_string += (char)('8' - move[2]);
			return move_string;
		}
		static int debugger(long long WP, long long WN, long long WB, long long WR, long long WQ, long long WK, long long BP, long long BN, long long BB, long long BR, long long BQ, long long BK, long long EP, bool CWK, bool CWQ, bool CBK, bool CBQ, bool white_to_move, int depth)	{
			//cout<<depth<<endl;
			int ans=1,temp;
			if(depth < max_depth)	{
				string move;
				if(white_to_move == true)	{
					move = moves::possible_moves_white(WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK, EP, CWK, CWQ, CBK, CBQ);
				}
				else	{
					move = moves::possible_moves_black(WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK, EP, CWK, CWQ, CBK, CBQ);
				}
//				if(move.length()%4!=0)	{
//					cout<<move<<endl;
//					flag=0;
//					return 0;
//				}
				//cout<<move<<endl;
				for(int i = 0; i < move.length(); i += 4)	{
					// if(move[i]=='-')	{
					// 	cout<<move<<endl;
					// 	break;
					// }
					long long temp_WP = moves::make_move(WP, move.substr(i, 4), 'P');
					long long temp_WN = moves::make_move(WN, move.substr(i, 4), 'N');
					long long temp_WB = moves::make_move(WB, move.substr(i, 4), 'B');
					long long temp_WR = moves::make_move(WR, move.substr(i, 4), 'R');
					long long temp_WQ = moves::make_move(WQ, move.substr(i, 4), 'Q');
					long long temp_WK = moves::make_move(WK, move.substr(i, 4), 'K');
					long long temp_BP = moves::make_move(BP, move.substr(i, 4), 'p');
					long long temp_BN = moves::make_move(BN, move.substr(i, 4), 'n');
					long long temp_BB = moves::make_move(BB, move.substr(i, 4), 'b');
					long long temp_BR = moves::make_move(BR, move.substr(i, 4), 'r');
					long long temp_BQ = moves::make_move(BQ, move.substr(i, 4), 'q');
					long long temp_BK = moves::make_move(BK, move.substr(i, 4), 'k');
					long long temp_EP = moves::make_move_enpassant(WP|BP, move.substr(i, 4));
//					cout<<temp_WP<<" "<<temp_WN<<" "<<temp_WB<<" "<<temp_WR<<" "<<temp_WQ<<" "<<temp_WK<<" "<<temp_BP<<" "<<temp_BN<<" "<<temp_BB<<" "<<temp_BR<<" "<<temp_BQ<<" "<<temp_BK<<" "<<temp_EP<<endl;
					bool temp_CWK = CWK;
					bool temp_CWQ = CWQ;
					bool temp_CBK = CBK;
					bool temp_CBQ = CBQ;

					if(move[i+3] >= '0' && move[i+3] <= '9')	{
						int start = (move[i] - '0') * 8 + (move[i+1] - '0');
						if((1LL << start) & WK != 0)	{
							temp_CWQ = false;
							temp_CWK = false;
						}
						if((1LL << start) & BK != 0)	{
							temp_CBQ = false;
							temp_CBK = false;
						}
						if((1LL << start) & WR & (1LL << 63) != 0)	{
							temp_CWK = false;
						}
						if((1LL << start) & WR & (1LL << 56) != 0)	{
							temp_CWQ = false;
						}
						if((1LL << start) & BR & (1LL << 7) != 0)	{
							temp_CBK = false;
						}
						if((1LL << start) & BR & 1LL != 0)	{
							temp_CBQ = false;
						}
					}
//					cout<<temp_CWK<<" "<<temp_CWQ<<" "<<temp_CBK<<" "<<temp_CBQ<<endl;
//					cout<<moves::unsafe_for_black(temp_WP, temp_WN, temp_WB, temp_WR, temp_WQ, temp_WK, temp_BP, temp_BN, temp_BB, temp_BR, temp_BQ, temp_BK)<<endl;
					if(((temp_WK & moves::unsafe_for_white(temp_WP, temp_WN, temp_WB, temp_WR, temp_WQ, temp_WK, temp_BP, temp_BN, temp_BB, temp_BR, temp_BQ, temp_BK)) == 0 && white_to_move) || ((temp_BK & moves::unsafe_for_black(temp_WP, temp_WN, temp_WB, temp_WR, temp_WQ, temp_WK, temp_BP, temp_BN, temp_BB, temp_BR, temp_BQ, temp_BK)) == 0 && !white_to_move))	{
//						cout<<"here"<<endl;
						if(depth + 1 == max_depth)	{
							move_counter++;
						}
						temp=debugger(temp_WP, temp_WN, temp_WB, temp_WR, temp_WQ, temp_WK, temp_BP, temp_BN, temp_BB, temp_BR, temp_BQ, temp_BK, temp_EP, temp_CWK, temp_CWQ, temp_CBK, temp_CBQ, !white_to_move, depth + 1);
						// if(flag==0)	{
						// 	cout<<"h"<<move.substr(i,i+4)<<"H"<<endl;
						// 	return 0;
						// }
						ans+=temp;
//						if(temp>1)	{
//							cout<<temp<<" "<<depth<<" "<<move.substr(i,4)<<endl;
//							getchar();
//						}
					}
				}
			}
			return ans;
		}
};