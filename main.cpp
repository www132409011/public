#include <stdio.h>
#include"./node.hpp"
extern int lineNo;
extern int yyparse();
extern int yyrestart(FILE* f);
extern FILE *yyin, *yyout;
extern void gen_code();
std::ofstream Mycout;
int main(int argc, char** args)
{
	for (int i = 1;i < argc;i++){
		if (args[i][0] == '-'){
			switch(args[i][1]){
				case 'S':
					break;
				case 'e':
					break;
				case 'o':
					i++;
					Mycout.open(args[i]);
					yyout = fopen(args[i],"w");
					break;
				default:
					break;
			}		
		}
		else{
			yyin = fopen(args[i],"r");
		}		
	}
	yyrestart(yyin);
	yyparse();
	gen_code();
	return 0;
}
