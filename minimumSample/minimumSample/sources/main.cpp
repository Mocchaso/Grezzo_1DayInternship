// main.cpp : アプリケーションのエントリ ポイントを定義します。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MinimumEngine.h"

// ボックス
typedef struct Box
{
	MEVector2 position;		// 中心座標
	MEVector2 size;			// サイズ
	MEColor color;			// カラー
	float rotation;			// 回転（ラジアン単位）
	float rotSpeed;			// 回転速度（ラジアン/秒）
} Box;

// グローバル変数
static const float PI = 3.1415926f;				// 円周率
static const float DEG2RAD = PI / 180.0f;		// °をラジアンに変換する係数
static const int DISPLAY_WIDTH = 1200;			// クライアント領域の幅
static const int DISPLAY_HEIGHT = 800;			// クライアント領域の高さ
static const size_t BOX_NUM = 100;				// ボックスの数
static Box g_boxes[BOX_NUM];					// ボックス情報テーブル


// float 乱数生成 [min, max]
static float Random(float min, float max)
{
	float range = max - min;
	return (float)((double)rand() / (double)RAND_MAX * range) + min;
}

// ゲームの初期化
static void InitializeApplication()
{
	MEColor clearColor = { 0.0f, 0.25f, 0.25f, 1.0f };

	// 乱数を初期化
	srand((unsigned int)time(NULL));

	// ボックスをランダムに配置
	for (int i = 0; i < BOX_NUM; ++i)
	{
		Box* box = &g_boxes[i];

		box->position.x = Random(DISPLAY_WIDTH * -0.5f, DISPLAY_WIDTH * 0.5f);
		box->position.y = Random(DISPLAY_HEIGHT * -0.5f, DISPLAY_HEIGHT * 0.5f);
		box->size.x = Random(32.0f, 100.0f);
		box->size.y = Random(32.0f, 100.0f);
		box->color.r = Random(0.5f, 1.0f);
		box->color.g = Random(0.5f, 1.0f);
		box->color.b = Random(0.5f, 1.0f);
		box->color.a = 1.0f;
		box->rotation = Random(0.0f, 360.0f * DEG2RAD);
		box->rotSpeed = Random(-1080.0f * DEG2RAD, 1080.0f * DEG2RAD);
	}

	// クリアカラーを設定しておく
	ME_SetClearColor(&clearColor);
}

// ゲームの更新
static void Update(float deltaTime)
{
	// ボックスを更新
	for (int i = 0; i < BOX_NUM; ++i)
	{
		Box* box = &g_boxes[i];

		// 回転させる
		box->rotation += box->rotSpeed * deltaTime;
	}

	// マウスカーソルの座標を取得
	MEVector2 mousePos;
	ME_GetMousePosition(&mousePos);

	// マウスカーソル座標をワールド座標系に変換
	mousePos.x -= DISPLAY_WIDTH * 0.5f;
	mousePos.y -= DISPLAY_HEIGHT * 0.5f;
	mousePos.y = -mousePos.y;

	// 0番目のボックスの座標をマウスカーソルに追従させる
	g_boxes[0].position = mousePos;
}

// 描画
static void Draw()
{
	const MEVector2 scale = { 1, 1 };
	const MEColor black = { 0, 0, 0, 1 };
	char stringBuffer[16];

	// ボックスを描画（若いインデックスのボックスほど手前に描画されるようにする）
	for (int i = BOX_NUM - 1; i >= 0; --i)
	{
		const Box* box = &g_boxes[i];

		// トランスフォームを設定
		ME_SetTransform(&box->position, box->rotation, &scale);

		// 矩形を描画
		MEVector2 start = { -box->size.x * 0.5f, -box->size.y * 0.5f };
		MEVector2 end = { box->size.x * 0.5f, box->size.y * 0.5f };
		ME_DrawRect(&start, &end, &box->color);

		// 番号を描画
		snprintf(stringBuffer, sizeof(stringBuffer), "%d", i);
		ME_DrawText(&start, &end, stringBuffer, 16.0f, &black, ME_TEXT_ALIGN_H_CENTER, ME_TEXT_ALIGN_V_CENTER);
	}
}

// エントリポイント
int main()
{
	// MEライブラリを初期化
	ME_Initialize("ここにタイトルを入力します", DISPLAY_WIDTH, DISPLAY_HEIGHT);

	// ゲームの初期化
	InitializeApplication();

	// メインループ
	int exitCode = ME_MainLoop(Update, Draw);

	// MEライブラリを終了
	ME_Finalize();
    return exitCode;
}

