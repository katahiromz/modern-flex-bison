#include <cstdio>
#include "processor.h"
#include "lexer.h"
#include "parser.h"

void yyerror(parse_result_t *result, const char *s)
{
    printf("%s\n", s);
}

int main(void)
{
    for (;;)
    {
        fflush(stdin);

        char expr[256];
        if (!fgets(expr, sizeof(expr), stdin))
            continue;

        YY_BUFFER_STATE state = yy_scan_bytes(expr, strcspn(expr, "\n"));
        if (!state)
            continue;

        parse_result_t result;
        if (yyparse(&result) == 0)
            printf("= %f\n", result);

        yy_delete_buffer(state);
    }

    return 0;
}
