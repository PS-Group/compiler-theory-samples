#include "BatchParser.h"
#include "Token.h"
#include "InterpreterContext.h"
#include <stdlib.h>
#include <new>
#include <iostream>


// pre-declaration of generated functions.
void *ParseBatchGrammarAlloc(void *(*mallocProc)(size_t));
void ParseBatchGrammar(void*, int, Token, CBatchParser*);
void ParseBatchGrammarFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */);
#ifndef NDEBUG
void ParseBatchGrammarTrace(FILE * TraceFILE, char * zTracePrompt);
#endif


CBatchParser::CBatchParser(CInterpreterContext & context)
    : m_program(context)
{
    auto allocate = [](size_t size) -> void* {
        return new (std::nothrow) char[size];
    };
    m_parser = ParseBatchGrammarAlloc(allocate);
    EnterBlock(&m_program);
}

CBatchParser::~CBatchParser()
{
    auto retain = [](void *pointer) -> void {
        auto array = reinterpret_cast<char *>(pointer);
        delete[] array;
    };
    ParseBatchGrammarFree(m_parser, retain);
}

bool CBatchParser::Advance(int tokenId, const Token &tokenData)
{
    ParseBatchGrammar(m_parser, tokenId, tokenData, this);
    return !m_isFatalError;
}

#ifndef NDEBUG
void CBatchParser::StartDebugTrace(FILE *output)
{
    m_tracePrompt = "";
    ParseBatchGrammarTrace(output, &m_tracePrompt[0]);
}
#endif

void CBatchParser::OnError(const Token &token)
{
    std::cerr << "Syntax error at (" << token.line << "," << token.column << ")." << std::endl;
}

void CBatchParser::OnStackOverflow()
{
    std::cerr << "LALR parser stack overflow occured." << std::endl;
    m_isFatalError = true;
}

void CBatchParser::OnFatalError()
{
    std::cerr << "Fatal error occured." << std::endl;
    m_isFatalError = true;
}

void CBatchParser::AddStatement(IStatementAstUniquePtr && stmt)
{
    if (stmt)
    {
        m_blocks.top()->AddStatement(std::move(stmt));
    }
}

void CBatchParser::EnterBlock(CAbstractBlockAST *block)
{
    m_blocks.push(block);
}

void CBatchParser::ExitBlock()
{
    m_blocks.pop();
}
