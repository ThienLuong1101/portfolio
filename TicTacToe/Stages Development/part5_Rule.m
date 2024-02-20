clearvars;
board();

CheckO = []; %contain numbers of the places that contain icon O
CheckX = []; %contain numbers of the places that contain icon X
checkMove = 1:9; % avalaible place that user can click

while true
    %prompting proper move
    [xClick, yClick] = ginput(1);
    moveX = xClick;
    moveY = yClick;
    %convert x and y coordinates into 1 to 9
    moveA = checkClick(moveX,moveY); 
   
    %eliminate a taken place that user clicked out of available number place
    checkMove(checkMove==moveA) = [];

    if mod(length(checkMove),2) == 1 %if total number in checkmove is even number it is O's turn (O go second)
        icon = 'O';
        displayIcon(moveA,icon);
        CheckO = [CheckO moveA]; %add user's click position to O vector for check win later
    else%if total number in checkmove is odd number it is X's turn (X go first)
        icon = 'X';
        displayIcon(moveA,icon);
        CheckX = [CheckX moveA]; %add user's click position to X vector for check win later
    end

    
    %examinize who wins
    if CheckWin(CheckX)
        %if X win display "X WIN!" in the plot
        txt = "X WIN!";
        text(1.5, 1.5, txt, 'FontSize', 100, 'HorizontalAlignment', 'center','Color',[0.9 0.6 0.2]);
        break;
    end

    if CheckWin(CheckO)
        %if O win display "O WIN!" in the plot
        txt = "O WIN!";
        text(1.5, 1.5, txt, 'FontSize', 100, 'HorizontalAlignment', 'center','Color',[0.5 0.1 1]);
        break;
    end
        %if noone win display "IT'S DRAW!"
    if isempty(checkMove)
        txt = "IT'S DRAW!";
        text(1.5, 1.5, txt, 'FontSize', 60, 'HorizontalAlignment', 'center','Color',[0.3 0.5 0]);
        break;
    end
end

%display the number of the place that contain X icon
fprintf("X's choices:");
disp(CheckX);
%display the number of place that contain O icon 
fprintf("O's choices:");
disp(CheckO);
function result = CheckWin(checkIcon)
    winLine = [1,2,3;4,5,6;7,8,9; %check win for row lines
               1,5,9;3,5,7;1,4,7; %check win for column lines
               2,5,8;3,6,9];      %check win for diagonal lines
    if all(ismember(winLine(1,:), checkIcon)) || all(ismember(winLine(2,:), checkIcon))...
            || all(ismember(winLine(3,:), checkIcon))  || all(ismember(winLine(4,:), checkIcon))...
            ||all(ismember(winLine(5,:), checkIcon)) || all(ismember(winLine(6,:), checkIcon)) ...
            || all(ismember(winLine(7,:), checkIcon)) || all(ismember(winLine(8,:), checkIcon))
    
        result = true;
    else
        result = false;
    end
end