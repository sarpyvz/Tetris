#include "piece.h"
#include "position.h"

class LPiece : public Piece {
public:
	LPiece() {
		id = 1;
		// CREATING A LINKED LIST THAT CONTAINS POSITIONS AND ADD IT TO CELL MAP RIGHT NOW IT WILL BE TOO LONG COULDNT FIND A SHORTCUT
		LList<Position> position0;
		position0.addToTail(Position(0, 2));
		position0.addToTail(Position(1, 0));
		position0.addToTail(Position(1, 1));
		position0.addToTail(Position(1, 2));
		cells[0] = { position0 };

		LList<Position> position1;
		position1.addToTail(Position(0, 1));
		position1.addToTail(Position(1, 1));
		position1.addToTail(Position(2, 1));
		position1.addToTail(Position(2, 2));
		cells[1] = { position1 };

		LList<Position> position2;
		position2.addToTail(Position(1, 0));
		position2.addToTail(Position(1, 1));
		position2.addToTail(Position(1, 2));
		position2.addToTail(Position(2, 0));
		cells[2] = { position2 };

		LList<Position> position3;
		position3.addToTail(Position(0, 0));
		position3.addToTail(Position(0, 1));
		position3.addToTail(Position(1, 1));
		position3.addToTail(Position(2, 1));
		cells[3] = position3;

 	}
};
