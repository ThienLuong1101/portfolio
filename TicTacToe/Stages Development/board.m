function board()
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
end