import java.lang.*;
import java.util.*;

class Points {
    int xCord[];
    int yCord[];
}
class Versions extends Points {
    public int verNo;
    Versions() { this.verNo = 1; }
    Versions(int verNo) {
        this.verNo = verNo;
    }
    public void changeVer(int verNo) {
        this.verNo = verNo;
    }
    public void generateVer() {
    }
    public boolean checkDown(char board[][]) {
        return false;
    }
    public boolean checkLeft(char board[][]) {
        return false;
    }
    public boolean checkRight(char board[][]) {
        return false;
    }
}
class Line extends Versions {
    Line() {
        xCord = new int[] {1, 2, 3, 4};
        yCord = new int[] {1, 1, 1, 1};
    }
    public void changeVer(int verNo) {
        super.changeVer(verNo);
        int tempVar;
        for(int i = 0;i<xCord.length;i++) {
            tempVar = xCord[i];
            xCord[i] = yCord[i];
            yCord[i] = tempVar;
        }
    }
    public void generateVer() {
        xCord = new int[] {1, 2, 3, 4};
        yCord = new int[] {1, 1, 1, 1};
    }
    public boolean checkDown(char board[][]) {
        if(verNo == 1 && (board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        } else if(verNo == 2 && ( board[xCord[0] + 1][yCord[0]] == '#'
                || board[xCord[1] + 1][yCord[1]] == '#' ||
                board[xCord[2] + 1][yCord[2]] == '#'
                || board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        }
        return false;
    }
    public boolean checkLeft(char board[][]) {
        if(verNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 2 && board[xCord[0]][yCord[0] - 1] == '#') {
            return true;
        }
        return false;
    }
    public boolean checkRight(char board[][]) {
        if(verNo == 1 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#' || board[xCord[2]][yCord[2] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')) {
            return true;
        } else if(verNo == 2 && board[xCord[3]][yCord[3] - 1] == '#') {
            return true;
        }
        return false;
    }
}

class Square extends Versions {
    Square() {
        xCord = new int[] {1, 1, 2, 2};
        yCord = new int[] {1, 2, 1, 2};
    }
    public void changeVer(int verNo) {
        super.changeVer(verNo);
    }
    public void generateVer() {
        xCord = new int[] {1, 1, 2, 2};
        yCord = new int[] {1, 2, 1, 2};
    }
    public boolean checkDown(char board[][]) {
        if(board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')
            return true;
        return false;
    }
    public boolean checkLeft(char board[][]) {
        if(board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')
            return true;
        return false;
    }public boolean checkRight(char board[][]) {
        if(board[xCord[1]][yCord[1] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')
            return true;
        return false;
    }
}

class T extends Versions {
    int tempVar[] = new int[4];
    T() {
        xCord = new int[] {1, 1, 1, 2};
        yCord = new int[] {1, 2, 3, 2};
    }
    public void changeVer(int verNo) {
        super.changeVer(verNo);
        int length = yCord.length;
        if(verNo == 1) { // 4 -> 1
            for (int i = 0; i<length; i++) {
                tempVar[i] = xCord[i];
                xCord[i] = yCord[i];
            }
            for(int i = 0;i<length - 1;i++) {
                yCord[i] = tempVar[length - (i+2)];
            }
            yCord[length - 1] = xCord[length - 1];
        } else if(verNo == 2) { // 1 -> 2
            int max = -32768;
            for (int i = 0; i<length; i++) {
                xCord[i] = yCord[i];
                max = max > yCord[i] ? max : yCord[i];
            }
            for(int i = 0;i<length - 1;i++) {
                yCord[i] = max;
            }
            yCord[length - 1] = xCord[length - 1];
        } else if(verNo == 3) { // 2 -> 3
            for (int i = 0; i<length; i++) {
                tempVar[i] = xCord[i];
                xCord[i] = yCord[i];
            }
            for(int i = 0;i<length - 1;i++) {
                yCord[i] = tempVar[length - (i+2)];
                yCord[length - 1] = xCord[length - 1];
            }
            yCord[length - 1] = xCord[length - 1];
        } else if(verNo == 4) { // 3 -> 4
            int min = 32768;
            for (int i = 0; i<length; i++) {
                xCord[i] = yCord[i];
                min = min < yCord[i] ? min : yCord[i];
            }
            for(int i = 0;i<length - 1;i++) {
                yCord[i] = min;
            }
            yCord[length - 1] = xCord[length - 1];
        }
    }
    public void generateVer() {
        xCord = new int[] {1, 1, 1, 2};
        yCord = new int[] {1, 2, 3, 2};
    }
    public boolean checkDown(char board[][]) {
        if(verNo == 1 && (board[xCord[0] + 1][yCord[0]] == '#'
                || board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        } else if(verNo == 2 && ( board[xCord[2] + 1][yCord[2]] == '#'
                || board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[0] + 1][yCord[0]] == '#'
                || board[xCord[1] + 1][yCord[1]] == '#' || board[xCord[2] + 1][yCord[2]] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')){
            return true;
        }
        return false;
    }
    public boolean checkLeft(char board[][]) {
        if(verNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[2]][yCord[2]- 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')) {
            return true;
        }
        return false;
    }
    public boolean checkRight(char board[][]) {
        if(verNo == 1 && (board[xCord[2]][yCord[2] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')) {
            return true;
        } else if(verNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        }
        return false;
    }
}

class L extends Versions {
    L() {
        xCord = new int[] {1, 2, 3, 3};
        yCord = new int[] {1, 1, 1, 2};
    }
    public void changeVer(int verNo) {
        super.changeVer(verNo);
        int length = yCord.length;
        if(verNo == 1) { // 4 -> 1
            int min = 32768;
            for (int i = 0; i<length ; i++) {
                min = min < xCord[i] ? min : xCord[i];
                xCord[i] = yCord[i];
            }
            for(int i = 0; i<length - 1; i++) {
                yCord[i] = min;
            }
            yCord[length - 1] = min + 1;
        } else if(verNo == 2) { // 1 -> 2
            int max = -32768;
            for (int i = 0; i<length ; i++) {
                max = max > xCord[i] ? max : xCord[i];
                xCord[i] = yCord[i];
            }
            max++;
            for(int i = 0; i<length - 1; i++) {
                yCord[i] = max--;
            }
            yCord[length - 1] = max + 1;
        } else if(verNo == 3) { // 2 -> 3
            int max = -32768;
            for (int i = 0; i<length ; i++) {
                max = max > xCord[i] ? max : xCord[i];
                xCord[i] = yCord[i];
            }
            for(int i = 0; i<length - 1; i++) {
                yCord[i] = max;
            }
            yCord[length - 1] = max - 1;
        } else if(verNo == 4) { // 3 -> 4
            int min = 32768;
            for (int i = 0; i<length ; i++) {
                min = min < xCord[i] ? min : xCord[i];
                xCord[i] = yCord[i];
            }
            min--;
            for(int i = 0; i<length - 1; i++) {
                yCord[i] = min++;
            }
            yCord[length - 1] = min - 1;
        }
    }
    public void generateVer() {
        xCord = new int[] {1, 2, 3, 3};
        yCord = new int[] {1, 1, 1, 2};
    }
    public boolean checkDown(char board[][]) {
        if(verNo == 1 && (board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        } else if(verNo == 2 && ( board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[1] + 1][yCord[1]] == '#'
                || board[xCord[2] + 1][yCord[2]] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[1] + 1][yCord[1]] == '#' || board[xCord[2] + 1][yCord[2]] == '#' )){
            return true;
        }
        return false;
    }
    public boolean checkLeft(char board[][]) {
        if(verNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')) {
            return true;
        } else if(verNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        }
        return false;
    }
    public boolean checkRight(char board[][]) {
        if(verNo == 1 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')) {
            return true;
        } else if(verNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#' || board[xCord[2]][yCord[2] + 1] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        }
        return false;
    }
}

class Z extends Versions{
    int tempVar[] = new int[4];
    Z() {
        xCord = new int[] {1, 2, 2, 3};
        yCord = new int[] {1, 1, 2, 2};
    }
    public void changeVer(int verNo) {
        super.changeVer(verNo);
        int length = yCord.length;
        if(verNo == 1) { //4 -> 1
            for (int i = 0; i<length ; i++) {
                tempVar[i] = xCord[i];
                xCord[i] = yCord[i] - 1;
            }
            for(int i = 0;i<length;i++) {
                yCord[i] = tempVar[i];
            }
        } else if(verNo == 2) { // 1 -> 2
            for (int i = 0; i<length ; i++) {
                tempVar[i] = xCord[i];
                xCord[i] = yCord[i];
            }
            for(int i = 0;i<length;i++) {
                yCord[i] = tempVar[i];
            }
        } else if(verNo == 3) { // 2 -> 3
            for (int i = 0; i<length ; i++) {
                tempVar[i] = xCord[i];
                xCord[i] = yCord[i] + 1;
            }
            for(int i = 0;i<length;i++) {
                yCord[i] = tempVar[i];
            }
        } else if(verNo == 4) { // 3 -> 4
            for (int i = 0; i<length ; i++) {
                tempVar[i] = xCord[i];
                xCord[i] = yCord[i];
            }
            for(int i = 0;i<length;i++) {
                yCord[i] = tempVar[i];
            }
        }
    }
    public void generateVer() {
        xCord = new int[] {1, 2, 2, 3};
        yCord = new int[] {1, 1, 2, 2};
    }
    public boolean checkDown(char board[][]) {
        if((verNo == 1 || verNo == 3 ) && (board[xCord[1] + 1][yCord[1]] == '#'
                || board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        } else if((verNo == 2 || verNo == 4 ) &&
                ( board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[2] + 1][yCord[2]] == '#'
                        || board[xCord[3] + 1][yCord[3]] == '#')) {
            return true;
        }
        return false;
    }
    public boolean checkLeft(char board[][]) {
        if(verNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 2 && (board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')) {
            return true;
        }
        return false;
    }
    public boolean checkRight(char board[][]) {
        if(verNo == 1 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[2]][yCord[2] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')) {
            return true;
        } else if(verNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')) {
            return true;
        } else if(verNo == 3 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')) {
            return true;
        } else if(verNo == 4 && (board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
            return true;
        }
        return false;
    }
}

public class Main {
    public static char board[][] = new char[25][25];
    public static int hashCount[] = new int[24];
    static int currentVer = 1, currentShapeNo = 2;
    public static Stack<String> undoStack = new Stack<String>();
    public static Stack<String> redoStack = new Stack<String>();
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        Line line = new Line();
        Square square = new Square();
        T t = new T();
        L l = new L();
        Z z = new Z();
        Versions currentShape = new Versions();
        char dir;
        initBoard();
        while(true) {
            currentShape = currentShapeNo == 1 ? line : currentShapeNo == 2 ? square : currentShapeNo == 3 ? t : currentShapeNo == 4 ? l : z;
            drawOnBoard(currentShape);
            displayBoard();
            dir = scanner.next().charAt(0);
            if (dir == 'r') {
                currentVer = currentVer > 4 ? 1 : ++currentVer;
                clearBoard(currentShape);
                currentShape.changeVer(currentVer);
                undoStack.push("r");
                clearScreen();
            } else if(dir == 'a') {
                moveLeft(currentShape);
                clearScreen();
            } else if(dir == 'd') {
                moveRight(currentShape);
                clearScreen();
            } else if(dir == 's') {
                moveDown(currentShape);
                clearScreen();
            } else if(dir == 'u') {
                if(undoStack.isEmpty()) continue ;
                undoStep(undoStack.peek(), currentShape);
                redoStack.push(undoStack.pop());
            } else if(dir == 'q') {
                if(redoStack.isEmpty()) continue ;
                if(redoStack.peek().equals("a"))
                    redoStep("d", currentShape);
                else if(redoStack.peek().equals("d"))
                    redoStep("a", currentShape);
                undoStack.push(redoStack.pop());
            } else if(dir == 'p') {
                printHash();
            } else if(dir == 'x') {
                break;
            }
        }
    }
    public static void clearBoard(Versions V) {
        for (int i = 0; i < V.xCord.length; i++) {
            board[V.xCord[i]][V.yCord[i]] = ' ';
        }
    }
    public static void initBoard() {
        for(int i = 0;i<board.length;i++) {
            for(int j = 0;j<board[i].length;j++) {
                if(i == 0 || j == 0 || i == board.length - 1 || j == board.length - 1 )
                    board[i][j] = '*';
                else
                    board[i][j] = ' ';
            }
        }
    }
    public static void printHash() {
        for(int i = 0;i<hashCount.length;i++) {
            System.out.println(hashCount[i]);
        }
    }
    public static void drawOnBoard(Versions V) {
        for(int i = 0;i<V.xCord.length;i++) {
            board[V.xCord[i]][V.yCord[i]] = '#';
        }
    }
    public static void displayBoard() {
        for(char arr[]:board) {
            for(char a:arr) {
                System.out.print(a);
            }
            System.out.println();
        }
    }
    public static void checkRemoval(Versions V) {
        for(int i=0;i<25;i++) {
            hashCount[board.length-1-V.xCord[i]]++;
            System.out.println("---"+(board.length-2-V.xCord[i]));
        }
        for(int i=1;i<29;i++) {
            System.out.print(hashCount[i]+" ");
        }
        System.out.println();

        for(int i=board.length-1;i>0;i--) {
            if(hashCount[i]>5) {
                System.out.println("Line no at"+i+"Remove Line");

                for(int j=board.length-1-i;j>0;j--) {
                    board[j]=board[j-1];
                }
                board[0]=new char[25];
            }
        }
    }
    public static void moveDown(Versions V) {
        if(V.xCord[0] == (board.length - 2) || V.xCord[1] == (board.length - 2) ||
                V.xCord[2] == (board.length - 2) || V.xCord[3] == (board.length - 2) || V.checkDown(board)) {
            for(int i:V.xCord ) {
                hashCount[i]++;
                if(hashCount[i] == board.length - 2) {
                    hashCount[i] = 0;
                    int j;
                    for(j = i;j>1 && hashCount[j - 1] != 0;j--) {
                        board[j] = board[j-1];
                    }
                    board[j] = new char[25];
                    board[j][0] = '*';
                    board[j][board.length - 1] = '*';
                    displayBoard();
                }
            }
            //checkRemoval(V);
            V.generateVer();
            currentShapeNo = (int)(Math.random() * 5) + 1;
            // currentShapeNo = 2;
            return;
        }
        for(int i = 0;i<V.xCord.length;i++) {
            board[V.xCord[i]][V.yCord[i]] = ' ';
            V.xCord[i]++;
        }
        undoStack.push("s");
    }
    static int randomshape()
    {
        Random random = new Random();
        return random.nextInt(5);
    }
    static int randomlocation(int range)
    {
        Random random = new Random();
        return random.nextInt(range);
    }
    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        //System.out.flush();
    }
    public static void moveLeft(Versions V) {
        if(V.yCord[0] == 1 || V.yCord[1] == 1 || V.yCord[2] == 1 || V.yCord[3] == 1 || V.checkLeft(board))
            return;
        for(int i = 0;i<V.xCord.length;i++) {
            board[V.xCord[i]][V.yCord[i]] = ' ';
            V.yCord[i]--;
        }
        undoStack.push("a");
    }
    public static void moveRight(Versions V) {
        if(V.yCord[0] == (board.length - 2) || V.yCord[1] == (board.length - 2) || V.yCord[2] == (board.length - 2) || V.yCord[3] == (board.length - 2) || V.checkRight(board))
            return;
        for(int i = 0;i<V.xCord.length;i++) {
            board[V.xCord[i]][V.yCord[i]] = ' ';
            V.yCord[i]++;
        }
        undoStack.push("d");
    }
    public static void undoStep(String dir, Versions V) {
        if(dir.equals("s")) {
            for(int i = 0;i<V.xCord.length;i++) {
                board[V.xCord[i]][V.yCord[i]] = ' ';
                V.xCord[i]--;
            }
        } else if( dir.equals("a")) {
            moveRight(V);
        } else if( dir.equals("d")) {
            moveLeft(V);
        } else if(dir.equals("r")) {
            currentVer--;
            V.changeVer(currentVer);
        }
    }
    public static void redoStep(String dir, Versions V) {
        if(dir.equals("s")) {
            moveDown(V);
        } else if( dir.equals("a")) {
            moveLeft(V);
        } else if( dir.equals("d")) {
            moveRight(V);
        } else if(dir.equals("r")) {
            currentVer++;
            V.changeVer(currentVer);
        }
    }
}