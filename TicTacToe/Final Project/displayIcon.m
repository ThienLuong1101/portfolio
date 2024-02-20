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