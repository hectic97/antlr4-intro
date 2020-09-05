
// Generated from Expr.g4 by ANTLR 4.8


#include "ExprListener.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::ExprContext *> ExprParser::ProgContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ProgContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ProgContext::NEWLINE() {
  return getTokens(ExprParser::NEWLINE);
}

tree::TerminalNode* ExprParser::ProgContext::NEWLINE(size_t i) {
  return getToken(ExprParser::NEWLINE, i);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}

void ExprParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ExprParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(13);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__4

    || _la == ExprParser::INT) {
      setState(4);
      expr(0);
      setState(8);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::NEWLINE) {
        setState(5);
        match(ExprParser::NEWLINE);
        setState(10);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(15);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ExprContext::INT() {
  return getToken(ExprParser::INT, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::ExprContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(22);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::INT: {
        setState(17);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::T__4: {
        setState(18);
        match(ExprParser::T__4);
        setState(19);
        expr(0);
        setState(20);
        match(ExprParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(32);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(30);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(24);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(25);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__0

          || _la == ExprParser::T__1)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(26);
          expr(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(27);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(28);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__2

          || _la == ExprParser::T__3)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(29);
          expr(4);
          break;
        }

        } 
      }
      setState(34);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "prog", "expr"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'*'", "'/'", "'+'", "'-'", "'('", "')'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "NEWLINE", "INT", "WS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xb, 0x26, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x9, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xc, 0xb, 0x2, 0x7, 
    0x2, 0xe, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x11, 0xb, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x21, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x24, 0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 
    0x4, 0x4, 0x2, 0x4, 0x2, 0x4, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 
    0x2, 0x28, 0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0xa, 0x5, 0x4, 0x3, 0x2, 0x7, 0x9, 0x7, 0x9, 0x2, 0x2, 0x8, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x9, 0xc, 0x3, 0x2, 0x2, 0x2, 0xa, 0x8, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0xb, 0x3, 0x2, 0x2, 0x2, 0xb, 0xe, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0xa, 0x3, 0x2, 0x2, 0x2, 0xd, 0x6, 0x3, 0x2, 0x2, 0x2, 0xe, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xf, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x3, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x12, 0x13, 0x8, 0x3, 0x1, 0x2, 0x13, 0x19, 0x7, 0xa, 0x2, 0x2, 0x14, 
    0x15, 0x7, 0x7, 0x2, 0x2, 0x15, 0x16, 0x5, 0x4, 0x3, 0x2, 0x16, 0x17, 
    0x7, 0x8, 0x2, 0x2, 0x17, 0x19, 0x3, 0x2, 0x2, 0x2, 0x18, 0x12, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x14, 0x3, 0x2, 0x2, 0x2, 0x19, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x1b, 0xc, 0x6, 0x2, 0x2, 0x1b, 0x1c, 0x9, 0x2, 0x2, 
    0x2, 0x1c, 0x21, 0x5, 0x4, 0x3, 0x7, 0x1d, 0x1e, 0xc, 0x5, 0x2, 0x2, 
    0x1e, 0x1f, 0x9, 0x3, 0x2, 0x2, 0x1f, 0x21, 0x5, 0x4, 0x3, 0x6, 0x20, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x21, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x7, 0xa, 0xf, 0x18, 0x20, 0x22, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
