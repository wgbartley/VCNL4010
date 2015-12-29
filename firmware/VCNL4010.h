#include "application.h"

class VCNL4010{
public:
    void initialize();
	int ambientLight();
	int proximity();
private:
    int address = 0x13;
};