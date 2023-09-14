#include <bits/stdc++.h>
using namespace std;
enum Direction { N, S, E, W, Up, Down };

string directionToString(Direction dir) {
    switch (dir) {
        case N: return "N";
        case S: return "S";
        case E: return "E";
        case W: return "W";
        case Up: return "Up";
        case Down: return "Down";
        default: return "Unknown";
    }
}

void move(char command, int& x, int& y, int& z, Direction& direction) {
    switch (command) {
        case 'f':
            switch (direction) {
                case N: y++; break;
                case S: y--; break;
                case E: x++; break;
                case W: x--; break;
                case Up: z++; break;
                case Down: z--; break;
            }
            break;
        case 'b':
            switch (direction) {
                case N: y--; break;
                case S: y++; break;
                case E: x--; break;
                case W: x++; break;
                case Up: z--; break;
                case Down: z++; break;
            }
            break;
        case 'l':
            switch (direction) {
                case N: direction = W; break;
                case S: direction = E; break;
                case E: direction = N; break;
                case W: direction = S; break;
            }
            break;
        case 'r':
            switch (direction) {
                case N: direction = E; break;
                case S: direction = W; break;
                case E: direction = S; break;
                case W: direction = N; break;
            }
            break;
        // case 'u':
        //     if (direction != Up && direction != Down) {
        //         direction = Up;
        //     }
        //     break;
        case 'd':
            if (direction != Up && direction != Down) {
                direction = Down;
            }
            break;
    }
}

int main() {
    int x = 0, y = 0, z = 0;
    Direction direction = N;

    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    for (char command : commands) {
        move(command, x, y, z, direction);
    }

    cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
    cout << "Final Direction: " << directionToString(direction) << "\n";

    return 0;
}
