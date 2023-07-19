clearvars;
%Ask the user to select a game mode
disp("TicTacToe game!!!");
disp("game mode:");
modeGame = input("press 1 for player vs player, press 2 for player vs computer: ");

%Run the selected game mode
if modeGame == 1
    disp("player vs player mode");
    playerVsPlayer
elseif modeGame == 2
    disp("player vs computer mode");
    playerVsCom
    
end

function playerVsPlayer
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
            display("Congratulations! X player win!");
            break;
        end
    
        if CheckWin(CheckO)
            %if O win display "O WIN!" in the plot
            txt = "O WIN!";
            text(1.5, 1.5, txt, 'FontSize', 100, 'HorizontalAlignment', 'center','Color',[0.5 0.1 1]);
            display("Congratulations! O player win!");
            break;
        end
            %if noone win display "IT'S DRAW!"
        if isempty(checkMove)
            txt = "IT'S DRAW!";
            text(1.5, 1.5, txt, 'FontSize', 60, 'HorizontalAlignment', 'center','Color',[0.3 0.5 0]);
            break;
        end
    end
end

function playerVsCom
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
        icon = 'X';
        displayIcon(moveA,icon);
        CheckX = [CheckX moveA]; %add user's click position to X vector for check win later
        
        if ~isempty(checkMove)
            computer = checkMove(randi(length(checkMove)));
            checkMove(checkMove==computer) = [];
            icon = 'O';
            displayIcon(computer,icon);
            CheckO = [CheckO computer]; %add user's click position to O vector for check win later
        end
        
        %examinize who wins
        if CheckWin(CheckX)
            %if X win display "X WIN!" in the plot
            txt = "YOU WIN!";
            text(1.5, 1.5, txt, 'FontSize', 70, 'HorizontalAlignment', 'center','Color',[0.9 0.6 0.2]);
            disp("congratulations! You Win!");
            break;
        end
    
        if CheckWin(CheckO)
            %if O win display "O WIN!" in the plot
            txt = "YOU LOSE!";
            text(1.5, 1.5, txt, 'FontSize', 60, 'HorizontalAlignment', 'center','Color',[0.5 0.1 1]);
            disp("You Lose!");
            break;
        end
            %if noone win display "IT'S DRAW!"
        if isempty(checkMove)
            txt = "IT'S DRAW!";
            text(1.5, 1.5, txt, 'FontSize', 60, 'HorizontalAlignment', 'center','Color',[0.3 0.5 0]);
            break;
        end
    
    end
end

function moveA = checkClick(xClick, yClick)
% Checks whose turn it is based on the clicked position

 %first row
    if 0<xClick && xClick<1 && 2<yClick && yClick<3
        moveA = 1;
    elseif 1<xClick && xClick<2 && 2<yClick && yClick<3
        moveA = 2;
    elseif 2<xClick && xClick<3 && 2<yClick && yClick<3
        moveA = 3;
    %second row
    elseif 0<xClick && xClick<1 && 1<yClick && yClick<2
        moveA = 4;
    elseif 1<xClick && xClick<2 && 1<yClick && yClick<2
        moveA =5;
    elseif 2<xClick && xClick<3 && 1<yClick && yClick<2
        moveA = 6;
    %third row
    elseif 0<xClick && xClick<1 && 0<yClick && yClick<1
        moveA = 7;
    elseif 1<xClick && xClick<2 && 0<yClick && yClick<1
        moveA = 8;
    elseif 2<xClick && xClick<3 && 0<yClick && yClick<1
        moveA = 9;
    else
        moveA = 10;
    end
end

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

function displayIcon(moveA,icon)

    %first row
    if moveA == 1
        text(0.5, 2.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif moveA == 2
        text(1.5, 2.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif  moveA == 3
        text(2.5, 2.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    end
    
    %second row
    if moveA == 4
        text(0.5, 1.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif moveA == 5
        text(1.5, 1.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif moveA == 6
        text(2.5, 1.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    end

    %third row
    if moveA == 7
        text(0.5, 0.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif moveA == 8
        text(1.5, 0.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif moveA == 9
        text(2.5, 0.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    end
end


