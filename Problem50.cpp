void ShowGameOverScreen()
{
    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout << Tabs(2) << " +++ G a m e O v e r
        ++ +\n ";
        cout
         << Tabs(2) << "__________________________________________________________\n\n";
}
void ShowFinalGameResults(stGameResults GameResults)
{
cout << Tabs(2) << "_____________________ [Game Results]_____________________\n\n";
 cout << Tabs(2) << "Game Rounds : " <<GameResults.GameRounds << endl;
 cout << Tabs(2) << "Player1 won times : " << GameResults.Player1WinTimes << endl;
 cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl;
 cout << Tabs(2) << "Draw times : " << GameResults.DrawTimes << endl;
 cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << endl;
 cout << Tabs(2) << "___________________________________________________________\n";
 SetWinnerScreenColor(GameResults.GameWinner);
}