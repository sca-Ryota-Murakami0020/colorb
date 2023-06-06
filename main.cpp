//指スマを作る
#include "game.h"
#include <DxLib.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() < 0) {
		return -1;
	}

	Game game; // Create an instance of the Game class
	game.Initialize(); // Call the Initialize() function on the instance
	game.RunLoop();

	DxLib_End();
	return 0;
}

//初期化処理
void Game::Initialize()
{
	playerlife = 2;
	enemylife = 2;
	playerNum = 0;
	selectNum = 0;
	playerFin = 0;
	enemyFin = 0;
}

//ゲームループの処理
void Game::RunLoop()
{
	while (isRunGame)
	{
		//ゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			ShutDown();
		}
		ProcessInput();
		
	}
}

//入力処理
void Game::ProcessInput()
{
	printf("Player Turn\n");
	printf("挙げる指の数を指定してください。（０～２）\n");
	scanf_s("%d", playerFin);
	printf("数字を指定してください。（０～４）\n");
	scanf_s("%d", playerNum);

	UpdatePlayerTurn(playerFin, playerNum);
}

//プレイヤー側の更新処理
void Game::UpdatePlayerTurn(int fin,int num)
{
	int Finger = fin;
	int Number = num;
	selectNum = rand() % 5;

	int jugeNum = selectNum + Finger;
	//挙げた指の合計が４を超えないようにする
	if (jugeNum >= 4) jugeNum = 4;

	if (jugeNum == Number)
	{
		--playerlife;
		playerFin = 0;
		playerNum = 0;
		if (playerlife != 0)
		{
			UpdateEnemyTurn();
		}
		else
		{
			Rezaluto('p');
		}
	}
}

void Game::UpdateEnemyTurn()
{
	printf("Enemy Turn\n");
	printf("挙げる指の数を指定してください。（０～２）");
	scanf_s("%d", playerFin);
	int Finger = 0;
	int Number = 0;
	Finger = rand() % 3;
	Number = rand() % 4;
	int jugeNum = playerFin + Finger;
	
	if (jugeNum == Number)
	{
		--enemylife;
		playerFin = 0;
		
		if (enemylife != 0)
		{
			ProcessInput();
		}
		else
		{
			Rezaluto('e');
		}
	}
}

bool Game::Rezaluto(char c)
{
	if (c == 'p') printf("Winner is Player!\n");
	if (c == 'e') printf("Winner is Enemy!\n");
	printf("One more play?(y/n)");
	char select;
	scanf_s("%c", select);
	if(select == 'y')
	{
		return isRunGame;
	}
	else if (select == 'n')
	{
		isRunGame = false;
		return isRunGame;
	}
}

//終了処理
int Game::ShutDown()
{
	isRunGame = false;
	return 0;
}
