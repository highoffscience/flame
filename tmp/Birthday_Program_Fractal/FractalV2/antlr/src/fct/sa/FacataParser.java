// Generated from src/fct/sa/Facata.g4 by ANTLR 4.7

package fct.sa;

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
		Or=21, Pre=22, Post=23, Ias=24, Ifs=25, None=26, Matrix=27, Keyword=28, 
		Identifier=29, Integer=30, Decimal=31, Whitespace=32, Comment=33;
	public static final int
		RULE_unit = 0, RULE_statementList = 1, RULE_statement = 2, RULE_typeExpression = 3, 
		RULE_matrixExpression = 4, RULE_additiveExpression = 5, RULE_multiplicativeExpression = 6, 
		RULE_primaryExpression = 7, RULE_parenthesisedExpression = 8;
	public static final String[] ruleNames = {
		"unit", "statementList", "statement", "typeExpression", "matrixExpression", 
		"additiveExpression", "multiplicativeExpression", "primaryExpression", 
		"parenthesisedExpression"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'='", "'~'", "'+'", "'-'", "'*'", "'/'", "','", "'<'", "'>'", "'('", 
		"')'", "'['", "']'", "'<='", "'>='", "'<-'", null, "'If'", "'End'", "'And'", 
		"'Or'", "'Pre'", "'Post'", "'Ias'", "'Ifs'", "'None'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Equal", "NotEqual", "Plus", "Minus", "Times", "Divide", "Comma", 
		"Less", "Greater", "LeftParen", "RightParen", "LeftBracket", "RightBracket", 
		"LessEqual", "GreaterEqual", "Assign", "Newline", "If", "End", "And", 
		"Or", "Pre", "Post", "Ias", "Ifs", "None", "Matrix", "Keyword", "Identifier", 
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
			setState(18);
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

			setState(21);
			statement();
			}
			_ctx.stop = _input.LT(-1);
			setState(27);
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
					setState(23);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(24);
					statement();
					}
					} 
				}
				setState(29);
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
	public static class MatrixStatement_Context extends StatementContext {
		public TerminalNode Matrix() { return getToken(FacataParser.Matrix, 0); }
		public TerminalNode Assign() { return getToken(FacataParser.Assign, 0); }
		public MatrixExpressionContext matrixExpression() {
			return getRuleContext(MatrixExpressionContext.class,0);
		}
		public TerminalNode Newline() { return getToken(FacataParser.Newline, 0); }
		public MatrixStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitMatrixStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PreStatement_Context extends StatementContext {
		public TerminalNode Pre() { return getToken(FacataParser.Pre, 0); }
		public TypeExpressionContext typeExpression() {
			return getRuleContext(TypeExpressionContext.class,0);
		}
		public List<TerminalNode> Newline() { return getTokens(FacataParser.Newline); }
		public TerminalNode Newline(int i) {
			return getToken(FacataParser.Newline, i);
		}
		public StatementListContext statementList() {
			return getRuleContext(StatementListContext.class,0);
		}
		public TerminalNode End() { return getToken(FacataParser.End, 0); }
		public PreStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitPreStatement_(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PostStatement_Context extends StatementContext {
		public TerminalNode Post() { return getToken(FacataParser.Post, 0); }
		public TypeExpressionContext typeExpression() {
			return getRuleContext(TypeExpressionContext.class,0);
		}
		public List<TerminalNode> Newline() { return getTokens(FacataParser.Newline); }
		public TerminalNode Newline(int i) {
			return getToken(FacataParser.Newline, i);
		}
		public StatementListContext statementList() {
			return getRuleContext(StatementListContext.class,0);
		}
		public TerminalNode End() { return getToken(FacataParser.End, 0); }
		public PostStatement_Context(StatementContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitPostStatement_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statement);
		try {
			setState(55);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				_localctx = new AssignmentStatement_Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(30);
				match(Identifier);
				setState(31);
				match(Assign);
				setState(32);
				additiveExpression(0);
				setState(33);
				match(Newline);
				}
				break;
			case Newline:
				_localctx = new EmptyStatement_Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(35);
				match(Newline);
				}
				break;
			case Pre:
				_localctx = new PreStatement_Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(36);
				match(Pre);
				setState(37);
				typeExpression();
				setState(38);
				match(Newline);
				setState(39);
				statementList(0);
				setState(40);
				match(End);
				setState(41);
				match(Newline);
				}
				break;
			case Post:
				_localctx = new PostStatement_Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(43);
				match(Post);
				setState(44);
				typeExpression();
				setState(45);
				match(Newline);
				setState(46);
				statementList(0);
				setState(47);
				match(End);
				setState(48);
				match(Newline);
				}
				break;
			case Matrix:
				_localctx = new MatrixStatement_Context(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(50);
				match(Matrix);
				setState(51);
				match(Assign);
				setState(52);
				matrixExpression();
				setState(53);
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

	public static class TypeExpressionContext extends ParserRuleContext {
		public TypeExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeExpression; }
	 
		public TypeExpressionContext() { }
		public void copyFrom(TypeExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class TypeExpression_Context extends TypeExpressionContext {
		public Token TYPE;
		public TerminalNode None() { return getToken(FacataParser.None, 0); }
		public TerminalNode Ias() { return getToken(FacataParser.Ias, 0); }
		public TerminalNode Ifs() { return getToken(FacataParser.Ifs, 0); }
		public TypeExpression_Context(TypeExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitTypeExpression_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypeExpressionContext typeExpression() throws RecognitionException {
		TypeExpressionContext _localctx = new TypeExpressionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_typeExpression);
		int _la;
		try {
			_localctx = new TypeExpression_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			((TypeExpression_Context)_localctx).TYPE = _input.LT(1);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Ias) | (1L << Ifs) | (1L << None))) != 0)) ) {
				((TypeExpression_Context)_localctx).TYPE = (Token)_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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

	public static class MatrixExpressionContext extends ParserRuleContext {
		public MatrixExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_matrixExpression; }
	 
		public MatrixExpressionContext() { }
		public void copyFrom(MatrixExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class MatrixExpression_Context extends MatrixExpressionContext {
		public AdditiveExpressionContext A;
		public AdditiveExpressionContext B;
		public AdditiveExpressionContext C;
		public AdditiveExpressionContext D;
		public AdditiveExpressionContext E;
		public AdditiveExpressionContext F;
		public AdditiveExpressionContext CLR;
		public AdditiveExpressionContext PROB;
		public TerminalNode LeftBracket() { return getToken(FacataParser.LeftBracket, 0); }
		public List<TerminalNode> Comma() { return getTokens(FacataParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FacataParser.Comma, i);
		}
		public TerminalNode RightBracket() { return getToken(FacataParser.RightBracket, 0); }
		public List<AdditiveExpressionContext> additiveExpression() {
			return getRuleContexts(AdditiveExpressionContext.class);
		}
		public AdditiveExpressionContext additiveExpression(int i) {
			return getRuleContext(AdditiveExpressionContext.class,i);
		}
		public MatrixExpression_Context(MatrixExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitMatrixExpression_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MatrixExpressionContext matrixExpression() throws RecognitionException {
		MatrixExpressionContext _localctx = new MatrixExpressionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_matrixExpression);
		try {
			_localctx = new MatrixExpression_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			match(LeftBracket);
			setState(60);
			((MatrixExpression_Context)_localctx).A = additiveExpression(0);
			setState(61);
			match(Comma);
			setState(62);
			((MatrixExpression_Context)_localctx).B = additiveExpression(0);
			setState(63);
			match(Comma);
			setState(64);
			((MatrixExpression_Context)_localctx).C = additiveExpression(0);
			setState(65);
			match(Comma);
			setState(66);
			((MatrixExpression_Context)_localctx).D = additiveExpression(0);
			setState(67);
			match(Comma);
			setState(68);
			((MatrixExpression_Context)_localctx).E = additiveExpression(0);
			setState(69);
			match(Comma);
			setState(70);
			((MatrixExpression_Context)_localctx).F = additiveExpression(0);
			setState(71);
			match(Comma);
			setState(72);
			((MatrixExpression_Context)_localctx).CLR = additiveExpression(0);
			setState(73);
			match(Comma);
			setState(74);
			((MatrixExpression_Context)_localctx).PROB = additiveExpression(0);
			setState(75);
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
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_additiveExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new AdditiveExpression_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(78);
			multiplicativeExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(85);
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
					setState(80);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(81);
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
					setState(82);
					multiplicativeExpression(0);
					}
					} 
				}
				setState(87);
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
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_multiplicativeExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new MultiplicativeExpression_Context(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(89);
			primaryExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(96);
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
					setState(91);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(92);
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
					setState(93);
					primaryExpression();
					}
					} 
				}
				setState(98);
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
	public static class Reference_Context extends PrimaryExpressionContext {
		public TerminalNode Identifier() { return getToken(FacataParser.Identifier, 0); }
		public Reference_Context(PrimaryExpressionContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FacataVisitor ) return ((FacataVisitor<? extends T>)visitor).visitReference_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PrimaryExpressionContext primaryExpression() throws RecognitionException {
		PrimaryExpressionContext _localctx = new PrimaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_primaryExpression);
		try {
			setState(103);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Integer:
				_localctx = new Integer_Context(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(99);
				match(Integer);
				}
				break;
			case Decimal:
				_localctx = new Decimal_Context(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(100);
				match(Decimal);
				}
				break;
			case Identifier:
				_localctx = new Reference_Context(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(101);
				match(Identifier);
				}
				break;
			case LeftParen:
				_localctx = new PrimaryParenthesisedExpression_Context(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(102);
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
		enterRule(_localctx, 16, RULE_parenthesisedExpression);
		try {
			_localctx = new ParenthesisedExpression_Context(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(105);
			match(LeftParen);
			setState(106);
			additiveExpression(0);
			setState(107);
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
		case 5:
			return additiveExpression_sempred((AdditiveExpressionContext)_localctx, predIndex);
		case 6:
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3#p\4\2\t\2\4\3\t\3"+
		"\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\3\2\3\3\3"+
		"\3\3\3\3\3\3\3\7\3\34\n\3\f\3\16\3\37\13\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\5\4:\n\4\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\7\7V\n\7\f\7\16\7Y\13\7"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\7\ba\n\b\f\b\16\bd\13\b\3\t\3\t\3\t\3\t\5\tj"+
		"\n\t\3\n\3\n\3\n\3\n\3\n\2\5\4\f\16\13\2\4\6\b\n\f\16\20\22\2\5\3\2\32"+
		"\34\3\2\5\6\3\2\7\b\2p\2\24\3\2\2\2\4\26\3\2\2\2\69\3\2\2\2\b;\3\2\2\2"+
		"\n=\3\2\2\2\fO\3\2\2\2\16Z\3\2\2\2\20i\3\2\2\2\22k\3\2\2\2\24\25\5\4\3"+
		"\2\25\3\3\2\2\2\26\27\b\3\1\2\27\30\5\6\4\2\30\35\3\2\2\2\31\32\f\4\2"+
		"\2\32\34\5\6\4\2\33\31\3\2\2\2\34\37\3\2\2\2\35\33\3\2\2\2\35\36\3\2\2"+
		"\2\36\5\3\2\2\2\37\35\3\2\2\2 !\7\37\2\2!\"\7\22\2\2\"#\5\f\7\2#$\7\23"+
		"\2\2$:\3\2\2\2%:\7\23\2\2&\'\7\30\2\2\'(\5\b\5\2()\7\23\2\2)*\5\4\3\2"+
		"*+\7\25\2\2+,\7\23\2\2,:\3\2\2\2-.\7\31\2\2./\5\b\5\2/\60\7\23\2\2\60"+
		"\61\5\4\3\2\61\62\7\25\2\2\62\63\7\23\2\2\63:\3\2\2\2\64\65\7\35\2\2\65"+
		"\66\7\22\2\2\66\67\5\n\6\2\678\7\23\2\28:\3\2\2\29 \3\2\2\29%\3\2\2\2"+
		"9&\3\2\2\29-\3\2\2\29\64\3\2\2\2:\7\3\2\2\2;<\t\2\2\2<\t\3\2\2\2=>\7\16"+
		"\2\2>?\5\f\7\2?@\7\t\2\2@A\5\f\7\2AB\7\t\2\2BC\5\f\7\2CD\7\t\2\2DE\5\f"+
		"\7\2EF\7\t\2\2FG\5\f\7\2GH\7\t\2\2HI\5\f\7\2IJ\7\t\2\2JK\5\f\7\2KL\7\t"+
		"\2\2LM\5\f\7\2MN\7\17\2\2N\13\3\2\2\2OP\b\7\1\2PQ\5\16\b\2QW\3\2\2\2R"+
		"S\f\4\2\2ST\t\3\2\2TV\5\16\b\2UR\3\2\2\2VY\3\2\2\2WU\3\2\2\2WX\3\2\2\2"+
		"X\r\3\2\2\2YW\3\2\2\2Z[\b\b\1\2[\\\5\20\t\2\\b\3\2\2\2]^\f\4\2\2^_\t\4"+
		"\2\2_a\5\20\t\2`]\3\2\2\2ad\3\2\2\2b`\3\2\2\2bc\3\2\2\2c\17\3\2\2\2db"+
		"\3\2\2\2ej\7 \2\2fj\7!\2\2gj\7\37\2\2hj\5\22\n\2ie\3\2\2\2if\3\2\2\2i"+
		"g\3\2\2\2ih\3\2\2\2j\21\3\2\2\2kl\7\f\2\2lm\5\f\7\2mn\7\r\2\2n\23\3\2"+
		"\2\2\7\359Wbi";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}