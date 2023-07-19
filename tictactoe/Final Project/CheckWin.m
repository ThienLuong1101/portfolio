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