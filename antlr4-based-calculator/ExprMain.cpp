#include <iostream>

#include "antlr4-cpp/ExprBaseListener.h"
#include "antlr4-cpp/ExprLexer.h"
#include "antlr4-cpp/ExprParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

class EvalListener : public ExprBaseListener {
	map<string,double> vars;
	stack<string> id_vars;
	stack<string> fullStack;
	int asgn = 0;
	string key;
	vector<string> array;
public:
	virtual void enterProg(ExprParser::ProgContext *ctx) {
		cout << "enterProg: "<< ctx->getText();
		string all = ctx->getText();
		std::replace(all.begin(),all.end(),'\n',';');
		stringstream ss(all);
		string temp;
		while (ss >> temp){
			array.push_back(temp);
			cout<< "\ntemp:"<<temp<<endl;
		}
		
	}
	virtual void exitProg(ExprParser::ProgContext *ctx) {
		cout << "exitProg: ";
		for (std::stack<string> dump = fullStack; !dump.empty(); dump.pop())
			std::cout << dump.top() << '\n';

	}
	virtual void enterExpr(ExprParser::ExprContext *ctx) {
		cout << "\tenterExpr: \n";
	}
	virtual void exitExpr(ExprParser::ExprContext *ctx) {
		cout << "\texitExpr: \n";
	}
	virtual void visitTerminal(tree::TerminalNode *node) {
		cout << "\t\tTerminal: " << node->getText() << "\n";
		if (asgn == 1){
			vars.insert(pair<string,double>(key,atof(node->getText().c_str())));
			vars[key]=atof(node->getText().c_str());
			cout<< key << ":" << vars[key] << endl;
			asgn = 0;
		}
		if (node->getText() == "="){
			asgn = 1;
			key = fullStack.top();
		}
		fullStack.push(node->getText());
		if (node->getSymbol()->getType() == ExprLexer::INT){
		int v = atoi(node->getText().c_str());
		}
	}
	
};

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		cerr << "[Usage] " << argv[0] << "  <input-file>\n";
		exit(0);
	}
	std::ifstream stream;
	stream.open(argv[1]);
	if (stream.fail()) {
		cerr << argv[1] << " : file open fail\n";
		exit(0);
	}

	cout << "---Expression Evaluation with ANTLR listener---\n";
	ANTLRInputStream input(stream);
	ExprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ExprParser parser(&tokens);	
	//ParseTree *tree = parser.prog();
	//cout << tree -> toStringTree(&parser) <<endl;
	ParseTreeWalker walker;
	EvalListener listener;	

	walker.walk(&listener, parser.prog());
//	cout << evalStack;
}
