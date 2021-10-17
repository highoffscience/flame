// Generated from src/fct/fa/Facata.g4 by ANTLR 4.7

package fct.fa;

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
		Newline=8, Width=9, Height=10, NIters=11, Gamma=12, Integer=13, Decimal=14, 
		Whitespace=15, Comment=16;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"Plus", "Minus", "Times", "Divide", "LeftParen", "RightParen", "Assign", 
		"Newline", "Width", "Height", "NIters", "Gamma", "Integer", "Decimal", 
		"Whitespace", "Comment"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'<-'", null, "'Width'", 
		"'Height'", "'NIters'", "'Gamma'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Plus", "Minus", "Times", "Divide", "LeftParen", "RightParen", "Assign", 
		"Newline", "Width", "Height", "NIters", "Gamma", "Integer", "Decimal", 
		"Whitespace", "Comment"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\22u\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\3\2\3\2\3"+
		"\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\n\3\n\3\n"+
		"\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\16\3\16\5\16Q\n\16\3\16\3\16\7\16U\n"+
		"\16\f\16\16\16X\13\16\5\16Z\n\16\3\17\3\17\3\17\6\17_\n\17\r\17\16\17"+
		"`\5\17c\n\17\3\20\6\20f\n\20\r\20\16\20g\3\20\3\20\3\21\3\21\3\21\7\21"+
		"o\n\21\f\21\16\21r\13\21\3\21\3\21\2\2\22\3\3\5\4\7\5\t\6\13\7\r\b\17"+
		"\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22\3\2\t\3\2\f\f\3\2"+
		"\62\62\3\2\63;\3\2\62;\3\2\60\60\5\2\13\13\17\17\"\"\3\2\61\61\2{\2\3"+
		"\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2"+
		"\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31"+
		"\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\3#\3\2\2\2"+
		"\5%\3\2\2\2\7\'\3\2\2\2\t)\3\2\2\2\13+\3\2\2\2\r-\3\2\2\2\17/\3\2\2\2"+
		"\21\62\3\2\2\2\23\64\3\2\2\2\25:\3\2\2\2\27A\3\2\2\2\31H\3\2\2\2\33Y\3"+
		"\2\2\2\35[\3\2\2\2\37e\3\2\2\2!k\3\2\2\2#$\7-\2\2$\4\3\2\2\2%&\7/\2\2"+
		"&\6\3\2\2\2\'(\7,\2\2(\b\3\2\2\2)*\7\61\2\2*\n\3\2\2\2+,\7*\2\2,\f\3\2"+
		"\2\2-.\7+\2\2.\16\3\2\2\2/\60\7>\2\2\60\61\7/\2\2\61\20\3\2\2\2\62\63"+
		"\t\2\2\2\63\22\3\2\2\2\64\65\7Y\2\2\65\66\7k\2\2\66\67\7f\2\2\678\7v\2"+
		"\289\7j\2\29\24\3\2\2\2:;\7J\2\2;<\7g\2\2<=\7k\2\2=>\7i\2\2>?\7j\2\2?"+
		"@\7v\2\2@\26\3\2\2\2AB\7P\2\2BC\7K\2\2CD\7v\2\2DE\7g\2\2EF\7t\2\2FG\7"+
		"u\2\2G\30\3\2\2\2HI\7I\2\2IJ\7c\2\2JK\7o\2\2KL\7o\2\2LM\7c\2\2M\32\3\2"+
		"\2\2NZ\t\3\2\2OQ\5\5\3\2PO\3\2\2\2PQ\3\2\2\2QR\3\2\2\2RV\t\4\2\2SU\t\5"+
		"\2\2TS\3\2\2\2UX\3\2\2\2VT\3\2\2\2VW\3\2\2\2WZ\3\2\2\2XV\3\2\2\2YN\3\2"+
		"\2\2YP\3\2\2\2Z\34\3\2\2\2[b\5\33\16\2\\^\t\6\2\2]_\t\5\2\2^]\3\2\2\2"+
		"_`\3\2\2\2`^\3\2\2\2`a\3\2\2\2ac\3\2\2\2b\\\3\2\2\2bc\3\2\2\2c\36\3\2"+
		"\2\2df\t\7\2\2ed\3\2\2\2fg\3\2\2\2ge\3\2\2\2gh\3\2\2\2hi\3\2\2\2ij\b\20"+
		"\2\2j \3\2\2\2kl\t\b\2\2lp\t\b\2\2mo\n\2\2\2nm\3\2\2\2or\3\2\2\2pn\3\2"+
		"\2\2pq\3\2\2\2qs\3\2\2\2rp\3\2\2\2st\b\21\2\2t\"\3\2\2\2\n\2PVY`bgp\3"+
		"\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}