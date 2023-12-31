#pragma once

#include "board.h"
#include "pieces.cpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector.hpp"
#include <SFML/Audio.hpp>


class Game 
{
public:
	Game();
	~Game();
	Piece GetRandomPiece();
	std::vector<Piece> GetAllPieces();
	void Draw(sf::RenderWindow& target);
	Board board;
	void HandleInput(sf::Keyboard::Key key);
	void MovePieceLeft();
	void MovePieceRight();
	void MovePieceDown();
	bool gameover;
	int score;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	sf::SoundBuffer soundBuffRot;
	sf::Sound rotateSound;
	sf::SoundBuffer soundBuffClear;
	sf::Sound clearSound;


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
	void UpdateScore(int lines_cleared,int move_down_points);


};