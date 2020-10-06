#include <iostream>
#include <cctype>
#include <cmath>

#include "antlr4-cpp/ExprBaseListener.h"
#include "antlr4-cpp/ExprLexer.h"
#include "antlr4-cpp/ExprParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

int op_rank(char op){
	if(op == '*' || op == '/')
		return 2;
	if(op == '+' || op == '-')
		return 1;
	return 0;
}

double cal_op(double a,double b,char op){
	if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
	else if (op == '+')
		return a + b;
	else
		return a - b;
}


class EvalListener : public ExprBaseListener {
	map<string,double> vars;
	int asgn = 0;

	list<string> terminal;
	list<string>::iterator temp;
public:
	virtual void enterProg(ExprParser::ProgContext *ctx) {
	}
	virtual void exitProg(ExprParser::ProgContext *ctx) {
		stack <string> val;
		stack <char> op;
		int assn_sign = 0;

		for (temp = terminal.begin(); temp != terminal.end();temp++)
		{
			if (assn_sign == 1)
			{
				vars.insert(pair<string,double>(val.top(),atof((*temp).c_str())));
				vars[val.top()] = atof((*temp).c_str());
				val.pop();
				assn_sign = 2;	
			}
			if(*temp == "(")
				op.push((*temp)[0]);
			else if (*temp == ")"){
				while (!op.empty() && op.top() != '('){
					double cal_val_1;
				        if (isalpha(val.top()[0]))
						cal_val_1 = vars[val.top()];
					else
						cal_val_1 = atof(val.top().c_str());
					val.pop();
					double cal_val_2;
					if (isalpha(val.top()[0]))
						cal_val_2 = vars[val.top()];
					else
						cal_val_2 = atof(val.top().c_str());
					val.pop();
					char opr = op.top();
					op.pop();
					val.push(to_string(cal_op(cal_val_2,cal_val_1,opr)));
					
				}
				if (!op.empty())
					op.pop();
			}
			else if (*temp == "=")
				assn_sign = 1;
			else if (*temp == "+" || *temp == "-" || *temp == "*" || *temp == "/"){
				while (!op.empty() && op_rank(op.top()) >= op_rank((*temp)[0])){
					double cal_val_1;
					if (isalpha(val.top()[0]))
						cal_val_1 = vars[val.top()];
					else
						cal_val_1 = atof(val.top().c_str());
					val.pop();
					double cal_val_2;
					if (isalpha(val.top()[0]))
						cal_val_2 = vars[val.top()];
					else
						cal_val_2 = atof(val.top().c_str());
					val.pop();
					char opr = op.top();
					op.pop();
					val.push(to_string(cal_op(cal_val_2,cal_val_1,opr)));
							
				}
				op.push((*temp)[0]);

			}
			else if (*temp == ";")
			{
				while (!op.empty()){
					double cal_val_1;
					if (isalpha(val.top()[0]))
						cal_val_1 = vars[val.top()];
					else
						cal_val_1 = atof(val.top().c_str());
					val.pop();
					double cal_val_2;
					if (isalpha(val.top()[0]))
						cal_val_2 = vars[val.top()];
					else
						cal_val_2 = atof(val.top().c_str());
					val.pop();
					char opr = op.top();
					op.pop();
					val.push(to_string(cal_op(cal_val_2,cal_val_1,opr)));
				}
				cout.setf(ios::fixed);
				cout.precision(1);
				if (assn_sign != 2)
					cout << std::round(atof(val.top().c_str())*10)/10 << endl;
				stack <string> val;
				stack <char> op;
				assn_sign = 0;

			}
			else{
				val.push(*temp);
			}
		}




	}
	virtual void enterExpr(ExprParser::ExprContext *ctx) {
	}
	virtual void exitExpr(ExprParser::ExprContext *ctx) {
	}
	virtual void visitTerminal(tree::TerminalNode *node) {
		if ((node->getSymbol()->getType() != ExprLexer::NEWLINE) && (node->getSymbol()->getType() != ExprLexer::WS))
		{
			terminal.push_back(node->getText());
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

	ANTLRInputStream input(stream);
	ExprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ExprParser parser(&tokens);	

	ParseTreeWalker walker;
	EvalListener listener;	

	walker.walk(&listener, parser.prog());

}
