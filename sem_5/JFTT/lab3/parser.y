%{
    long long FIELD = 1234577;
    int yyerror(char* s);
    int yywrap();
    int yylex();
    long long add(long long a, long long b, long long mod);
    long long substract(long long a, long long b, long long mod);
    long long multiply(long long a, long long b, long long mod);
    long long divide(long long a, long long b, long long mod);
    long long power(long long a, long long b, long long mod);
    long long positive_modulo(long long a, long long mod);
    long long gcd(long long a, long long b);
    long long inverse(long long a, long long mod);
%}


%union {
    long long num;
}

%token EOL
%token<num> NUMBER
%type<num> exp_prior_1
%type<num> exp_prior_2
%type<num> exp_prior_3
%type<num> exp_prior_4
%type<num> exp_prior_5
%type<num> exponent_exp_prior_1
%type<num> exponent_exp_prior_2
%type<num> exponent_exp_prior_3
%type<num> exponent_exp_prior_4
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token POWER
%token OPEN_BRACKET
%token CLOSE_BRACKET

%%

input:
|   line input
;

line: 
    exp_prior_1 EOL {printf("\n%lld\n", $1);}
|   EOL 
;

exp_prior_1:
    exp_prior_2 {$$ = $1;}
|   exp_prior_1 PLUS exp_prior_1 {$$ = add($1, $3, FIELD); printf(" +");}
|   exp_prior_1 MINUS exp_prior_1 {$$ = substract($1, $3, FIELD); printf(" -");}
;

exp_prior_2:
    exp_prior_3 {$$ = $1;}
|   exp_prior_2 MULTIPLY exp_prior_2 {$$ = multiply($1, $3, FIELD); printf(" *");}
|   exp_prior_2 DIVIDE exp_prior_2 {$$ = divide($1, $3, FIELD); printf(" /");}
;

exp_prior_3:
    exp_prior_4 {$$ = $1;}
|   exp_prior_3 POWER exponent_exp_prior_3 {$$ = power($1, $3, FIELD); printf(" ^");}
;

exp_prior_4:
    exp_prior_5 {$$ = $1;}
|   OPEN_BRACKET exp_prior_1 PLUS exp_prior_1 CLOSE_BRACKET {$$ = add($2, $4, FIELD); printf(" +");}
|   OPEN_BRACKET exp_prior_1 MINUS exp_prior_1 CLOSE_BRACKET {$$ = substract($2, $4, FIELD); printf(" -");}
|   OPEN_BRACKET exp_prior_2 MULTIPLY exp_prior_2 CLOSE_BRACKET {$$ = multiply($2, $4, FIELD); printf(" *");}
|   OPEN_BRACKET exp_prior_2 DIVIDE exp_prior_2 CLOSE_BRACKET {$$ = divide($2, $4, FIELD); printf(" /");}
|   OPEN_BRACKET exp_prior_3 POWER exponent_exp_prior_3 CLOSE_BRACKET {$$ = power($2, $4, FIELD); printf(" ^");}
;

exp_prior_5:
    NUMBER {$$ = positive_modulo($1, FIELD); printf(" %lld", $$);}
|   MINUS NUMBER {$$ = positive_modulo(- $2, FIELD); printf(" %lld", $$);}
;

exponent_exp_prior_1:
    exponent_exp_prior_2 {$$ = $1;}
|   exponent_exp_prior_1 PLUS exponent_exp_prior_1 {$$ = add($1, $3, FIELD - 1); printf(" +");}
|   exponent_exp_prior_1 MINUS exponent_exp_prior_1 {$$ = substract($1, $3, FIELD - 1); printf(" -");}
;

exponent_exp_prior_2:
    exponent_exp_prior_3 {$$ = $1;}
|   exponent_exp_prior_2 MULTIPLY exponent_exp_prior_2 {$$ = multiply($1, $3, FIELD - 1); printf(" *");}
|   exponent_exp_prior_2 DIVIDE exponent_exp_prior_2 {$$ = divide($1, $3, FIELD - 1); printf(" /");}
;

exponent_exp_prior_3:
    exponent_exp_prior_4 {$$ = $1;}
|   OPEN_BRACKET exponent_exp_prior_1 PLUS exponent_exp_prior_1 CLOSE_BRACKET {$$ = add($2, $4, FIELD - 1); printf(" +");}
|   OPEN_BRACKET exponent_exp_prior_1 MINUS exponent_exp_prior_1 CLOSE_BRACKET {$$ = substract($2, $4, FIELD - 1); printf(" -");}
|   OPEN_BRACKET exponent_exp_prior_2 MULTIPLY exponent_exp_prior_2 CLOSE_BRACKET {$$ = multiply($2, $4, FIELD - 1); printf(" *");}
|   OPEN_BRACKET exponent_exp_prior_2 DIVIDE exponent_exp_prior_2 CLOSE_BRACKET {$$ = divide($2, $4, FIELD - 1); printf(" /");}
;

exponent_exp_prior_4:
    NUMBER {$$ = positive_modulo($1, FIELD - 1); printf(" %lld", $$);}
|   MINUS NUMBER {$$ = positive_modulo(- $2, FIELD - 1); printf(" %lld", $$);}
;

%%

int main() { 
    return yyparse();
}

int yyerror(char* s) {
    printf("Błąd: %s\n", s);
    return yyparse();;
}

int yywrap() {
    return 1;
}

long long positive_modulo(long long a, long long mod) {
    return (a % mod + mod) % mod;
}

long long add(long long a, long long b, long long mod) {
    return positive_modulo(a + b, mod);
}

long long substract(long long a, long long b, long long mod) {
    return positive_modulo(a - b, mod);
}

long long multiply(long long a, long long b, long long mod) {
    return positive_modulo(a * b, mod);
}

long long divide(long long a, long long b, long long mod) {
    long long g = gcd(a, b);
    a /= g;
    b /= g;
    return positive_modulo(a * inverse(b, mod), mod);
}

long long power(long long a, long long b, long long mod) {
    long long result = 1;

    // Reduce exponent modulo (mod - 1) since (a^mod ≡ a) in a field
    b = b % (mod - 1);

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b = b / 2;
    }

    return result;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long inverse(long long a, long long mod) {
    long long t = 0, new_t = 1;
    long long r = mod, new_r = a;

    while (new_r != 0) {
        long long quotient = r / new_r;

        long long temp = new_t;
        new_t = t - quotient * new_t;
        t = temp;

        temp = new_r;
        new_r = r - quotient * new_r;
        r = temp;
    }

    if (r > 1) {
        printf("Błąd: nie ma odwrotności %lld modulo %lld\n", a, mod);
        return -1; // Inverse does not exist
    }

    if (t < 0) {
        t += mod;
    }

    return t;
}
