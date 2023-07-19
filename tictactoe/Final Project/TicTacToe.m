clearvars;

%Ask the user to select a game mode
disp("TicTacToe game!!!");
disp("game mode:");
modeGame = input("press 1 for player vs player, press 2 for player vs computer: ");

%Run the selected game mode
if modeGame == 1
    playerVsPlayer
elseif modeGame == 2
    playerVsCom
end


