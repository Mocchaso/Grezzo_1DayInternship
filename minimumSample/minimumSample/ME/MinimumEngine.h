#ifndef MINIMUM_ENGINE_H__
#define MINIMUM_ENGINE_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
	
#define DLL_EXPORT __declspec(dllexport)

//-----------------------------------------------------------------------------
// 更新関数
//
// 戻り値: なし
// 引数: deltaTime … 前回の描画開始からの経過時間[sec]
//
// ME_MainLoop() 関数の引数にこの型の関数へのポインタを指定すると、その関数がゲ
// ームフレームの更新関数として利用されます。詳細は ME_MainLoop() の説明をご覧
// ください。
//-----------------------------------------------------------------------------
typedef void (_cdecl *MEUpdateFunc)(float deltaTime);

//-----------------------------------------------------------------------------
// 描画関数
//
// 戻り値: なし
// 引数: なし
//
// ME_MainLoop() 関数の引数にこの型の関数へのポインタを指定すると、その関数が描
// 画関数として利用されます。詳細は ME_MainLoop() の説明をご覧ください。
//-----------------------------------------------------------------------------
typedef void (_cdecl *MEDisplayFunc)(void);

//-----------------------------------------------------------------------------
// ２次元ベクトル
//
// ２つの成分を持つベクトルです。
//-----------------------------------------------------------------------------
typedef struct MEVector2
{
	float x;						// X成分
	float y;						// Y成分
} MEVector2;

//-----------------------------------------------------------------------------
// カラー
//
// アルファ値付きのカラーを表す構造体です。RGBA の各チャンネルごとに 0.0 〜 1.0
// で輝度を表現します。
//-----------------------------------------------------------------------------
typedef struct MEColor
{
	float r;						// R成分
	float g;						// G成分
	float b;						// B成分
	float a;						// アルファ成分
} MEColor;

//-----------------------------------------------------------------------------
// テキスト水平アライン
//
// ME_DrawText() でテキストを描画する際に、描画領域に対してテキストをどのように
// 揃えるかを水平方向について指定するためのものです。
//-----------------------------------------------------------------------------
typedef enum METextAlignH
{
	ME_TEXT_ALIGN_H_LEFT,			// 左揃え
	ME_TEXT_ALIGN_H_CENTER,			// 中央揃え
	ME_TEXT_ALIGN_H_RIGHT			// 右揃え
} METextAlignH;

//-----------------------------------------------------------------------------
// テキスト垂直アライン
//
// ME_DrawText() でテキストを描画する際に、描画領域に対してテキストをどのように
// 揃えるかを垂直方向について指定するためのものです。
//-----------------------------------------------------------------------------
typedef enum METextAlignV
{
	ME_TEXT_ALIGN_V_TOP,			// 上揃え
	ME_TEXT_ALIGN_V_CENTER,			// 中央揃え
	ME_TEXT_ALIGN_V_BOTTOM			// 下揃え
} METextAlignV;

//-----------------------------------------------------------------------------
// キー
//-----------------------------------------------------------------------------
typedef enum MEKey
{
	ME_KEY_NONE = 0x00,				// (なし)
	ME_KEY_SHIFT = 0x01,			// Shift
	ME_KEY_CTRL = 0x02,				// Ctrl
	ME_KEY_ALT = 0x03,				// Alt
	ME_KEY_LEFT = 0x04,				// カーソルキー ←
	ME_KEY_UP = 0x05,				// カーソルキー ↑
	ME_KEY_RIGHT = 0x06,			// カーソルキー →
	ME_KEY_DOWN = 0x07,				// カーソルキー ↓
	ME_KEY_BACKSPACE = 0x08,		// BackSpace
	ME_KEY_TAB = 0x09,				// Tab
	ME_KEY_ENTER = 0x0A,			// Enter
	ME_KEY_PAGE_UP = 0x0B,			// PageUp
	ME_KEY_PAGE_DOWN = 0x0C,		// PageDown
	ME_KEY_HOME = 0x0D,				// Home
	ME_KEY_END = 0x0E,				// End
	ME_KEY_INSERT = 0x0F,			// Insert
	ME_MOUSE_LEFT_BUTTON = 0x10,	// マウス左ボタン
	ME_MOUSE_CENTER_BUTTON = 0x11,	// マウス中央ボタン
	ME_MOUSE_RIGHT_BUTTON = 0x12,	// マウス右ボタン
	ME_KEY_ESC = 0x1B,				// Esc
	ME_KEY_SPACE = 0x20,			// Space
	ME_KEY_EXCLAMATION = 0x21,		// !
	ME_KEY_QUOTATION = 0x22,		// "
	ME_KEY_NUMBER_SIGN = 0x23,		// #
	ME_KEY_DOLLAR = 0x24,			// $
	ME_KEY_PERCENT = 0x25,			// %
	ME_KEY_AMPERSAND = 0x26,		// &
	ME_KEY_APOSTROPHE = 0x27,		// '
	ME_KEY_L_PARENTHESIS = 0x28,	// (
	ME_KEY_R_PARENTHESIS = 0x29,	// )
	ME_KEY_ASTERISK = 0x2A,			// *
	ME_KEY_PLUS = 0x2B,				// +
	ME_KEY_COMMA = 0x2C,			// ,
	ME_KEY_HYPHEN = 0x2D,			// -
	ME_KEY_DOT = 0x2E,				// .
	ME_KEY_SLASH = 0x2F,			// /
	ME_KEY_0 = 0x30,				// 0
	ME_KEY_1 = 0x31,				// 1
	ME_KEY_2 = 0x32,				// 2
	ME_KEY_3 = 0x33,				// 3
	ME_KEY_4 = 0x34,				// 4
	ME_KEY_5 = 0x35,				// 5
	ME_KEY_6 = 0x36,				// 6
	ME_KEY_7 = 0x37,				// 7
	ME_KEY_8 = 0x38,				// 8
	ME_KEY_9 = 0x39,				// 9
	ME_KEY_COLON = 0x3A,			// :
	ME_KEY_SEMI_COLON = 0x3B,		// ;
	ME_KEY_LESS_THAN = 0x3C,		// <
	ME_KEY_EQUALS = 0x3D,			// =
	ME_KEY_GREATER_THAN = 0x3E,		// >
	ME_KEY_QUESTION = 0x3F,			// ?
	ME_KEY_COMMERCIAL_AT = 0x40,	// @
	ME_KEY_A = 0x41,				// A
	ME_KEY_B = 0x42,				// B
	ME_KEY_C = 0x43,				// C
	ME_KEY_D = 0x44,				// D
	ME_KEY_E = 0x45,				// E
	ME_KEY_F = 0x46,				// F
	ME_KEY_G = 0x47,				// G
	ME_KEY_H = 0x48,				// H
	ME_KEY_I = 0x49,				// I
	ME_KEY_J = 0x4A,				// J
	ME_KEY_K = 0x4B,				// K
	ME_KEY_L = 0x4C,				// L
	ME_KEY_M = 0x4D,				// M
	ME_KEY_N = 0x4E,				// N
	ME_KEY_O = 0x4F,				// O
	ME_KEY_P = 0x50,				// P
	ME_KEY_Q = 0x51,				// Q
	ME_KEY_R = 0x52,				// R
	ME_KEY_S = 0x53,				// S
	ME_KEY_T = 0x54,				// T
	ME_KEY_U = 0x55,				// U
	ME_KEY_V = 0x56,				// V
	ME_KEY_W = 0x57,				// W
	ME_KEY_X = 0x58,				// X
	ME_KEY_Y = 0x59,				// Y
	ME_KEY_Z = 0x5A,				// Z
	ME_KEY_L_SQUARE_BRACKET = 0x5B,	// [
	ME_KEY_BACK_SLASH = 0x5C,		// ＼
	ME_KEY_R_SQUARE_BRACKET = 0x5D,	// ]
	ME_KEY_CIRCUMFLEX = 0x5E,		// ^
	ME_KEY_UNDER_SCORE = 0x5F,		// _
	ME_KEY_GRAVE = 0x60,			// `
	ME_KEY_F1 = 0x61,				// F1
	ME_KEY_F2 = 0x62,				// F2
	ME_KEY_F3 = 0x63,				// F3
	ME_KEY_F4 = 0x64,				// F4
	ME_KEY_F5 = 0x65,				// F5
	ME_KEY_F6 = 0x66,				// F6
	ME_KEY_F7 = 0x67,				// F7
	ME_KEY_F8 = 0x68,				// F8
	ME_KEY_F9 = 0x69,				// F9
	ME_KEY_F10 = 0x6A,				// F10
	ME_KEY_F11 = 0x6B,				// F11
	ME_KEY_F12 = 0x6C,				// F12
	ME_KEY_L_CURLY_BRACKET = 0x7B,	// {
	ME_KEY_VERTICAL_BAR = 0x7C,		// |
	ME_KEY_R_CURLY_BRACKET = 0x7D,	// }
	ME_KEY_TILDE = 0x7E,			// ~
	ME_KEY_DELETE = 0x7F,			// Delete

	ME_KEY_MAX = 0x80
} MEKey;

//-----------------------------------------------------------------------------
// 初期化
//
// 戻り値: なし
// 引数: caption … ウィンドウのキャプション文字列（NULL終端文字列）
//       width … ウィンドウのクライアント領域の幅[px]
//       height … ウィンドウのクライアント領域の高さ[px]
//
// MinimumEngine を初期化し、ウィンドウを生成して表示します。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_Initialize(const char* caption, int width, int height);

//-----------------------------------------------------------------------------
// 終了
//
// 戻り値: なし
// 引数: なし
//
// MinimumEngine を終了します。内部で確保されていたメモリはすべて解放されます。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_Finalize(void);

//-----------------------------------------------------------------------------
// メインループ
//
// 戻り値: 終了コード（0: 成功 / 0以外: 失敗）
// 引数: updateFunc … 更新を行う関数へのポインタ
//       displayFunc … 描画を行う関数へのポインタ
//
// アプリケーションのメインループを実行します。updateFunc でゲームフレームの更
// 新を行い、displayFunc で描画を行います。
//
// updateFunc の deltaTime 引数には前回 displayFunc を実行してからの経過時間が
// 渡されます。初回の呼び出しでは ME_MainLoop() の呼び出しが行われてからの経過
// 時間が渡されます。
//
// ウィンドウが閉じられるなど、アプリケーションが終了すべきタイミングが来るまで
// この関数は処理を返しません。戻り値の終了コードはそのままプログラムの終了コー
// ドとして利用できます。
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_MainLoop(MEUpdateFunc updateFunc, MEDisplayFunc displayFunc);

//-----------------------------------------------------------------------------
// クリアカラーを設定
//
// 戻り値: なし
// 引数: color … クリアカラーを格納した MEColor 構造体へのポインタ
//
// 画面をクリアする際のカラーを設定します。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_SetClearColor(const MEColor* color);

//-----------------------------------------------------------------------------
// クリアカラーを取得
//
// 戻り値: なし
// 引数: color … クリアカラーを受け取る MEColor 構造体へのポインタ
//
// ME_SetClearColor() で設定されているクリアカラーを取得します。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetClearColor(MEColor* color);

//-----------------------------------------------------------------------------
// 線分を描画
//
// 戻り値: なし
// 引数: start … 始点座標を格納した MEVector2 構造体へのポインタ
//       end … 終点座標を格納した MEVector2 構造体へのポインタ
//       color … 線分のカラーを格納した MEColor 構造体へのポインタ
//
// 始点 start と終点 end を結ぶ線分を、color で指定されたカラーで描画します。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawLine(
	const MEVector2* start,
	const MEVector2* end,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// 折れ線を描画
//
// 戻り値: なし
// 引数: points … 折れ線の各頂点座標を格納する配列の先頭アドレス
//       count … 折れ線の頂点数（2〜）
//       color … 線分のカラーを格納した MEColor 構造体へのポインタ
//
// points の指す配列に格納された座標を、先頭から順に結んでできる折れ線を color
// で指定されたカラーで描画します。points の指す配列は少なくとも count 個の要素
// を持たなければなりません。count が 2 に満たない場合、この関数は何も描画しま
// せん。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawLineStrip(
	const MEVector2* points,
	int count,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// 矩形を描画
//
// 戻り値: なし
// 引数: start … 始点座標を格納した MEVector2 構造体へのポインタ
//       end … 終点座標を格納した MEVector2 構造体へのポインタ
//       color … 塗りつぶすカラーを格納した MEColor 構造体へのポインタ
//
// 始点 start と、終点 end を結んでできる線分を対角線の１つとして持つような軸並
// 行矩形を、color で指定されたカラーで描画します。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawRect(
	const MEVector2* start,
	const MEVector2* end,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// 円を描画
//
// 戻り値: なし
// 引数: center … 中心座標を格納した MEVector2 構造体へのポインタ
//       radius … 円の半径
//       color … 塗りつぶすカラーを格納した MEColor 構造体へのポインタ
//       segments … 分割数（3〜）
//
// center を中心とした半径 radius の円を color で指定されたカラーで描画します。
//
// 実際にはこの関数は segments で指定された数の頂点を持つ正多角形を描画します。
// segments を大きくすると滑らかになり円に近づきますが、描画負荷も大きくなりま
// す。segments が 3 に満たない場合、この関数は何も描画しません。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawCircle(
	const MEVector2* center,
	float radius,
	const MEColor* color,
	int segments
);

//-----------------------------------------------------------------------------
// 楕円を描画
//
// 戻り値: なし
// 引数: start … 始点座標を格納した MEVector2 構造体へのポインタ
//       end … 終点座標を格納した MEVector2 構造体へのポインタ
//       color … 塗りつぶすカラーを格納した MEColor 構造体へのポインタ
//       segments … 分割数（3〜）
//
// 始点 start と、終点 end を結んでできる線分を対角線の１つとして持つような軸並
// 行矩形に内接する楕円を、color で指定されたカラーで描画します。
//
// 実際にはこの関数は segments で指定された数の頂点を持つ多角形を描画します。
// segments を大きくすると滑らかになり楕円に近づきますが、描画負荷も大きくなりま
// す。segments が 3 に満たない場合、この関数は何も描画しません。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawEllipse(
	const MEVector2* start,
	const MEVector2* end,
	const MEColor* color,
	int segments
);

//-----------------------------------------------------------------------------
// 三角形ストリップを描画
//
// 戻り値: なし
// 引数: points … 三角形ストリップの各頂点座標を格納する配列の先頭アドレス
//       count … 頂点数（3〜）
//       color … 塗りつぶすカラーを格納した MEColor 構造体へのポインタ
//
// 三角形ストリップを color で指定されたカラーで描画します。points に格納すべき
// データのフォーマットについては別途ドキュメントをご覧ください。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawTriangleStrip(
	const MEVector2* points,
	int count,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// 文字列を描画
//
// 戻り値: なし
// 引数: start … 始点座標を格納した MEVector2 構造体へのポインタ
//       end … 終点座標を格納した MEVector2 構造体へのポインタ
//       string … 描画する文字列（NULL終端文字列）
//       size … フォントサイズ
//       color … フォントカラーを格納した MEColor 構造体へのポインタ
//       alignH … 水平方向のアライン指定
//       alignV … 垂直方向のアライン指定
//
// 始点 start と、終点 end を結んでできる線分を対角線の１つとして持つような軸並
// 行矩形の領域内に、string で指定された文字列を、size で指定されたフォントサイ
// ズ、color で指定されたカラーで描画します。
//
// テキストが矩形領域に収まりきらない場合であっても、テキストは切り取られずに描
// 画されます。矩形領域で切り抜かれるわけではないので注意してください。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawText(
	const MEVector2* start,
	const MEVector2* end,
	const char* string,
	float size,
	const MEColor* color,
	METextAlignH alignH,
	METextAlignV alignV
);

//-----------------------------------------------------------------------------
// 文字列を描画した際の大きさを取得
//
// 戻り値: string で指定された文字列の行数を返します。
// 引数: out … 結果を受け取る MEVector2 構造体へのポインタ
//       string … 描画する文字列（NULL終端文字列）
//       size … フォントサイズ
//
// string で指定された文字列を size で指定されたフォントサイズで ME_DrawText()
// を使って描画した際に、どれだけの大きさになるかを計算し、out で指定された変数
// に格納します。この関数は座標変換の影響を加味しないので注意してください。
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetTextSize(MEVector2* out, const char* string, float size);

//-----------------------------------------------------------------------------
// 座標変換を設定
//
// 戻り値: なし
// 引数: translate … 平行移動量を格納した MEVector2 構造体へのポインタ
//       rotation … 回転[radian]
//       scale … スケールを格納した MEVector2 構造体へのポインタ
//
// これ以降に描画されるシェイプに適用される座標変換を設定します。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_SetTransform(
	const MEVector2* translate,
	float rotation,
	const MEVector2* scale
);

//-----------------------------------------------------------------------------
// 座標変換を取得
//
// 戻り値: なし
// 引数: translate … 平行移動量を受け取る MEVector2 構造体へのポインタ
//       rotation … 回転量を受け取る float 型変数へのポインタ[radian]
//       scale … スケールを受け取る MEVector2 構造体へのポインタ
//
// ME_SetTransform() によって設定されている座標変換の設定を取得します。受け取る
// 必要が無い項目については NULL を設定することによって受け取らないこともできま
// す。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetTransform(
	MEVector2* translate,
	float* rotation,
	MEVector2* scale
);

//-----------------------------------------------------------------------------
// カメラの姿勢を設定
//
// 戻り値: なし
// 引数: position … 座標を格納した MEVector2 構造体へのポインタ
//       rotation … 回転[radian]
//       zoom … ズーム倍率
//
// カメラの姿勢を設定します。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_SetCameraPose(
	const MEVector2* position,
	float rotation,
	float zoom
);

//-----------------------------------------------------------------------------
// カメラの姿勢を取得
//
// 戻り値: なし
// 引数: position … 座標を受け取る MEVector2 構造体へのポインタ
//       rotation … 回転を受け取る float 型変数へのポインタ[radian]
//       zoom … ズーム倍率受け取る float 型変数へのポインタ
//
// ME_SetCameraPose() で指定されているカメラの姿勢を取得します。受け取る必要が
// 無い項目については NULL を設定することによって受け取らないこともできます。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetCameraPose(
	MEVector2* position,
	float* rotation,
	float* zoom
);

//-----------------------------------------------------------------------------
// マウス座標を取得
//
// 戻り値: なし
// 引数: position … 座標を受け取る MEVector2 構造体へのポインタ
//
// マウスポインタの座標を取得します。クライアント座標系（ウィンドウのクライアン
// ト領域の左上を原点とした右下向き正のピクセル単位の座標系）で取得されます。
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetMousePosition(MEVector2* position);

//-----------------------------------------------------------------------------
// キーが押されているかどうかチェック
//
// 戻り値: 押されている場合は 1 を、そうでなければ 0 を返します。
// 引数: key … チェックするキーの種類（MEKey 列挙型か、または文字コード）
//
// key で指定されたキーが押されているかどうかをチェックします。key には MEKey
// 列挙型の値を指定するか、または 'A', '\n' などのASCIIコードを指定できます。
// 
// 更新関数の直前で状態がチェックされ、更新関数の実行中にはこの関数の戻り値は変
// 化しません。
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetKeyPressed(int key);

//-----------------------------------------------------------------------------
// キーが押された瞬間かどうかチェック
//
// 戻り値: 押された瞬間の場合は 1 を、そうでなければ 0 を返します。
// 引数: key … チェックするキーの種類（MEKey 列挙型か、または文字コード）
//
// key で指定されたキーが押された瞬間かどうかをチェックします。key には MEKey
// 列挙型の値を指定するか、または 'A', '\n' などのASCIIコードを指定できます。
// 
// 更新関数の直前で状態がチェックされ、更新関数の実行中にはこの関数の戻り値は変
// 化しません。
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetKeyTriggered(int key);

//-----------------------------------------------------------------------------
// キーが離された瞬間かどうかチェック
//
// 戻り値: 離された瞬間の場合は 1 を、そうでなければ 0 を返します。
// 引数: key … チェックするキーの種類（MEKey 列挙型か、または文字コード）
//
// key で指定されたキーが離された瞬間かどうかをチェックします。key には MEKey
// 列挙型の値を指定するか、または 'A', '\n' などのASCIIコードを指定できます。
// 
// 更新関数の直前で状態がチェックされ、更新関数の実行中にはこの関数の戻り値は変
// 化しません。
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetKeyReleased(int key);

#ifdef __cplusplus
}
#endif

#endif //MINIMUM_ENGINE_H__
