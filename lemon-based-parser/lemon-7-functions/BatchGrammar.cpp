/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>

// Generated function: void ParseBatchGrammar(void*, int, Token, CBatchParser*);

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
#define YYNOCODE 34
#define YYACTIONTYPE unsigned char
#define ParseBatchGrammarTOKENTYPE Token
typedef union {
  int yyinit;
  ParseBatchGrammarTOKENTYPE yy0;
  StatementListPtr yy6;
  ExpressionPtr yy29;
  ExpressionListPtr yy35;
  NamesListPtr yy37;
  StatementPtr yy42;
  FunctionPtr yy63;
  int yy67;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseBatchGrammarARG_SDECL CBatchParser *pParse;
#define ParseBatchGrammarARG_PDECL ,CBatchParser *pParse
#define ParseBatchGrammarARG_FETCH CBatchParser *pParse = yypParser->pParse
#define ParseBatchGrammarARG_STORE yypParser->pParse = pParse
#define YYNSTATE 90
#define YYNRULE 40
#define YYERRORSYMBOL 21
#define YYERRSYMDT yy67
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
#define YY_ACTTAB_COUNT (232)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    90,   40,   23,   22,   88,   47,   86,   58,   53,   52,
 /*    10 */    27,   73,   87,   57,   20,   19,   18,   53,   17,   50,
 /*    20 */    71,   75,   31,   20,   19,   18,   51,   17,   50,    7,
 /*    30 */    86,   58,   53,   29,   28,   26,   25,   24,   20,   19,
 /*    40 */    18,   81,   17,   50,   29,   28,   26,   25,   24,    2,
 /*    50 */    26,   25,   24,   62,   68,   56,   29,   28,   26,   25,
 /*    60 */    24,    2,   74,   30,   21,   53,   67,   54,   83,   55,
 /*    70 */    82,   20,   19,   18,   53,   17,   50,   70,   80,   14,
 /*    80 */    20,   19,   18,   53,   17,   50,   69,    6,    5,   20,
 /*    90 */    19,   18,   53,   17,   50,   64,    4,   63,   20,   19,
 /*   100 */    18,   53,   17,   50,   65,   46,  132,   20,   19,   18,
 /*   110 */    53,   17,   50,   66,   41,  132,   20,   19,   18,   42,
 /*   120 */    17,   50,   59,   49,   85,   48,   43,   36,   84,  132,
 /*   130 */   131,    1,   61,   60,   29,   28,   26,   25,   24,   78,
 /*   140 */    77,   76,   45,   79,   44,   29,   28,   26,   25,   24,
 /*   150 */     3,   29,   28,   26,   25,   24,    2,   53,   54,  132,
 /*   160 */    55,   72,   12,   20,   19,   18,   53,   16,   50,   39,
 /*   170 */    38,  132,   20,   19,   18,   53,   17,   50,   37,   35,
 /*   180 */   132,   20,   19,   18,   34,   15,   50,   23,   22,  132,
 /*   190 */    59,  132,   85,   33,   52,   27,   84,   32,  132,  132,
 /*   200 */    89,   60,  132,  132,  132,   54,   75,   55,   72,   11,
 /*   210 */    54,  132,   55,   72,   13,  132,   54,  132,   55,   72,
 /*   220 */     9,  132,   54,  132,   55,   72,    8,   54,  132,   55,
 /*   230 */    72,   10,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     0,   22,    1,    2,    6,   26,    6,    7,    8,    8,
 /*    10 */     9,   10,    6,    8,   14,   15,   16,    8,   18,   19,
 /*    20 */    11,   20,    9,   14,   15,   16,   17,   18,   19,    6,
 /*    30 */     6,    7,    8,    1,    2,    3,    4,    5,   14,   15,
 /*    40 */    16,    6,   18,   19,    1,    2,    3,    4,    5,    6,
 /*    50 */     3,    4,    5,    8,   11,   10,    1,    2,    3,    4,
 /*    60 */     5,    6,   10,   13,   12,    8,   11,   21,   11,   23,
 /*    70 */    24,   14,   15,   16,    8,   18,   19,   11,    6,    9,
 /*    80 */    14,   15,   16,    8,   18,   19,   11,    6,    6,   14,
 /*    90 */    15,   16,    8,   18,   19,   11,    6,    8,   14,   15,
 /*   100 */    16,    8,   18,   19,   11,   28,   33,   14,   15,   16,
 /*   110 */     8,   18,   19,   11,   22,   33,   14,   15,   16,   22,
 /*   120 */    18,   19,   21,   10,   23,   12,   22,   22,   27,   33,
 /*   130 */    29,   30,   31,   32,    1,    2,    3,    4,    5,   22,
 /*   140 */    22,   22,   22,   10,   22,    1,    2,    3,    4,    5,
 /*   150 */     6,    1,    2,    3,    4,    5,    6,    8,   21,   33,
 /*   160 */    23,   24,   25,   14,   15,   16,    8,   18,   19,   22,
 /*   170 */    22,   33,   14,   15,   16,    8,   18,   19,   22,   22,
 /*   180 */    33,   14,   15,   16,   22,   18,   19,    1,    2,   33,
 /*   190 */    21,   33,   23,   22,    8,    9,   27,   22,   33,   33,
 /*   200 */    31,   32,   33,   33,   33,   21,   20,   23,   24,   25,
 /*   210 */    21,   33,   23,   24,   25,   33,   21,   33,   23,   24,
 /*   220 */    25,   33,   21,   33,   23,   24,   25,   21,   33,   23,
 /*   230 */    24,   25,
};
#define YY_SHIFT_USE_DFLT (-3)
#define YY_SHIFT_COUNT (60)
#define YY_SHIFT_MIN   (-2)
#define YY_SHIFT_MAX   (186)
static const short yy_shift_ofst[] = {
 /*     0 */    24,    0,  102,   93,  158,  167,  158,  158,    9,   84,
 /*    10 */    75,   66,   57,  149,    1,  186,  186,  186,  186,  186,
 /*    20 */   186,  186,  186,  186,  186,  186,  186,  186,  186,  186,
 /*    30 */   186,   45,   55,   43,  150,  144,  133,   32,   32,   32,
 /*    40 */    32,   32,   47,   47,   47,   47,  113,   52,   89,   90,
 /*    50 */    82,   81,   70,   50,   72,   35,   23,   13,    5,    6,
 /*    60 */    -2,
};
#define YY_REDUCE_USE_DFLT (-22)
#define YY_REDUCE_COUNT (31)
#define YY_REDUCE_MIN   (-21)
#define YY_REDUCE_MAX   (206)
static const short yy_reduce_ofst[] = {
 /*     0 */   101,  169,  206,  201,  195,  189,  184,  137,   46,   46,
 /*    10 */    46,   46,   46,   46,  -21,  175,  171,  162,  157,  156,
 /*    20 */   148,  147,  122,  120,  119,  118,  117,  105,  104,   97,
 /*    30 */    92,   77,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   130,  130,  130,  130,  130,  130,  130,  130,  130,  130,
 /*    10 */   130,  130,  130,  130,  130,  130,  130,  130,  130,  130,
 /*    20 */   130,  130,  130,  130,  130,  130,  130,  130,  130,  130,
 /*    30 */   130,  130,  130,  130,  130,  130,  130,  108,  107,  117,
 /*    40 */   116,  106,  121,  122,  127,  126,  130,  130,  130,  130,
 /*    50 */   130,  130,  129,  130,  130,  130,  130,  130,  130,  130,
 /*    60 */   130,   91,  100,  101,   99,  109,  112,  114,  115,  113,
 /*    70 */   111,  110,  102,  118,  119,  128,  125,  124,  123,  120,
 /*    80 */   105,  104,  103,   98,   97,   96,   95,   94,   93,   92,
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
  "NUMBER",        "error",         "expression",    "statement",   
  "statement_line",  "statement_list",  "expression_list",  "function_declaration",
  "parameter_list",  "translation_unit",  "toplevel_list",  "toplevel_line",
  "toplevel_statement",
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
 /*   5 */ "toplevel_line ::= NEWLINE",
 /*   6 */ "toplevel_statement ::= statement",
 /*   7 */ "toplevel_statement ::= function_declaration",
 /*   8 */ "function_declaration ::= FUNCTION ID LPAREN RPAREN NEWLINE statement_list END",
 /*   9 */ "function_declaration ::= FUNCTION ID LPAREN parameter_list RPAREN NEWLINE statement_list END",
 /*  10 */ "parameter_list ::= ID",
 /*  11 */ "parameter_list ::= parameter_list COMMA ID",
 /*  12 */ "statement_list ::= statement_line",
 /*  13 */ "statement_list ::= statement_list statement_line",
 /*  14 */ "statement_line ::= statement NEWLINE",
 /*  15 */ "statement_line ::= error NEWLINE",
 /*  16 */ "statement ::= ID ASSIGN expression",
 /*  17 */ "statement ::= PRINT expression",
 /*  18 */ "statement ::= RETURN expression",
 /*  19 */ "statement ::= IF expression NEWLINE END",
 /*  20 */ "statement ::= IF expression NEWLINE statement_list END",
 /*  21 */ "statement ::= IF expression NEWLINE statement_list ELSE NEWLINE statement_list END",
 /*  22 */ "statement ::= WHILE expression NEWLINE END",
 /*  23 */ "statement ::= WHILE expression NEWLINE statement_list END",
 /*  24 */ "statement ::= DO NEWLINE WHILE expression END",
 /*  25 */ "statement ::= DO NEWLINE statement_list WHILE expression END",
 /*  26 */ "expression_list ::= expression",
 /*  27 */ "expression_list ::= expression_list COMMA expression",
 /*  28 */ "expression ::= ID LPAREN RPAREN",
 /*  29 */ "expression ::= ID LPAREN expression_list RPAREN",
 /*  30 */ "expression ::= LPAREN expression RPAREN",
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
    case 20: /* NUMBER */
{

    (void)yypParser;
    (void)yypminor;
    (void)pParse;

}
      break;
    case 22: /* expression */
{
 Destroy((yypminor->yy29)); 
}
      break;
    case 23: /* statement */
    case 24: /* statement_line */
{
 Destroy((yypminor->yy42)); 
}
      break;
    case 25: /* statement_list */
{
 Destroy((yypminor->yy6)); 
}
      break;
    case 26: /* expression_list */
{
 Destroy((yypminor->yy35)); 
}
      break;
    case 27: /* function_declaration */
{
 Destroy((yypminor->yy63)); 
}
      break;
    case 28: /* parameter_list */
{
 Destroy((yypminor->yy37)); 
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
  { 29, 1 },
  { 30, 1 },
  { 30, 2 },
  { 31, 2 },
  { 31, 2 },
  { 31, 1 },
  { 32, 1 },
  { 32, 1 },
  { 27, 7 },
  { 27, 8 },
  { 28, 1 },
  { 28, 3 },
  { 25, 1 },
  { 25, 2 },
  { 24, 2 },
  { 24, 2 },
  { 23, 3 },
  { 23, 2 },
  { 23, 2 },
  { 23, 4 },
  { 23, 5 },
  { 23, 8 },
  { 23, 4 },
  { 23, 5 },
  { 23, 5 },
  { 23, 6 },
  { 26, 1 },
  { 26, 3 },
  { 22, 3 },
  { 22, 4 },
  { 22, 3 },
  { 22, 3 },
  { 22, 3 },
  { 22, 3 },
  { 22, 3 },
  { 22, 3 },
  { 22, 2 },
  { 22, 2 },
  { 22, 1 },
  { 22, 1 },
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
      case 5: /* toplevel_line ::= NEWLINE */ yytestcase(yyruleno==5);
{
  yy_destructor(yypParser,6,&yymsp[0].minor);
}
        break;
      case 6: /* toplevel_statement ::= statement */
{
    pParse->AddStatement(Take(yymsp[0].minor.yy42));
}
        break;
      case 7: /* toplevel_statement ::= function_declaration */
{
    pParse->AddFunction(Take(yymsp[0].minor.yy63));
}
        break;
      case 8: /* function_declaration ::= FUNCTION ID LPAREN RPAREN NEWLINE statement_list END */
{
    auto pBody = Take(yymsp[-1].minor.yy6);
    EmplaceAST<CFunctionAst>(yygotominor.yy63, yymsp[-5].minor.yy0.stringId, std::vector<unsigned>(), std::move(*pBody));
  yy_destructor(yypParser,7,&yymsp[-6].minor);
  yy_destructor(yypParser,9,&yymsp[-4].minor);
  yy_destructor(yypParser,10,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 9: /* function_declaration ::= FUNCTION ID LPAREN parameter_list RPAREN NEWLINE statement_list END */
{
    auto pParameters = Take(yymsp[-4].minor.yy37);
    auto pBody = Take(yymsp[-1].minor.yy6);
    EmplaceAST<CFunctionAst>(yygotominor.yy63, yymsp[-6].minor.yy0.stringId, std::move(*pParameters), std::move(*pBody));
  yy_destructor(yypParser,7,&yymsp[-7].minor);
  yy_destructor(yypParser,9,&yymsp[-5].minor);
  yy_destructor(yypParser,10,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 10: /* parameter_list ::= ID */
{
    auto list = Make<NamesList>();
    list->emplace_back(yymsp[0].minor.yy0.stringId);
    yygotominor.yy37 = list.release();
}
        break;
      case 11: /* parameter_list ::= parameter_list COMMA ID */
{
    auto pList = Take(yymsp[-2].minor.yy37);
    pList->emplace_back(yymsp[0].minor.yy0.stringId);
    yygotominor.yy37 = pList.release();
  yy_destructor(yypParser,12,&yymsp[-1].minor);
}
        break;
      case 12: /* statement_list ::= statement_line */
{
    CreateList(yygotominor.yy6, yymsp[0].minor.yy42);
}
        break;
      case 13: /* statement_list ::= statement_list statement_line */
{
    ConcatList(yygotominor.yy6, yymsp[-1].minor.yy6, yymsp[0].minor.yy42);
}
        break;
      case 14: /* statement_line ::= statement NEWLINE */
{
    MovePointer(yymsp[-1].minor.yy42, yygotominor.yy42);
  yy_destructor(yypParser,6,&yymsp[0].minor);
}
        break;
      case 15: /* statement_line ::= error NEWLINE */
{
    yygotominor.yy42 = nullptr;
  yy_destructor(yypParser,6,&yymsp[0].minor);
}
        break;
      case 16: /* statement ::= ID ASSIGN expression */
{
    EmplaceAST<CAssignAst>(yygotominor.yy42, yymsp[-2].minor.yy0.stringId, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,13,&yymsp[-1].minor);
}
        break;
      case 17: /* statement ::= PRINT expression */
{
    EmplaceAST<CPrintAst>(yygotominor.yy42, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,14,&yymsp[-1].minor);
}
        break;
      case 18: /* statement ::= RETURN expression */
{
    EmplaceAST<CReturnAst>(yygotominor.yy42, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,15,&yymsp[-1].minor);
}
        break;
      case 19: /* statement ::= IF expression NEWLINE END */
{
    EmplaceAST<CIfAst>(yygotominor.yy42, Take(yymsp[-2].minor.yy29));
  yy_destructor(yypParser,16,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-1].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 20: /* statement ::= IF expression NEWLINE statement_list END */
{
    auto pThenBody = Take(yymsp[-1].minor.yy6);
    EmplaceAST<CIfAst>(yygotominor.yy42, Take(yymsp[-3].minor.yy29), std::move(*pThenBody));
  yy_destructor(yypParser,16,&yymsp[-4].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 21: /* statement ::= IF expression NEWLINE statement_list ELSE NEWLINE statement_list END */
{
    auto pThenBody = Take(yymsp[-4].minor.yy6);
    auto pElseBody = Take(yymsp[-1].minor.yy6);
    EmplaceAST<CIfAst>(yygotominor.yy42, Take(yymsp[-6].minor.yy29), std::move(*pThenBody), std::move(*pElseBody));
  yy_destructor(yypParser,16,&yymsp[-7].minor);
  yy_destructor(yypParser,6,&yymsp[-5].minor);
  yy_destructor(yypParser,17,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 22: /* statement ::= WHILE expression NEWLINE END */
{
    EmplaceAST<CWhileAst>(yygotominor.yy42, Take(yymsp[-2].minor.yy29));
  yy_destructor(yypParser,18,&yymsp[-3].minor);
  yy_destructor(yypParser,6,&yymsp[-1].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 23: /* statement ::= WHILE expression NEWLINE statement_list END */
{
    auto pBody = Take(yymsp[-1].minor.yy6);
    EmplaceAST<CWhileAst>(yygotominor.yy42, Take(yymsp[-3].minor.yy29), std::move(*pBody));
  yy_destructor(yypParser,18,&yymsp[-4].minor);
  yy_destructor(yypParser,6,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 24: /* statement ::= DO NEWLINE WHILE expression END */
{
    EmplaceAST<CRepeatAst>(yygotominor.yy42, Take(yymsp[-1].minor.yy29));
  yy_destructor(yypParser,19,&yymsp[-4].minor);
  yy_destructor(yypParser,6,&yymsp[-3].minor);
  yy_destructor(yypParser,18,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 25: /* statement ::= DO NEWLINE statement_list WHILE expression END */
{
    auto pBody = Take(yymsp[-3].minor.yy6);
    EmplaceAST<CRepeatAst>(yygotominor.yy42, Take(yymsp[-1].minor.yy29), std::move(*pBody));
  yy_destructor(yypParser,19,&yymsp[-5].minor);
  yy_destructor(yypParser,6,&yymsp[-4].minor);
  yy_destructor(yypParser,18,&yymsp[-2].minor);
  yy_destructor(yypParser,11,&yymsp[0].minor);
}
        break;
      case 26: /* expression_list ::= expression */
{
    CreateList(yygotominor.yy35, yymsp[0].minor.yy29);
}
        break;
      case 27: /* expression_list ::= expression_list COMMA expression */
{
    ConcatList(yygotominor.yy35, yymsp[-2].minor.yy35, yymsp[0].minor.yy29);
  yy_destructor(yypParser,12,&yymsp[-1].minor);
}
        break;
      case 28: /* expression ::= ID LPAREN RPAREN */
{
    EmplaceAST<CCallAst>(yygotominor.yy29, yymsp[-2].minor.yy0.stringId, ExpressionList());
  yy_destructor(yypParser,9,&yymsp[-1].minor);
  yy_destructor(yypParser,10,&yymsp[0].minor);
}
        break;
      case 29: /* expression ::= ID LPAREN expression_list RPAREN */
{
    auto pList = Take(yymsp[-1].minor.yy35);
    EmplaceAST<CCallAst>(yygotominor.yy29, yymsp[-3].minor.yy0.stringId, std::move(*pList));
  yy_destructor(yypParser,9,&yymsp[-2].minor);
  yy_destructor(yypParser,10,&yymsp[0].minor);
}
        break;
      case 30: /* expression ::= LPAREN expression RPAREN */
{
    MovePointer(yymsp[-1].minor.yy29, yygotominor.yy29);
  yy_destructor(yypParser,9,&yymsp[-2].minor);
  yy_destructor(yypParser,10,&yymsp[0].minor);
}
        break;
      case 31: /* expression ::= expression PLUS expression */
{
    EmplaceAST<CBinaryExpressionAst>(yygotominor.yy29, Take(yymsp[-2].minor.yy29), BinaryOperation::Add, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,1,&yymsp[-1].minor);
}
        break;
      case 32: /* expression ::= expression MINUS expression */
{
    EmplaceAST<CBinaryExpressionAst>(yygotominor.yy29, Take(yymsp[-2].minor.yy29), BinaryOperation::Substract, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,2,&yymsp[-1].minor);
}
        break;
      case 33: /* expression ::= expression STAR expression */
{
    EmplaceAST<CBinaryExpressionAst>(yygotominor.yy29, Take(yymsp[-2].minor.yy29), BinaryOperation::Multiply, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,3,&yymsp[-1].minor);
}
        break;
      case 34: /* expression ::= expression SLASH expression */
{
    EmplaceAST<CBinaryExpressionAst>(yygotominor.yy29, Take(yymsp[-2].minor.yy29), BinaryOperation::Divide, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,4,&yymsp[-1].minor);
}
        break;
      case 35: /* expression ::= expression PERCENT expression */
{
    EmplaceAST<CBinaryExpressionAst>(yygotominor.yy29, Take(yymsp[-2].minor.yy29), BinaryOperation::Modulo, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,5,&yymsp[-1].minor);
}
        break;
      case 36: /* expression ::= PLUS expression */
{
    EmplaceAST<CUnaryExpressionAst>(yygotominor.yy29, UnaryOperation::Plus, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,1,&yymsp[-1].minor);
}
        break;
      case 37: /* expression ::= MINUS expression */
{
    EmplaceAST<CUnaryExpressionAst>(yygotominor.yy29, UnaryOperation::Minus, Take(yymsp[0].minor.yy29));
  yy_destructor(yypParser,2,&yymsp[-1].minor);
}
        break;
      case 38: /* expression ::= NUMBER */
{
    EmplaceAST<CLiteralAst>(yygotominor.yy29, yymsp[0].minor.yy0.value);
}
        break;
      case 39: /* expression ::= ID */
{
    EmplaceAST<CVariableRefAst>(yygotominor.yy29, yymsp[0].minor.yy0.stringId);
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
