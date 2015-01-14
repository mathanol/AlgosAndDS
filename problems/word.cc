#include <hunspell/hunspell.hxx>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;
class LadderNode { 
	
	public:
		int dist; 
		string word; 
		LadderNode *parent;
		LadderNode(string str, LadderNode *parent, int dist); 
		
};

LadderNode::LadderNode(string str, LadderNode *parent, int dist) {

	this->dist = dist; 
	this->parent = parent;
	word = str;
}


int ladder(string start, string end, Hunspell *h) {

	
	queue<LadderNode*> *word = new queue<LadderNode*>(); 
	
	word->push(new LadderNode(start, NULL, 1));

	while(!word->empty()) {
	
		LadderNode *curr_node = word->front(); 
		word->pop();
		string curr_word = curr_node->word;
		int curr_dist = curr_node->dist; 

		if (curr_word == end) {
			stack<string> st; 
			LadderNode *n = curr_node; 
			while (n != NULL) {
				st.push(n->word);
				n = n->parent;
			}
		
			while(!st.empty()) {
				std::cout << st.top() << " ";
				st.pop(); 
			}

			return curr_dist; 
		}
		for(int i = 0; i < curr_word.length(); i++) {
			for(char c='a'; c <= 'z'; c++) {
				string s(curr_word.c_str());
				s.at(i) = c;
				if(h->spell(s.c_str())) {
					LadderNode *n = new LadderNode(s, curr_node, curr_dist + 1); 
					word->push(n); 
					h->remove(s.c_str());
				}  
			
			}
		}
	}

	return 0; 
}

int main(void) {
	Hunspell *h = new Hunspell("./dict/en_US.aff", "./dict/en_US.dic");
	cout << "The path length is: " << ladder("cold", "warm", h) << endl;  
}
