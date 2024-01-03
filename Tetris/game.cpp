#include "game.h"
#include <random>
#include <algorithm>


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
	soundBuffer.loadFromFile("C:/Users/sarpy/source/repos/Tetris/Sounds/wedding-love-story.wav");
	sound.setBuffer(soundBuffer);
	sound.setVolume(50);
	sound.play();
	soundBuffRot.loadFromFile("C:/Users/sarpy/source/repos/Tetris/Sounds/Sounds_rotate.wav");
	rotateSound.setBuffer(soundBuffRot);
	soundBuffClear.loadFromFile("C:/Users/sarpy/source/repos/Tetris/Sounds/i-have-a-bad-feeling-about-this.wav");
	clearSound.setBuffer(soundBuffClear);
	holdPiece.id = 8;
	ghostPiece.id = 8;

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

//Vector<Piece> Game::GetAllPieces()
//{
//	
//  return pieces;
//}

void Game::Draw(sf::RenderWindow& target)
{
	board.Draw(target);
	currentPiece.Draw(target,11,11);
	ghostPiece.Draw(target,25,25);
	switch(nextPiece.id)
	{
	case 3:
		nextPiece.Draw(target, 255, 290);
		holdPiece.Draw(target, 255, 340);
		break;
	case 4:
		nextPiece.Draw(target,255, 280);
		holdPiece.Draw(target,255, 330 );
		break;
	default:
		nextPiece.Draw(target,270, 270);
		holdPiece.Draw(target, 270, 320);
		break;

	}
	
}

void Game::HandleInput(sf::Keyboard::Key keyPressed,sf::RenderWindow& target)
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
	case sf::Keyboard::Key::C:
		HoldPiece();
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
	// Vector<Position> tiles = currentPiece.GetCellPositions();
	//for (int i = 0; i < tiles.size();i++)
	for (Position item : tiles)
	{
		// Position item = tiles[i];
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
	if (IsPieceOutside() || PieceFits() == false)
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
	// Vector<Position> tiles = currentPiece.GetCellPositions();
	//for (int i = 0; i < tiles.size();i++)
	for (Position item : tiles)
	{
		//Position item = tiles[i];
		board.board[item.row][item.column] = currentPiece.id;
	}
	currentPiece = nextPiece;
	BoardShrink();
	if (PieceFits() == false)
	{
		gameover = true;
		scores.push_back(score);

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
	// Vector<Position> tiles = currentPiece.GetCellPositions();
	//for (int i = 0; i < tiles.size();i++)
	for (Position item : tiles)
	{
		//Position item = tiles[i];
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


void Game::HoldPiece()
{
	Piece temp;

	if (holdPiece.id == 8)
	{
		holdPiece.id = currentPiece.id;
		holdPiece = currentPiece;
		currentPiece = nextPiece;
		nextPiece = GetRandomPiece();
	}
	else
	{
		temp = currentPiece;
		currentPiece = holdPiece;
		holdPiece = temp;

		/*while (holdPiece.GetCellPositions() != holdPiece.cells[0])                        
		{
			holdPiece.Rotate();
		}*/
		//holdPiece.
	}

	/*if (std::find(pieces.begin(), pieces.end(), holdPiece) != pieces.end()) 
	{
		temp = currentPiece;
		currentPiece = holdPiece;
		holdPiece = temp;
		holdPiece.Draw(target, 460, 300);
	}
	else 
	{
		holdPiece = currentPiece;
		currentPiece = nextPiece;
		holdPiece.Draw(target, 460, 300);
	}*/
	
}


bool Game::GhostPieceFits()
{
	std::vector<Position> tiles = ghostPiece.GetCellPositions();
	// Vector<Position> tiles = currentPiece.GetCellPositions();
	//for (int i = 0; i < tiles.size();i++)
	for (Position item : tiles)
	{
		//Position item = tiles[i];
		if (board.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}

	}
	return true;
}

void Game::GhostPiece()
{
	ghostPiece = currentPiece;
	while (GhostPieceFits())
	{
		ghostPiece.Move(1, 0);
	}
	
}

void Game::BoardShrink()
{
	switch(score)
	{
	case 300:
		board.DecreaseNumRow(1);
	case 500:
		board.DecreaseNumRow(2);
	case 700:
		board.DecreaseNumRow(3);
	case 900:
		board.DecreaseNumRow(4);
		board.DecreaseNumRow(1);
	case 1500:
		board.DecreaseNumRow(8);
		board.DecreaseNumRow(1);
	}

}
