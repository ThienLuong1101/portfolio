clearvars;
board();

%that 2 problems are: if user click outside the plot and click on the same place multiple times


checkMove = 1:9; % avalaible place that user can click
while true
    %prompting proper move
    [xClick, yClick] = ginput(1);
    moveX = xClick;
    moveY = yClick;

    %convert x and y coordinates into 1 to 10
    moveA = checkClick(moveX,moveY); 


    %if this place is taken require user click again
    %if user click outside the plot moveA == 10, the checkList doesn't contain number 10. Therefore, it also require user click again
    while ~ismember(moveA,checkMove) %the place is taken will not in CheckMove list
        disp("plz click on proper place");
        %promt user click again
        [xClick, yClick] = ginput(1);
        moveX = xClick;
        moveY = yClick;
        moveA = checkClick(moveX,moveY);
    end
    
    %eliminate a taken number that user clicked out of available number place
    checkMove(checkMove==moveA) = [];

    disp(moveA);
end



