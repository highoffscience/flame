// Generated from src/fct/vb/Facata.g4 by ANTLR 4.7

package fct.vb;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FacataParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Equal=1, NotEqual=2, Plus=3, Minus=4, Times=5, Divide=6, Comma=7, Less=8, 
		Greater=9, LeftParen=10, RightParen=11, LeftBracket=12, RightBracket=13, 
		LessEqual=14, GreaterEqual=15, Assign=16, Newline=17, If=18, End=19, And=20, 
		Or=21, Return=22, X=23, Y=24, Sin=25, Cos=26, Tan=27, Var=28, Keyword=29, 
		Identifier=30, Integer=31, Decimal=32, Whitespace=33, Comment=34;
	public static final int
		RULE_unit = 0, RULE_statementList = 1, RULE_statement = 2, RULE_numbersList = 3, 
		RULE_additiveExpression = 4, RULE_multiplicativeExpression = 5, RULE_primaryExpression = 6, 
		RULE_functionCall = 7, RULE_pointExpression = 8, RULE_parenthesisedExpression = 9;
	public static final String[] ruleNames = {
		"unit", "statementList", "statement", "numbersList", "additiveExpression", 
		"multiplicativeExpression", "primaryExpression", "functionCall", "pointExpression", 
		"parenthesisedExpression"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'='", "'~'", "'+'", "'-'", "'*'", "'/'", "','", "'<'", "'>'", "'('", 
		"')'", "'['", "']'", "'<='", "'>='", "'<-'", null, "'If'", "'End'", "'And'", 
		"'Or'", "'Return'", "'X'", "'Y'", "'Sin'", "'Cos'", "'Tan'", "'Var'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Equal", "NotEqual", "Plus", "Minus", "Times", "Divide", "Comma", 
		"Less", "Greater", "LeftParen", "RightParen", "LeftBracket", "RightBracket", 
		"LessEqual", "GreaterEqual", "Assign", "Newline", "If", "End", "And", 
		"Or", "Return", "X", "Y", "Sin", "Cos", "Tan", "Var", "Keyword", "Identifier", 
		"Integer", "Decimal", "Whitespace", "Comment"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Facata.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public FacataParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class UnitContext extends ParserRuleContext {
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	 
		public UnitContext() { }
		public void copyFrom(UnitContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Unit_Context extends UnitContext {
		public StatementListContext statementList() {
			return getRuleContext(StatementListContext.class,0);
		}
		public Unit_Context(UnitContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitUnit_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_unit);
		try {
			_localctx = new Unit_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(20);
			statementList(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementListContext extends ParserRuleContext {
		public StatementListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statementList; }
	 
		public StatementListContext() { }
		public void copyFrom(StatementListContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class SingleStatement_Context extends StatementListContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public SingleStatement_Context(StatementListContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitSingleStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ListStatement_Context extends StatementListContext {
		public StatementListContext statementList() {
			return getRuleContext(StatementListContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public ListStatement_Context(StatementListContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitListStatement_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StatementListContext statementList() throws RecognitionException {
		return statementList(0);
	}

	private StatementListContext statementList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementListContext _localctx = new StatementListContext(_ctx, _parentState);
		StatementListContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_statementList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new SingleStatement_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(23);
			statement();
			}
			_ctx.stop = _input.LT(-1);
			setState(29);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ListStatement_Context(new StatementListContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_statementList);
					setState(25);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(26);
					statement();
					}
					} 
				}
				setState(31);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class EmptyStatement_Context extends StatementContext {
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public EmptyStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitEmptyStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AssignmentStatement_Context extends StatementContext {
		public TerminalNode Identifier() { return getToken(FacataParser.Identifier, 0); }
		public TerminalNode Assign() { return getToken(FacataParser.Assign, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public AssignmentStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAssignmentStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ReturnStatement_Context extends StatementContext {
		public TerminalNode Return() { return getToken(FacataParser.Return, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public ReturnStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitReturnStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class VarStatement_Context extends StatementContext {
		public TerminalNode Var() { return getToken(FacataParser.Var, 0); }
		public NumbersListContext numbersList() {
			return getRuleContext(NumbersListContext.class,0);
		}
		public List<TerminalNode> Newline() { return getTokens(FacataParser.Newline); }
		public TerminalNode Newline(int i) {
			return getToken(FacataParser.Newline, i);
		}
		public StatementListContext statementList() {
			return getRuleContext(StatementListContext.class,0);
		}
		public TerminalNode End() { return getToken(FacataParser.End, 0); }
		public VarStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitVarStatement_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statement);
		try {
			setState(49);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				_localctx = new AssignmentStatement_Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(32);
				match(Identifier);
				setState(33);
				match(Assign);
				setState(34);
				additiveExpression(0);
				setState(35);
				match(Newline);
				}
				break;
			case Return:
				_localctx = new ReturnStatement_Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(37);
				match(Return);
				setState(38);
				additiveExpression(0);
				setState(39);
				match(Newline);
				}
				break;
			case Newline:
				_localctx = new EmptyStatement_Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(41);
				match(Newline);
				}
				break;
			case Var:
				_localctx = new VarStatement_Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(42);
				match(Var);
				setState(43);
				numbersList(0);
				setState(44);
				match(Newline);
				setState(45);
				statementList(0);
				setState(46);
				match(End);
				setState(47);
				match(Newline);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NumbersListContext extends ParserRuleContext {
		public NumbersListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numbersList; }
	 
		public NumbersListContext() { }
		public void copyFrom(NumbersListContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class SingleNumber_Context extends NumbersListContext {
		public TerminalNode Decimal() { return getToken(FacataParser.Decimal, 0); }
		public SingleNumber_Context(NumbersListContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitSingleNumber_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class NumbersList_Context extends NumbersListContext {
		public NumbersListContext numbersList() {
			return getRuleContext(NumbersListContext.class,0);
		}
		public TerminalNode Decimal() { return getToken(FacataParser.Decimal, 0); }
		public NumbersList_Context(NumbersListContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitNumbersList_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NumbersListContext numbersList() throws RecognitionException {
		return numbersList(0);
	}

	private NumbersListContext numbersList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		NumbersListContext _localctx = new NumbersListContext(_ctx, _parentState);
		NumbersListContext _prevctx = _localctx;
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_numbersList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new SingleNumber_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(52);
			match(Decimal);
			}
			_ctx.stop = _input.LT(-1);
			setState(58);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new NumbersList_Context(new NumbersListContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_numbersList);
					setState(54);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(55);
					match(Decimal);
					}
					} 
				}
				setState(60);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class AdditiveExpressionContext extends ParserRuleContext {
		public AdditiveExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_additiveExpression; }
	 
		public AdditiveExpressionContext() { }
		public void copyFrom(AdditiveExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class AdditiveExpression_Context extends AdditiveExpressionContext {
		public MultiplicativeExpressionContext multiplicativeExpression() {
			return getRuleContext(MultiplicativeExpressionContext.class,0);
		}
		public AdditiveExpression_Context(AdditiveExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAdditiveExpression_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AdditionExpression_Context extends AdditiveExpressionContext {
		public Token OP;
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public MultiplicativeExpressionContext multiplicativeExpression() {
			return getRuleContext(MultiplicativeExpressionContext.class,0);
		}
		public TerminalNode Plus() { return getToken(FacataParser.Plus, 0); }
		public TerminalNode Minus() { return getToken(FacataParser.Minus, 0); }
		public AdditionExpression_Context(AdditiveExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAdditionExpression_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AdditiveExpressionContext additiveExpression() throws RecognitionException {
		return additiveExpression(0);
	}

	private AdditiveExpressionContext additiveExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		AdditiveExpressionContext _localctx = new AdditiveExpressionContext(_ctx, _parentState);
		AdditiveExpressionContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_additiveExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new AdditiveExpression_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(62);
			multiplicativeExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(69);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new AdditionExpression_Context(new AdditiveExpressionContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_additiveExpression);
					setState(64);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(65);
					((AdditionExpression_Context)_localctx).OP = _input.LT(1);
					_la = _input.LA(1);
					if ( !(_la==Plus || _la==Minus) ) {
						((AdditionExpression_Context)_localctx).OP = (Token)_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(66);
					multiplicativeExpression(0);
					}
					} 
				}
				setState(71);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class MultiplicativeExpressionContext extends ParserRuleContext {
		public MultiplicativeExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplicativeExpression; }
	 
		public MultiplicativeExpressionContext() { }
		public void copyFrom(MultiplicativeExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class MultiplicationExpression_Context extends MultiplicativeExpressionContext {
		public Token OP;
		public MultiplicativeExpressionContext multiplicativeExpression() {
			return getRuleContext(MultiplicativeExpressionContext.class,0);
		}
		public PrimaryExpressionContext primaryExpression() {
			return getRuleContext(PrimaryExpressionContext.class,0);
		}
		public TerminalNode Times() { return getToken(FacataParser.Times, 0); }
		public TerminalNode Divide() { return getToken(FacataParser.Divide, 0); }
		public MultiplicationExpression_Context(MultiplicativeExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitMultiplicationExpression_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MultiplicativeExpression_Context extends MultiplicativeExpressionContext {
		public PrimaryExpressionContext primaryExpression() {
			return getRuleContext(PrimaryExpressionContext.class,0);
		}
		public MultiplicativeExpression_Context(MultiplicativeExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitMultiplicativeExpression_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MultiplicativeExpressionContext multiplicativeExpression() throws RecognitionException {
		return multiplicativeExpression(0);
	}

	private MultiplicativeExpressionContext multiplicativeExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		MultiplicativeExpressionContext _localctx = new MultiplicativeExpressionContext(_ctx, _parentState);
		MultiplicativeExpressionContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_multiplicativeExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new MultiplicativeExpression_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(73);
			primaryExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(80);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new MultiplicationExpression_Context(new MultiplicativeExpressionContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
					setState(75);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(76);
					((MultiplicationExpression_Context)_localctx).OP = _input.LT(1);
					_la = _input.LA(1);
					if ( !(_la==Times || _la==Divide) ) {
						((MultiplicationExpression_Context)_localctx).OP = (Token)_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(77);
					primaryExpression();
					}
					} 
				}
				setState(82);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class PrimaryExpressionContext extends ParserRuleContext {
		public PrimaryExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primaryExpression; }
	 
		public PrimaryExpressionContext() { }
		public void copyFrom(PrimaryExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Decimal_Context extends PrimaryExpressionContext {
		public TerminalNode Decimal() { return getToken(FacataParser.Decimal, 0); }
		public Decimal_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitDecimal_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class Integer_Context extends PrimaryExpressionContext {
		public TerminalNode Integer() { return getToken(FacataParser.Integer, 0); }
		public Integer_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitInteger_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PrimaryPointExpression_Context extends PrimaryExpressionContext {
		public PointExpressionContext pointExpression() {
			return getRuleContext(PointExpressionContext.class,0);
		}
		public PrimaryPointExpression_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitPrimaryPointExpression_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class Y_Context extends PrimaryExpressionContext {
		public TerminalNode Y() { return getToken(FacataParser.Y, 0); }
		public Y_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitY_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class X_Context extends PrimaryExpressionContext {
		public TerminalNode X() { return getToken(FacataParser.X, 0); }
		public X_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitX_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PrimaryParenthesisedExpression_Context extends PrimaryExpressionContext {
		public ParenthesisedExpressionContext parenthesisedExpression() {
			return getRuleContext(ParenthesisedExpressionContext.class,0);
		}
		public PrimaryParenthesisedExpression_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitPrimaryParenthesisedExpression_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class Reference_Context extends PrimaryExpressionContext {
		public TerminalNode Identifier() { return getToken(FacataParser.Identifier, 0); }
		public Reference_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitReference_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class FunctionCall_Context extends PrimaryExpressionContext {
		public FunctionCallContext functionCall() {
			return getRuleContext(FunctionCallContext.class,0);
		}
		public FunctionCall_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitFunctionCall_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PrimaryExpressionContext primaryExpression() throws RecognitionException {
		PrimaryExpressionContext _localctx = new PrimaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_primaryExpression);
		try {
			setState(91);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Integer:
				_localctx = new Integer_Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(83);
				match(Integer);
				}
				break;
			case Decimal:
				_localctx = new Decimal_Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(84);
				match(Decimal);
				}
				break;
			case Identifier:
				_localctx = new Reference_Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(85);
				match(Identifier);
				}
				break;
			case X:
				_localctx = new X_Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(86);
				match(X);
				}
				break;
			case Y:
				_localctx = new Y_Context(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(87);
				match(Y);
				}
				break;
			case Sin:
			case Cos:
			case Tan:
				_localctx = new FunctionCall_Context(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(88);
				functionCall();
				}
				break;
			case LeftBracket:
				_localctx = new PrimaryPointExpression_Context(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(89);
				pointExpression();
				}
				break;
			case LeftParen:
				_localctx = new PrimaryParenthesisedExpression_Context(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(90);
				parenthesisedExpression();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionCallContext extends ParserRuleContext {
		public FunctionCallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionCall; }
	 
		public FunctionCallContext() { }
		public void copyFrom(FunctionCallContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Sin_Context extends FunctionCallContext {
		public AdditiveExpressionContext ARG;
		public TerminalNode Sin() { return getToken(FacataParser.Sin, 0); }
		public TerminalNode LeftParen() { return getToken(FacataParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(FacataParser.RightParen, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public Sin_Context(FunctionCallContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitSin_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class Cos_Context extends FunctionCallContext {
		public AdditiveExpressionContext ARG;
		public TerminalNode Cos() { return getToken(FacataParser.Cos, 0); }
		public TerminalNode LeftParen() { return getToken(FacataParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(FacataParser.RightParen, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public Cos_Context(FunctionCallContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitCos_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class Tan_Context extends FunctionCallContext {
		public AdditiveExpressionContext ARG;
		public TerminalNode Tan() { return getToken(FacataParser.Tan, 0); }
		public TerminalNode LeftParen() { return getToken(FacataParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(FacataParser.RightParen, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public Tan_Context(FunctionCallContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitTan_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FunctionCallContext functionCall() throws RecognitionException {
		FunctionCallContext _localctx = new FunctionCallContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_functionCall);
		try {
			setState(108);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Sin:
				_localctx = new Sin_Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(93);
				match(Sin);
				setState(94);
				match(LeftParen);
				setState(95);
				((Sin_Context)_localctx).ARG = additiveExpression(0);
				setState(96);
				match(RightParen);
				}
				break;
			case Cos:
				_localctx = new Cos_Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(98);
				match(Cos);
				setState(99);
				match(LeftParen);
				setState(100);
				((Cos_Context)_localctx).ARG = additiveExpression(0);
				setState(101);
				match(RightParen);
				}
				break;
			case Tan:
				_localctx = new Tan_Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(103);
				match(Tan);
				setState(104);
				match(LeftParen);
				setState(105);
				((Tan_Context)_localctx).ARG = additiveExpression(0);
				setState(106);
				match(RightParen);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PointExpressionContext extends ParserRuleContext {
		public PointExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pointExpression; }
	 
		public PointExpressionContext() { }
		public void copyFrom(PointExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class PointExpression_Context extends PointExpressionContext {
		public AdditiveExpressionContext XCoord;
		public AdditiveExpressionContext YCoord;
		public TerminalNode LeftBracket() { return getToken(FacataParser.LeftBracket, 0); }
		public TerminalNode Comma() { return getToken(FacataParser.Comma, 0); }
		public TerminalNode RightBracket() { return getToken(FacataParser.RightBracket, 0); }
		public List<AdditiveExpressionContext> additiveExpression() {
			return getRuleContexts(AdditiveExpressionContext.class);
		}
		public AdditiveExpressionContext additiveExpression(int i) {
			return getRuleContext(AdditiveExpressionContext.class,i);
		}
		public PointExpression_Context(PointExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitPointExpression_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PointExpressionContext pointExpression() throws RecognitionException {
		PointExpressionContext _localctx = new PointExpressionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_pointExpression);
		try {
			_localctx = new PointExpression_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			match(LeftBracket);
			setState(111);
			((PointExpression_Context)_localctx).XCoord = additiveExpression(0);
			setState(112);
			match(Comma);
			setState(113);
			((PointExpression_Context)_localctx).YCoord = additiveExpression(0);
			setState(114);
			match(RightBracket);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParenthesisedExpressionContext extends ParserRuleContext {
		public ParenthesisedExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parenthesisedExpression; }
	 
		public ParenthesisedExpressionContext() { }
		public void copyFrom(ParenthesisedExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ParenthesisedExpression_Context extends ParenthesisedExpressionContext {
		public TerminalNode LeftParen() { return getToken(FacataParser.LeftParen, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(FacataParser.RightParen, 0); }
		public ParenthesisedExpression_Context(ParenthesisedExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitParenthesisedExpression_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ParenthesisedExpressionContext parenthesisedExpression() throws RecognitionException {
		ParenthesisedExpressionContext _localctx = new ParenthesisedExpressionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_parenthesisedExpression);
		try {
			_localctx = new ParenthesisedExpression_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(116);
			match(LeftParen);
			setState(117);
			additiveExpression(0);
			setState(118);
			match(RightParen);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return statementList_sempred((StatementListContext)_localctx, predIndex);
		case 3:
			return numbersList_sempred((NumbersListContext)_localctx, predIndex);
		case 4:
			return additiveExpression_sempred((AdditiveExpressionContext)_localctx, predIndex);
		case 5:
			return multiplicativeExpression_sempred((MultiplicativeExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean statementList_sempred(StatementListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean numbersList_sempred(NumbersListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean additiveExpression_sempred(AdditiveExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean multiplicativeExpression_sempred(MultiplicativeExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3${\4\2\t\2\4\3\t\3"+
		"\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\3\2"+
		"\3\2\3\3\3\3\3\3\3\3\3\3\7\3\36\n\3\f\3\16\3!\13\3\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4\64\n\4\3\5\3\5\3"+
		"\5\3\5\3\5\7\5;\n\5\f\5\16\5>\13\5\3\6\3\6\3\6\3\6\3\6\3\6\7\6F\n\6\f"+
		"\6\16\6I\13\6\3\7\3\7\3\7\3\7\3\7\3\7\7\7Q\n\7\f\7\16\7T\13\7\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\5\b^\n\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t"+
		"\3\t\3\t\3\t\3\t\3\t\3\t\5\to\n\t\3\n\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3"+
		"\13\3\13\3\13\2\6\4\b\n\f\f\2\4\6\b\n\f\16\20\22\24\2\4\3\2\5\6\3\2\7"+
		"\b\2\u0080\2\26\3\2\2\2\4\30\3\2\2\2\6\63\3\2\2\2\b\65\3\2\2\2\n?\3\2"+
		"\2\2\fJ\3\2\2\2\16]\3\2\2\2\20n\3\2\2\2\22p\3\2\2\2\24v\3\2\2\2\26\27"+
		"\5\4\3\2\27\3\3\2\2\2\30\31\b\3\1\2\31\32\5\6\4\2\32\37\3\2\2\2\33\34"+
		"\f\4\2\2\34\36\5\6\4\2\35\33\3\2\2\2\36!\3\2\2\2\37\35\3\2\2\2\37 \3\2"+
		"\2\2 \5\3\2\2\2!\37\3\2\2\2\"#\7 \2\2#$\7\22\2\2$%\5\n\6\2%&\7\23\2\2"+
		"&\64\3\2\2\2\'(\7\30\2\2()\5\n\6\2)*\7\23\2\2*\64\3\2\2\2+\64\7\23\2\2"+
		",-\7\36\2\2-.\5\b\5\2./\7\23\2\2/\60\5\4\3\2\60\61\7\25\2\2\61\62\7\23"+
		"\2\2\62\64\3\2\2\2\63\"\3\2\2\2\63\'\3\2\2\2\63+\3\2\2\2\63,\3\2\2\2\64"+
		"\7\3\2\2\2\65\66\b\5\1\2\66\67\7\"\2\2\67<\3\2\2\289\f\4\2\29;\7\"\2\2"+
		":8\3\2\2\2;>\3\2\2\2<:\3\2\2\2<=\3\2\2\2=\t\3\2\2\2><\3\2\2\2?@\b\6\1"+
		"\2@A\5\f\7\2AG\3\2\2\2BC\f\4\2\2CD\t\2\2\2DF\5\f\7\2EB\3\2\2\2FI\3\2\2"+
		"\2GE\3\2\2\2GH\3\2\2\2H\13\3\2\2\2IG\3\2\2\2JK\b\7\1\2KL\5\16\b\2LR\3"+
		"\2\2\2MN\f\4\2\2NO\t\3\2\2OQ\5\16\b\2PM\3\2\2\2QT\3\2\2\2RP\3\2\2\2RS"+
		"\3\2\2\2S\r\3\2\2\2TR\3\2\2\2U^\7!\2\2V^\7\"\2\2W^\7 \2\2X^\7\31\2\2Y"+
		"^\7\32\2\2Z^\5\20\t\2[^\5\22\n\2\\^\5\24\13\2]U\3\2\2\2]V\3\2\2\2]W\3"+
		"\2\2\2]X\3\2\2\2]Y\3\2\2\2]Z\3\2\2\2][\3\2\2\2]\\\3\2\2\2^\17\3\2\2\2"+
		"_`\7\33\2\2`a\7\f\2\2ab\5\n\6\2bc\7\r\2\2co\3\2\2\2de\7\34\2\2ef\7\f\2"+
		"\2fg\5\n\6\2gh\7\r\2\2ho\3\2\2\2ij\7\35\2\2jk\7\f\2\2kl\5\n\6\2lm\7\r"+
		"\2\2mo\3\2\2\2n_\3\2\2\2nd\3\2\2\2ni\3\2\2\2o\21\3\2\2\2pq\7\16\2\2qr"+
		"\5\n\6\2rs\7\t\2\2st\5\n\6\2tu\7\17\2\2u\23\3\2\2\2vw\7\f\2\2wx\5\n\6"+
		"\2xy\7\r\2\2y\25\3\2\2\2\t\37\63<GR]n";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}