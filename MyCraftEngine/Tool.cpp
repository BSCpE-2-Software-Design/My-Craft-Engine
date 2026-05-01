#include "Tool.h"

	Tool::Tool(std::string n, int t) {
		name = n;
		tier = t;
	}

	void Tool::upgrade() {
		tier++;
	}