#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
#include <map>

using namespace std;

typedef vector<char> Tape;
typedef map<string, string> Instance;

class TuringMachine {
private:
    Tape tape;
    Instance instance;
    char start, halt, init, state;
    bool tapeChange;
    int moves;
    int position;

    inline void print() {
        if (tapeChange) {
            for (int i = 0; i < tape.size(); i++)
                cout << tape[i];

            cout << endl;
        }
    }

    inline string getLHS() {
        char sp[3] = {0};
        sp[0] = state;
        sp[1] = tape[position];

        return string(sp);
    }

    inline string getRHS(string &lhs) {
        return instance[lhs];
    }

    inline void updateTape(char oldSymbol, char newSymbol) {
        if (oldSymbol != newSymbol) {
            tape[position] = newSymbol;

            if (tapeChange)
                tapeChange = false;

            else
                tapeChange = true;
        }

        else
            tapeChange = false;
    }

    inline void updateState(char newState) {
        state = newState;
    }

    inline void movePos(char move) {
        if (move == 'l')
            position -= 1;

        else if (move == 'r')
            position += 1;

        else
            throw string("Wrong state");

        if (position < 0) {
            tape.insert(tape.begin(), init);
            position = 0;
        }

        if (position >= tape.size()) {
            tape.push_back(init);
        }

        moves++;
    }


public:
    TuringMachine(Instance instance, char start, char halt, char init):
        tape(1, init), instance(instance), start(start), halt(halt),
        init(init), state(start), moves(0), tapeChange(1), position(0) { }

    void run() {
        while (state != halt) {
            print();
            string lhs = getLHS();
            string rhs = getRHS(lhs);

            char newState = rhs[0];
            char newSymbol = rhs[1];
            char move = rhs[2];

            char oldSymbol = lhs[1];
            updateTape(oldSymbol, newSymbol);
            updateState(newState);
            movePos(move);
        }

        print();
    }

    int getMoves() {
        return moves;
    }
};

vector<Instance> beavers;

void init6() {
    Instance bb6;
    bb6.insert(make_pair("a0", "b1r"));
    bb6.insert(make_pair("b0", "c1l"));
    bb6.insert(make_pair("c0", "d1l"));
    bb6.insert(make_pair("d0", "e1l"));
    bb6.insert(make_pair("e0", "a1l"));
    bb6.insert(make_pair("f0", "e1l"));

    bb6.insert(make_pair("a1", "e0l"));
    bb6.insert(make_pair("b1", "a0r"));
    bb6.insert(make_pair("c1", "c0r"));
    bb6.insert(make_pair("d1", "f0l"));
    bb6.insert(make_pair("e1", "c1l"));
    bb6.insert(make_pair("f1", "h1r"));

    beavers.push_back(bb6);
}

void init5() {
    Instance bb5;
    bb5.insert(make_pair("a0", "b1l"));
    bb5.insert(make_pair("b0", "c1r"));
    bb5.insert(make_pair("c0", "a1l"));
    bb5.insert(make_pair("d0", "a1l"));
    bb5.insert(make_pair("e0", "h1r"));

    bb5.insert(make_pair("a1", "a1l"));
    bb5.insert(make_pair("b1", "b1r"));
    bb5.insert(make_pair("c1", "d1r"));
    bb5.insert(make_pair("d1", "e1r"));
    bb5.insert(make_pair("e1", "c0r"));

    beavers.push_back(bb5);
}

void init4() {
    Instance bb4;
    bb4.insert(make_pair("a0", "b1r"));
    bb4.insert(make_pair("b0", "a1l"));
    bb4.insert(make_pair("c0", "h1r"));
    bb4.insert(make_pair("d0", "d1r"));

    bb4.insert(make_pair("a1", "b1l"));
    bb4.insert(make_pair("b1", "c0l"));
    bb4.insert(make_pair("c1", "d1l"));
    bb4.insert(make_pair("d1", "a0r"));

    beavers.push_back(bb4);
}

void init3() {
    Instance bb3;
    bb3.insert(make_pair("a0", "b1r"));
    bb3.insert(make_pair("b0", "c0r"));
    bb3.insert(make_pair("c0", "c1l"));

    bb3.insert(make_pair("a1", "h1r"));
    bb3.insert(make_pair("b1", "b1r"));
    bb3.insert(make_pair("c1", "a1l"));

    beavers.push_back(bb3);
}

void init2() {
    Instance bb2;
    bb2.insert(make_pair("a0", "b1r"));
    bb2.insert(make_pair("b0", "a1l"));

    bb2.insert(make_pair("a1", "b1l"));
    bb2.insert(make_pair("b1", "h1r"));

    beavers.push_back(bb2);
}

void init1() {
    Instance bb1;
    bb1.insert(make_pair("a0", "h1r"));

    beavers.push_back(bb1);
}

void initBB() {
    beavers.push_back(Instance());
    init1(); init2(); init3(); init4(); init5(); init6();
}

void busyBeaver(int x) {
    cout << "--- " << x << " states ---" << endl;
    TuringMachine tm(beavers[x], 'a', 'h', '0');
    tm.run();

    cout << "Finished in " << tm.getMoves() << " steps." << endl;
}

void usage(const char *use) {
    cout << "States allowed: " << use << " 1, 2, 3, 4, 5, 6.\n";
    exit(1);
}


int main(int argc, char **argv) {
    if (argc < 2)
        usage(argv[0]);

    int input = atoi(argv[1]);

    if (input < 1 || input > 6) {
        cout << "State must be >0 and <7.\n\n";
        usage(argv[0]);
    }

    initBB();
    busyBeaver(input);
}
