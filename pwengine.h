#ifndef PWENGINE_H
#define PWENGINE_H

typedef void (*PWEngineFunction)();

//cursor must be less than cursor_limit
struct PWEngineVariables{
	const char* parent;
	short cursor_;
	short row_width_;
	short cursor_limit_;
};

//functions for what to do for each keyboard button pressed
struct PWEngineKeystrokeFunctionArray{
	PWEngineFunction function_[128];
	PWEngineKeystrokeFunctionArray& operator=(const PWEngineKeystrokeFunctionArray& r);
};

//functions for what to do when something is "clicked"
struct PWEngineFunctionArray{
	PWEngineFunction function_[128 * 128];
};

void start_engine();
void initiate_engine();
void handle_input(unsigned char ch);



namespace pwfunctions{
	void do_abstract_task();
	
	//generic menu functions
	void decrement_cursor();
	void increment_cursor();
	
	//for start menu
	void exit_game();
	void enter_start_menu_username();
	void enter_start_menu_password();
	void attempt_login();
	void enter_start_menu();
	
	//generic text field functions
	void backspace();
	void input_32();
	void input_33();
	void input_34();
	void input_35();
	void input_36();
	void input_37();
	void input_38();
	void input_39();
	void input_40();
	void input_41();
	void input_42();
	void input_43();
	void input_44();
	void input_45();
	void input_46();
	void input_47();
	void input_48();
	void input_49();
	void input_50();
	void input_51();
	void input_52();
	void input_53();
	void input_54();
	void input_55();
	void input_56();
	void input_57();
	void input_58();
	void input_59();
	void input_60();
	void input_61();
	void input_62();
	void input_63();
	void input_64();
	void input_65();
	void input_66();
	void input_67();
	void input_68();
	void input_69();
	void input_70();
	void input_71();
	void input_72();
	void input_73();
	void input_74();
	void input_75();
	void input_76();
	void input_77();
	void input_78();
	void input_79();
	void input_80();
	void input_81();
	void input_82();
	void input_83();
	void input_84();
	void input_85();
	void input_86();
	void input_87();
	void input_88();
	void input_89();
	void input_90();
	void input_91();
	void input_92();
	void input_93();
	void input_94();
	void input_95();
	void input_96();
	void input_97();
	void input_98();
	void input_99();
	void input_100();
	void input_101();
	void input_102();
	void input_103();
	void input_104();
	void input_105();
	void input_106();
	void input_107();
	void input_108();
	void input_109();
	void input_110();
	void input_111();
	void input_112();
	void input_113();
	void input_114();
	void input_115();
	void input_116();
	void input_117();
	void input_118();
	void input_119();
	void input_120();
	void input_121();
	void input_122();
	void input_123();
	void input_124();
	void input_125();
	void input_126();
}


#endif