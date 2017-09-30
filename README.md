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