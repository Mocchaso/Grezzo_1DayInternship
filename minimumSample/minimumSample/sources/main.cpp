// main.cpp : アプリケーションのエントリ ポイントを定義します。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MinimumEngine.h"

// 障害物
class Object {
public:
	MEVector2 center;		// 中心座標
	MEVector2 size;			// サイズ
	MEColor color;			// カラー
	float rotation;			// 回転（ラジアン単位）
	float rotSpeed;			// 回転速度（ラジアン/秒）
};

// グローバル変数
static const float PI = 3.1415926f;				// 円周率
static const float DEG2RAD = PI / 180.0f;		// °をラジアンに変換する係数
static const int DISPLAY_WIDTH = 1200;			// クライアント領域の幅
static const int DISPLAY_HEIGHT = 800;			// クライアント領域の高さ
static const size_t OBSTACLE_NUM = 10;				// 障害物の数
static Object player; // プレイヤー
static Object obstacles[OBSTACLE_NUM];			// 障害物情報テーブル
static bool hasStartedJumping = false;
static bool hasFinishedJumping = false;
static int score = 0; // プレイヤーが進んだ距離
static bool isGameOver = false;

// float 乱数生成 [min, max]
static float Random(float min, float max)
{
	float range = max - min;
	return (float)((double)rand() / (double)RAND_MAX * range) + min;
}

static bool isCollider(MEVector2 player_start, MEVector2 player_end, MEVector2 obstracle_start, MEVector2 obstracle_end) { // 衝突判定
	return player_end.x > obstracle_start.x && obstracle_end.x > player_start.x && player_end.y > obstracle_start.y && obstracle_end.y > player_start.y;
}

// ゲームの初期化
static void InitializeApplication()
{
	MEColor clearColor = { 0.0f, 0.25f, 0.25f, 1.0f };

	// 乱数を初期化
	srand((unsigned int)time(NULL));

	// プレイヤーのパラメータを初期化
	Object* p = &player;
	const MEVector2 scale = { 1, 1 };
	ME_SetTransform(&p->center, p->rotation, &scale);
	p->center.x = -450.0f;
	p->center.y = -250.0f;
	p->size.x = 70.0f;
	p->size.y = 70.0f;
	p->color.r = 1.0f;
	p->color.g = 1.0f;
	p->color.b = 1.0f;
	p->color.a = 1.0f;
	p->rotation = 0.0f;
	p->rotSpeed = Random(-1080.0f * DEG2RAD, 1080.0f * DEG2RAD);

	// 障害物たちをランダムに初期化
	for (int i = 0; i < OBSTACLE_NUM; i++) {
		Object* obstacle = &obstacles[i];
		obstacle->center.x = Random(200.0f, 400.f);
		obstacle->center.y = -250.0f;
		obstacle->size.x = 50.0f;
		obstacle->size.y = 70.0f;
		obstacle->color.r = Random(0.5f, 1.0f);
		obstacle->color.g = Random(0.5f, 1.0f);
		obstacle->color.b = Random(0.5f, 1.0f);
		obstacle->color.a = 1.0f;
		obstacle->rotation = 0.0f;
		obstacle->rotSpeed = Random(-1080.0f * DEG2RAD, 1080.0f * DEG2RAD);
	}

	// クリアカラーを設定しておく
	ME_SetClearColor(&clearColor);
}

// ゲームの更新
static void Update(float deltaTime)
{

	// マウスカーソルの座標を取得
	MEVector2 mousePos;
	ME_GetMousePosition(&mousePos);

	// マウスカーソル座標をワールド座標系に変換
	mousePos.x -= DISPLAY_WIDTH * 0.5f;
	mousePos.y -= DISPLAY_HEIGHT * 0.5f;
	mousePos.y = -mousePos.y;

	if (ME_GetKeyTriggered(ME_KEY_SPACE) == 1) { // スペースキーが押されたら
		printf("space pushed");
		Object* p = &player;
		if (p->center.y == -250.0f) { // 地面に着いているときだけジャンプ開始判定をオン
			hasStartedJumping = true;
		}
	}

	const Object* p = &player;
	MEVector2 start = { p->center.x + -(p->size.x * 0.5f), p->center.y +  -(p->size.y * 0.5f) };
	MEVector2 end = { p->center.x + (p->size.x * 0.5f), p->center.y + (p->size.y * 0.5f) };

	const Object* o = &obstacles[0];
	MEVector2 start2 = { o->center.x + -o->size.x * 0.5f, o->center.y + -o->size.y * 0.5f };
	MEVector2 end2 = { o->size.x * 0.5f, o->size.y * 0.5f };

	if (isCollider(start, end, start2, end2)) {
		isGameOver = true;
	}

	// ジャンプ
	if (hasStartedJumping) {
		Object* p = &player;
		p->center.y += 5.0f;
		if (p->center.y == -100.0f) {
			hasStartedJumping = false;
			hasFinishedJumping = true;
		}
	}
	if (hasFinishedJumping) {
		Object* p = &player;
		p->center.y -= 5.0f;
		if (p->center.y == -250.0f) {
			hasFinishedJumping = false;
		}
	}

	// 障害物をスクロール
	for (int i = 0; i < OBSTACLE_NUM; i++) {
		Object* o = &obstacles[i];
		o->center.x -= 6.0f;
	}

	if (!isGameOver) {
		score++; // スコア加算
	}
}

// 描画
static void Draw()
{
	// 主人公（矩形）を描画
	const Object* p = &player;
	const MEVector2 scale = { 1, 1 };
	const MEColor black = { 0, 0, 0, 1 };
	char stringBuffer[16];
	// トランスフォームを設定
	ME_SetTransform(&p->center, p->rotation, &scale);
	MEVector2 start = { -(p->size.x * 0.5f),  -(p->size.y * 0.5f) };
	MEVector2 end = { (p->size.x * 0.5f), (p->size.y * 0.5f) };
	if (isGameOver) { // 衝突したらゲームオーバー
		MEColor color = { 1.0f, 1.0f, 1.0f, 1 };
		MEVector2 d = { 0, 0 };
		ME_SetTransform(&d, 0.0f, &scale);
		char stringBuffer[100];
		snprintf(stringBuffer, sizeof(stringBuffer), "Game Over... Your score is %d", score);
		ME_DrawText(&start, &end, stringBuffer, 32.0f, &color, ME_TEXT_ALIGN_H_CENTER, ME_TEXT_ALIGN_V_CENTER);
	}
	else {
		ME_DrawRect(&start, &end, &p->color);

		// 障害物を描画
		const Object* o = &obstacles[0];
		// トランスフォームを設定
		ME_SetTransform(&o->center, o->rotation, &scale);
		MEVector2 start2 = { -o->size.x * 0.5f, -o->size.y * 0.5f };
		MEVector2 end2 = { o->size.x * 0.5f, o->size.y * 0.5f };
		ME_DrawRect(&start2, &end2, &o->color);
	}
}

// エントリポイント
int main()
{
	// MEライブラリを初期化
	ME_Initialize("障害物避けゲー", DISPLAY_WIDTH, DISPLAY_HEIGHT);

	// ゲームの初期化
	InitializeApplication();

	// メインループ
	int exitCode = ME_MainLoop(Update, Draw);

	// MEライブラリを終了
	ME_Finalize();
    return exitCode;
}

