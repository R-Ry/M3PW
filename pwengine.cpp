#include "pwengine.h"
#include "pwinput_handler.h"
#include "hash.h"

#include <iostream>
#include <conio.h>
#include <ctime>


//this is to keep track of how to respond to input
static const char* input_state = 0;
static void* current_variable = 0;

static HashTable* misc_variables = 0;
static HashTable* engine_variables = 0;
static HashTable* key_functions = 0;
static HashTable* function_arrays = 0;

void start_engine(){
	unsigned char ch;
	
	//start the interface at the starting menu
	input_state = "start_menu";
	do{
		std::cout << "input state: " << input_state << "\n";
		
		PWEngineVariables* ev = (PWEngineVariables*)engine_variables->find(input_state);
		std::cout << "cursor: " << ev->cursor_ << "\n";
		do{
			//stuff
		}while(!kbhit());
		
		ch = KeyHandler::get_instance()->get_ch();
		
		handle_input(ch);
	}while(input_state);
}

void handle_input(unsigned char ch){
	PWEngineKeystrokeFunctionArray* kfa
	= (PWEngineKeystrokeFunctionArray*)key_functions->find(input_state);
	
	//only do something if a function is initiated at that particular keystroke
	if(kfa->function_[ch]) kfa->function_[ch]();
}

void initiate_engine(){
	if(!misc_variables) misc_variables = new HashTable;
	if(!engine_variables) engine_variables = new HashTable;
	if(!key_functions) key_functions = new HashTable;
	if(!function_arrays) function_arrays = new HashTable;
	
	{
		//engine variables
		PWEngineVariables* start_menu = new PWEngineVariables;
		start_menu->cursor_ = 0;
		start_menu->row_width_ = 0;
		start_menu->cursor_limit_ = 4;
		engine_variables->add("start_menu", start_menu);
		
		PWEngineVariables* start_menu_username = new PWEngineVariables;
		start_menu_username->cursor_ = 0;
		start_menu_username->row_width_ = 0;
		start_menu_username->cursor_limit_ = 30;
		engine_variables->add("start_menu_username", start_menu_username);
		
		PWEngineVariables* start_menu_password = new PWEngineVariables;
		start_menu_password->cursor_ = 0;
		start_menu_password->row_width_ = 0;
		start_menu_password->cursor_limit_ = 30;
		engine_variables->add("start_menu_password", start_menu_password);
	}
	{
		//keystroke arrays
		
		//generic textbox
		PWEngineKeystrokeFunctionArray generic_textbox;
		for(int i = 0; i < 128; ++i) generic_textbox.function_[i] = 0;
		generic_textbox.function_[special_control_key::BKS] = pwfunctions::backspace;
		generic_textbox.function_[32] = pwfunctions::input_32;
		generic_textbox.function_[33] = pwfunctions::input_33;
		generic_textbox.function_[34] = pwfunctions::input_34;
		generic_textbox.function_[35] = pwfunctions::input_35;
		generic_textbox.function_[36] = pwfunctions::input_36;
		generic_textbox.function_[37] = pwfunctions::input_37;
		generic_textbox.function_[38] = pwfunctions::input_38;
		generic_textbox.function_[39] = pwfunctions::input_39;
		generic_textbox.function_[40] = pwfunctions::input_40;
		generic_textbox.function_[41] = pwfunctions::input_41;
		generic_textbox.function_[42] = pwfunctions::input_42;
		generic_textbox.function_[43] = pwfunctions::input_43;
		generic_textbox.function_[44] = pwfunctions::input_44;
		generic_textbox.function_[45] = pwfunctions::input_45;
		generic_textbox.function_[46] = pwfunctions::input_46;
		generic_textbox.function_[47] = pwfunctions::input_47;
		generic_textbox.function_[48] = pwfunctions::input_48;
		generic_textbox.function_[49] = pwfunctions::input_49;
		generic_textbox.function_[50] = pwfunctions::input_50;
		generic_textbox.function_[51] = pwfunctions::input_51;
		generic_textbox.function_[52] = pwfunctions::input_52;
		generic_textbox.function_[53] = pwfunctions::input_53;
		generic_textbox.function_[54] = pwfunctions::input_54;
		generic_textbox.function_[55] = pwfunctions::input_55;
		generic_textbox.function_[56] = pwfunctions::input_56;
		generic_textbox.function_[57] = pwfunctions::input_57;
		generic_textbox.function_[58] = pwfunctions::input_58;
		generic_textbox.function_[59] = pwfunctions::input_59;
		generic_textbox.function_[60] = pwfunctions::input_60;
		generic_textbox.function_[61] = pwfunctions::input_61;
		generic_textbox.function_[62] = pwfunctions::input_62;
		generic_textbox.function_[63] = pwfunctions::input_63;
		generic_textbox.function_[64] = pwfunctions::input_64;
		generic_textbox.function_[65] = pwfunctions::input_65;
		generic_textbox.function_[66] = pwfunctions::input_66;
		generic_textbox.function_[67] = pwfunctions::input_67;
		generic_textbox.function_[68] = pwfunctions::input_68;
		generic_textbox.function_[69] = pwfunctions::input_69;
		generic_textbox.function_[70] = pwfunctions::input_70;
		generic_textbox.function_[71] = pwfunctions::input_71;
		generic_textbox.function_[72] = pwfunctions::input_72;
		generic_textbox.function_[73] = pwfunctions::input_73;
		generic_textbox.function_[74] = pwfunctions::input_74;
		generic_textbox.function_[75] = pwfunctions::input_75;
		generic_textbox.function_[76] = pwfunctions::input_76;
		generic_textbox.function_[77] = pwfunctions::input_77;
		generic_textbox.function_[78] = pwfunctions::input_78;
		generic_textbox.function_[79] = pwfunctions::input_79;
		generic_textbox.function_[80] = pwfunctions::input_80;
		generic_textbox.function_[81] = pwfunctions::input_81;
		generic_textbox.function_[82] = pwfunctions::input_82;
		generic_textbox.function_[83] = pwfunctions::input_83;
		generic_textbox.function_[84] = pwfunctions::input_84;
		generic_textbox.function_[85] = pwfunctions::input_85;
		generic_textbox.function_[86] = pwfunctions::input_86;
		generic_textbox.function_[87] = pwfunctions::input_87;
		generic_textbox.function_[88] = pwfunctions::input_88;
		generic_textbox.function_[89] = pwfunctions::input_89;
		generic_textbox.function_[90] = pwfunctions::input_90;
		generic_textbox.function_[91] = pwfunctions::input_91;
		generic_textbox.function_[92] = pwfunctions::input_92;
		generic_textbox.function_[93] = pwfunctions::input_93;
		generic_textbox.function_[94] = pwfunctions::input_94;
		generic_textbox.function_[95] = pwfunctions::input_95;
		generic_textbox.function_[96] = pwfunctions::input_96;
		generic_textbox.function_[97] = pwfunctions::input_97;
		generic_textbox.function_[98] = pwfunctions::input_98;
		generic_textbox.function_[99] = pwfunctions::input_99;
		generic_textbox.function_[100] = pwfunctions::input_100;
		generic_textbox.function_[101] = pwfunctions::input_101;
		generic_textbox.function_[102] = pwfunctions::input_102;
		generic_textbox.function_[103] = pwfunctions::input_103;
		generic_textbox.function_[104] = pwfunctions::input_104;
		generic_textbox.function_[105] = pwfunctions::input_105;
		generic_textbox.function_[106] = pwfunctions::input_106;
		generic_textbox.function_[107] = pwfunctions::input_107;
		generic_textbox.function_[108] = pwfunctions::input_108;
		generic_textbox.function_[109] = pwfunctions::input_109;
		generic_textbox.function_[110] = pwfunctions::input_110;
		generic_textbox.function_[111] = pwfunctions::input_111;
		generic_textbox.function_[112] = pwfunctions::input_112;
		generic_textbox.function_[113] = pwfunctions::input_113;
		generic_textbox.function_[114] = pwfunctions::input_114;
		generic_textbox.function_[115] = pwfunctions::input_115;
		generic_textbox.function_[116] = pwfunctions::input_116;
		generic_textbox.function_[117] = pwfunctions::input_117;
		generic_textbox.function_[118] = pwfunctions::input_118;
		generic_textbox.function_[119] = pwfunctions::input_119;
		generic_textbox.function_[120] = pwfunctions::input_120;
		generic_textbox.function_[121] = pwfunctions::input_121;
		generic_textbox.function_[122] = pwfunctions::input_122;
		generic_textbox.function_[123] = pwfunctions::input_123;
		generic_textbox.function_[124] = pwfunctions::input_124;
		generic_textbox.function_[125] = pwfunctions::input_125;
		generic_textbox.function_[126] = pwfunctions::input_126;

		
		
		PWEngineKeystrokeFunctionArray* start_menu = new PWEngineKeystrokeFunctionArray;
		for(int i = 0; i < 128; ++i) start_menu->function_[i] = 0;
		start_menu->function_[special_control_key::KU] = pwfunctions::decrement_cursor;
		start_menu->function_[special_control_key::KD] = pwfunctions::increment_cursor;
		start_menu->function_[special_control_key::ESC] = pwfunctions::exit_game;
		start_menu->function_[special_control_key::ENT] = pwfunctions::do_abstract_task;
		key_functions->add("start_menu", start_menu);
		
		PWEngineKeystrokeFunctionArray* start_menu_username = new PWEngineKeystrokeFunctionArray;
		for(int i = 0; i < 128; ++i) start_menu_username->function_[i] = 0;
		*start_menu_username = generic_textbox;
		start_menu_username->function_[special_control_key::ESC] = pwfunctions::enter_start_menu;
		start_menu_username->function_[special_control_key::ENT] = pwfunctions::attempt_login;
		key_functions->add("start_menu_username", start_menu_username);
		
		PWEngineKeystrokeFunctionArray* start_menu_password = new PWEngineKeystrokeFunctionArray;
		for(int i = 0; i < 128; ++i) start_menu_password->function_[i] = 0;
		*start_menu_password = generic_textbox;
		start_menu_password->function_[special_control_key::ESC] = pwfunctions::enter_start_menu;
		start_menu_password->function_[special_control_key::ENT] = pwfunctions::attempt_login;
		key_functions->add("start_menu_password", start_menu_password);	
	}
	{
		//function arrays
		PWEngineFunctionArray* start_menu = new PWEngineFunctionArray;
		for(int i = 0; i < 128*128; ++i) start_menu->function_[i] = 0;
		start_menu->function_[0] = pwfunctions::enter_start_menu_username;
		start_menu->function_[1] = pwfunctions::enter_start_menu_password;
		start_menu->function_[2] = pwfunctions::attempt_login;
		start_menu->function_[3] = pwfunctions::exit_game;
		function_arrays->add("start_menu", start_menu);
		
		PWEngineFunctionArray* start_menu_username = new PWEngineFunctionArray;
		for(int i = 0; i < 128*128; ++i) start_menu_username->function_[i] = 0;
		function_arrays->add("start_menu_username", start_menu_username);
		
		PWEngineFunctionArray* start_menu_password = new PWEngineFunctionArray;
		for(int i = 0; i < 128*128; ++i) start_menu_password->function_[i] = 0;
		function_arrays->add("start_menu_password", start_menu_password);
	}
	{
		//misc variables
		misc_variables->add("start_menu_username", new char[30]);
		misc_variables->add("start_menu_password", new char[30]);
	}
}

PWEngineKeystrokeFunctionArray& PWEngineKeystrokeFunctionArray::operator=(const PWEngineKeystrokeFunctionArray& r){
	for(int i = 0; i < 128; ++i) this->function_[i] = r.function_[i];
	return *this;
}

//ALL functions that respond to controls
namespace pwfunctions{
	void decrement_cursor(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ > 0) pwev->cursor_--;
	}
		
	void increment_cursor(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 1 < pwev->cursor_limit_) pwev->cursor_++;
	}
	//do_abstract_task is like the equivalent of what happens when you just click
	//anything on a screen. It could be a button that does something or a highlighted
	//url on the internet. It just responds to a "click" at a particular area on the screen.
	void do_abstract_task(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		PWEngineFunctionArray* pwefa = (PWEngineFunctionArray*)function_arrays->find(input_state);
		
		pwefa->function_[pwev->cursor_]();
	}
	
	void exit_game(){
		input_state = 0;
	}
	
	void enter_start_menu_username(){
		input_state = "start_menu_username";
		current_variable = misc_variables->find("start_menu_username");
	}
	
	void enter_start_menu_password(){
		input_state = "start_menu_password";
		current_variable = misc_variables->find("start_menu_password");
	}
	void attempt_login(){
		const char* username = (const char*)misc_variables->find("start_menu_username");
		const char* password = (const char*)misc_variables->find("start_menu_password");
		std::cout << "username: " << username << "\npassword: " << password << "\n";
	}
	
	void enter_start_menu(){
		input_state = "start_menu";
	}

	void backspace(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ > 0){
			char* sz = (char*)current_variable;
			pwev->cursor_--;
			sz[pwev->cursor_] = '\0';
		}
	}
	void input_32(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = ' ';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_33(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '!';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_34(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '\"';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_35(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '#';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_36(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '$';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_37(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '%';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_38(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '&';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_39(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '\'';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_40(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '(';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_41(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = ')';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_42(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '*';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_43(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '+';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_44(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = ',';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_45(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '-';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_46(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '.';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_47(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '/';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_48(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '0';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_49(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '1';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_50(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '2';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_51(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '3';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_52(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '4';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_53(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '5';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_54(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '6';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_55(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '7';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_56(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '8';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_57(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '9';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_58(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = ':';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_59(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = ';';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_60(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '<';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_61(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '=';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_62(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '>';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_63(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '?';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_64(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '@';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_65(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'A';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_66(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'B';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_67(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'C';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_68(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'D';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_69(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'E';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_70(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'F';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_71(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'G';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_72(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'H';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_73(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'I';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_74(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'J';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_75(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'K';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_76(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'L';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_77(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'M';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_78(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'N';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_79(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'O';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_80(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'P';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_81(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'Q';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_82(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'R';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_83(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'S';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_84(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'T';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_85(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'U';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_86(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'V';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_87(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'W';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_88(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'X';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_89(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'Y';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_90(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'Z';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_91(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '[';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_92(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '\\';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_93(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = ']';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_94(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '^';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_95(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '_';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_96(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '`';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_97(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'a';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_98(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'b';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_99(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'c';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_100(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'd';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_101(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'e';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_102(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'f';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_103(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'g';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_104(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'h';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_105(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'i';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_106(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'j';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_107(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'k';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_108(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'l';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_109(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'm';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_110(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'n';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_111(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'o';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_112(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'p';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_113(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'q';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_114(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'r';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_115(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 's';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_116(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 't';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_117(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'u';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_118(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'v';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_119(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'w';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_120(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'x';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_121(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'y';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_122(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = 'z';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_123(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '{';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_124(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '|';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_125(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '}';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
	void input_126(){
		PWEngineVariables* pwev = (PWEngineVariables*)engine_variables->find(input_state);
		if(pwev->cursor_ + 2 < pwev->cursor_limit_){
			char* sz = (char*)current_variable;
			sz[pwev->cursor_] = '~';
			sz[pwev->cursor_ + 1] = '\0';
			pwev->cursor_++;
		}
	}
}