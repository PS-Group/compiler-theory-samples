/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>

// Generated function: void ParseBatchGrammar(void*, int, SToken, CBatchParser*);

#include "BatchParser_private.h"

using namespace parser_private;

// Indicate that ParseBatchGrammarFree() will never be called with a nullptr.
#define YYPARSEFREENEVERNULL 1

/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/*
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands.
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseBatchGrammarTOKENTYPE     is the data type used for minor tokens given
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseBatchGrammarTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseBatchGrammarARG_SDECL     A static variable declaration for the %extra_argument
**    ParseBatchGrammarARG_PDECL     A parameter declaration for the %extra_argument
**    ParseBatchGrammarARG_STORE     Code to store %extra_argument into yypParser
**    ParseBatchGrammarARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 35
#define YYACTIONTYPE unsigned char
#define ParseBatchGrammarTOKENTYPE SToken
typedef union {
  int yyinit;
  ParseBatchGrammarTOKENTYPE yy0;
  NamesListPtr yy15;
  ExpressionPtr yy23;
  StatementListPtr yy40;
  FunctionPtr yy53;
  StatementPtr yy56;
  ExpressionListPtr yy63;
  int yy69;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseBatchGrammarARG_SDECL CBatchParser *pParse;
#define ParseBatchGrammarARG_PDECL ,CBatchParser *pParse
#define ParseBatchGrammarARG_FETCH CBatchParser *pParse = yypParser->pParse
#define ParseBatchGrammarARG_STORE yypParser->pParse = pParse
#define YYNSTATE 91
#define YYNRULE 40
#define YYERRORSYMBOL 22
#define YYERRSYMDT yy69
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (238)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    29,   27,   26,   25,   24,    2,   26,   25,   24,   67,
 /*    10 */    73,   61,   29,   27,   26,   25,   24,    2,   59,   30,
 /*    20 */    60,   84,   72,   30,   62,   79,   58,   21,   89,   76,
 /*    30 */    32,   30,   20,   19,   18,   53,   17,   52,   91,   88,
 /*    40 */    29,   27,   26,   25,   24,   63,   58,   42,    7,   81,
 /*    50 */    83,   49,   20,   19,   18,   82,   17,   52,   31,   30,
 /*    60 */    14,   29,   27,   26,   25,   24,    3,   29,   27,   26,
 /*    70 */    25,   24,    2,    6,   51,   59,   50,   60,   77,   12,
 /*    80 */    30,   58,   30,    5,   85,    4,   30,   20,   19,   18,
 /*    90 */    58,   17,   52,   75,   68,   43,   20,   19,   18,   58,
 /*   100 */    17,   52,   74,   48,   40,   20,   19,   18,   58,   17,
 /*   110 */    52,   69,   44,   37,   20,   19,   18,   58,   17,   52,
 /*   120 */    70,   47,   56,   20,   19,   18,   58,   17,   52,   71,
 /*   130 */    55,   54,   20,   19,   18,   46,   17,   52,   64,   59,
 /*   140 */    87,   60,   77,   11,   86,   45,  132,    1,   66,   65,
 /*   150 */    41,   39,   63,   58,   29,   27,   26,   25,   24,   20,
 /*   160 */    19,   18,   38,   17,   52,   59,  133,   60,   77,   13,
 /*   170 */    36,   35,   34,   30,   33,   23,   22,   59,  133,   60,
 /*   180 */    77,    9,   57,   28,   78,   23,   22,  133,  133,  133,
 /*   190 */   133,   58,   57,   28,  133,   80,  133,   20,   19,   18,
 /*   200 */    58,   16,   52,  133,  133,   80,   20,   19,   18,   58,
 /*   210 */    17,   52,  133,  133,  133,   20,   19,   18,  133,   15,
 /*   220 */    52,   64,   59,   87,   60,   77,    8,   86,  133,  133,
 /*   230 */   133,   90,   65,   59,  133,   60,   77,   10,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    3,    4,    5,    8,
 /*    10 */    11,   10,    1,    2,    3,    4,    5,    6,   22,   20,
 /*    20 */    24,   25,   11,   20,    8,   10,    8,   12,    6,   11,
 /*    30 */     9,   20,   14,   15,   16,   17,   18,   19,    0,    6,
 /*    40 */     1,    2,    3,    4,    5,    7,    8,   23,    6,   10,
 /*    50 */     6,   27,   14,   15,   16,    6,   18,   19,   13,   20,
 /*    60 */     9,    1,    2,    3,    4,    5,    6,    1,    2,    3,
 /*    70 */     4,    5,    6,    6,   10,   22,   12,   24,   25,   26,
 /*    80 */    20,    8,   20,    6,   11,    6,   20,   14,   15,   16,
 /*    90 */     8,   18,   19,   11,    8,   23,   14,   15,   16,    8,
 /*   100 */    18,   19,   11,   29,   23,   14,   15,   16,    8,   18,
 /*   110 */    19,   11,   23,   23,   14,   15,   16,    8,   18,   19,
 /*   120 */    11,   23,   23,   14,   15,   16,    8,   18,   19,   11,
 /*   130 */    23,   23,   14,   15,   16,   23,   18,   19,   22,   22,
 /*   140 */    24,   24,   25,   26,   28,   23,   30,   31,   32,   33,
 /*   150 */    23,   23,    7,    8,    1,    2,    3,    4,    5,   14,
 /*   160 */    15,   16,   23,   18,   19,   22,   34,   24,   25,   26,
 /*   170 */    23,   23,   23,   20,   23,    1,    2,   22,   34,   24,
 /*   180 */    25,   26,    8,    9,   10,    1,    2,   34,   34,   34,
 /*   190 */    34,    8,    8,    9,   34,   21,   34,   14,   15,   16,
 /*   200 */     8,   18,   19,   34,   34,   21,   14,   15,   16,    8,
 /*   210 */    18,   19,   34,   34,   34,   14,   15,   16,   34,   18,
 /*   220 */    19,   22,   22,   24,   24,   25,   26,   28,   34,   34,
 /*   230 */    34,   32,   33,   22,   34,   24,   25,   26,
};
#define YY_SHIFT_USE_DFLT (-2)
#define YY_SHIFT_COUNT (65)
#define YY_SHIFT_MIN   (-1)
#define YY_SHIFT_MAX   (201)
static const short yy_shift_ofst[] = {
 /*     0 */   145,   38,  118,  109,  192,  201,  192,  192,   18,  100,
 /*    10 */    91,   82,   73,  183,  174,  184,  184,  184,  184,  184,
 /*    20 */   184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
 /*    30 */   184,  184,    1,   11,   -1,   66,   60,   39,  153,  153,
 /*    40 */   153,  153,  153,  153,    3,    3,    3,    3,   64,   15,
 /*    50 */    86,   79,   77,   67,   62,   62,   62,   51,   45,   49,
 /*    60 */    44,   42,   21,   16,   33,   22,
};
#define YY_REDUCE_USE_DFLT (-5)
#define YY_REDUCE_COUNT (32)
#define YY_REDUCE_MIN   (-4)
#define YY_REDUCE_MAX   (211)
static const short yy_reduce_ofst[] = {
 /*     0 */   116,  199,  211,  200,  155,  143,  117,   53,   -4,   -4,
 /*    10 */    -4,   -4,   -4,   -4,   24,  151,  149,  148,  147,  139,
 /*    20 */   128,  127,  122,  112,  108,  107,   99,   98,   90,   89,
 /*    30 */    81,   72,   74,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   131,  131,  131,  131,  131,  131,  131,  131,  131,  131,
 /*    10 */   131,  131,  131,  131,  131,  131,  131,  131,  131,  131,
 /*    20 */   131,  131,  131,  131,  131,  131,  131,  131,  131,  131,
 /*    30 */   131,  131,  131,  131,  131,  131,  131,  131,  108,  107,
 /*    40 */   121,  117,  116,  106,  122,  128,  127,  123,  131,  131,
 /*    50 */   131,  131,  131,  131,  126,  125,  124,  130,  131,  131,
 /*    60 */   131,  131,  131,  131,  131,  131,   92,  100,  101,   99,
 /*    70 */   109,  112,  114,  115,  113,  111,  110,  102,  118,  119,
 /*    80 */   129,  120,  105,  104,  103,   98,   97,   96,   95,   94,
 /*    90 */    93,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
**
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseBatchGrammarARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/*
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseBatchGrammarTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = {
  "$",             "PLUS",          "MINUS",         "STAR",
  "SLASH",         "PERCENT",       "NEWLINE",       "FUNCTION",
  "ID",            "LPAREN",        "RPAREN",        "END",
  "COMMA",         "ASSIGN",        "PRINT",         "RETURN",
  "IF",            "ELSE",          "WHILE",         "DO",
  "LESS",          "NUMBER",        "error",         "expression",
  "statement",     "statement_line",  "statement_list",  "expression_list",
  "function_declaration",  "parameter_list",  "translation_unit",  "toplevel_list",
  "toplevel_line",  "toplevel_statement",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "translation_unit ::= toplevel_list",
 /*   1 */ "toplevel_list ::= toplevel_line",
 /*   2 */ "toplevel_list ::= toplevel_list toplevel_line",
 /*   3 */ "toplevel_line ::= toplevel_statement NEWLINE",
 /*   4 */ "toplevel_line ::= error NEWLINE",
 /*   5 */ "toplevel_statement ::= statement",
 /*   6 */ "toplevel_statement ::= function_declaration",
 /*   7 */ "function_declaration ::= FUNCTION ID LPAREN RPAREN NEWLINE statement_list END",
 /*   8 */ "function_declaration ::= FUNCTION ID LPAREN parameter_list RPAREN NEWLINE statement_list END",
 /*   9 */ "parameter_list ::= ID",
 /*  10 */ "parameter_list ::= parameter_list COMMA ID",
 /*  11 */ "statement_list ::= statement_line",
 /*  12 */ "statement_list ::= statement_list statement_line",
 /*  13 */ "statement_line ::= statement NEWLINE",
 /*  14 */ "statement_line ::= error NEWLINE",
 /*  15 */ "statement ::= ID ASSIGN expression",
 /*  16 */ "statement ::= PRINT expression",
 /*  17 */ "statement ::= RETURN expression",
 /*  18 */ "statement ::= IF expression NEWLINE END",
 /*  19 */ "statement ::= IF expression NEWLINE statement_list END",
 /*  20 */ "statement ::= IF expression NEWLINE statement_list ELSE NEWLINE statement_list END",
 /*  21 */ "statement ::= WHILE expression NEWLINE END",
 /*  22 */ "statement ::= WHILE expression NEWLINE statement_list END",
 /*  23 */ "statement ::= DO NEWLINE WHILE expression END",
 /*  24 */ "statement ::= DO NEWLINE statement_list WHILE expression END",
 /*  25 */ "expression_list ::= expression",
 /*  26 */ "expression_list ::= expression_list COMMA expression",
 /*  27 */ "expression ::= ID LPAREN RPAREN",
 /*  28 */ "expression ::= ID LPAREN expression_list RPAREN",
 /*  29 */ "expression ::= LPAREN expression RPAREN",
 /*  30 */ "expression ::= expression LESS expression",
 /*  31 */ "expression ::= expression PLUS expression",
 /*  32 */ "expression ::= expression MINUS expression",
 /*  33 */ "expression ::= expression STAR expression",
 /*  34 */ "expression ::= expression SLASH expression",
 /*  35 */ "expression ::= expression PERCENT expression",
 /*  36 */ "expression ::= PLUS expression",
 /*  37 */ "expression ::= MINUS expression",
 /*  38 */ "expression ::= NUMBER",
 /*  39 */ "expression ::= ID",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/*
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to ParseBatchGrammar and ParseBatchGrammarFree.
*/
void *ParseBatchGrammarAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseBatchGrammarARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
      /* TERMINAL Destructor */
    case 1: /* PLUS */
    case 2: /* MINUS */
    case 3: /* STAR */
    case 4: /* SLASH */
    case 5: /* PERCENT */
    case 6: /* NEWLINE */
    case 7: /* FUNCTION */
    case 8: /* ID */
    case 9: /* LPAREN */
    case 10: /* RPAREN */
    case 11: /* END */
    case 12: /* COMMA */
    case 13: /* ASSIGN */
    case 14: /* PRINT */
    case 15: /* RETURN */
    case 16: /* IF */
    case 17: /* ELSE */
    case 18: /* WHILE */
    case 19: /* DO */
    case 20: /* LESS */
    case 21: /* NUMBER */
{

    (void)yypParser;
    (void)yypminor;
    (void)pParse;

}
      break;
    case 23: /* expression */
{
 Destroy((yypminor->yy23));
}
      break;
    case 24: /* statement */
    case 25: /* statement_line */
{
 Destroy((yypminor->yy56));
}
      break;
    case 26: /* statement_list */
{
 Destroy((yypminor->yy40));
}
      break;
    case 27: /* expression_list */
{
 Destroy((yypminor->yy63));
}
      break;
    case 28: /* function_declaration */
{
 Destroy((yypminor->yy53));  Destroy((yypminor->yy53));
}
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/*
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseBatchGrammarAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseBatchGrammarFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseBatchGrammarStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;

  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if(
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseBatchGrammarARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */

    (void)yypMinor; // Silence compiler warnings.
    pParse->OnStackOverflow();
   ParseBatchGrammarARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 30, 1 },
  { 31, 1 },
  { 31, 2 },
  { 32, 2 },
  { 32, 2 },
  { 33, 1 },
  { 33, 1 },
  { 28, 7 },
  { 28, 8 },
  { 29, 1 },
  { 29, 3 },
  { 26, 1 },
  { 26, 2 },
  { 25, 2 },
  { 25, 2 },
  { 24, 3 },
  { 24, 2 },
  { 24, 2 },
  { 24, 4 },
  { 24, 5 },
  { 24, 8 },
  { 24, 4 },
  { 24, 5 },
  { 24, 5 },
  { 24, 6 },
  { 27, 1 },
  { 27, 3 },
  { 23, 3 },
  { 23, 4 },
  { 23, 3 },
  { 23, 3 },
  { 23, 3 },
  { 23, 3 },
  { 23, 3 },
  { 23, 3 },
  { 23, 3 },
  { 23, 2 },
  { 23, 2 },
  { 23, 1 },
  { 23, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseBatchGrammarARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 3: /* toplevel_line ::= toplevel_statement NEWLINE */
      case 4: /* toplevel_line ::= error NEWLINE */ yytestcase(yyruleno==4);
{
  yy_destructor(yypParser,6,&yymsp[0].minor);
}
        break;
      case 5: /* toplevel_statement ::= statement */
{
    pParse->AddStatement(Take(yymsp[0].minor.yy56));
}
        break;
      case 6: /* toplevel_statement ::= function_declaration */
{
    pParse->AddFunction(Take(yymsp[0].minor.yy53));
}
        break;
      case 7: /* function_declaration ::= FUNCTION ID LPAREN RPAREN NEWLINE statement_list END */
{
    auto pBody = Take(yymsp[-1].minor.yy40);
    EmplaceAST<CFunctionAST>(yygotominor.yy53, yymsp[-5].minor.yy0.stringId, std::vector<unsigned>(), std::move(*pBody));
  yy_destructor(yypParser,7,&yymsp[-6].minor);
  yy_destructor(yypParser,9,&yymsp[-4].minor);
  yy_destructor(yypParser,10,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 8: /* function_declaration ::= FUNCTION ID LPAREN parameter_list RPAREN NEWLINE statement_list END */
{
    auto pParameters = Take(yymsp[-4].minor.yy15);
    auto pBody = Take(yymsp[-1].minor.yy40);
    EmplaceAST<CFunctionAST>(yygotominor.yy53, yymsp[-6].minor.yy0.stringId, std::move(*pParameters), std::move(*pBody));
  yy_destructor(yypParser,7,&yymsp[-7].minor);
  yy_destructor(yypParser,9,&yymsp[-5].minor);
  yy_destructor(yypParser,10,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 9: /* parameter_list ::= ID */
{
    auto list = Make<NamesList>();
    list->emplace_back(yymsp[0].minor.yy0.stringId);
    yygotominor.yy15 = list.release();
}
        break;
      case 10: /* parameter_list ::= parameter_list COMMA ID */
{
    auto pList = Take(yymsp[-2].minor.yy15);
    pList->emplace_back(yymsp[0].minor.yy0.stringId);
    yygotominor.yy15 = pList.release();
  yy_destructor(yypParser,12,&yymsp[-1].minor);
}
        break;
      case 11: /* statement_list ::= statement_line */
{
    CreateList(yygotominor.yy40, yymsp[0].minor.yy56);
}
        break;
      case 12: /* statement_list ::= statement_list statement_line */
{
    ConcatList(yygotominor.yy40, yymsp[-1].minor.yy40, yymsp[0].minor.yy56);
}
        break;
      case 13: /* statement_line ::= statement NEWLINE */
{
    MovePointer(yymsp[-1].minor.yy56, yygotominor.yy56);
  yy_destructor(yypParser,6,&yymsp[0].minor);
}
        break;
      case 14: /* statement_line ::= error NEWLINE */
{
    yygotominor.yy56 = nullptr;
  yy_destructor(yypParser,6,&yymsp[0].minor);
}
        break;
      case 15: /* statement ::= ID ASSIGN expression */
{
    EmplaceAST<CAssignAST>(yygotominor.yy56, yymsp[-2].minor.yy0.stringId, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,13,&yymsp[-1].minor);
}
        break;
      case 16: /* statement ::= PRINT expression */
{
    EmplaceAST<CPrintAST>(yygotominor.yy56, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,14,&yymsp[-1].minor);
}
        break;
      case 17: /* statement ::= RETURN expression */
{
    EmplaceAST<CReturnAST>(yygotominor.yy56, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,15,&yymsp[-1].minor);
}
        break;
      case 18: /* statement ::= IF expression NEWLINE END */
{
    EmplaceAST<CIfAst>(yygotominor.yy56, Take(yymsp[-2].minor.yy23));
  yy_destructor(yypParser,16,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-1].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 19: /* statement ::= IF expression NEWLINE statement_list END */
{
    auto pThenBody = Take(yymsp[-1].minor.yy40);
    EmplaceAST<CIfAst>(yygotominor.yy56, Take(yymsp[-3].minor.yy23), std::move(*pThenBody));
  yy_destructor(yypParser,16,&yymsp[-4].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 20: /* statement ::= IF expression NEWLINE statement_list ELSE NEWLINE statement_list END */
{
    auto pThenBody = Take(yymsp[-4].minor.yy40);
    auto pElseBody = Take(yymsp[-1].minor.yy40);
    EmplaceAST<CIfAst>(yygotominor.yy56, Take(yymsp[-6].minor.yy23), std::move(*pThenBody), std::move(*pElseBody));
  yy_destructor(yypParser,16,&yymsp[-7].minor);
  yy_destructor(yypParser,6,&yymsp[-5].minor);
  yy_destructor(yypParser,17,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 21: /* statement ::= WHILE expression NEWLINE END */
{
    EmplaceAST<CWhileAst>(yygotominor.yy56, Take(yymsp[-2].minor.yy23));
  yy_destructor(yypParser,18,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-1].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 22: /* statement ::= WHILE expression NEWLINE statement_list END */
{
    auto pBody = Take(yymsp[-1].minor.yy40);
    EmplaceAST<CWhileAst>(yygotominor.yy56, Take(yymsp[-3].minor.yy23), std::move(*pBody));
  yy_destructor(yypParser,18,&yymsp[-4].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 23: /* statement ::= DO NEWLINE WHILE expression END */
{
    EmplaceAST<CRepeatAst>(yygotominor.yy56, Take(yymsp[-1].minor.yy23));
  yy_destructor(yypParser,19,&yymsp[-4].minor);
  yy_destructor(yypParser,6,&yymsp[-3].minor);
  yy_destructor(yypParser,18,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 24: /* statement ::= DO NEWLINE statement_list WHILE expression END */
{
    auto pBody = Take(yymsp[-3].minor.yy40);
    EmplaceAST<CRepeatAst>(yygotominor.yy56, Take(yymsp[-1].minor.yy23), std::move(*pBody));
  yy_destructor(yypParser,19,&yymsp[-5].minor);
  yy_destructor(yypParser,6,&yymsp[-4].minor);
  yy_destructor(yypParser,18,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 25: /* expression_list ::= expression */
{
    CreateList(yygotominor.yy63, yymsp[0].minor.yy23);
}
        break;
      case 26: /* expression_list ::= expression_list COMMA expression */
{
    ConcatList(yygotominor.yy63, yymsp[-2].minor.yy63, yymsp[0].minor.yy23);
  yy_destructor(yypParser,12,&yymsp[-1].minor);
}
        break;
      case 27: /* expression ::= ID LPAREN RPAREN */
{
    EmplaceAST<CCallAST>(yygotominor.yy23, yymsp[-2].minor.yy0.stringId, ExpressionList());
  yy_destructor(yypParser,9,&yymsp[-1].minor);
  yy_destructor(yypParser,10,&yymsp[0].minor);
}
        break;
      case 28: /* expression ::= ID LPAREN expression_list RPAREN */
{
    auto pList = Take(yymsp[-1].minor.yy63);
    EmplaceAST<CCallAST>(yygotominor.yy23, yymsp[-3].minor.yy0.stringId, std::move(*pList));
  yy_destructor(yypParser,9,&yymsp[-2].minor);
  yy_destructor(yypParser,10,&yymsp[0].minor);
}
        break;
      case 29: /* expression ::= LPAREN expression RPAREN */
{
    MovePointer(yymsp[-1].minor.yy23, yygotominor.yy23);
  yy_destructor(yypParser,9,&yymsp[-2].minor);
  yy_destructor(yypParser,10,&yymsp[0].minor);
}
        break;
      case 30: /* expression ::= expression LESS expression */
{
    EmplaceAST<CBinaryExpressionAST>(yygotominor.yy23, Take(yymsp[-2].minor.yy23), BinaryOperation::Less, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,20,&yymsp[-1].minor);
}
        break;
      case 31: /* expression ::= expression PLUS expression */
{
    EmplaceAST<CBinaryExpressionAST>(yygotominor.yy23, Take(yymsp[-2].minor.yy23), BinaryOperation::Add, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,1,&yymsp[-1].minor);
}
        break;
      case 32: /* expression ::= expression MINUS expression */
{
    EmplaceAST<CBinaryExpressionAST>(yygotominor.yy23, Take(yymsp[-2].minor.yy23), BinaryOperation::Substract, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,2,&yymsp[-1].minor);
}
        break;
      case 33: /* expression ::= expression STAR expression */
{
    EmplaceAST<CBinaryExpressionAST>(yygotominor.yy23, Take(yymsp[-2].minor.yy23), BinaryOperation::Multiply, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,3,&yymsp[-1].minor);
}
        break;
      case 34: /* expression ::= expression SLASH expression */
{
    EmplaceAST<CBinaryExpressionAST>(yygotominor.yy23, Take(yymsp[-2].minor.yy23), BinaryOperation::Divide, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,4,&yymsp[-1].minor);
}
        break;
      case 35: /* expression ::= expression PERCENT expression */
{
    EmplaceAST<CBinaryExpressionAST>(yygotominor.yy23, Take(yymsp[-2].minor.yy23), BinaryOperation::Modulo, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,5,&yymsp[-1].minor);
}
        break;
      case 36: /* expression ::= PLUS expression */
{
    EmplaceAST<CUnaryExpressionAST>(yygotominor.yy23, UnaryOperation::Plus, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,1,&yymsp[-1].minor);
}
        break;
      case 37: /* expression ::= MINUS expression */
{
    EmplaceAST<CUnaryExpressionAST>(yygotominor.yy23, UnaryOperation::Minus, Take(yymsp[0].minor.yy23));
  yy_destructor(yypParser,2,&yymsp[-1].minor);
}
        break;
      case 38: /* expression ::= NUMBER */
{
    EmplaceAST<CLiteralAST>(yygotominor.yy23, CValue::FromDouble(yymsp[0].minor.yy0.value));
}
        break;
      case 39: /* expression ::= ID */
{
    EmplaceAST<CVariableRefAST>(yygotominor.yy23, yymsp[0].minor.yy0.stringId);
}
        break;
      default:
      /* (0) translation_unit ::= toplevel_list */ yytestcase(yyruleno==0);
      /* (1) toplevel_list ::= toplevel_line */ yytestcase(yyruleno==1);
      /* (2) toplevel_list ::= toplevel_list toplevel_line */ yytestcase(yyruleno==2);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseBatchGrammarARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */

    pParse->OnFatalError();
  ParseBatchGrammarARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseBatchGrammarARG_FETCH;
#define TOKEN (yyminor.yy0)

    (void)yymajor;  // Silence compiler warnings.
    pParse->OnError(TOKEN); // TOKEN has type defined in '%token_type'
  ParseBatchGrammarARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseBatchGrammarARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  ParseBatchGrammarARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseBatchGrammarAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void ParseBatchGrammar(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseBatchGrammarTOKENTYPE yyminor       /* The value for the token */
  ParseBatchGrammarARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseBatchGrammarARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;

#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
