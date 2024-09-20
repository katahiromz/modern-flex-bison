%option noyywrap

%top {
    #include "processor.h"
    #include "parser.h"
}

VALUE [0-9]+(\.[0-9]+)?

%%

"+" { return PLUS; }
"-" { return MINUS; }
"*" { return TIMES; }
"(" { return LPAREN; }
")" { return RPAREN; }

{VALUE} {
    yylval = std::make_shared<node_t>(atof(yytext));
    return NUMBER;
}

. ;
