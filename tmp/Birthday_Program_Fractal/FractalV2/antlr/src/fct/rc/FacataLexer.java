// Generated from src/fct/rc/Facata.g4 by ANTLR 4.7

package fct.rc;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FacataLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Plus=1, Minus=2, Times=3, Divide=4, LeftParen=5, RightParen=6, Assign=7, 
		Newline=8, Width=9, Height=10, Integer=11, Decimal=12, Whitespace=13, 
		Comment=14;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"Plus", "Minus", "Times", "Divide", "LeftParen", "RightParen", "Assign", 
		"Newline", "Width", "Height", "Integer", "Decimal", "Whitespace", "Comment"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'<-'", null, "'Width'", 
		"'Height'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Plus", "Minus", "Times", "Divide", "LeftParen", "RightParen", "Assign", 
		"Newline", "Width", "Height", "Integer", "Decimal", "Whitespace", "Comment"
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


	public FacataLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Facata.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\20d\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3"+
		"\5\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\n\3\13\3"+
		"\13\3\13\3\13\3\13\3\13\3\13\3\f\3\f\5\f@\n\f\3\f\3\f\7\fD\n\f\f\f\16"+
		"\fG\13\f\5\fI\n\f\3\r\3\r\3\r\6\rN\n\r\r\r\16\rO\5\rR\n\r\3\16\6\16U\n"+
		"\16\r\16\16\16V\3\16\3\16\3\17\3\17\3\17\7\17^\n\17\f\17\16\17a\13\17"+
		"\3\17\3\17\2\2\20\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31"+
		"\16\33\17\35\20\3\2\t\3\2\f\f\3\2\62\62\3\2\63;\3\2\62;\3\2\60\60\5\2"+
		"\13\13\17\17\"\"\3\2\61\61\2j\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t"+
		"\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2"+
		"\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\3"+
		"\37\3\2\2\2\5!\3\2\2\2\7#\3\2\2\2\t%\3\2\2\2\13\'\3\2\2\2\r)\3\2\2\2\17"+
		"+\3\2\2\2\21.\3\2\2\2\23\60\3\2\2\2\25\66\3\2\2\2\27H\3\2\2\2\31J\3\2"+
		"\2\2\33T\3\2\2\2\35Z\3\2\2\2\37 \7-\2\2 \4\3\2\2\2!\"\7/\2\2\"\6\3\2\2"+
		"\2#$\7,\2\2$\b\3\2\2\2%&\7\61\2\2&\n\3\2\2\2\'(\7*\2\2(\f\3\2\2\2)*\7"+
		"+\2\2*\16\3\2\2\2+,\7>\2\2,-\7/\2\2-\20\3\2\2\2./\t\2\2\2/\22\3\2\2\2"+
		"\60\61\7Y\2\2\61\62\7k\2\2\62\63\7f\2\2\63\64\7v\2\2\64\65\7j\2\2\65\24"+
		"\3\2\2\2\66\67\7J\2\2\678\7g\2\289\7k\2\29:\7i\2\2:;\7j\2\2;<\7v\2\2<"+
		"\26\3\2\2\2=I\t\3\2\2>@\5\5\3\2?>\3\2\2\2?@\3\2\2\2@A\3\2\2\2AE\t\4\2"+
		"\2BD\t\5\2\2CB\3\2\2\2DG\3\2\2\2EC\3\2\2\2EF\3\2\2\2FI\3\2\2\2GE\3\2\2"+
		"\2H=\3\2\2\2H?\3\2\2\2I\30\3\2\2\2JQ\5\27\f\2KM\t\6\2\2LN\t\5\2\2ML\3"+
		"\2\2\2NO\3\2\2\2OM\3\2\2\2OP\3\2\2\2PR\3\2\2\2QK\3\2\2\2QR\3\2\2\2R\32"+
		"\3\2\2\2SU\t\7\2\2TS\3\2\2\2UV\3\2\2\2VT\3\2\2\2VW\3\2\2\2WX\3\2\2\2X"+
		"Y\b\16\2\2Y\34\3\2\2\2Z[\t\b\2\2[_\t\b\2\2\\^\n\2\2\2]\\\3\2\2\2^a\3\2"+
		"\2\2_]\3\2\2\2_`\3\2\2\2`b\3\2\2\2a_\3\2\2\2bc\b\17\2\2c\36\3\2\2\2\n"+
		"\2?EHOQV_\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}