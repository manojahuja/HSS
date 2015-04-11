#ifndef CONFIG
#define CONFIG

class HumanInterface {
	private:
		int systemState;
	public:
		HumanInterface(int sysState); //constructor
		void userInterfaceSM(); // statechart
} ;


#endif
