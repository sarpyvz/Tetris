#pragma once
#include "board.h"
#include "pieces.cpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector.hpp"

class Game 
{
public:
	Game();
	Piece GetRandomPiece();
	std::vector<Piece> GetAllPieces();
	void Draw(sf::RenderWindow& target);
	Board board;
	void HandleInput(sf::Keyboard::Key key);
	void MovePieceLeft();
	void MovePieceRight();
	void MovePieceDown();
	bool gameover;


private:
	//Piece* pieces = new Piece[100];
	bool IsPieceOutside();
	void RotateBlock();
	std::vector<Piece> pieces;
	Piece currentPiece;
	Piece nextPiece;
	void LockPiece();
	bool PieceFits();
	void Reset();

};