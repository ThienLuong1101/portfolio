clearvars;
%Make tictactoe board
plot(1, 1);
% Set the axis limits
xlim([0, 3]);
ylim([0, 3]);
%hiding line axis 
set(gca,'XTick',[],'YTick',[]);
% Draw vertical lines
line([1 1], [0 3], 'LineWidth', 2);
line([2 2], [0 3], 'LineWidth', 2);
line([0 0],[0 3], 'LineWidth', 2);
line([3 3], [0 3], 'LineWidth', 2);
% Draw horizontal lines
line([0 3], [1 1], 'LineWidth', 2);
line([0 3], [2 2], 'LineWidth', 2);
line([0 3],[0 0], 'LineWidth', 2);
line([0 3], [3 3], 'LineWidth', 2);


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
    
    %if user click outside the plot it will return moveA == 10 and ask user
    %click again
    while moveA == 10
        disp("plz click on an empty place");
        [xClick, yClick] = ginput(1);
        moveX = xClick;
        moveY = yClick;
        moveA = checkClick(moveX,moveY);
    end
    
    %if this place place is taken require user click again
    while ~ismember(moveA,checkMove)
        disp("plz click on an empty place");
        [xClick, yClick] = ginput(1);
        moveX = xClick;
        moveY = yClick;
        moveA = checkClick(moveX,moveY);
    end
    
    %eliminate a taken place that user clicked
    checkMove(checkMove==moveA) = [];
    
    %display icon X or O on the place that user clicked
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
        error;
    end
    
    if CheckWin(CheckO)
        %if O win display "O WIN!" in the plot
        txt = "O WIN!";
        text(1.5, 1.5, txt, 'FontSize', 100, 'HorizontalAlignment', 'center','Color',[0.5 0.1 1]);
        error;
    end
        %if noone win display "IT'S DRAW!"
    if isempty(checkMove)
        txt = "IT'S DRAW!";
        text(1.5, 1.5, txt, 'FontSize', 60, 'HorizontalAlignment', 'center','Color',[0.3 0.5 0]);
        error;
    end

end

