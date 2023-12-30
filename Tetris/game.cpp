#include "game.h"
#include <random>
#include <SFML/Graphics.hpp>

Game::Game() 
{
	board = Board();
	/*pieces[0] = IPiece();
	pieces[1] = JPiece();
	pieces[2] = LPiece();
	pieces[3] = OPiece();
	pieces[4] = SPiece();
	pieces[5] = TPiece();
	pieces[6] = ZPiece();*/
	pieces = GetAllPieces();
	currentPiece = GetRandomPiece();
	nextPiece = GetRandomPiece();
	gameover = false;
}

Piece Game::GetRandomPiece()
{
	if (pieces.empty()) 
	{
		pieces = GetAllPieces();
	}
	int randomIndex = rand() % pieces.size();
	Piece piece = pieces[randomIndex];
	pieces.erase(pieces.begin() + randomIndex);
	return piece;

}

std::vector<Piece> Game::GetAllPieces()
{
	return { IPiece(),  JPiece() ,LPiece(), OPiece() ,SPiece() ,TPiece(),ZPiece() };
}

void Game::Draw(sf::RenderWindow& target)
{
	board.Draw(target);
	currentPiece.Draw(target);
}

void Game::HandleInput(sf::Keyboard::Key keyPressed)
{
	if (gameover && keyPressed != 0)
	{
		gameover = false;
		Reset();
	}
	switch (keyPressed)
	{
	case sf::Keyboard::Key::Left:
		MovePieceLeft();
		break;
	case sf::Keyboard::Key::Right:
		MovePieceRight();
		break;
	case sf::Keyboard::Key::Down:
		MovePieceDown();
		break;
	case sf::Keyboard::Key::Up:
		RotateBlock();
		break;
	}
}

void Game::MovePieceLeft()
{
	if (!gameover) 
	{
		currentPiece.Move(0, -1);
		if (IsPieceOutside() || PieceFits() == false)
		{
			currentPiece.Move(0, 1);
		}
	}
}

void Game::MovePieceRight()
{
	if (!gameover)
	{
		currentPiece.Move(0, 1);
		if (IsPieceOutside() || PieceFits() == false)
		{
			currentPiece.Move(0, -1);
		}
	}
}

void Game::MovePieceDown()
{
	if (!gameover)
	{
		currentPiece.Move(1, 0);
		if (IsPieceOutside() || PieceFits() == false)
		{
			currentPiece.Move(-1, 0);
			LockPiece();
		}
	}
}

bool Game::IsPieceOutside()
{
	std::vector<Position> tiles = currentPiece.GetCellPositions();
	for (Position item : tiles)
	{
		if (board.IsCellOutside(item.row, item.column))
		{
			return true;
		}
	
	}
	return false;
	
}

void Game::RotateBlock()
{
	currentPiece.Rotate();
	if (IsPieceOutside() ||PieceFits() == false)
	{
		currentPiece.UndoRotation();
	}
}

void Game::LockPiece()
{
	std::vector<Position> tiles = currentPiece.GetCellPositions();
	for (Position item : tiles)
	{
		board.board[item.row][item.column] = currentPiece.id;
	}
	currentPiece = nextPiece;
	if (PieceFits() == false)
	{
		gameover = true;

	}
	nextPiece = GetRandomPiece();
	int completeRows = board.ClearFullRows();
}

bool Game::PieceFits()
{
	std::vector<Position> tiles = currentPiece.GetCellPositions();
	for (Position item : tiles)
	{
		if (board.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}

	}
	return true;
 }

void Game::Reset()
{
	board.Init();
	pieces = GetAllPieces();
	currentPiece = GetRandomPiece();
	nextPiece = GetRandomPiece();
}
