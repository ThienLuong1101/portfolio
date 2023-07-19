
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
    
    %eliminate a taken number that user clicked
    checkMove(checkMove==moveA) = [];

    %display X
    icon = 'X';
    displayIcon(moveA,icon);
    CheckX = [CheckX moveA]; %add user's click position to X vector for check win later
    
    %prompt move for computer
    if ~isempty(checkMove) %stop when no available positions for computer 
        computer = checkMove(randi(length(checkMove))); %random available positions number

        checkMove(checkMove==computer) = [];
        icon = 'O';
        displayIcon(computer,icon);
        CheckO = [CheckO computer]; %add user's click position to O vector for check win later
    end
    
    

end

