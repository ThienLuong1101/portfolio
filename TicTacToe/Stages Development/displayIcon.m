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