#include "CalcParser.h"
#include "Token.h"
#include <stdlib.h>
#include <new>
#include <iostream>


// pre-declaration of generated functions.
void *ParseCalcGrammarAlloc(void *(*mallocProc)(size_t));
void ParseCalcGrammar(void*, int, Token, CCalcParser*);
void ParseCalcGrammarFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */);
#ifndef NDEBUG
void ParseCalcGrammarTrace(FILE * TraceFILE, char * zTracePrompt);
#endif


CCalcParser::CCalcParser()
{
    // Лямбда-функция allocate не захватывает переменных,
    //  и может быть преобразована в указатель на функцию
    auto allocate = [](size_t size) -> void* {
        return new (std::nothrow) char[size];
    };
    m_parser = ParseCalcGrammarAlloc(allocate);
}

CCalcParser::~CCalcParser()
{
    // Лямбда-функция retain не захватывает переменных,
    //  и может быть преобразована в указатель на функцию
    auto retain = [](void *pointer) -> void {
        auto array = reinterpret_cast<char *>(pointer);
        delete[] array;
    };
    ParseCalcGrammarFree(m_parser, retain);
}

bool CCalcParser::Advance(int tokenId, const Token &tokenData)
{
    ParseCalcGrammar(m_parser, tokenId, tokenData, this);
    return !m_isErrorState;
}

#ifndef NDEBUG
void CCalcParser::StartDebugTrace(FILE *output)
{
    m_tracePrompt = "";
    ParseCalcGrammarTrace(output, &m_tracePrompt[0]);
}
#endif

void CCalcParser::OnError(const Token &token)
{
    std::cerr << "Syntax error at position " << token.position << std::endl;
    m_isErrorState = true;
}

void CCalcParser::OnStackOverflow()
{
    std::cerr << "LALR parser stack overflow occured." << std::endl;
    m_isErrorState = true;
}

void CCalcParser::PrintResult(double value)
{
    std::cerr << value << std::endl;
}
