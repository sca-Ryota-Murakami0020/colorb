#include <vector>
#include <DxLib.h>
#include <Time.h>

class Game
{
public:
	//初期化
	void Initialize();
	//ゲームループ
	void RunLoop();
	//ゲームのシャットダウンを行う
	int ShutDown();
	//プレイヤーターンの更新
	void UpdatePlayerTurn(int fin,int num);
	//敵のターン更新
	void UpdateEnemyTurn();
	//入力処理
	void ProcessInput();
	//リザルト
	bool Rezaluto(char c);
	//ゲームループの実行の判別
	bool isRunGame;
	//敵のターンかの判別
	bool isEnemyTurn;
	//プレイヤーの指定した数字
	int playerNum;
	//プレイヤーがあげた指の数
	int playerFin = 0;
	//敵の指定した数字
	int enemyNum;
	//敵があげた指の数
	int enemyFin = 0;
	//指定された数字
	int selectNum;
	//ライフ
	int playerlife = 2;
	//敵のライフ
	int enemylife = 2;
};

