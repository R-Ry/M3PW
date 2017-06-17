#ifndef PWINPUT_HANDLER_H
#define PWINPUT_HANDLER_H

class KeyHandler{

public:
	unsigned char get_ch();
	void change_control(unsigned char index, unsigned char new_input);
	unsigned char get_ch_input_value(unsigned char index);
	
	static KeyHandler* get_instance();	
private:
	//default constructor
	KeyHandler();
	
	//modifiable controls... indices are the original intended controls
	unsigned char ch_input_[128];
	
	static KeyHandler* singleton_;
};

/*****************************************************
CONSTANTS
****************************************************/

const short kScreenWidth = 80;
const short kScreenHeight = 50;

/*
0 = f1, 1 = f2, 2 = f3, 3 = f4, 4 = f5, 5 = f6, 6 = f7, 7 = f8, 8 = backspace, 9 = tab, 10 = f9,
11 = f10, 12 = f11, 13 = enter, 14 = f12, 15 = home, 16 = insert, 17 = delete,
18 = pg up, 19 = pg down, 20 = end, 21 = up, 22 = left, 23 = right, 24 = down, 27 = esc
*/

namespace special_control_key{
	enum{
		F1, F2, F3, F4, F5, F6, F7, F8, BKS, TAB,
		F9, F10, F11, ENT, F12, HOM, INS, DEL, PUP, PDN,
		END, KU, KL, KR, KD, ESC = 27
	};
}

/*
	Used to quickly convert special characters such as arrow keys to the enumerated
	values. Keys such as tab, backspace, esc, are in the enumeration to so integer
	literals don't have to be used to represent them.
*/

const unsigned char kConvertSpecialKey[] = 
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, special_control_key::TAB,	//0
	0, 0, 0, special_control_key::ENT, 0, 0, 0, 0, 0, 0,	//10
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//20
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//30
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//40
	0, 0, 0, 0, 0, 0, 0, 0, 0, special_control_key::F1,	//50
	special_control_key::F2, special_control_key::F3, special_control_key::F4, special_control_key::F5, special_control_key::F6, special_control_key::F7, special_control_key::F8, special_control_key::F9, special_control_key::F10, 0,	//60
	0, special_control_key::HOM, special_control_key::KU, special_control_key::PUP, 0, special_control_key::KL, 0, special_control_key::KR, 0, special_control_key::END,	//70
	special_control_key::KD, special_control_key::PDN, special_control_key::INS, special_control_key::DEL, 0, 0, 0, 0, 0, 0,	//80
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//90
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//100
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//110
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	//120
	0, 0, 0, special_control_key::F11, special_control_key::F12, 0, 0, 0, 0, 0	//130
};

/*
	These values will be stored in the KeyHandler class ch_input_[]
*/
const unsigned char kControlValues[] = 
{
special_control_key::F1, special_control_key::F2, special_control_key::F3, special_control_key::F4, special_control_key::F5, special_control_key::F6, special_control_key::F7, special_control_key::F8, special_control_key::BKS, special_control_key::TAB,
special_control_key::F9, special_control_key::F10, special_control_key::F11, special_control_key::ENT, special_control_key::F12, special_control_key::HOM, special_control_key::INS, special_control_key::DEL, special_control_key::PUP, special_control_key::PDN,
special_control_key::END, special_control_key::KU, special_control_key::KL, special_control_key::KR, special_control_key::KD, 0, 0, special_control_key::ESC, 0, 0,
0, 0, ' ', '!', '\"', '#', '$', '%', '&', '\'',	//30
'(', ')', '*', '+', ',', '-', '.', '/', '0', '1',	//40
'2', '3', '4', '5', '6', '7', '8', '9', ':', ';',	//50
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E',	//60
'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',	//70
'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',	//80
'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c',	//90
'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',	//100
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',	//110
'x', 'y', 'z', '{', '|', '}', '~', 0, 0, 0	//120
};


#endif