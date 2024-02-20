% Clear all variables
clearvars;

% Generate a tic-tac-toe board using plot function
plot(1, 1);

% Set the axis limits to define the board size
xlim([0, 3]);
ylim([0, 3]);

% Draw vertical lines of the board
line([1 1], [0 3], 'LineWidth', 2);
line([2 2], [0 3], 'LineWidth', 2);
line([0 0],[0 3], 'LineWidth', 2);
line([3 3], [0 3], 'LineWidth', 2);

% Draw horizontal lines of the board
line([0 3], [1 1], 'LineWidth', 2);
line([0 3], [2 2], 'LineWidth', 2);
line([0 3],[0 0], 'LineWidth', 2);
line([0 3], [3 3], 'LineWidth', 2);

% Loop to take multiple clicks from the user
while true
    % Get the x and y coordinates of the user's click
    [xClick, yClick] = ginput(1);
    
    % Store the coordinates of the user's move
    moveX = xClick;
    moveY = yClick;
    
    % Display the x and y coordinates of the user's move
    fprintf("x: %.5f\n", xClick);
    fprintf('y: %.5f\n',yClick);
end
