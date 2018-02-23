import java.util.*;
public class UCI {
    static String ENGINENAME="Shikamaru v0";
    public static void uciCommunication() {
        Scanner input = new Scanner(System.in);
        while (true)
        {
            String inputString=input.nextLine();
            if ("uci".equals(inputString))
            {
                inputUCI();
            }
            else if (inputString.startsWith("setoption"))
            {
                inputSetOption(inputString);
            }
            else if ("isready".equals(inputString))
            {
                inputIsReady();
            }
            else if ("ucinewgame".equals(inputString))
            {
                inputUCINewGame();
            }
            else if (inputString.startsWith("position"))
            {
                inputPosition(inputString);
            }
            else if (inputString.startsWith("go"))
            {
                inputGo();
            }
            else if (inputString.equals("quit"))
            {
                inputQuit();
            }
            else if ("print".equals(inputString))
            {
                inputPrint();
            }
        }
    }
    public static void inputUCI() {
        System.out.println("id name "+ENGINENAME);
        System.out.println("id author Shakti");
        //options go here
        System.out.println("uciok");
    }
    public static void inputSetOption(String inputString) {
        //set options
    }
    public static void inputIsReady() {
         System.out.println("readyok");
    }
    public static void inputUCINewGame() {
        //add code here
    }
    public static void inputPosition(String input) {
        input=input.substring(9).concat(" ");
        if (input.contains("startpos ")) {
            input=input.substring(9);
            BoardGeneration.importFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        }
        else if (input.contains("fen")) {
            input=input.substring(4);
            BoardGeneration.importFEN(input);
        }
        if (input.contains("moves")) {
            input=input.substring(input.indexOf("moves")+6);
            while (input.length()>0)
            {
                String moves;
                if (Shikamaru.WhiteToMove) {
                    moves=Moves.possibleMovesW(Shikamaru.WP,Shikamaru.WN,Shikamaru.WB,Shikamaru.WR,Shikamaru.WQ,Shikamaru.WK,Shikamaru.BP,Shikamaru.BN,Shikamaru.BB,Shikamaru.BR,Shikamaru.BQ,Shikamaru.BK,Shikamaru.EP,Shikamaru.CWK,Shikamaru.CWQ,Shikamaru.CBK,Shikamaru.CBQ);
                } else {
                    moves=Moves.possibleMovesB(Shikamaru.WP,Shikamaru.WN,Shikamaru.WB,Shikamaru.WR,Shikamaru.WQ,Shikamaru.WK,Shikamaru.BP,Shikamaru.BN,Shikamaru.BB,Shikamaru.BR,Shikamaru.BQ,Shikamaru.BK,Shikamaru.EP,Shikamaru.CWK,Shikamaru.CWQ,Shikamaru.CBK,Shikamaru.CBQ);
                }
                algebraToMove(input,moves);
                input=input.substring(input.indexOf(' ')+1);
            }
        }
    }
    public static void inputGo() {
        String move;
        if (Shikamaru.WhiteToMove) {
            move=Moves.possibleMovesW(Shikamaru.WP,Shikamaru.WN,Shikamaru.WB,Shikamaru.WR,Shikamaru.WQ,Shikamaru.WK,Shikamaru.BP,Shikamaru.BN,Shikamaru.BB,Shikamaru.BR,Shikamaru.BQ,Shikamaru.BK,Shikamaru.EP,Shikamaru.CWK,Shikamaru.CWQ,Shikamaru.CBK,Shikamaru.CBQ);
        } else {
            move=Moves.possibleMovesB(Shikamaru.WP,Shikamaru.WN,Shikamaru.WB,Shikamaru.WR,Shikamaru.WQ,Shikamaru.WK,Shikamaru.BP,Shikamaru.BN,Shikamaru.BB,Shikamaru.BR,Shikamaru.BQ,Shikamaru.BK,Shikamaru.EP,Shikamaru.CWK,Shikamaru.CWQ,Shikamaru.CBK,Shikamaru.CBQ);
        }
        int index=(int)(Math.floor(Math.random()*(move.length()/4))*4);
        System.out.println("bestmove "+moveToAlgebra(move.substring(index,index+4)));
    }
    public static String moveToAlgebra(String move) {
        String append="";
        int start=0,end=0;
        if (Character.isDigit(move.charAt(3))) {//'regular' move
            start=(Character.getNumericValue(move.charAt(0))*8)+(Character.getNumericValue(move.charAt(1)));
            end=(Character.getNumericValue(move.charAt(2))*8)+(Character.getNumericValue(move.charAt(3)));
        } else if (move.charAt(3)=='P') {//pawn promotion
            if (Character.isUpperCase(move.charAt(2))) {
                start=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(0)-'0']&Moves.RankMasks8[1]);
                end=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(1)-'0']&Moves.RankMasks8[0]);
            } else {
                start=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(0)-'0']&Moves.RankMasks8[6]);
                end=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(1)-'0']&Moves.RankMasks8[7]);
            }
            append=""+Character.toLowerCase(move.charAt(2));
        } else if (move.charAt(3)=='E') {//en passant
            if (move.charAt(2)=='W') {
                start=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(0)-'0']&Moves.RankMasks8[3]);
                end=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(1)-'0']&Moves.RankMasks8[2]);
            } else {
                start=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(0)-'0']&Moves.RankMasks8[4]);
                end=Long.numberOfTrailingZeros(Moves.FileMasks8[move.charAt(1)-'0']&Moves.RankMasks8[5]);
            }
        }
        String returnMove="";
        returnMove+=(char)('a'+(start%8));
        returnMove+=(char)('8'-(start/8));
        returnMove+=(char)('a'+(end%8));
        returnMove+=(char)('8'-(end/8));
        returnMove+=append;
        return returnMove;
    }
    public static void algebraToMove(String input,String moves) {
        int start=0,end=0;
        int from=(input.charAt(0)-'a')+(8*('8'-input.charAt(1)));
        int to=(input.charAt(2)-'a')+(8*('8'-input.charAt(3)));
        for (int i=0;i<moves.length();i+=4) {
            if (Character.isDigit(moves.charAt(i+3))) {//'regular' move
                start=(Character.getNumericValue(moves.charAt(i+0))*8)+(Character.getNumericValue(moves.charAt(i+1)));
                end=(Character.getNumericValue(moves.charAt(i+2))*8)+(Character.getNumericValue(moves.charAt(i+3)));
            } else if (moves.charAt(i+3)=='P') {//pawn promotion
                if (Character.isUpperCase(moves.charAt(i+2))) {
                    start=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+0)-'0']&Moves.RankMasks8[1]);
                    end=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+1)-'0']&Moves.RankMasks8[0]);
                } else {
                    start=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+0)-'0']&Moves.RankMasks8[6]);
                    end=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+1)-'0']&Moves.RankMasks8[7]);
                }
            } else if (moves.charAt(i+3)=='E') {//en passant
                if (moves.charAt(i+2)=='W') {
                    start=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+0)-'0']&Moves.RankMasks8[3]);
                    end=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+1)-'0']&Moves.RankMasks8[2]);
                } else {
                    start=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+0)-'0']&Moves.RankMasks8[4]);
                    end=Long.numberOfTrailingZeros(Moves.FileMasks8[moves.charAt(i+1)-'0']&Moves.RankMasks8[5]);
                }
            }
            if ((start==from) && (end==to)) {
                if ((input.charAt(4)==' ') || (Character.toUpperCase(input.charAt(4))==Character.toUpperCase(moves.charAt(i+2)))) {
                    if (Character.isDigit(moves.charAt(i+3))) {//'regular' move
                        start=(Character.getNumericValue(moves.charAt(i))*8)+(Character.getNumericValue(moves.charAt(i+1)));
                        if (((1L<<start)&Shikamaru.WK)!=0) {Shikamaru.CWK=false; Shikamaru.CWQ=false;}
                        else if (((1L<<start)&Shikamaru.BK)!=0) {Shikamaru.CBK=false; Shikamaru.CBQ=false;}
                        else if (((1L<<start)&Shikamaru.WR&(1L<<63))!=0) {Shikamaru.CWK=false;}
                        else if (((1L<<start)&Shikamaru.WR&(1L<<56))!=0) {Shikamaru.CWQ=false;}
                        else if (((1L<<start)&Shikamaru.BR&(1L<<7))!=0) {Shikamaru.CBK=false;}
                        else if (((1L<<start)&Shikamaru.BR&1L)!=0) {Shikamaru.CBQ=false;}
                    }
                    Shikamaru.EP=Moves.makeMoveEP(Shikamaru.WP|Shikamaru.BP,moves.substring(i,i+4));
                    Shikamaru.WR=Moves.makeMoveCastle(Shikamaru.WR, Shikamaru.WK|Shikamaru.BK, moves.substring(i,i+4), 'R');
                    Shikamaru.BR=Moves.makeMoveCastle(Shikamaru.BR, Shikamaru.WK|Shikamaru.BK, moves.substring(i,i+4), 'r');
                    Shikamaru.WP=Moves.makeMove(Shikamaru.WP, moves.substring(i,i+4), 'P');
                    Shikamaru.WN=Moves.makeMove(Shikamaru.WN, moves.substring(i,i+4), 'N');
                    Shikamaru.WB=Moves.makeMove(Shikamaru.WB, moves.substring(i,i+4), 'B');
                    Shikamaru.WR=Moves.makeMove(Shikamaru.WR, moves.substring(i,i+4), 'R');
                    Shikamaru.WQ=Moves.makeMove(Shikamaru.WQ, moves.substring(i,i+4), 'Q');
                    Shikamaru.WK=Moves.makeMove(Shikamaru.WK, moves.substring(i,i+4), 'K');
                    Shikamaru.BP=Moves.makeMove(Shikamaru.BP, moves.substring(i,i+4), 'p');
                    Shikamaru.BN=Moves.makeMove(Shikamaru.BN, moves.substring(i,i+4), 'n');
                    Shikamaru.BB=Moves.makeMove(Shikamaru.BB, moves.substring(i,i+4), 'b');
                    Shikamaru.BR=Moves.makeMove(Shikamaru.BR, moves.substring(i,i+4), 'r');
                    Shikamaru.BQ=Moves.makeMove(Shikamaru.BQ, moves.substring(i,i+4), 'q');
                    Shikamaru.BK=Moves.makeMove(Shikamaru.BK, moves.substring(i,i+4), 'k');
                    Shikamaru.WhiteToMove=!Shikamaru.WhiteToMove;
                    break;
                }
            }
        }
    }
    public static void inputQuit() {
        System.exit(0);
    }
    public static void inputPrint() {
        BoardGeneration.drawArray(Shikamaru.WP,Shikamaru.WN,Shikamaru.WB,Shikamaru.WR,Shikamaru.WQ,Shikamaru.WK,Shikamaru.BP,Shikamaru.BN,Shikamaru.BB,Shikamaru.BR,Shikamaru.BQ,Shikamaru.BK);
        System.out.print("Zobrist Hash: ");
        System.out.println(Zobrist.getZobristHash(Shikamaru.WP,Shikamaru.WN,Shikamaru.WB,Shikamaru.WR,Shikamaru.WQ,Shikamaru.WK,Shikamaru.BP,Shikamaru.BN,Shikamaru.BB,Shikamaru.BR,Shikamaru.BQ,Shikamaru.BK,Shikamaru.EP,Shikamaru.CWK,Shikamaru.CWQ,Shikamaru.CBK,Shikamaru.CBQ,Shikamaru.WhiteToMove));
    }
}