%{
    #include "parser.tab.h"
%}

%%

^#.*$        {}
[0-9]+       {yylval.num = atoi(yytext); return NUMBER;}
\+           {return PLUS;}
\-           {return MINUS;}
\*           {return MULTIPLY;}
\/           {return DIVIDE;}
\^           {return POWER;}
\(           {return OPEN_BRACKET;}
\)           {return CLOSE_BRACKET;}
\\\n         {}
\n           {return EOL;}
[[:blank:]]* {}
.            {}

%%
