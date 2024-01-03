#include "piece.h"
#include "position.h"

#pragma once


class LPiece : public Piece {
public:
	LPiece() {
		id = 1;
		
		// COMMENTED  ARE FOR WHEN USING LLIST 
		/*LList<Position> position0;
		position0.addToTail(Position(0, 2));
		position0.addToTail(Position(1, 0));
		position0.addToTail(Position(1, 1));
		position0.addToTail(Position(1, 2));
		cells[0] = position0;

		LList<Position> position1;
		position1.addToTail(Position(0, 1));
		position1.addToTail(Position(1, 1));
		position1.addToTail(Position(2, 1));
		position1.addToTail(Position(2, 2));
		cells[1] = position1;

		LList<Position> position2;
		position2.addToTail(Position(1, 0));
		position2.addToTail(Position(1, 1));
		position2.addToTail(Position(1, 2));
		position2.addToTail(Position(2, 0));
		cells[2] = position2;

		LList<Position> position3;
		position3.addToTail(Position(0, 0));
		position3.addToTail(Position(0, 1));
		position3.addToTail(Position(1, 1));
		position3.addToTail(Position(2, 1)); 
		cells[3] = position3;*/

		 
		cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };

		// MY VECTOR IMPLEMENTATION
		/*cells[0].push_back(Position(0, 2));
		cells[0].push_back(Position(1, 0));
		cells[0].push_back(Position(1, 1));
		cells[0].push_back(Position(1, 2));
		cells[1].push_back(Position(0, 1));
		cells[1].push_back(Position(1, 1));
		cells[1].push_back(Position(2, 1));
		cells[1].push_back(Position(2, 2));
		cells[2].push_back(Position(1, 0));
		cells[2].push_back(Position(1, 1));
		cells[2].push_back(Position(1, 2));
		cells[2].push_back(Position(2, 0));
		cells[3].push_back(Position(0, 0));
		cells[3].push_back(Position(0, 1));
		cells[3].push_back(Position(1, 1));
		cells[3].push_back(Position(2, 1));*/

		Move(0, 3);
 	}
	
};

class JPiece : public Piece {
public:
	JPiece() {
		id = 2;
		/*LList<Position> position0;
		position0.addToTail(Position(0, 0));
		position0.addToTail(Position(1, 0));
		position0.addToTail(Position(1, 1));
		position0.addToTail(Position(1, 2));
		cells[0] = position0;

		LList<Position> position1;
		position1.addToTail(Position(0, 1));
		position1.addToTail(Position(0, 2));
		position1.addToTail(Position(1, 1));
		position1.addToTail(Position(2, 1));
		cells[1] = position1;

		LList<Position> position2;
		position2.addToTail(Position(1, 0));
		position2.addToTail(Position(1, 1));
		position2.addToTail(Position(1, 2));
		position2.addToTail(Position(2, 2));
		cells[2] = position2;

		LList<Position> position3;
		position3.addToTail(Position(0, 1));
		position3.addToTail(Position(1, 1));
		position3.addToTail(Position(2, 0));
		position3.addToTail(Position(2, 1));
		cells[3] = position3;*/

		cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
	
		// MY VECTOR IMPLEMENT
		/*cells[0].push_back(Position(0, 0));
		cells[0].push_back(Position(1, 0));
		cells[0].push_back(Position(1, 1));
		cells[0].push_back(Position(1, 2));
		cells[1].push_back(Position(0, 1));
		cells[1].push_back(Position(0, 2));
		cells[1].push_back(Position(1, 1));
		cells[1].push_back(Position(2, 1));
		cells[2].push_back(Position(1, 0));
		cells[2].push_back(Position(1, 1));
		cells[2].push_back(Position(1, 2));
		cells[2].push_back(Position(2, 2));
		cells[3].push_back(Position(0, 1));
		cells[3].push_back(Position(1, 1));
		cells[3].push_back(Position(2, 0));
		cells[3].push_back(Position(2, 1));*/
		Move(0, 3);

	}

};

class IPiece : public Piece {
public:
	IPiece() {
		id = 3;
		/*LList<Position> position0;
		position0.addToTail(Position(1, 0));
		position0.addToTail(Position(1, 1));
		position0.addToTail(Position(1, 2));
		position0.addToTail(Position(1, 3));
		cells[0] = position0;

		LList<Position> position1;
		position1.addToTail(Position(0, 2));
		position1.addToTail(Position(1, 2));
		position1.addToTail(Position(2, 2));
		position1.addToTail(Position(3, 2));
		cells[1] = position1;

		LList<Position> position2;
		position2.addToTail(Position(2, 0));
		position2.addToTail(Position(2, 1));
		position2.addToTail(Position(2, 2));
		position2.addToTail(Position(2, 3));
		cells[2] = position2;

		LList<Position> position3;
		position3.addToTail(Position(0, 1));
		position3.addToTail(Position(1, 1));
		position3.addToTail(Position(2, 1));
		position3.addToTail(Position(3, 1));
		cells[3] = position3;*/

		cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
		cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
		cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };

		//MY VECTOR IMP
		/*cells[0].push_back(Position(1, 0));
		cells[0].push_back(Position(1, 1));
		cells[0].push_back(Position(1, 2));
		cells[0].push_back(Position(1, 3));
		cells[1].push_back(Position(0, 2));
		cells[1].push_back(Position(1, 2));
		cells[1].push_back(Position(2, 2));
		cells[1].push_back(Position(3, 2));
		cells[2].push_back(Position(2, 0));
		cells[2].push_back(Position(2, 1));
		cells[2].push_back(Position(2, 2));
		cells[2].push_back(Position(2, 3));
		cells[3].push_back(Position(0, 1));
		cells[3].push_back(Position(1, 1));
		cells[3].push_back(Position(2, 1));
		cells[3].push_back(Position(3, 1));*/
		Move(-1, 3);

	}

};

class OPiece : public Piece {
public:
	OPiece() {
		id = 4;
		/*LList<Position> position0;
		position0.addToTail(Position(0, 0));
		position0.addToTail(Position(0, 1));
		position0.addToTail(Position(1, 0));
		position0.addToTail(Position(1, 1));
		cells[0] = position0;*/

		/*LList<Position> position1;
		position1.addToTail(Position(0, 0));
		position1.addToTail(Position(0, 1));
		position1.addToTail(Position(1, 0));
		position1.addToTail(Position(1, 1));
		cells[1] = position1;

		LList<Position> position2;
		position2.addToTail(Position(0, 0));
		position2.addToTail(Position(0, 1));
		position2.addToTail(Position(1, 0));
		position2.addToTail(Position(1, 1));
		cells[2] = position2;

		LList<Position> position3;
		position3.addToTail(Position(0, 0));
		position3.addToTail(Position(0, 1));
		position3.addToTail(Position(1, 0));
		position3.addToTail(Position(1, 1));
		cells[3] = position3;*/

		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };

		//MY VECTOR IMP
		/*cells[0].push_back(Position(0, 0));
		cells[0].push_back(Position(0, 1));
		cells[0].push_back(Position(1, 0));
		cells[0].push_back(Position(1, 1));
		*/
		Move(0, 4);

	}

};

class SPiece : public Piece {
public:
	SPiece() {
		id = 5;
		/*LList<Position> position0;
		//position0.addToTail(Position(0, 1));
		//position0.addToTail(Position(0, 2));
		//position0.addToTail(Position(1, 0));
		//position0.addToTail(Position(1, 1));
		//cells[0] = position0;

		//LList<Position> position1;
		//position1.addToTail(Position(0, 1));
		//position1.addToTail(Position(1, 1));
		//position1.addToTail(Position(1, 2));
		position1.addToTail(Position(2, 2));
		cells[1] = position1;

		LList<Position> position2;
		position2.addToTail(Position(1, 1));
		position2.addToTail(Position(1, 2));
		position2.addToTail(Position(2, 0));
		position2.addToTail(Position(2, 1));
		cells[2] = position2;

		LList<Position> position3;
		position3.addToTail(Position(0, 0));
		position3.addToTail(Position(1, 0));
		position3.addToTail(Position(1, 1));
		position3.addToTail(Position(2, 1));
		cells[3] = position3;*/

		cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
		cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };

		//MY VECTOR IMP
		/*cells[0].push_back(Position(0, 1));
		cells[0].push_back(Position(0, 2));
		cells[0].push_back(Position(1, 0));
		cells[0].push_back(Position(1, 1));
		cells[1].push_back(Position(0, 1));
		cells[1].push_back(Position(1, 1));
		cells[1].push_back(Position(1, 2));
		cells[1].push_back(Position(2, 2));
		cells[2].push_back(Position(1, 1));
		cells[2].push_back(Position(1, 2));
		cells[2].push_back(Position(2, 0));
		cells[2].push_back(Position(2, 1));
		cells[3].push_back(Position(0, 0));
		cells[3].push_back(Position(1, 0));
		cells[3].push_back(Position(1, 1));
		cells[3].push_back(Position(2, 1));*/

		Move(0, 3);

	}

};

class TPiece : public Piece {
public:
	TPiece() {
		id = 6;
		/*LList<Position> position0;
		position0.addToTail(Position(0, 1));
		position0.addToTail(Position(1, 0));
		position0.addToTail(Position(1, 1));
		position0.addToTail(Position(1, 2));
		cells[0] = position0;

		LList<Position> position1;
		position1.addToTail(Position(0, 1));
		position1.addToTail(Position(1, 1));
		position1.addToTail(Position(1, 2));
		position1.addToTail(Position(2, 1));
		cells[1] = position1;

		LList<Position> position2;
		position2.addToTail(Position(1, 0));
		position2.addToTail(Position(1, 1));
		position2.addToTail(Position(1, 2));
		position2.addToTail(Position(2, 1));
		cells[2] = position2;

		LList<Position> position3;
		position3.addToTail(Position(0, 1));
		position3.addToTail(Position(1, 0));
		position3.addToTail(Position(1, 1));
		position3.addToTail(Position(2, 1));
		cells[3] = position3;*/

		cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };

		//MYVECTOR IMP
		/*cells[0].push_back(Position(0, 1));
		cells[0].push_back(Position(1, 0));
		cells[0].push_back(Position(1, 1));
		cells[0].push_back(Position(1, 2));
		cells[1].push_back(Position(0, 1));
		cells[1].push_back(Position(1, 1));
		cells[1].push_back(Position(1, 2));
		cells[1].push_back(Position(2, 1));
		cells[2].push_back(Position(1, 0));
		cells[2].push_back(Position(1, 1));
		cells[2].push_back(Position(1, 2));
		cells[2].push_back(Position(2, 1));
		cells[3].push_back(Position(0, 1));
		cells[3].push_back(Position(1, 0));
		cells[3].push_back(Position(1, 1));
		cells[3].push_back(Position(2, 1));*/
		Move(0, 3);

	}

};

class ZPiece : public Piece {
public:
	ZPiece() {
		id = 7;
		/*LList<Position> position0;
		position0.addToTail(Position(0, 0));
		position0.addToTail(Position(0, 1));
		position0.addToTail(Position(1, 1));
		position0.addToTail(Position(1, 2));
		cells[0] = position0;

		LList<Position> position1;
		position1.addToTail(Position(0, 2));
		position1.addToTail(Position(1, 1));
		position1.addToTail(Position(1, 2));
		position1.addToTail(Position(2, 1));
		cells[1] = position1;

		LList<Position> position2;
		position2.addToTail(Position(1, 0));
		position2.addToTail(Position(1, 1));
		position2.addToTail(Position(2, 1));
		position2.addToTail(Position(2, 2));
		cells[2] = position2;

		LList<Position> position3;
		position3.addToTail(Position(0, 1));
		position3.addToTail(Position(1, 0));
		position3.addToTail(Position(1, 1));
		position3.addToTail(Position(2, 0));
		cells[3] = position3;*/

		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };

		//cells[0].push_back(Position(0, 0));
		//cells[0].push_back(Position(0, 1));
		//cells[0].push_back(Position(1, 1));
		//cells[0].push_back(Position(1, 2));
		//cells[1].push_back(Position(0, 2));
		//cells[1].push_back(Position(1, 1));
		//cells[1].push_back(Position(1, 2));
		//cells[1].push_back(Position(2, 1));
		//cells[2].push_back(Position(1, 0));
		//cells[2].push_back(Position(1, 1));
		//cells[2].push_back(Position(2, 1));
		//cells[2].push_back(Position(2, 2));
		//cells[3].push_back(Position(0, 1));
		//cells[3].push_back(Position(1, 0));
		//cells[3].push_back(Position(1, 1));
		//cells[3].push_back(Position(2, 0));
		Move(0, 3);

	}

};
//
//class GhostPiece : public Piece {
//public:
//	ghostPiece() {
//		id = 8;
//
//		cells[0] = { Position(0,0),Position(0,0) ,Position(0,0) ,Position(0,0) };
//	}
//
//};