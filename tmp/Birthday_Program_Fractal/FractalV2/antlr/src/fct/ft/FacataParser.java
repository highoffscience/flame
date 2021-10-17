// Generated from src/fct/ft/Facata.g4 by ANTLR 4.7

package fct.ft;

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
		Plus=1, Minus=2, Times=3, Divide=4, Comma=5, LeftParen=6, RightParen=7, 
		LeftBracket=8, RightBracket=9, Assign=10, Newline=11, Scale=12, Trans=13, 
		Width=14, Height=15, Auto=16, On=17, Off=18, Integer=19, Decimal=20, Whitespace=21, 
		Comment=22;
	public static final int
		RULE_unit = 0, RULE_statementList = 1, RULE_statement = 2, RULE_additiveExpression = 3, 
		RULE_multiplicativeExpression = 4, RULE_primaryExpression = 5, RULE_pointExpression = 6, 
		RULE_parenthesisedExpression = 7;
	public static final String[] ruleNames = {
		"unit", "statementList", "statement", "additiveExpression", "multiplicativeExpression", 
		"primaryExpression", "pointExpression", "parenthesisedExpression"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'+'", "'-'", "'*'", "'/'", "','", "'('", "')'", "'['", "']'", "'<-'", 
		null, "'Scale'", "'Trans'", "'Width'", "'Height'", "'Auto'", "'On'", "'Off'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Plus", "Minus", "Times", "Divide", "Comma", "LeftParen", "RightParen", 
		"LeftBracket", "RightBracket", "Assign", "Newline", "Scale", "Trans", 
		"Width", "Height", "Auto", "On", "Off", "Integer", "Decimal", "Whitespace", 
		"Comment"
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
			setState(16);
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

			setState(19);
			statement();
			}
			_ctx.stop = _input.LT(-1);
			setState(25);
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
					setState(21);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(22);
					statement();
					}
					} 
				}
				setState(27);
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
	public static class AssignTransStatement_Context extends StatementContext {
		public TerminalNode Trans() { return getToken(FacataParser.Trans, 0); }
		public TerminalNode Assign() { return getToken(FacataParser.Assign, 0); }
		public PointExpressionContext pointExpression() {
			return getRuleContext(PointExpressionContext.class,0);
		}
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public AssignTransStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAssignTransStatement_(this);
			else return visitor.visitChildren(this);
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
	public static class AssignScaleStatement_Context extends StatementContext {
		public TerminalNode Scale() { return getToken(FacataParser.Scale, 0); }
		public TerminalNode Assign() { return getToken(FacataParser.Assign, 0); }
		public PointExpressionContext pointExpression() {
			return getRuleContext(PointExpressionContext.class,0);
		}
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public AssignScaleStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAssignScaleStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AssignHeightStatement_Context extends StatementContext {
		public TerminalNode Height() { return getToken(FacataParser.Height, 0); }
		public TerminalNode Assign() { return getToken(FacataParser.Assign, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public AssignHeightStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAssignHeightStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AssignAutoStatement_Context extends StatementContext {
		public Token OP;
		public TerminalNode Auto() { return getToken(FacataParser.Auto, 0); }
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public TerminalNode On() { return getToken(FacataParser.On, 0); }
		public TerminalNode Off() { return getToken(FacataParser.Off, 0); }
		public AssignAutoStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAssignAutoStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AssignWidthStatement_Context extends StatementContext {
		public TerminalNode Width() { return getToken(FacataParser.Width, 0); }
		public TerminalNode Assign() { return getToken(FacataParser.Assign, 0); }
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public AssignWidthStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitAssignWidthStatement_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statement);
		int _la;
		try {
			setState(52);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Scale:
				_localctx = new AssignScaleStatement_Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(28);
				match(Scale);
				setState(29);
				match(Assign);
				setState(30);
				pointExpression();
				setState(31);
				match(Newline);
				}
				break;
			case Trans:
				_localctx = new AssignTransStatement_Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(33);
				match(Trans);
				setState(34);
				match(Assign);
				setState(35);
				pointExpression();
				setState(36);
				match(Newline);
				}
				break;
			case Width:
				_localctx = new AssignWidthStatement_Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(38);
				match(Width);
				setState(39);
				match(Assign);
				setState(40);
				additiveExpression(0);
				setState(41);
				match(Newline);
				}
				break;
			case Height:
				_localctx = new AssignHeightStatement_Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(43);
				match(Height);
				setState(44);
				match(Assign);
				setState(45);
				additiveExpression(0);
				setState(46);
				match(Newline);
				}
				break;
			case Auto:
				_localctx = new AssignAutoStatement_Context(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(48);
				match(Auto);
				setState(49);
				((AssignAutoStatement_Context)_localctx).OP = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==On || _la==Off) ) {
					((AssignAutoStatement_Context)_localctx).OP = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(50);
				match(Newline);
				}
				break;
			case Newline:
				_localctx = new EmptyStatement_Context(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(51);
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
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_additiveExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new AdditiveExpression_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(55);
			multiplicativeExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(62);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new AdditionExpression_Context(new AdditiveExpressionContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_additiveExpression);
					setState(57);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(58);
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
					setState(59);
					multiplicativeExpression(0);
					}
					} 
				}
				setState(64);
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
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_multiplicativeExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new MultiplicativeExpression_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(66);
			primaryExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(73);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new MultiplicationExpression_Context(new MultiplicativeExpressionContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
					setState(68);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(69);
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
					setState(70);
					primaryExpression();
					}
					} 
				}
				setState(75);
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

	public final PrimaryExpressionContext primaryExpression() throws RecognitionException {
		PrimaryExpressionContext _localctx = new PrimaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_primaryExpression);
		try {
			setState(79);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Integer:
				_localctx = new Integer_Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(76);
				match(Integer);
				}
				break;
			case Decimal:
				_localctx = new Decimal_Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(77);
				match(Decimal);
				}
				break;
			case LeftParen:
				_localctx = new PrimaryParenthesisedExpression_Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(78);
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
		enterRule(_localctx, 12, RULE_pointExpression);
		try {
			_localctx = new PointExpression_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(81);
			match(LeftBracket);
			setState(82);
			((PointExpression_Context)_localctx).XCoord = additiveExpression(0);
			setState(83);
			match(Comma);
			setState(84);
			((PointExpression_Context)_localctx).YCoord = additiveExpression(0);
			setState(85);
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
		enterRule(_localctx, 14, RULE_parenthesisedExpression);
		try {
			_localctx = new ParenthesisedExpression_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(87);
			match(LeftParen);
			setState(88);
			additiveExpression(0);
			setState(89);
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
			return additiveExpression_sempred((AdditiveExpressionContext)_localctx, predIndex);
		case 4:
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
	private boolean additiveExpression_sempred(AdditiveExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean multiplicativeExpression_sempred(MultiplicativeExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\30^\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\3\2\3\2\3\3\3\3\3\3"+
		"\3\3\3\3\7\3\32\n\3\f\3\16\3\35\13\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4\67"+
		"\n\4\3\5\3\5\3\5\3\5\3\5\3\5\7\5?\n\5\f\5\16\5B\13\5\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\7\6J\n\6\f\6\16\6M\13\6\3\7\3\7\3\7\5\7R\n\7\3\b\3\b\3\b\3\b\3"+
		"\b\3\b\3\t\3\t\3\t\3\t\3\t\2\5\4\b\n\n\2\4\6\b\n\f\16\20\2\5\3\2\23\24"+
		"\3\2\3\4\3\2\5\6\2_\2\22\3\2\2\2\4\24\3\2\2\2\6\66\3\2\2\2\b8\3\2\2\2"+
		"\nC\3\2\2\2\fQ\3\2\2\2\16S\3\2\2\2\20Y\3\2\2\2\22\23\5\4\3\2\23\3\3\2"+
		"\2\2\24\25\b\3\1\2\25\26\5\6\4\2\26\33\3\2\2\2\27\30\f\4\2\2\30\32\5\6"+
		"\4\2\31\27\3\2\2\2\32\35\3\2\2\2\33\31\3\2\2\2\33\34\3\2\2\2\34\5\3\2"+
		"\2\2\35\33\3\2\2\2\36\37\7\16\2\2\37 \7\f\2\2 !\5\16\b\2!\"\7\r\2\2\""+
		"\67\3\2\2\2#$\7\17\2\2$%\7\f\2\2%&\5\16\b\2&\'\7\r\2\2\'\67\3\2\2\2()"+
		"\7\20\2\2)*\7\f\2\2*+\5\b\5\2+,\7\r\2\2,\67\3\2\2\2-.\7\21\2\2./\7\f\2"+
		"\2/\60\5\b\5\2\60\61\7\r\2\2\61\67\3\2\2\2\62\63\7\22\2\2\63\64\t\2\2"+
		"\2\64\67\7\r\2\2\65\67\7\r\2\2\66\36\3\2\2\2\66#\3\2\2\2\66(\3\2\2\2\66"+
		"-\3\2\2\2\66\62\3\2\2\2\66\65\3\2\2\2\67\7\3\2\2\289\b\5\1\29:\5\n\6\2"+
		":@\3\2\2\2;<\f\4\2\2<=\t\3\2\2=?\5\n\6\2>;\3\2\2\2?B\3\2\2\2@>\3\2\2\2"+
		"@A\3\2\2\2A\t\3\2\2\2B@\3\2\2\2CD\b\6\1\2DE\5\f\7\2EK\3\2\2\2FG\f\4\2"+
		"\2GH\t\4\2\2HJ\5\f\7\2IF\3\2\2\2JM\3\2\2\2KI\3\2\2\2KL\3\2\2\2L\13\3\2"+
		"\2\2MK\3\2\2\2NR\7\25\2\2OR\7\26\2\2PR\5\20\t\2QN\3\2\2\2QO\3\2\2\2QP"+
		"\3\2\2\2R\r\3\2\2\2ST\7\n\2\2TU\5\b\5\2UV\7\7\2\2VW\5\b\5\2WX\7\13\2\2"+
		"X\17\3\2\2\2YZ\7\b\2\2Z[\5\b\5\2[\\\7\t\2\2\\\21\3\2\2\2\7\33\66@KQ";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}