#include <iostream>
using namespace std;

struct FootballGame {
    int FirstGameFirstTeam = 0, FirstGameSecondTeam = 0;
    int SecondGameFirstTeam = 0, SecondGameSecondTeam = 0;
    int WasGameAtHome = 0;
    int GetGoalScore() const {
        int GoalScoreGoal = FirstGameSecondTeam + SecondGameSecondTeam - FirstGameFirstTeam - SecondGameFirstTeam;
        if (GoalScoreGoal < 0) {
            GoalScoreGoal = 0;
        } else {
            if ((WasGameAtHome == 1 && FirstGameSecondTeam >= SecondGameFirstTeam + GoalScoreGoal) ||
                (WasGameAtHome == 2 && SecondGameSecondTeam >= FirstGameFirstTeam)) {
                ++GoalScoreGoal;
            }
        }
        return GoalScoreGoal;
    }
};
int main()
{
    FootballGame game;
    char zap;
    cin >> game.FirstGameFirstTeam >> zap >> game.FirstGameSecondTeam >> game.SecondGameFirstTeam >> zap >> game.SecondGameSecondTeam  >> game.WasGameAtHome;
    cout << game.GetGoalScore();
}
