#include <iostream>

#include "antlr4-cpp/ExprBaseListener.h"
#include "antlr4-cpp/ExprLexer.h"
#include "antlr4-cpp/ExprParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

class EvalListener : public ExprBaseListener {
public:
	virtual void enterProg(ExprParser::ProgContext *ctx) {
		cout << "enterProg: \n";
	}
	virtual void exitProg(ExprParser::ProgContext *ctx) {
		cout << "exitProg: \n";
	}
	virtual void enterExpr(ExprParser::ExprContext *ctx) {
		cout << "\tenterExpr: \n";
	}
	virtual void exitExpr(ExprParser::ExprContext *ctx) {
		cout << "\texitExpr: \n";
	}
	virtual void visitTerminal(tree::TerminalNode *node) {
		cout << "\t\tTerminal: " << node->getText() << "\n";
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

	ParseTreeWalker walker;
	EvalListener listener;	

	walker.walk(&listener, parser.prog());
}
