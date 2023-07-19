clearvars;
%Make tictactoe board
board();

checkMove = 1:9; % avalaible place that user can click

while true
    %prompting proper move
    [xClick, yClick] = ginput(1);
    moveX = xClick;
    moveY = yClick;
    %convert x and y coordinates into 1 to 9
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
   
    %eliminate a taken place that user clicked out of available number place
    checkMove(checkMove==moveA) = [];


    if mod(length(checkMove),2) == 1 %if total number in checkmove is even number it is O's turn (O always goes second)
        icon = 'O';
        displayIcon(moveA,icon);
        
    else %if total number in checkmove is odd number it is X's turn 
        icon = 'X';
        displayIcon(moveA,icon);
        
    end
    %if the no empty place break
    if isempty(checkMove)
        break
    end

end




function displayIcon(position,icon)

    
    %first row
    if position == 1
        text(0.5, 2.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif position == 2
        text(1.5, 2.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif  position == 3
        text(2.5, 2.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    end
    
    %second row
    if position == 4
        text(0.5, 1.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif position == 5
        text(1.5, 1.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif position == 6
        text(2.5, 1.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    end

    %third row
    if position == 7
        text(0.5, 0.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif position == 8
        text(1.5, 0.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    elseif position == 9
        text(2.5, 0.5, icon, 'FontSize', 40, 'HorizontalAlignment', 'center');
    end

    
end