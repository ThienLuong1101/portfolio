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
