#ifndef MINIMUM_ENGINE_H__
#define MINIMUM_ENGINE_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
	
#define DLL_EXPORT __declspec(dllexport)

//-----------------------------------------------------------------------------
// �X�V�֐�
//
// �߂�l: �Ȃ�
// ����: deltaTime �c �O��̕`��J�n����̌o�ߎ���[sec]
//
// ME_MainLoop() �֐��̈����ɂ��̌^�̊֐��ւ̃|�C���^���w�肷��ƁA���̊֐����Q
// �[���t���[���̍X�V�֐��Ƃ��ė��p����܂��B�ڍׂ� ME_MainLoop() �̐���������
// ���������B
//-----------------------------------------------------------------------------
typedef void (_cdecl *MEUpdateFunc)(float deltaTime);

//-----------------------------------------------------------------------------
// �`��֐�
//
// �߂�l: �Ȃ�
// ����: �Ȃ�
//
// ME_MainLoop() �֐��̈����ɂ��̌^�̊֐��ւ̃|�C���^���w�肷��ƁA���̊֐����`
// ��֐��Ƃ��ė��p����܂��B�ڍׂ� ME_MainLoop() �̐������������������B
//-----------------------------------------------------------------------------
typedef void (_cdecl *MEDisplayFunc)(void);

//-----------------------------------------------------------------------------
// �Q�����x�N�g��
//
// �Q�̐��������x�N�g���ł��B
//-----------------------------------------------------------------------------
typedef struct MEVector2
{
	float x;						// X����
	float y;						// Y����
} MEVector2;

//-----------------------------------------------------------------------------
// �J���[
//
// �A���t�@�l�t���̃J���[��\���\���̂ł��BRGBA �̊e�`�����l�����Ƃ� 0.0 �` 1.0
// �ŋP�x��\�����܂��B
//-----------------------------------------------------------------------------
typedef struct MEColor
{
	float r;						// R����
	float g;						// G����
	float b;						// B����
	float a;						// �A���t�@����
} MEColor;

//-----------------------------------------------------------------------------
// �e�L�X�g�����A���C��
//
// ME_DrawText() �Ńe�L�X�g��`�悷��ۂɁA�`��̈�ɑ΂��ăe�L�X�g���ǂ̂悤��
// �����邩�𐅕������ɂ��Ďw�肷�邽�߂̂��̂ł��B
//-----------------------------------------------------------------------------
typedef enum METextAlignH
{
	ME_TEXT_ALIGN_H_LEFT,			// ������
	ME_TEXT_ALIGN_H_CENTER,			// ��������
	ME_TEXT_ALIGN_H_RIGHT			// �E����
} METextAlignH;

//-----------------------------------------------------------------------------
// �e�L�X�g�����A���C��
//
// ME_DrawText() �Ńe�L�X�g��`�悷��ۂɁA�`��̈�ɑ΂��ăe�L�X�g���ǂ̂悤��
// �����邩�𐂒������ɂ��Ďw�肷�邽�߂̂��̂ł��B
//-----------------------------------------------------------------------------
typedef enum METextAlignV
{
	ME_TEXT_ALIGN_V_TOP,			// �㑵��
	ME_TEXT_ALIGN_V_CENTER,			// ��������
	ME_TEXT_ALIGN_V_BOTTOM			// ������
} METextAlignV;

//-----------------------------------------------------------------------------
// �L�[
//-----------------------------------------------------------------------------
typedef enum MEKey
{
	ME_KEY_NONE = 0x00,				// (�Ȃ�)
	ME_KEY_SHIFT = 0x01,			// Shift
	ME_KEY_CTRL = 0x02,				// Ctrl
	ME_KEY_ALT = 0x03,				// Alt
	ME_KEY_LEFT = 0x04,				// �J�[�\���L�[ ��
	ME_KEY_UP = 0x05,				// �J�[�\���L�[ ��
	ME_KEY_RIGHT = 0x06,			// �J�[�\���L�[ ��
	ME_KEY_DOWN = 0x07,				// �J�[�\���L�[ ��
	ME_KEY_BACKSPACE = 0x08,		// BackSpace
	ME_KEY_TAB = 0x09,				// Tab
	ME_KEY_ENTER = 0x0A,			// Enter
	ME_KEY_PAGE_UP = 0x0B,			// PageUp
	ME_KEY_PAGE_DOWN = 0x0C,		// PageDown
	ME_KEY_HOME = 0x0D,				// Home
	ME_KEY_END = 0x0E,				// End
	ME_KEY_INSERT = 0x0F,			// Insert
	ME_MOUSE_LEFT_BUTTON = 0x10,	// �}�E�X���{�^��
	ME_MOUSE_CENTER_BUTTON = 0x11,	// �}�E�X�����{�^��
	ME_MOUSE_RIGHT_BUTTON = 0x12,	// �}�E�X�E�{�^��
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
	ME_KEY_BACK_SLASH = 0x5C,		// �_
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
// ������
//
// �߂�l: �Ȃ�
// ����: caption �c �E�B���h�E�̃L���v�V����������iNULL�I�[������j
//       width �c �E�B���h�E�̃N���C�A���g�̈�̕�[px]
//       height �c �E�B���h�E�̃N���C�A���g�̈�̍���[px]
//
// MinimumEngine �����������A�E�B���h�E�𐶐����ĕ\�����܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_Initialize(const char* caption, int width, int height);

//-----------------------------------------------------------------------------
// �I��
//
// �߂�l: �Ȃ�
// ����: �Ȃ�
//
// MinimumEngine ���I�����܂��B�����Ŋm�ۂ���Ă����������͂��ׂĉ������܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_Finalize(void);

//-----------------------------------------------------------------------------
// ���C�����[�v
//
// �߂�l: �I���R�[�h�i0: ���� / 0�ȊO: ���s�j
// ����: updateFunc �c �X�V���s���֐��ւ̃|�C���^
//       displayFunc �c �`����s���֐��ւ̃|�C���^
//
// �A�v���P�[�V�����̃��C�����[�v�����s���܂��BupdateFunc �ŃQ�[���t���[���̍X
// �V���s���AdisplayFunc �ŕ`����s���܂��B
//
// updateFunc �� deltaTime �����ɂ͑O�� displayFunc �����s���Ă���̌o�ߎ��Ԃ�
// �n����܂��B����̌Ăяo���ł� ME_MainLoop() �̌Ăяo�����s���Ă���̌o��
// ���Ԃ��n����܂��B
//
// �E�B���h�E��������ȂǁA�A�v���P�[�V�������I�����ׂ��^�C�~���O������܂�
// ���̊֐��͏�����Ԃ��܂���B�߂�l�̏I���R�[�h�͂��̂܂܃v���O�����̏I���R�[
// �h�Ƃ��ė��p�ł��܂��B
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_MainLoop(MEUpdateFunc updateFunc, MEDisplayFunc displayFunc);

//-----------------------------------------------------------------------------
// �N���A�J���[��ݒ�
//
// �߂�l: �Ȃ�
// ����: color �c �N���A�J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//
// ��ʂ��N���A����ۂ̃J���[��ݒ肵�܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_SetClearColor(const MEColor* color);

//-----------------------------------------------------------------------------
// �N���A�J���[���擾
//
// �߂�l: �Ȃ�
// ����: color �c �N���A�J���[���󂯎�� MEColor �\���̂ւ̃|�C���^
//
// ME_SetClearColor() �Őݒ肳��Ă���N���A�J���[���擾���܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetClearColor(MEColor* color);

//-----------------------------------------------------------------------------
// ������`��
//
// �߂�l: �Ȃ�
// ����: start �c �n�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       end �c �I�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       color �c �����̃J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//
// �n�_ start �ƏI�_ end �����Ԑ������Acolor �Ŏw�肳�ꂽ�J���[�ŕ`�悵�܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawLine(
	const MEVector2* start,
	const MEVector2* end,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// �܂����`��
//
// �߂�l: �Ȃ�
// ����: points �c �܂���̊e���_���W���i�[����z��̐擪�A�h���X
//       count �c �܂���̒��_���i2�`�j
//       color �c �����̃J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//
// points �̎w���z��Ɋi�[���ꂽ���W���A�擪���珇�Ɍ���łł���܂���� color
// �Ŏw�肳�ꂽ�J���[�ŕ`�悵�܂��Bpoints �̎w���z��͏��Ȃ��Ƃ� count �̗v�f
// �������Ȃ���΂Ȃ�܂���Bcount �� 2 �ɖ����Ȃ��ꍇ�A���̊֐��͉����`�悵��
// ����B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawLineStrip(
	const MEVector2* points,
	int count,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// ��`��`��
//
// �߂�l: �Ȃ�
// ����: start �c �n�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       end �c �I�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       color �c �h��Ԃ��J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//
// �n�_ start �ƁA�I�_ end ������łł��������Ίp���̂P�Ƃ��Ď��悤�Ȏ���
// �s��`���Acolor �Ŏw�肳�ꂽ�J���[�ŕ`�悵�܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawRect(
	const MEVector2* start,
	const MEVector2* end,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// �~��`��
//
// �߂�l: �Ȃ�
// ����: center �c ���S���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       radius �c �~�̔��a
//       color �c �h��Ԃ��J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//       segments �c �������i3�`�j
//
// center �𒆐S�Ƃ������a radius �̉~�� color �Ŏw�肳�ꂽ�J���[�ŕ`�悵�܂��B
//
// ���ۂɂ͂��̊֐��� segments �Ŏw�肳�ꂽ���̒��_���������p�`��`�悵�܂��B
// segments ��傫������Ɗ��炩�ɂȂ�~�ɋ߂Â��܂����A�`�敉�ׂ��傫���Ȃ��
// ���Bsegments �� 3 �ɖ����Ȃ��ꍇ�A���̊֐��͉����`�悵�܂���B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawCircle(
	const MEVector2* center,
	float radius,
	const MEColor* color,
	int segments
);

//-----------------------------------------------------------------------------
// �ȉ~��`��
//
// �߂�l: �Ȃ�
// ����: start �c �n�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       end �c �I�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       color �c �h��Ԃ��J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//       segments �c �������i3�`�j
//
// �n�_ start �ƁA�I�_ end ������łł��������Ίp���̂P�Ƃ��Ď��悤�Ȏ���
// �s��`�ɓ��ڂ���ȉ~���Acolor �Ŏw�肳�ꂽ�J���[�ŕ`�悵�܂��B
//
// ���ۂɂ͂��̊֐��� segments �Ŏw�肳�ꂽ���̒��_�������p�`��`�悵�܂��B
// segments ��傫������Ɗ��炩�ɂȂ�ȉ~�ɋ߂Â��܂����A�`�敉�ׂ��傫���Ȃ��
// ���Bsegments �� 3 �ɖ����Ȃ��ꍇ�A���̊֐��͉����`�悵�܂���B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawEllipse(
	const MEVector2* start,
	const MEVector2* end,
	const MEColor* color,
	int segments
);

//-----------------------------------------------------------------------------
// �O�p�`�X�g���b�v��`��
//
// �߂�l: �Ȃ�
// ����: points �c �O�p�`�X�g���b�v�̊e���_���W���i�[����z��̐擪�A�h���X
//       count �c ���_���i3�`�j
//       color �c �h��Ԃ��J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//
// �O�p�`�X�g���b�v�� color �Ŏw�肳�ꂽ�J���[�ŕ`�悵�܂��Bpoints �Ɋi�[���ׂ�
// �f�[�^�̃t�H�[�}�b�g�ɂ��Ă͕ʓr�h�L�������g���������������B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_DrawTriangleStrip(
	const MEVector2* points,
	int count,
	const MEColor* color
);

//-----------------------------------------------------------------------------
// �������`��
//
// �߂�l: �Ȃ�
// ����: start �c �n�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       end �c �I�_���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       string �c �`�悷�镶����iNULL�I�[������j
//       size �c �t�H���g�T�C�Y
//       color �c �t�H���g�J���[���i�[���� MEColor �\���̂ւ̃|�C���^
//       alignH �c ���������̃A���C���w��
//       alignV �c ���������̃A���C���w��
//
// �n�_ start �ƁA�I�_ end ������łł��������Ίp���̂P�Ƃ��Ď��悤�Ȏ���
// �s��`�̗̈���ɁAstring �Ŏw�肳�ꂽ��������Asize �Ŏw�肳�ꂽ�t�H���g�T�C
// �Y�Acolor �Ŏw�肳�ꂽ�J���[�ŕ`�悵�܂��B
//
// �e�L�X�g����`�̈�Ɏ��܂肫��Ȃ��ꍇ�ł����Ă��A�e�L�X�g�͐؂���ꂸ�ɕ`
// �悳��܂��B��`�̈�Ő؂蔲�����킯�ł͂Ȃ��̂Œ��ӂ��Ă��������B
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
// �������`�悵���ۂ̑傫�����擾
//
// �߂�l: string �Ŏw�肳�ꂽ������̍s����Ԃ��܂��B
// ����: out �c ���ʂ��󂯎�� MEVector2 �\���̂ւ̃|�C���^
//       string �c �`�悷�镶����iNULL�I�[������j
//       size �c �t�H���g�T�C�Y
//
// string �Ŏw�肳�ꂽ������� size �Ŏw�肳�ꂽ�t�H���g�T�C�Y�� ME_DrawText()
// ���g���ĕ`�悵���ۂɁA�ǂꂾ���̑傫���ɂȂ邩���v�Z���Aout �Ŏw�肳�ꂽ�ϐ�
// �Ɋi�[���܂��B���̊֐��͍��W�ϊ��̉e�����������Ȃ��̂Œ��ӂ��Ă��������B
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetTextSize(MEVector2* out, const char* string, float size);

//-----------------------------------------------------------------------------
// ���W�ϊ���ݒ�
//
// �߂�l: �Ȃ�
// ����: translate �c ���s�ړ��ʂ��i�[���� MEVector2 �\���̂ւ̃|�C���^
//       rotation �c ��][radian]
//       scale �c �X�P�[�����i�[���� MEVector2 �\���̂ւ̃|�C���^
//
// ����ȍ~�ɕ`�悳���V�F�C�v�ɓK�p�������W�ϊ���ݒ肵�܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_SetTransform(
	const MEVector2* translate,
	float rotation,
	const MEVector2* scale
);

//-----------------------------------------------------------------------------
// ���W�ϊ����擾
//
// �߂�l: �Ȃ�
// ����: translate �c ���s�ړ��ʂ��󂯎�� MEVector2 �\���̂ւ̃|�C���^
//       rotation �c ��]�ʂ��󂯎�� float �^�ϐ��ւ̃|�C���^[radian]
//       scale �c �X�P�[�����󂯎�� MEVector2 �\���̂ւ̃|�C���^
//
// ME_SetTransform() �ɂ���Đݒ肳��Ă�����W�ϊ��̐ݒ���擾���܂��B�󂯎��
// �K�v���������ڂɂ��Ă� NULL ��ݒ肷�邱�Ƃɂ���Ď󂯎��Ȃ����Ƃ��ł���
// ���B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetTransform(
	MEVector2* translate,
	float* rotation,
	MEVector2* scale
);

//-----------------------------------------------------------------------------
// �J�����̎p����ݒ�
//
// �߂�l: �Ȃ�
// ����: position �c ���W���i�[���� MEVector2 �\���̂ւ̃|�C���^
//       rotation �c ��][radian]
//       zoom �c �Y�[���{��
//
// �J�����̎p����ݒ肵�܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_SetCameraPose(
	const MEVector2* position,
	float rotation,
	float zoom
);

//-----------------------------------------------------------------------------
// �J�����̎p�����擾
//
// �߂�l: �Ȃ�
// ����: position �c ���W���󂯎�� MEVector2 �\���̂ւ̃|�C���^
//       rotation �c ��]���󂯎�� float �^�ϐ��ւ̃|�C���^[radian]
//       zoom �c �Y�[���{���󂯎�� float �^�ϐ��ւ̃|�C���^
//
// ME_SetCameraPose() �Ŏw�肳��Ă���J�����̎p�����擾���܂��B�󂯎��K�v��
// �������ڂɂ��Ă� NULL ��ݒ肷�邱�Ƃɂ���Ď󂯎��Ȃ����Ƃ��ł��܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetCameraPose(
	MEVector2* position,
	float* rotation,
	float* zoom
);

//-----------------------------------------------------------------------------
// �}�E�X���W���擾
//
// �߂�l: �Ȃ�
// ����: position �c ���W���󂯎�� MEVector2 �\���̂ւ̃|�C���^
//
// �}�E�X�|�C���^�̍��W���擾���܂��B�N���C�A���g���W�n�i�E�B���h�E�̃N���C�A��
// �g�̈�̍�������_�Ƃ����E���������̃s�N�Z���P�ʂ̍��W�n�j�Ŏ擾����܂��B
//-----------------------------------------------------------------------------
void DLL_EXPORT ME_GetMousePosition(MEVector2* position);

//-----------------------------------------------------------------------------
// �L�[��������Ă��邩�ǂ����`�F�b�N
//
// �߂�l: ������Ă���ꍇ�� 1 ���A�����łȂ���� 0 ��Ԃ��܂��B
// ����: key �c �`�F�b�N����L�[�̎�ށiMEKey �񋓌^���A�܂��͕����R�[�h�j
//
// key �Ŏw�肳�ꂽ�L�[��������Ă��邩�ǂ������`�F�b�N���܂��Bkey �ɂ� MEKey
// �񋓌^�̒l���w�肷�邩�A�܂��� 'A', '\n' �Ȃǂ�ASCII�R�[�h���w��ł��܂��B
// 
// �X�V�֐��̒��O�ŏ�Ԃ��`�F�b�N����A�X�V�֐��̎��s���ɂ͂��̊֐��̖߂�l�͕�
// �����܂���B
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetKeyPressed(int key);

//-----------------------------------------------------------------------------
// �L�[�������ꂽ�u�Ԃ��ǂ����`�F�b�N
//
// �߂�l: �����ꂽ�u�Ԃ̏ꍇ�� 1 ���A�����łȂ���� 0 ��Ԃ��܂��B
// ����: key �c �`�F�b�N����L�[�̎�ށiMEKey �񋓌^���A�܂��͕����R�[�h�j
//
// key �Ŏw�肳�ꂽ�L�[�������ꂽ�u�Ԃ��ǂ������`�F�b�N���܂��Bkey �ɂ� MEKey
// �񋓌^�̒l���w�肷�邩�A�܂��� 'A', '\n' �Ȃǂ�ASCII�R�[�h���w��ł��܂��B
// 
// �X�V�֐��̒��O�ŏ�Ԃ��`�F�b�N����A�X�V�֐��̎��s���ɂ͂��̊֐��̖߂�l�͕�
// �����܂���B
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetKeyTriggered(int key);

//-----------------------------------------------------------------------------
// �L�[�������ꂽ�u�Ԃ��ǂ����`�F�b�N
//
// �߂�l: �����ꂽ�u�Ԃ̏ꍇ�� 1 ���A�����łȂ���� 0 ��Ԃ��܂��B
// ����: key �c �`�F�b�N����L�[�̎�ށiMEKey �񋓌^���A�܂��͕����R�[�h�j
//
// key �Ŏw�肳�ꂽ�L�[�������ꂽ�u�Ԃ��ǂ������`�F�b�N���܂��Bkey �ɂ� MEKey
// �񋓌^�̒l���w�肷�邩�A�܂��� 'A', '\n' �Ȃǂ�ASCII�R�[�h���w��ł��܂��B
// 
// �X�V�֐��̒��O�ŏ�Ԃ��`�F�b�N����A�X�V�֐��̎��s���ɂ͂��̊֐��̖߂�l�͕�
// �����܂���B
//-----------------------------------------------------------------------------
int DLL_EXPORT ME_GetKeyReleased(int key);

#ifdef __cplusplus
}
#endif

#endif //MINIMUM_ENGINE_H__
