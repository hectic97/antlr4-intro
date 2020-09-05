/* Expr.g4 */
grammar Expr;

// parser rules
prog	:	(expr NEWLINE* )* ;

expr	:	expr ('*'|'/') expr
	|	expr ('+'|'-') expr
	|	INT
	|	'(' expr ')' ;

// lexer rules
NEWLINE	:	[\n\r] ;
INT	:	[0-9]+ ;
WS	:	[ \t\r\n]+ -> skip ;
 
