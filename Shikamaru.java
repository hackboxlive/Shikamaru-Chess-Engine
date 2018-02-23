public class Shikamaru {
    static long WP=0L,WN=0L,WB=0L,WR=0L,WQ=0L,WK=0L,BP=0L,BN=0L,BB=0L,BR=0L,BQ=0L,BK=0L,EP=0L;
    static boolean CWK=true,CWQ=true,CBK=true,CBQ=true,WhiteToMove=true;//true=castle is possible
    static long UniversalWP=0L,UniversalWN=0L,UniversalWB=0L,UniversalWR=0L,
            UniversalWQ=0L,UniversalWK=0L,UniversalBP=0L,UniversalBN=0L,
            UniversalBB=0L,UniversalBR=0L,UniversalBQ=0L,UniversalBK=0L,
            UniversalEP=0L;
    static int searchDepth=7,moveCounter;
    static int MATE_SCORE=5000,NULL_INT=Integer.MIN_VALUE;
    public static void main(String[] args) {
        //Zobrist.random64();
        //Zobrist.testDistribution();
        Zobrist.zobristFillArray();
        BoardGeneration.importFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        //BoardGeneration.initiateStandardChess();
        UCI.inputPrint();
        UCI.inputPrint();
        BoardGeneration.importFEN("rnbqkbnr/ppp1pppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        UCI.inputPrint();
        long startTime = System.currentTimeMillis();
        System.out.println(PrincipalVariation.pvSearch(-1000,1000,WP,WN,WB,WR,WQ,WK,BP,BN,BB,BR,BQ,BK,EP,CWK,CWQ,CBK,CBQ,!WhiteToMove,0));
        long endTime = System.currentTimeMillis();
        System.out.println("That took " + (endTime - startTime) + " milliseconds");
        UCI.uciCommunication();
    }
}