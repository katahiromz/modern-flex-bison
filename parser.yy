%code top {
    #include "processor.h"
}

%define api.value.type {node_ptr_t}
%parse-param {parse_result_t *result}

// Terminals

%token NUMBER PLUS MINUS TIMES UMINUS LPAREN RPAREN

// Precedence and associativity

%left PLUS MINUS
%left TIMES
%left UMINUS

%%

// Grammar rules

start
    : expr { *result = $1->m_value; }
    ;

expr
    : expr PLUS expr            { $$ = op_add($1, $3); }
    | expr MINUS expr           { $$ = op_sub($1, $3); }
    | expr TIMES expr           { $$ = op_mul($1, $3); }
    | MINUS expr %prec UMINUS   { $$ = op_uminus($2); }
    | LPAREN expr RPAREN        { $$ = $2; }
    | NUMBER                    { $$ = $1; }
    ;
