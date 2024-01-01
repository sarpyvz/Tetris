#include "game.h"
#include <random>

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
	score = 0;
	soundBuffer.loadFromFile("C:/Users/sarpy/source/repos/Tetris/Sounds/AcrosstheStarsLoveTheme.ogg");
	sound.setBuffer(soundBuffer);
	sound.setVolume(50);
	sound.play();
	soundBuffRot.loadFromFile("C:/Users/sarpy/source/repos/Tetris/Sounds/lightsaber-ignition.wav");
	rotateSound.setBuffer(soundBuffRot);
	soundBuffClear.loadFromFile("C:/Users/sarpy/source/repos/Tetris/Sounds/i-have-a-bad-feeling-about-this.wav");
	clearSound.setBuffer(soundBuffClear);
}

Game::~Game()
{
	sound.stop();
	clearSound.stop();
	rotateSound.stop();
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
	currentPiece.Draw(target,11,11);
	switch(nextPiece.id)
	{
	case 3:
		nextPiece.Draw(target, 255, 290);
		break;
	case 4:
		nextPiece.Draw(target,255, 280);
		break;
	default:
		nextPiece.Draw(target,270, 270);
		break;

	}
	
}

void Game::HandleInput(sf::Keyboard::Key keyPressed/*sf::RenderWindow& target*/)
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
		UpdateScore(0, 1);
		break;
	case sf::Keyboard::Key::Up:
		RotateBlock();
		break;
	/*case sf::Keyboard::Key::C:
		HoldPiece(target);
		break;*/
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
	else
	{
		rotateSound.play();
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
	if (completeRows > 0)
	{
		clearSound.play();
		UpdateScore(completeRows, 0);
	}
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
	score = 0;
}

void Game::UpdateScore(int lines_cleared, int move_down_points)
{
	switch (lines_cleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
	}
	score += move_down_points; 
}

//void Game::HoldPiece(sf::RenderWindow& target)
//{
//	Piece holdPiece = currentPiece;
//	currentPiece = nextPiece;
//	holdPiece.Draw(target, 270, 530);
//}