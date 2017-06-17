#include "pwinput_handler.h"
#include <conio.h>
#include <ctime>
//this is to keep track of how to respond to input
static unsigned long input_state = 0;

KeyHandler* KeyHandler::singleton_ = 0;

KeyHandler::KeyHandler(){
	for(int i = 0; i < 128; ++i) ch_input_[i] = kControlValues[i];
}

KeyHandler* KeyHandler::get_instance(){
	if(!singleton_) singleton_ = new KeyHandler;
	
	return singleton_;
}

unsigned char KeyHandler::get_ch(){
	unsigned char ch = getch();
	
	if(ch == 0 || ch == 224){
		ch = getch();
		return kConvertSpecialKey[ch];
	}
	else{
		return kControlValues[ch];
	}
}

void KeyHandler::change_control(unsigned char index, unsigned char new_input){
	ch_input_[index] = new_input;
}

unsigned char KeyHandler::get_ch_input_value(unsigned char index){
	return ch_input_[index];
}
