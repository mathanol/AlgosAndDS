#include "List.h"

using namespace std; 
int main(void) { 
	
	ListST<string,string> *l = new ListST<string, string>(); 
	l->put("tutty", "haha"); 
	l->put("potty", "chandeep"); 
	l->del("potty"); 
	cout << l->get("tutty") << endl; 
	return 0;
}
