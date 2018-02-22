Shikamaru will be able to:

	- Play standard chess - think and play against you
	- Play Chess960 - Play from any random chess state
	- Force move - Play the best move that has been processed within a span of time
	- Timing - Limit the complete gameplay by the engine to a specific amount of time

Shikamaru will be much faster and intelligent than the Shakti-Chess-Engine.

Shikamaru implements:

	- Bitboards
	- Interative Deepening
	- Multi-Threading
	- Alpha-Beta Pruning
	- Transposition Tables
	- Aspiration Windows
	- Principal Variation Search
	- Advanced Theoretical Evaluation

There will be a few more things along with the above.

Shikamaru is written in C++ completely and is inspired by Orion Chess Engine.

Some implementation details:
	- Characters 'r' & 'R' represent a Rook
	- Characters 'n; & 'N' represent a Knight
	- Characters 'b' & 'B' represent a Bishop
	- Characters 'q' & 'Q' represent a Queen
	- Characters 'k' & 'K' represent a King
	- Characters 'p' & 'P' represent a Pawn
	- The lower-case characters represent a black piece while the upper-case characters represent a white piece

The bits are counted from the top-left corner to the bottom-right corner in that order.

The moves.hpp file consists of all the move generation code of the chess-engine. Tricks used here:
	- Some basic bit manipulation for pawn movements
	- Hyperbola Quintessence which applies to the o^(o-2r) trick for bishop, rook and queen movements
	- Added moves for king and knight using sliding constant mask values
	- Added king danger detection from opponent's piece
	- Added basic castling technique (for each side, queen and king)

The chess engine is checked for optimizations throught Perft Debugging, and hopefully doesn't contain any problems. :P

UCI protocol is integrated to connect the chess to any GUI. Checked for Arena.

// GUI: tell the engine to use the UCI protocol
uci

// ENGINE: identify  
id name Chess Engine
id author John Smith

// ENGINE: send the options that can be changed
//         in this case the hash size can have a value from 1 to 128 MB
option name Hash type spin default 1 min 1 max 128

// ENGINE: sent all parameters and is ready
uciok

// GUI: set hash to 32 MB
setoption name Hash value 32

// GUI: waiting for the engine to finish initializing
isready

// ENGINE: finished setting up the internal values and is ready to start
readyok

// GUI: let the engine know if starting a new game
ucinewgame

// GUI: tell the engine the position to search
position startpos moves e2e4

// GUI: tell the engine to start searching
//      in this case give it the timing information in milliseconds
go wtime 122000 btime 120000 winc 2000 binc 2000

// ENGINE: send search information continuously during search
//         this includes depth, search value, time, nodes, speed, and pv line
info depth 1 score cp -1 time 10 nodes 26 nps 633 pv e7e6
info depth 2 score cp -38 time 22 nodes 132 nps 2659 pv e7e6 e2e4
info depth 3 score cp -6 time 31 nodes 533 nps 10690 pv d7d5 e2e3 e7e6
info depth 4 score cp -30 time 55 nodes 1292 nps 25606 pv d7d5 e2e3 e7e6 g1f3

// ENGINE: return the best move found
bestmove d7d5