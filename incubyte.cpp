#include <bits/stdc++.h>
using namespace std;

class Spacecraft {
private:
    int x_pos, y_pos, z_pos;
    char direction;

public:
    Spacecraft(int initial_x, int initial_y, int initial_z, char initial_direction) {
        x_pos = initial_x;
        y_pos = initial_y;
        z_pos = initial_z;
        direction = initial_direction;
    }

    void move_forward() {
        switch (direction) {
            case 'N':
                y_pos++;
                break;
            case 'S':
                y_pos--;
                break;
            case 'E':
                x_pos++;
                break;
            case 'W':
                x_pos--;
                break;
            case 'U':
                z_pos++;
                break;
            case 'D':
                z_pos--;
                break;
        }
    }

    void move_backward() {
        switch (direction) {
            case 'N':
                y_pos--;
                break;
            case 'S':
                y_pos++;
                break;
            case 'E':
                x_pos--;
                break;
            case 'W':
                x_pos++;
                break;
            case 'U':
                z_pos--;
                break;
            case 'D':
                z_pos++;
                break;
        }
    }

    void turn_left() {
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
            case 'U':
                direction = 'N';
                break;
            case 'D':
                direction = 'S';
                break;
        }
    }

    void turn_right() {
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
            case 'U':
                direction = 'S';
                break;
            case 'D':
                direction = 'N';
                break;
        }
    }

    void turn_up() {
        direction = 'U';
    }

    void turn_down() {
        direction = 'D';
    }

    void execute_commands(string commands) {
        for (int i = 0; i < commands.size(); i++) {
            switch (commands[i]) {
                case 'f':
                    move_forward();
                    break;
                case 'b':
                    move_backward();
                    break;
                case 'l':
                    turn_left();
                    break;
                case 'r':
                    turn_right();
                    break;
                case 'u':
                    turn_up();
                    break;
                case 'd':
                    turn_down();
                    break;
                default:
                    break;
            }
        }
    }

    void get_position(int &x, int &y, int &z) const {
        x = x_pos;
        y = y_pos;
        z = z_pos;
    }

    char get_direction() const {
        return direction;
    }
};

int main() {
    int x, y, z;
    cout << "Enter the initial positions:" << endl;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Z: ";
    cin >> z;
    char direction = 'N';
    Spacecraft spacecraft(x, y, z, direction);
    string commands;
    cout << "Enter the commands: ";
    cin >> commands;
    cout << endl;
    spacecraft.execute_commands(commands);
    spacecraft.get_position(x, y, z);
    direction = spacecraft.get_direction();

    cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
    cout << "Final Direction: " << direction << "\n";

    return 0;
}